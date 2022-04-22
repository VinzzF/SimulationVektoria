#include "pch.h"
#include "FallingCubeScene.h"


FallingCubeScene::FallingCubeScene()
{
	m_zmCube.MakeTextureDiffuse(const_cast<char*>("./../Resources/wood.jpg"));
	m_zgCube.Init(1.0f, &m_zmCube);
	m_zpCube.AddGeo(&m_zgCube);
	this->AddPlacement(&m_zpCube);

	// Init particle
	m_particle = new r3::Particle();
	m_particle->setMass(1.0f);

	// Init particle placement and register it
	m_particleNode = new ParticlePlacement(m_particle, &m_zpCube);
	auto particlePlacementWorld = m_physicsEngine.getParticlePlacementWorld();
	particlePlacementWorld->addParticlePlacement(m_particleNode);

	// Init force generator and register it
	m_particleGravity = new r3::ParticleGravity(glm::vec3(0.0f, -0.1f, 0.0f));
	auto particleWorld = particlePlacementWorld->getWorld();
	particleWorld->getParticleForceRegistry().add(m_particle, m_particleGravity);
}

FallingCubeScene::~FallingCubeScene() = default;

void FallingCubeScene::reset()
{
	m_particle->reset();
}
