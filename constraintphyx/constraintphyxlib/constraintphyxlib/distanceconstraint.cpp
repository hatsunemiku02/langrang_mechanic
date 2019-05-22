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
