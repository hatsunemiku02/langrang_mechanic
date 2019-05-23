#include "particle.h"
Particle::Particle(float mass, const vector3& pos, ParticleType type)
{
	this->mMass = mass;
	this->mPosition = pos;
	this->m_Type = type;

}

Particle::~Particle()
{

}


