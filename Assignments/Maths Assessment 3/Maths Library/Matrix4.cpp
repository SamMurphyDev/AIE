#include "Matrix4.h"

Matrix4::Matrix4()
{
}

Matrix4::Matrix4(float x, float y, float z, float w, float v, float u, float t, float s, float r, float q, float p, float o, float n, float m, float l, float k)
{

	matrixData[0][0] = x;
	matrixData[0][1] = y;
	matrixData[0][2] = z;
	matrixData[0][3] = w;
	
	matrixData[1][0] = v;
	matrixData[1][1] = u;
	matrixData[1][2] = t;
	matrixData[1][3] = s;
	
	matrixData[2][0] = r;
	matrixData[2][1] = q;
	matrixData[2][2] = p;
	matrixData[2][3] = o;

	matrixData[3][0] = n;
	matrixData[3][1] = m;
	matrixData[3][2] = l;
	matrixData[3][3] = k;

}

Matrix4::Matrix4(const Matrix4 & copy)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int ii = 0; ii < 4; ++ii)
		{
			matrixData[i][ii] = copy.matrixData[i][ii];
		}
	}
}


Matrix4::~Matrix4()
{
}

void Matrix4::setRotateX(float x)
{
	matrixData[1][1] = cosf(x);
	matrixData[2][1] = -sinf(x);
	matrixData[1][2] = sinf(x);
	matrixData[2][2] = cosf(x);
}

void Matrix4::setRotateY(float y)
{
	matrixData[0][0] = cosf(y);
	matrixData[0][2] = -sinf(y);
	matrixData[2][0] = sinf(y);
	matrixData[2][2] = cosf(y);
}

void Matrix4::setRotateZ(float z)
{
	matrixData[0][0] = cosf(z);
	matrixData[1][0] = -sinf(z);
	matrixData[0][1] = sinf(z);
	matrixData[1][1] = cosf(z);
}

void Matrix4::setPosition(Vector4 otherVector)
{
	matrixData[3][0] = otherVector.x;
	matrixData[3][1] = otherVector.y;
	matrixData[3][2] = otherVector.z;
	matrixData[3][3] = otherVector.a;
}

void Matrix4::setPosition(float x, float y, float z, float w)
{
	matrixData[3][0] = x;
	matrixData[3][1] = y;
	matrixData[3][2] = z;
	matrixData[3][3] = w;
}

void Matrix4::setPosition(Vector3 otherVector)
{
	matrixData[3][0] = otherVector.x;
	matrixData[3][1] = otherVector.y;
	matrixData[3][2] = otherVector.z;
}

void Matrix4::setPosition(float x, float y, float z)
{
	matrixData[3][0] = x;
	matrixData[3][1] = y;
	matrixData[3][2] = z;
}

void Matrix4::setScale(Vector4 otherVector)
{
	matrixData[0][0] = otherVector.x;
	matrixData[1][1] = otherVector.y;
	matrixData[2][2] = otherVector.z;
	matrixData[3][3] = otherVector.a;
}

void Matrix4::setScale(float x, float y, float z, float w)
{
	matrixData[0][0] = x;
	matrixData[1][1] = y;
	matrixData[2][2] = z;
	matrixData[3][3] = w;
}

void Matrix4::setScale(Vector3 otherVector)
{
	matrixData[0][0] = otherVector.x;
	matrixData[1][1] = otherVector.y;
	matrixData[2][2] = otherVector.z;
}

void Matrix4::setScale(float x, float y, float z)
{
	matrixData[0][0] = x;
	matrixData[1][1] = y;
	matrixData[2][2] = z;
}

Matrix4 & Matrix4::transpose()
{
	Matrix4* temp = new Matrix4();

	temp->matrixData[0][0] = matrixData[0][0];
	temp->matrixData[0][1] = matrixData[1][0];
	temp->matrixData[0][2] = matrixData[2][0];
	temp->matrixData[0][3] = matrixData[3][0];
		
	temp->matrixData[1][0] = matrixData[0][1];
	temp->matrixData[1][1] = matrixData[1][1];
	temp->matrixData[1][2] = matrixData[2][1];
	temp->matrixData[1][3] = matrixData[3][1];
		
	temp->matrixData[2][0] = matrixData[0][2];
	temp->matrixData[2][1] = matrixData[1][2];
	temp->matrixData[2][2] = matrixData[2][2];
	temp->matrixData[2][3] = matrixData[3][2];
		
	temp->matrixData[3][0] = matrixData[0][3];
	temp->matrixData[3][1] = matrixData[1][3];
	temp->matrixData[3][2] = matrixData[2][3];
	temp->matrixData[3][3] = matrixData[3][3];

	return *temp;
}

