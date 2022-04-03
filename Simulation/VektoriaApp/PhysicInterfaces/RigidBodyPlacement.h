#pragma once
#include "R3D/RigidBodyEngine/RigidBody.h"

namespace Vektoria
{
	class CPlacement;
}

namespace r3
{
	class RigidBody;
}

class RigidBodyPlacement
{
public:
	RigidBodyPlacement(r3::RigidBody* rigidBody,
					   Vektoria::CPlacement* placement);
	~RigidBodyPlacement();

	/**
	 * Update the scene graph node with the associated rigid body
	 * node.
	 */
	void update() const;

	/** Set the current rigid body. */
	void setRigidBody(r3::RigidBody* rigidBody);
	/** Get the current rigid body. */
	r3::RigidBody* getRigidBody() const;

	/** Set the current node. */
	void setPlacement(Vektoria::CPlacement* placement);
	/** Get the current node. */
	Vektoria::CPlacement* getPlacement() const;
	
	/**
	 * Set the scale, which the scene graph node will be resized to
	 * \detail Position and rotation of a scene graph node cannot be set individually.
	 * Every time, one attribute has to be set, so do all the others. Due to rounding
	 * errors, the scale cannot be extracted from the scene graph object.
	 */
	void setScale(glm::vec3 scale);

private:
	glm::vec3 m_scale;

	r3::RigidBody* m_rigidBody;
	Vektoria::CPlacement* m_placement;
};

