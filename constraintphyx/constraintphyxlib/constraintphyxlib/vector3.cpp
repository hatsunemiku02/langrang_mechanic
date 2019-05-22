#include <math.h>
#include "vector3.h"

vector3::vector3()
{

}

vector3::~vector3()
{

}


float vector3::Length()
{
	return sqrtf(x*x + y * y + z * z);
}

vector3 vector3::operator-(const vector3& rhs)
{
	vector3 ret;
	ret.x = this->x - rhs.x;
	ret.y = this->y - rhs.y;
	ret.z = this->z - rhs.z;
	return ret;
}

vector3 vector3::operator+(const vector3& rhs)
{
	vector3 ret;
	ret.x = this->x + rhs.x;
	ret.y = this->y + rhs.y;
	ret.z = this->z + rhs.z;
	return ret;
}



