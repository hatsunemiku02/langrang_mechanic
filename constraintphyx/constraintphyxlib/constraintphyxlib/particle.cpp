#include "particle.h"

Particle::Particle(float mass, const vector3& pos, ParticleType type)
{
	this->mMass = mass;
	this->mPosition = pos;
	this->m_Type = type;
	if (m_Type==pt_dynamic)
	{
		mExternalForce = mMass * vector3(0, -9.8, 0);
	}
	else
	{
		mExternalForce = vector3(0, 0, 0);
		mInternalForce = vector3(0, 0, 0);
	}
	mVelocity = vector3(0, 0, 0);
}

Particle::~Particle()
{

}

void Particle::Update(float time)
{
	if (m_Type== pt_dynamic)
	{
		vector3 force = mExternalForce + mInternalForce;
		float invmass = 1.0f / mMass;
		vector3 av = force * invmass;
		mVelocity = mVelocity + av*time;
		mPosition = mPosition + mVelocity * time;
	}
	else if (m_Type==pt_static)
	{
// 		float invtime = 1.0f / time;
// 		vector3 deltapos = mPosition - mPrePosition;
// 		mVelocity = deltapos * invtime;
	}
	//abort();
}

