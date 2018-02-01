#include "Matrix.hpp"

//default constructor
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

//constructor accept array
Matrix::Matrix(int a[], int x)
{
	len = x;
	p = new int[square(len)];
	for (size_t i{0}; i< square(len); i++)
		this->p[i] = a[i];
}

//copy constructor
Matrix::Matrix(const Matrix& otherMatrix)
{
	this->len = otherMatrix.len;
	p = new int[square(this->len)];
	for (size_t i{ 0 }; i<square(this->len); i++)
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

//change the matrixs to identity matrixs
//pre:must have at lest one elements
//post: the 0 shoud be changed to 1
//return a new identity matrixs
Matrix Matrix::identity() const
{
	Matrix id(len);
	for (size_t i{ 0 }; i < len; i++)
		id.set_value(i, i, 1);
	return id;
}

//deconstructor
Matrix::~Matrix()
{
	if (p)
	delete[] p;
}

//increment
//pre must have one elements
//post
//return a incremented matrixs
Matrix& Matrix::operator++()
{
	for (size_t i{ 0 }; i < square(len); i++)
		p[i]++;
	return *this;
}

//increment
//pre must have one elements
//post
//return a incremented matrixs
Matrix Matrix::operator++(int)
{
	Matrix temp(*this);
	operator++();
	return temp;
}

//decrement
//pre must have one elements
//post
//return a decremented matrixs
Matrix& Matrix::operator--()
{
	for (size_t i{ 0 }; i < square(len); i++)
		p[i]--;
	return *this;
}

//decrement
//pre must have one elements
//post
//return a decremented matrixs
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


//swap two matrixs
//pre
//post
//return
void swap(Matrix& firstMatrix, Matrix& secondMatrix)
{
	swap(firstMatrix.len, secondMatrix.len);
	swap(firstMatrix.p, secondMatrix.p);
}


//operater +=
//pre: must have same size for each matrix
//post
//return combined matrix
Matrix& Matrix::operator+=(const Matrix& x)
{
	for (size_t i{ 0 }; i < square(len); i++)
		p[i] += x.p[i];
	return *this;
}

//operater -=
//pre: must have same size for each matrix
//post
//return minused matrix
Matrix& Matrix::operator-=(const Matrix& x)
{
	for (size_t i{ 0 }; i < square(len); i++)
		p[i] -= x.p[i];
	return *this;
}

