#pragma once
#include "SimulationScene.h"

#include <vector>

namespace Vektoria
{
	class CGeoSphere;
	class CPlacmeent;
}

namespace r3
{
	class Particle;
	class ParticleGravity;
	class ParticleCollision;
	class ParticleCable;
}

class ParticlePlacement;

class PendulumSimulation : public SimulationScene
{
public:
	explicit PendulumSimulation(Vektoria::CGeoSphere* sphereGeo,
								int elementCount = 5);
	~PendulumSimulation();

	void update(float timeDelta) override;

private:
	void init();
	
	/* Scene graph */
	Vektoria::CGeoSphere* m_sphereGeo;
	std::vector<Vektoria::CPlacement*> m_placements;
	
	/* Particles */
	std::vector<r3::Particle*> m_particles;
	std::vector<r3::Particle*> m_cableParticles;
	std::vector<ParticlePlacement*> m_particlePlacements;
	
	int m_pendulumElementCount;
	float m_particleMass;
	float radius;

	/* Particle contact generators */
	std::vector<r3::ParticleCable*> m_cables;
	std::vector<r3::ParticleCollision*> m_particleCollisions;	

	int m_cableLength;
	float m_restitution;
	float m_penetration;

	/* Particle force generators */
	r3::ParticleGravity* m_gravityGenerator;
	Vektoria::CHVector m_gravity;
};