#include "particle.h"
#include "distanceconstraint.h"
#include "vector3.h"
#include <vector>
using namespace std;
int main()
{
	Particle PA(1.0f, vector3(0.0f, 0.0f, 0.0f), Particle::pt_static);
	Particle PB(1.0f, vector3(1.0f, 0.0f, 0.0f), Particle::pt_dynamic);
	DistanceConstraint constraint;
	constraint.Init(&PA, &PB);
	vector3 gravity = vector3(0, -9.8, 0);
	std::vector<vector3> poslist;
	while (true)
	{
		PB.mExternalImpsule = gravity* PB.mMass * 0.01f;
		PA.PrediectV(0.01f);
		PB.PrediectV(0.01f);
	
		constraint.Update();
		PA.ProjV(0.01f);
		PB.ProjV(0.01f);
		PA.UpdatePosition(0.01f);
		PB.UpdatePosition(0.01f);
		poslist.push_back(PB.mPosition);
		vector3 dis = PA.mPosition - PB.mPosition;
		if (dis.Length()>1.2f || dis.Length()<0.8f)
		{
			int jj = 0;
		}
	}
	return 0;
}