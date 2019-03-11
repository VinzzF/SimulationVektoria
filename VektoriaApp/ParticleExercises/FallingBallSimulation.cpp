#include "FallingBallSimulation.h"

#include "PhysicInterfaces/ParticlePlacementWorld.h"
#include "PhysicInterfaces/ParticlePlacement.h"

#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/ParticleGravity.h"
#include "R3D/ParticleEngine/ParticleWorld.h"

#include "Vektoria/Placement.h"
#include "Vektoria/Geo.h"
#include "Vektoria/Scene.h"

FallingBallSimulation::FallingBallSimulation(Vektoria::CGeo* geo)
	: m_sphereGeo(geo)
{
	init();
}

FallingBallSimulation::~FallingBallSimulation()
= default;

void FallingBallSimulation::update(float timeDelta)
{
	m_physicsEngine.tick(timeDelta);
}

void FallingBallSimulation::init()
{
	m_spherePlacement = new Vektoria::CPlacement();

	this->AddPlacement(m_spherePlacement);
	m_spherePlacement->AddGeo(m_sphereGeo);

	// Create a new particle
	auto particlePlacementWorld = m_physicsEngine.getParticlePlacementWorld();
	auto particleWorld = particlePlacementWorld->getWorld();
	m_particle = new r3::Particle();
	m_particle->setMass(1.0f);

	// Register the particle placement
	m_particlePlacement = new ParticlePlacement(m_particle, m_spherePlacement);	
	particlePlacementWorld->addParticlePlacement(m_particlePlacement);

	// Register force generator
	m_gravity = new r3::ParticleGravity(glm::vec3(0.0f, -0.1f, 0.0f));

	auto& registry = particleWorld->getParticleForceRegistry();
	registry.add(m_particle, m_gravity);
}
