#pragma once

#include "DefaultScene.h"
#include "PhysicInterfaces/ParticlePlacement.h"

#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/ParticleGravity.h"

#include <string>

namespace Vektoria
{
	class CGeo;
	class CPlacement;
}

class FallingCubeScene : public DefaultScene
{
public:
	explicit FallingCubeScene();
	~FallingCubeScene();

	void reset() override;

private:
	Vektoria::CMaterial m_zmCube;
	Vektoria::CPlacement m_zpCube;
	Vektoria::CGeoCube m_zgCube;

	r3::Particle* m_particle;
	ParticlePlacement* m_particleNode;

	r3::ParticleGravity* m_particleGravity;
};