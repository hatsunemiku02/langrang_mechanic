#pragma once
class Particle;
class DistanceConstraint
{
public:
	DistanceConstraint();
	~DistanceConstraint();
	void Init(Particle* pa, Particle* pb, float distance);
	Particle* m_pPA;
	Particle* m_pPB;
	float m_Distance;
protected:
private:
};