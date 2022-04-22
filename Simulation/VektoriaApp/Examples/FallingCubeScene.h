#pragma once

#include "DefaultScene.h"

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