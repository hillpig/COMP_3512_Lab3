#include "Matrix.hpp"

Matrix::Matrix()
{
	len = 1;
	p = new int[len];
	p[0] = 0;
}

Matrix::Matrix(size_t n = 1)
{
	len = n;
	p = new int[square(len)];
	for (size_t i{ 0 }; i < square(len); i++)
		p[i] = 0;
}

Matrix::Matrix(int a[], int x)
{
	len = x;
	p = new int[square(len)];
	for (size_t i{0}; i< square(len); i++)
		this->p[i] = a[i];
}

Matrix::Matrix(const Matrix& otherMatrix)
{
	this->len = otherMatrix.len;
	p = new int[square(len)];
	for (size_t i{ 0 }; i<square(len); i++)
		this->p[i] = otherMatrix.p[i];
}

//3-parameter, row, colum, vaule
//pre:input must within the matrix
//post:set the specific location's element equal to vaule
//return:n/a
void Matrix::set_value(size_t row, size_t column, int x) const
{
	p[len*row + column] = x;
}

//2-parameter, row,colum
//pre:input must within the matrix
//post
//return: the specific position of matrixs' elements
int Matrix::get_value(size_t row, size_t column) const
{
	return p[len*row + column];
}

//clear the matrixs:set all elements to 0
//pre
//post
//return:
void Matrix::clear() const
{
	for (size_t i{ 0 }; i < square(len); i++)
		p[i] = 0;
}

Matrix Matrix::identity() const
{
	Matrix id(len);
	for (size_t i{ 0 }; i < len; i++)
		id.set_value(i, i, 1);
	return id;
}

Matrix::~Matrix()
{
	delete[] p;
}

Matrix& Matrix::operator++()
{
	for (size_t i{ 0 }; i < square(len); i++)
		p[i]++;
	return *this;
}
Matrix Matrix::operator++(int)
{
	Matrix temp(*this);
	operator++();
	return temp;
}
Matrix& Matrix::operator--()
{
	for (size_t i{ 0 }; i < square(len); i++)
		p[i]--;
	return *this;
}
Matrix Matrix::operator--(int)
{
	Matrix temp(*this);
	operator--();
	return temp;
}
Matrix& Matrix::operator=(const Matrix& otherMatrix)
{
	this->len=otherMatrix.len;
	this->p=otherMatrix.p;
	return *this;
}

void swap(Matrix& firstMatrix, Matrix& secondMatrix)
{
	swap(firstMatrix.len, secondMatrix.len);
	swap(firstMatrix.p, secondMatrix.p);
}

Matrix& Matrix::operator+=(const Matrix& x)
{
	for (size_t i{ 0 }; i < square(len); i++)
		p[i] += x.p[i];
	return *this;
}


Matrix& Matrix::operator-=(const Matrix& x)
{
	for (size_t i{ 0 }; i < square(len); i++)
		p[i] -= x.p[i];
	return *this;
}

