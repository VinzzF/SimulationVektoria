#include "pch.h"
#include "RigidBodyPlacement.h"
#include "Converter.h"

RigidBodyPlacement::RigidBodyPlacement(r3::RigidBody* rigidBody, 
									   Vektoria::CPlacement* placement)
	: m_rigidBody(rigidBody),
	m_placement(placement)
{
}

RigidBodyPlacement::~RigidBodyPlacement()
= default;

void RigidBodyPlacement::update() const
{
	const auto& transform = m_rigidBody->getTransform();
	auto position = convertVector(transform.getPosition());

	// Build transformation matrices
	glm::quat rotation = transform.getRotation();
	auto rotMat = Vektoria::CQuaternion(rotation.x, rotation.y, rotation.z, -rotation.w).GetMatrix();
	Vektoria::CHMat scaleMat;
	scaleMat.Scale(m_scale.x, m_scale.y, m_scale.z);
	

	// Apply transformation
	//m_placement->Scale(convertVector(m_scale));
	//m_placement->RotateDelta(rotation.x, rotation.y, rotation.z, rotation.w);
	Vektoria::CHMat newMat = rotMat * scaleMat;
	m_placement->SetMat(newMat);
	m_placement->TranslateDelta(position);
}

void RigidBodyPlacement::setRigidBody(r3::RigidBody* rigidBody)
{
	m_rigidBody = rigidBody;
}

r3::RigidBody* RigidBodyPlacement::getRigidBody() const
{
	return m_rigidBody;
}

void RigidBodyPlacement::setPlacement(Vektoria::CPlacement* placement)
{
	m_placement = placement;
}

Vektoria::CPlacement* RigidBodyPlacement::getPlacement() const
{
	return m_placement;
}

void RigidBodyPlacement::setScale(glm::vec3 scale)
{
	m_scale = scale;
}
