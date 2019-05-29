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

void DistanceConstraint::Update()
{
	vector3 impsulea = ComputeLambdaA()*ComputeJacobiPA();
	vector3 impsuleb = ComputeLambdaB()*ComputeJacobiPB();

	//vector3 forcea = ComputeJacobiPA();
	//vector3 forceb = ComputeJacobiPB();
	m_pPA->mContraintImpsule = impsulea;
	m_pPB->mContraintImpsule = impsuleb;
}

vector3 DistanceConstraint::ComputeJacobiPA()
{
	vector3 jacobi;
	jacobi = (m_pPA->mPosition - m_pPB->mPosition)* 2;

	//vector3 temp = m_pPA->mMass*m_pPA->mAcceleration - m_pPA->mExternalForce ;

	return jacobi;
}

vector3 DistanceConstraint::ComputeJacobiPB()
{
	vector3 jacobi;
	jacobi = (m_pPB->mPosition - m_pPA->mPosition) * 2;

	//vector3 temp = m_pPB->mMass*m_pPB->mAcceleration - m_pPB->mExternalForce;
	return jacobi;
}

float DistanceConstraint::ComputeLambda(Particle* par)
{
	matrix33 inversemat;
	inversemat.value[0][0] = 1.0f / par->mMass;
	inversemat.value[1][1] = 1.0f / par->mMass;
	inversemat.value[2][2] = 1.0f / par->mMass;
	return 0;
}

float DistanceConstraint::ComputeLambdaA()
{
	matrix33 inversemat;
	inversemat.value[0][0] = 1.0f / m_pPA->mMass;
	inversemat.value[1][1] = 1.0f / m_pPA->mMass;
	inversemat.value[2][2] = 1.0f / m_pPA->mMass;

	vector3 Jacobi = ComputeJacobiPA();
	float Denominator = Jacobi.Dot(inversemat*Jacobi);
	float Molecule = Jacobi.Dot(m_pPA->mVelocity);
	return -Molecule / Denominator;
}

float DistanceConstraint::ComputeLambdaB()
{
	matrix33 inversemat;
	inversemat.value[0][0] = 1.0f / m_pPB->mMass;
	inversemat.value[1][1] = 1.0f / m_pPB->mMass;
	inversemat.value[2][2] = 1.0f / m_pPB->mMass;

	vector3 Jacobi = ComputeJacobiPB();
	float Denominator = Jacobi.Dot(inversemat*Jacobi);
	float Molecule = Jacobi.Dot(m_pPB->mVelocity);
	return -Molecule / Denominator;
}
