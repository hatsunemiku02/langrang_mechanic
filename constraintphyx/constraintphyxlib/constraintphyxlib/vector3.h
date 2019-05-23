#pragma once
class vector3
{
public:
	vector3();
	~vector3();

	vector3 operator + (const vector3& rhs);
	vector3 operator - (const vector3& rhs);

	friend vector3 operator * (const vector3& rhs, const float& lhs)
	{
		vector3 ret;
		ret.x = rhs.x * lhs;
		ret.y = rhs.y * lhs;
		ret.z = rhs.z * lhs;
		return ret;
	}

	friend vector3 operator * (const float& lhs, const vector3& rhs)
	{
		vector3 ret;
		ret.x = rhs.x * lhs;
		ret.y = rhs.y * lhs;
		ret.z = rhs.z * lhs;
		return ret;
	}

	float Length();
	float x;
	float y;
	float z;
};