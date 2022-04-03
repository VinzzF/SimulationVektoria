#include "pch.h"
#include "ParticlePlacementWorld.h"

#include "R3D/ParticleEngine/ParticleWorld.h"
#include "R3D/ParticleEngine/Particle.h"
#include "R3D/ParticleEngine/DefaultParticleEngineCI.h"

#include "ParticlePlacement.h"

ParticlePlacementWorld::ParticlePlacementWorld()
{
	init();
}

ParticlePlacementWorld::~ParticlePlacementWorld()
= default;

void ParticlePlacementWorld::update()
{
	for(auto& it : m_particlePlacements)
	{
		it->update();
	}
}

const std::vector<r3::Particle*>& ParticlePlacementWorld::getParticles() const
{
	return m_world->getParticles();
}

std::vector<r3::Particle*>& ParticlePlacementWorld::getParticles()
{
	return m_world->getParticles();
}

void ParticlePlacementWorld::addParticlePlacement(ParticlePlacement* placement)
{
	m_particlePlacements.push_back(placement);
	m_world->addParticle(placement->getParticle());
}

bool ParticlePlacementWorld::removeParticlePlacement(ParticlePlacement* placement)
{
	const auto removedPlacement = std::remove(m_particlePlacements.begin(),
											  m_particlePlacements.end(),
											  placement);

	const bool found = removedPlacement != m_particlePlacements.end();
	if(found)
	{
		m_world->removeParticle(placement->getParticle());
		m_particlePlacements.erase(removedPlacement);
	}

	return found;
}

void ParticlePlacementWorld::clear()
{
	for(auto& it : m_particlePlacements)
	{
		m_world->removeParticle(it->getParticle());
	}
	m_particlePlacements.clear();
}

r3::ParticleWorld* ParticlePlacementWorld::getWorld() const
{
	return m_world.get();
}

void ParticlePlacementWorld::init()
{
	m_world = std::make_unique<r3::ParticleWorld>();

	const auto ci = new r3::DefaultParticleEngineCI(1000, 0, m_world.get());
	m_world->setComputationInterface(ci);
}
