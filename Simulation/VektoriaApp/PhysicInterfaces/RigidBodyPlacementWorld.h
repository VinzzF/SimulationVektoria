#pragma once

#include <memory>
#include <vector>

namespace r3
{
	class RigidBodyWorld;
	class RigidBody;
}

class RigidBodyPlacement;

class RigidBodyPlacementWorld
{
public:
	using RigidBodyWorld_Ptr = std::unique_ptr<r3::RigidBodyWorld>;

	explicit RigidBodyPlacementWorld();
	~RigidBodyPlacementWorld();

	/** \brief Update all rigid body nodes. */
	void update();

	/** \brief Get all registered rigid bodies. */
	const std::vector<r3::RigidBody*>& getRigidBodies() const;
	/** \brief Get all registered rigid bodies. */
	std::vector<r3::RigidBody*>& getRigidBodies();

	/** \brief Register a new rigid body placement. */
	void addRigidBodyPlacement(RigidBodyPlacement* placement);
	/** \brief Unregister an already registered rigid body placement. 
	 * \return True if the placement was found, false otherwise.
	 */
	bool removeRigidBodyPlacement(RigidBodyPlacement* placement);

	/** \brief Clear the list of rigid body placements. */
	void clear();

	/** \brief Get the rigid body world. */
	r3::RigidBodyWorld* getWorld() const;

private:
	void init();

	std::vector<RigidBodyPlacement*> m_rigidBodyPlacements;

	RigidBodyWorld_Ptr m_world;
};