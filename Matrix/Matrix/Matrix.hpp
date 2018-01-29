#pragma once

#include <iostream>
#include <iomanip>

inline size_t square(size_t x) { return x * x; }

using namespace std;

class Matrix {
private:
	size_t len;
	int *p;

public:
	Matrix(size_t n = 0);
	Matrix(const int* a[]);
	void set_value(size_t row, size_t column, int x) const;
	int get_value(size_t row, size_t column) const;
	void clear() const;
	Matrix& identity();
	~Matrix();
	friend ostream& operator<<(ostream& os, const Matrix& obj);
	bool operator==(Matrix& otherMatrix);
	bool operator<(Matrix& otherMatrix);
	bool operator>(Matrix& otherMatrix);
	bool operator!=(Matrix& otherMatrix);
	bool operator>=(Matrix& otherMatrix);
	bool operator<=(Matrix& otherMatrix);
	Matrix& operator++();
	Matrix& operator++(int);
	Matrix& operator--();
	Matrix& operator--(int);
	Matrix& operator=(Matrix& otherMatrix);
	Matrix(const Matrix& otherMatrix);
	friend void swap(Matrix& firstMatrix, Matrix& secondMatrix);

};