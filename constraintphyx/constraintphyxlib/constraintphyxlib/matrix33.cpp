#include "matrix33.h"

matrix33::matrix33()
{
	for (int i=0;i<3;i++)
	{
		for (int j = 0;j<3;j++)
		{
			value[i][j] = 0;
		}
	}
}

matrix33::~matrix33()
{

}
//treat rhs as column
vector3 matrix33::operator*(const vector3& rhs)
{
	vector3 ret;
	ret.x = this->vecs[1].Dot(rhs);
	ret.y = this->vecs[2].Dot(rhs);
	ret.z = this->vecs[3].Dot(rhs);
	return ret;
}

vector3 matrix33::GetColumnVecs(int i) const
{
	return vector3(this->value[0][i], this->value[1][i], this->value[2][i]);
}
