#pragma once
#include "SimulationScene.h"
#include "PhysicInterfaces/ParticlePlacement.h"

#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/ParticleGravity.h"

#include <string>

namespace Vektoria
{
	class CGeo;
	class CPlacement;
}

class FallingCubeScene : public SimulationScene
{
public:
	explicit FallingCubeScene(Vektoria::CGeo* geo);
	~FallingCubeScene();

	void update(float timeDelta) override;
	void reset() override;

private:
	Vektoria::CPlacement* m_placement;
	Vektoria::CGeo* m_cubeGeo;

	r3::Particle* m_particle;
	ParticlePlacement* m_particleNode;

	r3::ParticleGravity* m_particleGravity;
};