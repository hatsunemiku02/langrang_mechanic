#pragma once
class vector3;
class matrix33
{
public:
	matrix33();
	virtual ~matrix33();

	matrix33 operator* (const vector3& rhs);

	float value[3][3];

protected:




};