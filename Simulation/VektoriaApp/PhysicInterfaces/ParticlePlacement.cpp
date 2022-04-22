#include "pch.h"
#include "ParticlePlacement.h"

#include "R3D/ParticleEngine/Particle.h"

#include "Converter.h"

ParticlePlacement::ParticlePlacement(r3::Particle* particle,
									 Vektoria::CPlacement* placement)
	: m_particle(particle),
	m_placement(placement)
{
}

ParticlePlacement::ParticlePlacement()
	: m_particle(nullptr)
	, m_placement(nullptr)
{
}

ParticlePlacement::~ParticlePlacement()
= default;

void ParticlePlacement::update() const
{	
	auto pos = convertVector(m_particle->getPosition());
	m_placement->Translate(pos);	
}

void ParticlePlacement::setParticle(r3::Particle* particle)
{
	m_particle = particle;
}

r3::Particle* ParticlePlacement::getParticle() const
{
	return m_particle;
}

void ParticlePlacement::setPlacement(Vektoria::CPlacement* placement)
{
	m_placement = placement;
}

Vektoria::CPlacement* ParticlePlacement::setPlacement() const
{
	return m_placement;
}