Matrix4& Matrix4::operator*(const Matrix4 & otherMatrix)
{
	Matrix4 temp = Matrix4();

	temp.matrixData[0][0] = (matrixData[0][0] * otherMatrix.matrixData[0][0]) + (matrixData[1][0] * otherMatrix.matrixData[0][1]) + (matrixData[2][0] * otherMatrix.matrixData[0][2]) + (matrixData[3][0] * otherMatrix.matrixData[0][3]);
	temp.matrixData[0][1] = (matrixData[0][1] * otherMatrix.matrixData[0][0]) + (matrixData[1][1] * otherMatrix.matrixData[0][1]) + (matrixData[2][1] * otherMatrix.matrixData[0][2]) + (matrixData[3][1] * otherMatrix.matrixData[0][3]);
	temp.matrixData[0][2] = (matrixData[0][2] * otherMatrix.matrixData[0][0]) + (matrixData[1][2] * otherMatrix.matrixData[0][1]) + (matrixData[2][2] * otherMatrix.matrixData[0][2]) + (matrixData[3][2] * otherMatrix.matrixData[0][3]);
	temp.matrixData[0][3] = (matrixData[0][3] * otherMatrix.matrixData[0][0]) + (matrixData[1][3] * otherMatrix.matrixData[0][1]) + (matrixData[2][3] * otherMatrix.matrixData[0][2]) + (matrixData[3][3] * otherMatrix.matrixData[0][3]);

	temp.matrixData[1][0] = (matrixData[0][0] * otherMatrix.matrixData[1][0]) + (matrixData[1][0] * otherMatrix.matrixData[1][1]) + (matrixData[2][0] * otherMatrix.matrixData[1][2]) + (matrixData[3][0] * otherMatrix.matrixData[1][3]);
	temp.matrixData[1][1] = (matrixData[0][1] * otherMatrix.matrixData[1][0]) + (matrixData[1][1] * otherMatrix.matrixData[1][1]) + (matrixData[2][1] * otherMatrix.matrixData[1][2]) + (matrixData[3][1] * otherMatrix.matrixData[1][3]);
	temp.matrixData[1][2] = (matrixData[0][2] * otherMatrix.matrixData[1][0]) + (matrixData[1][2] * otherMatrix.matrixData[1][1]) + (matrixData[2][2] * otherMatrix.matrixData[1][2]) + (matrixData[3][2] * otherMatrix.matrixData[1][3]);
	temp.matrixData[1][3] = (matrixData[0][3] * otherMatrix.matrixData[1][0]) + (matrixData[1][3] * otherMatrix.matrixData[1][1]) + (matrixData[2][3] * otherMatrix.matrixData[1][2]) + (matrixData[3][3] * otherMatrix.matrixData[1][3]);

	temp.matrixData[2][0] = (matrixData[0][0] * otherMatrix.matrixData[2][0]) + (matrixData[1][0] * otherMatrix.matrixData[2][1]) + (matrixData[2][0] * otherMatrix.matrixData[2][2]) + (matrixData[3][0] * otherMatrix.matrixData[2][3]);
	temp.matrixData[2][1] = (matrixData[0][1] * otherMatrix.matrixData[2][0]) + (matrixData[1][1] * otherMatrix.matrixData[2][1]) + (matrixData[2][1] * otherMatrix.matrixData[2][2]) + (matrixData[3][1] * otherMatrix.matrixData[2][3]);
	temp.matrixData[2][2] = (matrixData[0][2] * otherMatrix.matrixData[2][0]) + (matrixData[1][2] * otherMatrix.matrixData[2][1]) + (matrixData[2][2] * otherMatrix.matrixData[2][2]) + (matrixData[3][2] * otherMatrix.matrixData[2][3]);
	temp.matrixData[2][3] = (matrixData[0][3] * otherMatrix.matrixData[2][0]) + (matrixData[1][3] * otherMatrix.matrixData[2][1]) + (matrixData[2][3] * otherMatrix.matrixData[2][2]) + (matrixData[3][3] * otherMatrix.matrixData[2][3]);

	temp.matrixData[3][0] = (matrixData[0][0] * otherMatrix.matrixData[3][0]) + (matrixData[1][0] * otherMatrix.matrixData[3][1]) + (matrixData[2][0] * otherMatrix.matrixData[3][2]) + (matrixData[3][0] * otherMatrix.matrixData[3][3]);
	temp.matrixData[3][1] = (matrixData[0][1] * otherMatrix.matrixData[3][0]) + (matrixData[1][1] * otherMatrix.matrixData[3][1]) + (matrixData[2][1] * otherMatrix.matrixData[3][2]) + (matrixData[3][1] * otherMatrix.matrixData[3][3]);
	temp.matrixData[3][2] = (matrixData[0][2] * otherMatrix.matrixData[3][0]) + (matrixData[1][2] * otherMatrix.matrixData[3][1]) + (matrixData[2][2] * otherMatrix.matrixData[3][2]) + (matrixData[3][2] * otherMatrix.matrixData[3][3]);
	temp.matrixData[3][3] = (matrixData[0][3] * otherMatrix.matrixData[3][0]) + (matrixData[1][3] * otherMatrix.matrixData[3][1]) + (matrixData[2][3] * otherMatrix.matrixData[3][2]) + (matrixData[3][3] * otherMatrix.matrixData[3][3]);

	return temp;
}

