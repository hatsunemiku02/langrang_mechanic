#pragma once
#include "vector3.h"
class Particle;
class DistanceConstraint
{
	/*	Constraint  (posa-posb).length - distance = 0 
		(xa-xb)^2+(ya-yb)^2+(za-zb)^2 = distance
	*/

	/* Jacobi :
		(                            
			2xa-2xb,2ya-2yb,2za-2zb,
			2xb-2xa,2yb-2ya,2zb-2za,
		)
	*/
	/* Lambda :
	(
		Jacobi*v/Jacobi*(invermat)*JacobiTrans.
	)
	*/
public:
	DistanceConstraint();
	~DistanceConstraint();
	void Init(Particle* pa, Particle* pb);
	vector3 ComputeJacobiPA();
	vector3 ComputeJacobiPB();
	float ComputeLambdaA();
	float ComputeLambdaB();
	
	Particle* m_pPA;
	Particle* m_pPB;
	float m_Distance;
protected:
	float ComputeLambda(Particle* par);
private:
};