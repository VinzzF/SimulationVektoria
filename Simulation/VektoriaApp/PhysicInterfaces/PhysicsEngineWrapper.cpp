#include "pch.h"
#include "PhysicsEngineWrapper.h"
#include "R3D/ParticleEngine/ParticleWorld.h"
#include "R3D/RigidBodyEngine/RigidBodyWorld.h"

#include "ParticlePlacementWorld.h"
#include "RigidBodyPlacementWorld.h"

PhysicsEngineWrapper::PhysicsEngineWrapper()
{
	init();
}

PhysicsEngineWrapper::~PhysicsEngineWrapper()
= default;

void PhysicsEngineWrapper::tick(float timeDelta)
{
	static const auto limit = 1.0f / 60.0f;
	if(timeDelta > limit)
	{
		timeDelta = limit;
	}

	//printf("Timedelta %f, fps %f\n", timeDelta, 1.0f / timeDelta);
	m_physicsEngine.tick(timeDelta);

	m_particlePlacementWorld->update();
	m_rigidBodyPlacementWorld->update();
}

ParticlePlacementWorld* PhysicsEngineWrapper::getParticlePlacementWorld() const
{
	return m_particlePlacementWorld.get();
}

RigidBodyPlacementWorld* PhysicsEngineWrapper::getRigidBodyPlacementWorld() const
{
	return m_rigidBodyPlacementWorld.get();
}

void PhysicsEngineWrapper::init()
{
	m_particlePlacementWorld = std::make_unique<ParticlePlacementWorld>();
	m_rigidBodyPlacementWorld = std::make_unique<RigidBodyPlacementWorld>();

	m_physicsEngine.registerModule(m_particlePlacementWorld->getWorld(), "particle");
	m_physicsEngine.registerModule(m_rigidBodyPlacementWorld->getWorld(), "rigid_body");

	m_physicsEngine.resume();
}
