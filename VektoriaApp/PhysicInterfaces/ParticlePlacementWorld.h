#pragma once
#include <memory>

#include <vector>

namespace r3
{
	class ParticleWorld;
}

class ParticlePlacement;

class ParticlePlacementWorld
{
public:
	using ParticleWorld_Ptr = std::unique_ptr<r3::ParticleWorld>;

	explicit ParticlePlacementWorld();
	~ParticlePlacementWorld();

	/** \brief Update all particle placements. */
	void update();

	/** \brief Add a new particle particle placement. */
	void addParticlePlacement(ParticlePlacement* placement);
	/** \brief Remove an already registered particle placement. 
	 * \return True if the placement was found, false otherwise.
	 */
	bool removeParticlePlacement(ParticlePlacement* placement);

	/** \brief Clear the list of particle placements. */
	void clear();

	/** \brief Get the particle world. */
	r3::ParticleWorld* getWorld() const;

private:
	void init();

	std::vector<ParticlePlacement*> m_particlePlacements;

	ParticleWorld_Ptr m_world;	
};