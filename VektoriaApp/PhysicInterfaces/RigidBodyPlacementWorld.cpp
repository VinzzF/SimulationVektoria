#include "pch.h"
#include "RigidBodyPlacementWorld.h"
#include "RigidBodyPlacement.h"
#include "R3D/RigidBodyEngine/RigidBodyWorld.h"
#include "R3D/RigidBodyEngine/RigidBody.h"
#include "R3D/RigidBodyEngine/DefaultRigidBodyEngineCI.h"

#include <algorithm>

RigidBodyPlacementWorld::RigidBodyPlacementWorld()
{
	init();
}

RigidBodyPlacementWorld::~RigidBodyPlacementWorld()
{
}

void RigidBodyPlacementWorld::update()
{
	for(auto& it : m_rigidBodyPlacements)
	{
		it->update();
	}
}

const std::vector<r3::RigidBody*>& RigidBodyPlacementWorld::getRigidBodies() const
{
	return m_world->getRigidBodies();
}

std::vector<r3::RigidBody*>& RigidBodyPlacementWorld::getRigidBodies()
{
	return m_world->getRigidBodies();
}

void RigidBodyPlacementWorld::addRigidBodyPlacement(RigidBodyPlacement* placement)
{
	m_rigidBodyPlacements.emplace_back(placement);
}

bool RigidBodyPlacementWorld::removeRigidBodyPlacement(RigidBodyPlacement* placement)
{
	const auto removedBody = std::remove(m_rigidBodyPlacements.begin(),
										 m_rigidBodyPlacements.end(),
										 placement);

	const bool found = removedBody != m_rigidBodyPlacements.end();
	if(found)
	{
		m_world->removeRigidBody(placement->getRigidBody());
		m_rigidBodyPlacements.erase(removedBody);
	}

	return found;
}

void RigidBodyPlacementWorld::clear()
{
	for(auto& it : m_rigidBodyPlacements)
	{
		m_world->removeRigidBody(it->getRigidBody());
	}
	m_rigidBodyPlacements.clear();
}

r3::RigidBodyWorld* RigidBodyPlacementWorld::getWorld() const
{
	return m_world.get();
}

void RigidBodyPlacementWorld::init()
{
	m_world = std::make_unique<r3::RigidBodyWorld>();

	const auto ci = new r3::DefaultRigidBodyEngineCI();
	ci->setRigidBodyWorld(m_world.get());
	m_world->setComputationInterface(ci);
}