#pragma once

#include "vector3.h"

class matrix33
{
public:
	matrix33();
	virtual ~matrix33();

	vector3 operator* (const vector3& rhs);
	union
	{
		float value[3][3];
		vector3 vecs[3];//row vec3;
	};
	vector3 GetColumnVecs(int i) const;

protected:




};