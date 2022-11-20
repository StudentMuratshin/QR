#include "function.h"
#include <vector>
#include <Eigen/Dense>

using namespace std;



Matrix Gram_Schmidt(const signed int n, Matrix& arr)
{
    Matrix b{ 1,4 };
    for (int j = 0; j < arr.getW(); j++)
    {
        b.ref(0, j) = arr.get(0, j);
    }
    Matrix term = Matrix{ 1,4 };
    for (int i = 1; i < n; i++)
    {
        term = Matrix{ 1,4 };

        for (int j = 0; j < i; j++)
        {
            term = term - (Matrix::I(4,Dot_product(arr.getRow(i), b.getRow(0)) / Dot_product(b.getRow(0), b.getRow(0))) * b.getRow(j).transpose()).transpose();
        }
        for (int j = 0; j < b.getH(); j++)
            b.ref(i, j) = arr.get(i, j) + term.get(0, j);
    }
    return b;
}

double Dot_product(const Matrix a, const Matrix b)
{
    Matrix t = a * b.transpose();
    return t.get(0,0);
}
