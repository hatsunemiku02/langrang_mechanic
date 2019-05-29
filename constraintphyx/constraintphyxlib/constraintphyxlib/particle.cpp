#include "particle.h"

Particle::Particle(float mass, const vector3& pos, ParticleType type)
{
	this->mMass = mass;
	this->mInvMass = 1 / this->mMass;
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
	mAcceleration = vector3(0, 0, 0);
	mContraintImpsule = vector3(0, 0, 0);
	mExternalImpsule = vector3(0,0,0);
}

Particle::~Particle()
{

}

void Particle::PrediectV(float time)
{
	if (m_Type == pt_static)
		return;
	mVelocity = mVelocity + mExternalImpsule * mInvMass;
}

void Particle::ProjV(float time)
{
	if (m_Type == pt_static)
		return;
	mVelocity = mVelocity + mContraintImpsule * mInvMass;
}

void Particle::UpdatePosition(float time)
{
	if (m_Type == pt_static)
		return;
	mPosition = mPosition+ mVelocity * time;
}


void Particle::Update(float time)
{
	if (m_Type== pt_dynamic)
	{
		vector3 force = mExternalForce + mInternalForce;
		float invmass = 1.0f / mMass;
		mAcceleration = force * invmass;
		mVelocity = mVelocity + mAcceleration *time;
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

