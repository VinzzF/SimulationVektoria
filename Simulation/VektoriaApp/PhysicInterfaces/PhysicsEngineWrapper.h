#pragma once

#include "R3D/PhysicsEngine.h"

class ParticlePlacementWorld;
class RigidBodyPlacementWorld;

class PhysicsEngineWrapper
{
public:
	using ParticlePlacementWorld_Ptr = std::unique_ptr<ParticlePlacementWorld>;
	using RigidBodyPlacementWorld_Ptr = std::unique_ptr<RigidBodyPlacementWorld>;

	explicit PhysicsEngineWrapper();
	~PhysicsEngineWrapper();

	void tick(float timeDelta);

	ParticlePlacementWorld* getParticlePlacementWorld() const;
	RigidBodyPlacementWorld* getRigidBodyPlacementWorld() const;

private:
	void init();

	r3::PhysicsEngine m_physicsEngine;

	ParticlePlacementWorld_Ptr m_particlePlacementWorld;
	RigidBodyPlacementWorld_Ptr m_rigidBodyPlacementWorld;
};