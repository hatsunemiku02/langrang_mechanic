#include "vector3.h"

vector3::vector3()
{

}

vector3::~vector3()
{

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



