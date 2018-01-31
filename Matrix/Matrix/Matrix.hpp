#pragma once

#include <iostream>
#include <iomanip>
#include <math.h>

inline size_t square(size_t x) { return x * x; }

using namespace std;

class Matrix {
private:
	size_t len;
	int *p;

public:
	Matrix();
	Matrix(size_t n);
	Matrix(int a[]);
	void set_value(size_t row, size_t column, int x) const;
	int get_value(size_t row, size_t column) const;
	void clear() const;
	Matrix identity() const;
	~Matrix();
	friend ostream& operator<<(ostream& os, const Matrix& obj);
	bool operator==(Matrix& otherMatrix);
	bool operator<(Matrix& otherMatrix);
	bool operator>(Matrix& otherMatrix);
	bool operator!=(Matrix& otherMatrix);
	bool operator>=(Matrix& otherMatrix);
	bool operator<=(Matrix& otherMatrix);
	Matrix& operator++();
	Matrix operator++(int);
	Matrix& operator--();
	Matrix& operator--(int);
	Matrix& operator=(const Matrix& otherMatrix);
	Matrix(const Matrix& otherMatrix);
	friend void swap(Matrix& firstMatrix, Matrix& secondMatrix);

};