#include <math.h>
#include "vector3.h"
#include "matrix33.h"
vector3::vector3()
{

}

vector3::vector3(float xx, float yy, float zz)
{
	x = xx;
	y = yy;
	z = zz;
}

vector3::~vector3()
{

}

float vector3::Dot(const vector3& rhs)
{
	return this->x*rhs.x + this->y*rhs.y + this->z*rhs.z;
}
//vector is a row vector;
vector3 vector3::operator*(const matrix33& rhs)
{
	vector3 rvecs[3];
	for (int i=0;i<3;i++)
	{
		rvecs[i] = rhs.GetColumnVecs(i);
	}
	vector3 ret;
	ret.x = this->Dot(rvecs[0]);
	ret.y = this->Dot(rvecs[1]);
	ret.z = this->Dot(rvecs[2]);

	return ret;
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