Matrix4& operator*(const Matrix4 & firstMatrix, const Matrix4 & secondMatrix)
{
	Matrix4 temp = Matrix4();

	temp.matrixData[0][0] = (firstMatrix.matrixData[0][0] * secondMatrix.matrixData[0][0]) + (firstMatrix.matrixData[1][0] * secondMatrix.matrixData[0][1]) + (firstMatrix.matrixData[2][0] * secondMatrix.matrixData[0][2]) + (firstMatrix.matrixData[3][0] * secondMatrix.matrixData[0][3]);
	temp.matrixData[0][1] = (firstMatrix.matrixData[0][1] * secondMatrix.matrixData[0][0]) + (firstMatrix.matrixData[1][1] * secondMatrix.matrixData[0][1]) + (firstMatrix.matrixData[2][1] * secondMatrix.matrixData[0][2]) + (firstMatrix.matrixData[3][1] * secondMatrix.matrixData[0][3]);
	temp.matrixData[0][2] = (firstMatrix.matrixData[0][2] * secondMatrix.matrixData[0][0]) + (firstMatrix.matrixData[1][2] * secondMatrix.matrixData[0][1]) + (firstMatrix.matrixData[2][2] * secondMatrix.matrixData[0][2]) + (firstMatrix.matrixData[3][2] * secondMatrix.matrixData[0][3]);
	temp.matrixData[0][3] = (firstMatrix.matrixData[0][3] * secondMatrix.matrixData[0][0]) + (firstMatrix.matrixData[1][3] * secondMatrix.matrixData[0][1]) + (firstMatrix.matrixData[2][3] * secondMatrix.matrixData[0][2]) + (firstMatrix.matrixData[3][3] * secondMatrix.matrixData[0][3]);

	temp.matrixData[1][0] = (firstMatrix.matrixData[0][0] * secondMatrix.matrixData[1][0]) + (firstMatrix.matrixData[1][0] * secondMatrix.matrixData[1][1]) + (firstMatrix.matrixData[2][0] * secondMatrix.matrixData[1][2]) + (firstMatrix.matrixData[3][0] * secondMatrix.matrixData[1][3]);
	temp.matrixData[1][1] = (firstMatrix.matrixData[0][1] * secondMatrix.matrixData[1][0]) + (firstMatrix.matrixData[1][1] * secondMatrix.matrixData[1][1]) + (firstMatrix.matrixData[2][1] * secondMatrix.matrixData[1][2]) + (firstMatrix.matrixData[3][1] * secondMatrix.matrixData[1][3]);
	temp.matrixData[1][2] = (firstMatrix.matrixData[0][2] * secondMatrix.matrixData[1][0]) + (firstMatrix.matrixData[1][2] * secondMatrix.matrixData[1][1]) + (firstMatrix.matrixData[2][2] * secondMatrix.matrixData[1][2]) + (firstMatrix.matrixData[3][2] * secondMatrix.matrixData[1][3]);
	temp.matrixData[1][3] = (firstMatrix.matrixData[0][3] * secondMatrix.matrixData[1][0]) + (firstMatrix.matrixData[1][3] * secondMatrix.matrixData[1][1]) + (firstMatrix.matrixData[2][3] * secondMatrix.matrixData[1][2]) + (firstMatrix.matrixData[3][3] * secondMatrix.matrixData[1][3]);

	temp.matrixData[2][0] = (firstMatrix.matrixData[0][0] * secondMatrix.matrixData[2][0]) + (firstMatrix.matrixData[1][0] * secondMatrix.matrixData[2][1]) + (firstMatrix.matrixData[2][0] * secondMatrix.matrixData[2][2]) + (firstMatrix.matrixData[3][0] * secondMatrix.matrixData[2][3]);
	temp.matrixData[2][1] = (firstMatrix.matrixData[0][1] * secondMatrix.matrixData[2][0]) + (firstMatrix.matrixData[1][1] * secondMatrix.matrixData[2][1]) + (firstMatrix.matrixData[2][1] * secondMatrix.matrixData[2][2]) + (firstMatrix.matrixData[3][1] * secondMatrix.matrixData[2][3]);
	temp.matrixData[2][2] = (firstMatrix.matrixData[0][2] * secondMatrix.matrixData[2][0]) + (firstMatrix.matrixData[1][2] * secondMatrix.matrixData[2][1]) + (firstMatrix.matrixData[2][2] * secondMatrix.matrixData[2][2]) + (firstMatrix.matrixData[3][2] * secondMatrix.matrixData[2][3]);
	temp.matrixData[2][3] = (firstMatrix.matrixData[0][3] * secondMatrix.matrixData[2][0]) + (firstMatrix.matrixData[1][3] * secondMatrix.matrixData[2][1]) + (firstMatrix.matrixData[2][3] * secondMatrix.matrixData[2][2]) + (firstMatrix.matrixData[3][3] * secondMatrix.matrixData[2][3]);

	temp.matrixData[3][0] = (firstMatrix.matrixData[0][0] * secondMatrix.matrixData[3][0]) + (firstMatrix.matrixData[1][0] * secondMatrix.matrixData[3][1]) + (firstMatrix.matrixData[2][0] * secondMatrix.matrixData[3][2]) + (firstMatrix.matrixData[3][0] * secondMatrix.matrixData[3][3]);
	temp.matrixData[3][1] = (firstMatrix.matrixData[0][1] * secondMatrix.matrixData[3][0]) + (firstMatrix.matrixData[1][1] * secondMatrix.matrixData[3][1]) + (firstMatrix.matrixData[2][1] * secondMatrix.matrixData[3][2]) + (firstMatrix.matrixData[3][1] * secondMatrix.matrixData[3][3]);
	temp.matrixData[3][2] = (firstMatrix.matrixData[0][2] * secondMatrix.matrixData[3][0]) + (firstMatrix.matrixData[1][2] * secondMatrix.matrixData[3][1]) + (firstMatrix.matrixData[2][2] * secondMatrix.matrixData[3][2]) + (firstMatrix.matrixData[3][2] * secondMatrix.matrixData[3][3]);
	temp.matrixData[3][3] = (firstMatrix.matrixData[0][3] * secondMatrix.matrixData[3][0]) + (firstMatrix.matrixData[1][3] * secondMatrix.matrixData[3][1]) + (firstMatrix.matrixData[2][3] * secondMatrix.matrixData[3][2]) + (firstMatrix.matrixData[3][3] * secondMatrix.matrixData[3][3]);

	return temp;
}

