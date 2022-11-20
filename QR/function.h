#pragma once
#include <vector>
#include <Eigen/Dense>
using namespace std;

class Matrix {
	struct MatrixSize {
		int w;
		int h;
	} size;
	std::vector<double> vec;
public:

	Matrix(int h, int w, const double* coefficients);
	Matrix(int h, int w);
	Matrix(int h, int w, std::initializer_list<double> coefficients);
	static Matrix I(int s, double a = 1.0);

	double get(int i, int j)const;
	double& ref(int i, int j);


	Matrix operator*(const Matrix& b) const;

	Matrix operator+(const Matrix& other)const;

	Matrix operator-(const Matrix& other)const;

	Matrix getRow(int col);

	Matrix transpose()const;
	int getW() const;
	int getH() const;

};

Matrix Gram_Schmidt(const signed int n, Matrix& arr);

double Dot_product(const Matrix a, const Matrix b);

