#pragma once
#include "SimulationScene.h"
#include "PhysicInterfaces/PhysicsEngineWrapper.h"

namespace Vektoria
{
	class CGeo;
	class CPlacement;
}

namespace r3
{
	class Particle;
	class ParticleGravity;
}

class ParticlePlacement;

class FallingBallSimulation : public SimulationScene
{
public:
	explicit FallingBallSimulation(Vektoria::CGeo* geo);
	~FallingBallSimulation();

	void update(float timeDelta) override;

private:
	void init();

	Vektoria::CGeo* m_sphereGeo;
	Vektoria::CPlacement* m_spherePlacement;

	r3::Particle* m_particle;
	r3::ParticleGravity* m_gravity;
	ParticlePlacement* m_particlePlacement;
};