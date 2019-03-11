#include "RigidBodyPlacement.h"
#include "Vektoria/Placement.h"
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
	auto pos = convertVector(transform.getPosition());
	
	auto scale = m_placement->GetScale();
	m_placement->Scale(scale);
	m_placement->TranslateDelta(pos);
	
	
	/// \todo set rotation
	//m_placement->Rotate(transform.getRotation());	
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
