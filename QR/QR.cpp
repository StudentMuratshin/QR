#include <iostream>
#include "function.h"
#include <vector>
#include <Eigen/Dense>

using namespace std;



Matrix::Matrix(int h, int w, const double* coefficients) {
    size.w = w;
    size.h = h;
    vec.assign(coefficients, coefficients + w * h);
}
Matrix::Matrix(int h, int w) {
	size.w = w;
	size.h = h;
	vec.resize(w*h,0);
}
Matrix::Matrix(int h, int w, std::initializer_list<double> coefficients) {
    size.w = w;
    size.h = h;
    vec.assign(coefficients.begin(), coefficients.end());
}

Matrix Matrix::I(int s, double a) {
    double* c = new double[s * s];
    for (int y = 0; y < s; y++) {
        for (int x = 0; x < s; x++) {
            c[y * s + x] = ((x == y) ? a : 0.0);
        }
    }
    Matrix i(s, s, c);
    delete[] c;
    return i;
}

double Matrix::get(int i, int j) const {
    return vec[size.w * i + j];
}
double& Matrix::ref(int i, int j)  {
	return vec[size.w * i + j];
}
Matrix Matrix::operator*(const Matrix& b) const {
    const Matrix& a = *this;
    if (a.size.w != b.size.h)
        throw std::runtime_error("Can't multiply matricies with incompatible sizes!");
    int h = a.size.h;
    int w = b.size.w;
    std::vector<double> v;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++) {
            double sum = 0;
            for (int k = 0; k < a.size.w; k++)
                sum += a.get(i, k) * b.get(k, j);
            v.push_back(sum);
        }
    return Matrix(h, w, v.data());
}

Matrix Matrix::operator+(const Matrix& other)const {
    if (other.size.w != size.w || other.size.h != size.h) {
        throw std::runtime_error("Can't add matricies with incompatible sizes!");
    }
    std::vector<double> c(size.w * size.h);
    for (int i = 0; i < size.h; i++)
        for (int j = 0; j < size.w; j++)
            c[i * size.w + j] = get(i, j) + other.get(i, j);
    return Matrix(size.h, size.w, c.data());
}

Matrix Matrix::operator-(const Matrix& other)const {
    if (other.size.w != size.w || other.size.h != size.h) {
        throw std::runtime_error("Can't add matricies with incompatible sizes!");
    }
    std::vector<double> c(size.w * size.h);
    for (int i = 0; i < size.h; i++)
        for (int j = 0; j < size.w; j++)
            c[i * size.w + j] = get(i, j) - other.get(i, j);
    return Matrix(size.h, size.w, c.data());
}
    
Matrix Matrix::getRow(int col) {
    vector<double>col_data;
    for (int i = 0; i < size.w; i++) {
        col_data.push_back(get(col, i));
    }
    return Matrix{ 1, size.w, col_data.data() };
}
Matrix Matrix::transpose() const{
	vector<double>col_data;
	for (int i = 0; i < size.h; i++) {
        for (int j = 0; j < size.w; j++) {
            col_data.push_back(get(i, j));
        }
	}
    return Matrix{ size.w,size.h,col_data.data() };
}
int Matrix::getW() const {
    return size.w;
}
int Matrix::getH() const {
	return size.h;
}


int main()
{
    int n = 3;
    Matrix mat = { 3,4,{
        1,2,2,-1,
        1,1,-5,3,
        3,2,8,-7
    } };

    Matrix res = Gram_Schmidt(n, mat);


}