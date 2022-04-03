#pragma once

#include "DefaultScene.h"
#include "PhysicInterfaces/ParticlePlacement.h"

#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/ParticleGravity.h"

/**
 * Sample scene using Rumble3D physics engine for a falling cube
 */
class FallingCubeScene : public DefaultScene
{
public:
	explicit FallingCubeScene();
	~FallingCubeScene();

	void reset() override;

protected:
	Vektoria::CMaterial m_zmCube;
	Vektoria::CPlacement m_zpCube;
	Vektoria::CGeoCube m_zgCube;

	r3::Particle* m_particle;
	ParticlePlacement* m_particleNode;

	r3::ParticleGravity* m_particleGravity;
};