#include "distanceconstraint.h"
#include "particle.h"

DistanceConstraint::DistanceConstraint()
{

}

DistanceConstraint::~DistanceConstraint()
{

}

void DistanceConstraint::Init(Particle* pa, Particle* pb)
{
	m_pPA = pa;
	m_pPB = pb;
	m_Distance = (m_pPA->mPosition - m_pPB->mPosition).Length();
}

vector3 DistanceConstraint::ComputeJacobiPA()
{
	vector3 jacobi;
	jacobi = (m_pPA->mPosition - m_pPB->mPosition)*2;
	return jacobi;
}

vector3 DistanceConstraint::ComputeJacobiPB()
{
	vector3 jacobi;
	jacobi = (m_pPB->mPosition - m_pPA->mPosition) * 2;
	return jacobi;
}

float DistanceConstraint::ComputeLambdaA()
{
	return 0;
}

float DistanceConstraint::ComputeLambdaB()
{
	return 0;
}
