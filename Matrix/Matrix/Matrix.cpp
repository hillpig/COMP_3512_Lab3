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

Matrix::Matrix(const Matrix& otherMatrix)
{
	this->len = otherMatrix.len;
	this->p = otherMatrix.p;
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
	Matrix id(len);
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
	return os;
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
	return !operator< (otherMatrix);
}

bool Matrix::operator<=(Matrix& otherMatrix)
{
	return !operator> (otherMatrix);
}

Matrix& Matrix::operator++()
{
	for (size_t i{ 0 }; i < len; i++)
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
	for (size_t i{ 0 }; i < len; i++)
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

Matrix& Matrix::operator+=(int x)
{
	for (size_t i{ 0 }; i < len; i++)
		p[i] += x;
	return *this;
}

Matrix operator+(Matrix m, int x)
{
	m += x;
	return m;
}

