#pragma once
#include "vector3.h"
class Particle
{
public:
	enum ParticleType
	{
		pt_dynamic,
		pt_static,
	};
public:
	Particle();
	virtual ~Particle();
	ParticleType m_Type;
	vector3 mPosition;
	float mMass;
	vector3 mExternalForce;
	vector3 mInternalForce;
protected:
private:
	
};