Vector4 & Matrix4::operator*(Vector4 & otherVector)
{
	float* matrix = (float*)*this;

	return Vector4(
		matrix[0] * otherVector.x + matrix[4] * otherVector.x + matrix[8] * otherVector.x + matrix[12] * otherVector.x,
		matrix[1] * otherVector.y + matrix[5] * otherVector.y + matrix[9] * otherVector.y + matrix[13] * otherVector.y,
		matrix[2] * otherVector.z + matrix[6] * otherVector.z + matrix[10] * otherVector.z + matrix[14] * otherVector.z,
		matrix[3] * otherVector.a + matrix[7] * otherVector.a + matrix[11] * otherVector.a + matrix[15] * otherVector.a);
}

Vector4 & operator*(const Vector4 & otherVector, Matrix4 & otherMatrix)
{
	float* matrix = (float*)otherMatrix;

	return Vector4(
		matrix[0] * otherVector.x + matrix[4] * otherVector.y + matrix[8] * otherVector.z + matrix[12] * otherVector.a,
		matrix[1] * otherVector.x + matrix[5] * otherVector.y + matrix[9] * otherVector.z + matrix[13] * otherVector.a,
		matrix[2] * otherVector.x + matrix[6] * otherVector.y + matrix[10] * otherVector.z + matrix[14] * otherVector.a,
		matrix[3] * otherVector.x + matrix[7] * otherVector.y + matrix[11] * otherVector.z + matrix[15] * otherVector.a);
}

Matrix4::operator float*()
{
	float allData[16] =
	{
		matrixData[0][0], matrixData[0][1], matrixData[0][2], matrixData[0][3],
		matrixData[1][0], matrixData[1][1], matrixData[1][2], matrixData[1][3],
		matrixData[2][0], matrixData[2][1], matrixData[2][2], matrixData[2][3],
		matrixData[3][0], matrixData[3][1], matrixData[3][2], matrixData[3][3]
	};

	return allData;
}

float Matrix4::operator[](int i)
{
	if (i > sizeof(matrixData) || i < 0)
	{
		return *(matrixData[i]);
	}
	else
	{
		throw std::out_of_range("Index is not in range of Matrix4");
	}
}

void Matrix4::operator+=(const Vector4 & otherVector)
{
	matrixData[3][0] += otherVector.x;
	matrixData[3][1] += otherVector.y;
	matrixData[3][2] += otherVector.z;
	matrixData[3][3] += otherVector.a;
}

void Matrix4::operator+=(const Vector3 & otherVector)
{
	matrixData[3][0] += otherVector.x;
	matrixData[3][1] += otherVector.y;
	matrixData[3][2] += otherVector.z;
}
