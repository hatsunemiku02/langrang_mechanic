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

	std::vector<vector3> poslist;
	while (true)
	{

		constraint.Update();
		PA.Update(0.001f);
		PB.Update(0.00001f);
		poslist.push_back(PB.mPosition);
		vector3 dis = PA.mPosition - PB.mPosition;
		if (dis.Length()>1.1f || dis.Length()<0.9f)
		{
			int jj = 0;
		}
	}
	return 0;
}