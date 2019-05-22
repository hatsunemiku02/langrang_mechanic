#pragma once
#include "vector3.h"
class Particle
{
public:
	Particle();
	virtual ~Particle();

	vector3 mPosition;
	float mMass;
	vector3 mExternalForce;
	vector3 mInternalForce;
protected:
private:
	
};