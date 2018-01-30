#include "Matrix.hpp"


Matrix::Matrix()
{
	len = 1;
	p = new int[1];
	p[0] = 0;
}


Matrix::Matrix(size_t n)
{
	len = n;
	p = new int[square(len)];
	for (size_t i{ 0 }; i < square(len); i++)
		p[i] = 0;
}

Matrix::Matrix(int a[])
{
	len = (int)sqrt(sizeof(a)/sizeof(int));
	this->p = a;
}

void Matrix::set_value(size_t row, size_t column, int x) const
{
	p[len*row + column] = x;
}

int Matrix::get_value(size_t row, size_t column) const
{
	return p[len*row + column];
}
void Matrix::clear() const
{
	for (size_t i{ 0 }; i < len; i++)
		p[i] = 0;
}

Matrix Matrix::identity() const
{
	Matrix id = Matrix(len);
	for (size_t i{ 0 }; i < len; i++)
		id.set_value(i, i, 1);
	return id;
}

Matrix::~Matrix()
{
	delete[] p;
}


ostream& operator<<(ostream& os, const Matrix& obj)
{
	for (size_t i{ 0 }; i < obj.len; i++) {
		for (size_t j{ 0 }; j < obj.len; j++)
			os << obj.get_value(i, j);
		os << endl;
	}
}

bool Matrix::operator==(Matrix& otherMatrix)
{
	return len == otherMatrix.len ? true : false;
}

bool Matrix::operator<(Matrix& otherMatrix)
{
	return len < otherMatrix.len ? true : false;
}

bool Matrix::operator>(Matrix& otherMatrix)
{
	return len > otherMatrix.len ? true : false;
}

bool Matrix::operator!=(Matrix& otherMatrix)
{
	return !operator== (otherMatrix);
}

bool Matrix::operator>=(Matrix& otherMatrix)
{
	return !operator== (otherMatrix);
}

bool Matrix::operator<=(Matrix& otherMatrix)
{
}

//Matrix& operator++();
//Matrix& operator++(int);
//Matrix& operator--();
//Matrix& operator--(int);
//Matrix& operator=(Matrix& otherMatrix);
//Matrix(const Matrix& otherMatrix);
void swap(Matrix& firstMatrix, Matrix& secondMatrix)
{
}