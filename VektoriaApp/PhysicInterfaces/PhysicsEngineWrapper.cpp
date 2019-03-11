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

	m_particleWorld->update();
	m_rigidBodyWorld->update();
}

ParticlePlacementWorld* PhysicsEngineWrapper::getParticlePlacementWorld() const
{
	return m_particleWorld.get();
}

RigidBodyPlacementWorld* PhysicsEngineWrapper::getRigidBodyPlacementWorld() const
{
	return m_rigidBodyWorld.get();
}

void PhysicsEngineWrapper::init()
{
	m_particleWorld = std::make_unique<ParticlePlacementWorld>();
	m_rigidBodyWorld = std::make_unique<RigidBodyPlacementWorld>();

	m_physicsEngine.registerModule(m_particleWorld->getWorld(), "particle");
	m_physicsEngine.registerModule(m_rigidBodyWorld->getWorld(), "rigid_body");

	m_physicsEngine.resume();
}
