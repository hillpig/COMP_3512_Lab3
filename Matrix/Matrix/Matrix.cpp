#include "Matrix.hpp"



Matrix::Matrix(size_t n = 0)
{
	len = n;
	p = new int[square(len)];
}

Matrix::Matrix(int*& a)
{
	len = sqrt(sizeof(a));
	this->p = a;
}

void Matrix::set_value(size_t row, size_t column, int x) const
{

}

int Matrix::get_value(size_t row, size_t column) const
{

}
void Matrix::clear() const
{
}

//Matrix& identity();

Matrix::~Matrix()
{
}


ostream& operator<<(ostream& os, const Matrix& obj)
{
}

bool Matrix::operator==(Matrix& otherMatrix)
{
}

bool Matrix::operator<(Matrix& otherMatrix)
{
}

bool Matrix::operator>(Matrix& otherMatrix)
{
}

bool Matrix::operator!=(Matrix& otherMatrix)
{
}

bool Matrix::operator>=(Matrix& otherMatrix)
{
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