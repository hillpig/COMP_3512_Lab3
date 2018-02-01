#pragma once

#include <iostream>
#include <iomanip>
#include <array>
#include <math.h>

inline size_t square(size_t x) { return x * x; }

using namespace std;

class Matrix {
private:


public:
	size_t len;
	int *p;
	Matrix();
	Matrix(size_t n);
	Matrix(int a[], int x);
	void set_value(size_t row, size_t column, int x) const;
	int get_value(size_t row, size_t column) const;
	void clear() const;
	Matrix identity() const;
	~Matrix();
	Matrix& operator++();
	Matrix operator++(int);
	Matrix& operator--();
	Matrix operator--(int);
	Matrix& operator=(const Matrix& otherMatrix);
	Matrix(const Matrix& otherMatrix);
	friend void swap(Matrix& firstMatrix, Matrix& secondMatrix);
	Matrix& operator+=(const Matrix& x);
	Matrix& operator-=(const Matrix& x);
};

inline ostream& operator<<(ostream& os, const Matrix& obj)
{
	for (size_t i{ 0 }; i < obj.len; i++) {
		for (size_t j{ 0 }; j < obj.len; j++)
			os << obj.get_value(i, j) <<"\t";
		os << endl;
	}
	return os;
}

inline bool operator==(const Matrix& thisMatrix, const Matrix& otherMatrix)
{
	return thisMatrix.len == otherMatrix.len ? true : false;
}

inline bool operator<(const Matrix& thisMatrix, const Matrix& otherMatrix)
{
	return thisMatrix.len < otherMatrix.len ? true : false;
}

inline bool operator>(const Matrix& thisMatrix, const Matrix& otherMatrix)
{
	return thisMatrix.len > otherMatrix.len ? true : false;
}

inline bool operator!=(const Matrix& thisMatrix, const Matrix& otherMatrix)
{
	return !(thisMatrix == otherMatrix);
}

inline bool operator>=(const Matrix& thisMatrix, const Matrix& otherMatrix)
{
	return !(thisMatrix < otherMatrix);
}

inline bool operator<=(const Matrix& thisMatrix, const Matrix& otherMatrix)
{
	return !(thisMatrix > otherMatrix);
}

inline Matrix operator+(Matrix& f, const Matrix& s)
{
	f += s;
	return f;
}

inline Matrix operator-(Matrix& f, Matrix& s)
{
	f -= s;
	return f;
}