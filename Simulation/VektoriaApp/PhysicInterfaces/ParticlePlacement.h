#pragma once

namespace r3
{
	class Particle;
}

class ParticlePlacement
{
public:
	explicit ParticlePlacement();
	explicit ParticlePlacement(r3::Particle* particle, 
							   Vektoria::CPlacement* placement);
	~ParticlePlacement();

	/** Update the scene graph node with the associated particle node. */
	void update() const;

	/** Set the current particle. */
	void setParticle(r3::Particle* particle);
	/** Get the current particle. */
	r3::Particle* getParticle() const;

	/** Set the current placement. */
	void setPlacement(Vektoria::CPlacement* placement);
	/** Get the current placement. */
	Vektoria::CPlacement* getPlacement() const;

private:
	r3::Particle* m_particle;
	Vektoria::CPlacement* m_placement;
};

