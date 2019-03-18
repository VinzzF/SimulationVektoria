#include "FallingCubeScene.h"

#include "PhysicInterfaces/ParticlePlacementWorld.h"
#include "PhysicInterfaces/ParticlePlacement.h"

#include "R3D/ParticleEngine/ParticleWorld.h"

#include "Vektoria/Geo.h"
#include "Vektoria/Placement.h"

FallingCubeScene::FallingCubeScene(Vektoria::CGeo* geo)
	: m_cubeGeo(geo)
{
	auto particlePlacementWorld = m_physicsEngine.getParticlePlacementWorld();
	auto particleWorld = particlePlacementWorld->getWorld();

	// Init scene graph placement and add it to the scene graph
	m_placement = new Vektoria::CPlacement();
	this->AddPlacement(m_placement);

	m_placement->AddGeo(geo);

	// Init particle
	m_particle = new r3::Particle();
	m_particle->setMass(1.0f);

	// Init particle placement and register it
	m_particleNode = new ParticlePlacement(m_particle, m_placement);
	particlePlacementWorld->addParticlePlacement(m_particleNode);

	// Init force generator and register it
	m_particleGravity = new r3::ParticleGravity(glm::vec3(0.0f, -0.1f, 0.0f));
	particleWorld->getParticleForceRegistry().add(m_particle, m_particleGravity);
}

FallingCubeScene::~FallingCubeScene()
{
}

void FallingCubeScene::update(const float timeDelta)
{
	__super::update(timeDelta);
}

void FallingCubeScene::reset()
{
	m_particle->reset();
}
