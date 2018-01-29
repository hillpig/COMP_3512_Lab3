#pragma once

#include <iostream>
#include <iomanip>
using namespace std;

class Matrix {
private:
	size_t len;
	int *p = new int[len];

public:
	Matrix(size_t n = 0);
	Matrix(int* a[]);
	void set_value(size_t row, size_t column, int x) const;
	int get_value(size_t row, size_t column) const;
	void clear() const;
	Matrix& identity();
	~Matrix();
	friend std::ostream& operator<<(std::ostream& os, const Matrix& obj);
	Matrix& operator==(Matrix& otherMatrix);
	Matrix& operator<(Matrix& otherMatrix);
	Matrix& operator>(Matrix& otherMatrix);
	Matrix& operator!=(Matrix& otherMatrix);
	Matrix& operator>=(Matrix& otherMatrix);
	Matrix& operator<=(Matrix& otherMatrix);
	Matrix& operator++();
	Matrix& operator++(int);
	Matrix& operator--();
	Matrix& operator--(int);
	Matrix& operator=(Matrix& otherMatrix);
	Matrix(const Matrix& otherMatrix);
	friend void swap(Matrix& firstMatrix, Matrix& secondMatrix);

};