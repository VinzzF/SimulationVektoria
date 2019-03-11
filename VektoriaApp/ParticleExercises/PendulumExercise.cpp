#include "PendulumExercise.h"

#include "Vektoria/GeoSphere.h"
#include "Vektoria/Placement.h"

#include "R3D/ParticleEngine/ParticleWorld.h"
#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/ParticleGravity.h"
#include "R3D/ParticleEngine/ParticleCollision.h"
#include "R3D/ParticleEngine/ParticleCable.h"

#include "PhysicInterfaces/Converter.h"
#include "PhysicInterfaces/ParticlePlacementWorld.h"
#include "PhysicInterfaces/ParticlePlacement.h"

PendulumSimulation::PendulumSimulation(Vektoria::CGeoSphere* sphereGeo, int elementCount)
	: m_sphereGeo(sphereGeo),
	m_pendulumElementCount(elementCount),
	m_gravity(0.0f, -9.81f, 0.0f),
	m_restitution(1.0f),
	m_penetration(0.01f),
	m_cableLength(3.0f),
	m_particleMass(1.0f)
{
	init();
}

PendulumSimulation::~PendulumSimulation()
= default;

void PendulumSimulation::update(const float timeDelta)
{
	m_physicsEngine.tick(timeDelta);
}

void PendulumSimulation::init()
{
	const auto& particlePlacementWorld = m_physicsEngine.getParticlePlacementWorld();
	const auto& particleWorld = particlePlacementWorld->getWorld();

	// Create particles
	float offset = 2.01f;
	float xPos = -m_pendulumElementCount * offset * 0.5f;
	float yPos = 0.0f;
	for(int i = 0; i < m_pendulumElementCount; ++i)
	{
		// Create particles
		auto particle = new r3::Particle();
		particle->setMass(m_particleMass);
		particle->setPosition(xPos, yPos, 0.0f);
		m_particles.emplace_back(particle);

		auto cableParticle = new r3::Particle();
		cableParticle->setPosition(xPos, yPos + m_cableLength, 0.0f);
		m_cableParticles.emplace_back(cableParticle);

		xPos += offset;

		// Create placements
		auto placement = new Vektoria::CPlacement();
		placement->AddGeo(m_sphereGeo);
		this->AddPlacement(placement);
		m_placements.emplace_back(placement);

		// Create particle placements
		auto particlePlacement = new ParticlePlacement(particle, placement);
		particlePlacementWorld->addParticlePlacement(particlePlacement);
		m_particlePlacements.emplace_back(particlePlacement);
	}

	// Create particle collisions
	auto& contactRegistry = particleWorld->getContactGeneratorRegistry();
	float distance = 2.0f;
	auto particleCount = m_particles.size();
	if(particleCount > 1)
	{
		for(int i = 0; i < particleCount - 1; ++i)
		{
			auto* particleCollision = new r3::ParticleCollision(m_restitution,
																distance,
																m_penetration);
			m_particleCollisions.emplace_back(particleCollision);

			auto* particle1 = m_particles[i];
			auto* particle2 = m_particles[i + 1];

			particleCollision->setParticles(particle1, particle2);

			contactRegistry.registerContactGenerator(particleCollision);
		}
	}

	// Create particle cables
	for(int i = 0; i < m_particles.size(); ++i)
	{
		auto particleCable = new r3::ParticleCable(m_cableLength);
		particleCable->setParticles(m_particles[i], m_cableParticles[i]);
		contactRegistry.registerContactGenerator(particleCable);
	}

	// Register gravity force generator
	m_gravityGenerator = new r3::ParticleGravity(convertVector(m_gravity));
	auto& registry = particleWorld->getParticleForceRegistry();
	for(auto& it : m_particles)
	{
		registry.add(it, m_gravityGenerator);
	}

	// Move the left particle 
	auto first = m_particles.front();
	auto firstPosition = first->getPosition();
	firstPosition.y = yPos + sqrt(m_cableLength);
	firstPosition.x -= sqrt(m_cableLength);
	first->setPosition(firstPosition);
}
