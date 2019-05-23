#pragma once
#include "vector3.h"
#include "matrix33.h"
class Particle
{
public:
	enum ParticleType
	{
		pt_dynamic,
		pt_static,
	};
public:
	Particle(float mass,const vector3& pos, ParticleType type);
	virtual ~Particle();
	ParticleType m_Type;
	vector3 mPosition;
	float mMass;


	vector3 mExternalForce;
	vector3 mInternalForce;

	vector3 mVelocity;

protected:


private:
	
};