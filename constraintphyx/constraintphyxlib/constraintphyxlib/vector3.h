#pragma once
class vector3
{
public:
	vector3();
	~vector3();

	vector3 operator + (const vector3& rhs);
	vector3 operator - (const vector3& rhs);

	float Length();
	float x;
	float y;
	float z;
};