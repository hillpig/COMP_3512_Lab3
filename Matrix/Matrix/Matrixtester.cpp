#include "Matrix.hpp"

int main(int argc, char ** argv) {

	// the default constructor
	Matrix test1;
	cout << "Test1: Print the default matrix1. " << endl;
	cout << test1 << endl;


	//the constructor with given side length
	cout << "Test2: Print the matrix2 building with side length 5. " << endl;
	Matrix test2(5);
	cout << test2 << endl;


	// the constructor with given int array
	cout << "Test3: Print the matrix3 building with an array: " << endl;
	int a[] = { 0, 1, 2, 3 };
	Matrix test3(a, 2);
	cout << test3 << endl;


	// test the function of identity()
	cout << "Test4: Print the identity matrix4 based on Matrix 2: " << endl;
	Matrix test4 = test2.identity();
	cout << test4 << endl;

	// test the function of get_value()
	cout << "Test5:the bottom-right element of the Matrix in test 3 is: ";
	cout << test3.get_value(1, 1) << endl;

	cout << endl;




	// test the function of clear()
	cout << "Test6: clear the Matrix 3: " << endl;
	test3.clear();
	cout << test3 << endl;

	// test the operator postfix ++
	cout << "Test7: Matrix 3 ++: " << endl;
	cout << test3++ << endl;

	//test the opperator prefix ++
	cout << "Test8: ++Matrix 3: " << endl;
	test3.clear();
	cout << ++test3 << endl;

	//test the operator postfix --
	cout << "Test9: Matrix 3 --: " << endl;
	test3.clear();
	cout << test3-- << endl;


	//test the operator prefix --
	cout << "Test10: -- Matrix 3: " << endl;
	test3.clear();
	cout << --test3 << endl;

	//test the operator =
	cout << "Test11: Matrix 3 = Matrix 2: " << endl;
	test3 = test2;
	cout << test3 << endl;

	// the constructor with another Matrix
	Matrix test5(test2);

	//test the operator ==
	cout << "Test12: Matrix 3 = Matrix 5(Matrix5 is as same as Matrix2): ";
	cout << (test3 == test5) << endl;

	//test the operator <
	cout << "Test13: Matrix 3 < Matrix 5: ";
	cout << (test3 < test5) << endl;

	//test the operator >
	cout << "Test14: Matrix 4 > Matrix 5: ";
	cout << (test4 > test5) << endl;

	//test the operator !=
	cout << "Test15: Matrix 4 != Matrix 5: ";
	cout << (test4 != test5) << endl;

	//test the operator >= and <=
	cout << "Test16: Matrix 4 VS Matrix 5: " <<endl;
	cout << (test4 >= test5 ? test4 : test5) << "is not less than " <<endl;


	cout << (test4 <= test5 ? test4 : test5) << "." << endl;

	// test the operator + and -
	cout << "Test17: Matrix 3 + (++ Matrix 5): " <<endl;
	if (test3 == test5)
		cout << (test3 + (++test5)) << endl;

	cout << "Test18: Matrix 3 - Matrix 5: " << endl;
	if (test3 == test5)
		cout << (test3 - test5) << endl;

	cout << "Test19: Matrix 3 += Matrix 5: " <<endl;
	if (test3 == test5)
		cout << (test3 += test5) << endl;

	cout << "Test20: Matrix 3 -= Matrix 5: " <<endl;
	if (test3 == test5)
		cout << (test3 -= test5) << endl;

	cout << "Test21: Matrix 3 and Matrix 5: " << endl;
	cout << test3 << endl;

	cout << test5 << endl;
	cout << "Test22: after swaping, Matrix 3 and Matrix 5: " <<endl;
	if (test3 == test5)
		swap(test3, test5);


	cout << test3 << endl;

	cout << test5 << endl;

	return 0;
}