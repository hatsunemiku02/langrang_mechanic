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
	float mInvMass;
	vector3 mPrediectPosition;

	vector3 mExternalForce;
	vector3 mInternalForce;
	vector3 mExternalImpsule;
	vector3 mContraintImpsule;

	vector3 mVelocity;
	vector3 mAcceleration;

	void PrediectV(float time);
	void ProjV(float time);
	void UpdatePosition(float time);
	void Update(float time);

protected:


private:
	
};