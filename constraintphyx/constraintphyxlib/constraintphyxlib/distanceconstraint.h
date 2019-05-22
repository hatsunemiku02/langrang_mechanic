#pragma once
class Particle;
class DistanceConstraint
{
	/*	Constraint  (posa-posb).length - distance = 0 
		(xa-xb)^2+(ya-yb)^2+(za-zb)^2 = distance
	*/

	/* Jacobi :
	*/
public:
	DistanceConstraint();
	~DistanceConstraint();
	void Init(Particle* pa, Particle* pb);
	Particle* m_pPA;
	Particle* m_pPB;
	float m_Distance;
protected:
private:
};