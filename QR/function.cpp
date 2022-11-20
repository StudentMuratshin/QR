#include "function.h"
#include <vector>
#include <Eigen/Dense>

using namespace std;



vector<Eigen::Vector4d> Gram_Schmidt(const unsigned int n, vector<Eigen::Vector4d>& arr)
{
    vector<Eigen::Vector4d> b(n);
    b[0] = arr[0];
    Eigen::Vector4d term = Eigen::Vector4d::Zero();
    for (int i = 1; i < n; i++)
    {
        term = Eigen::Vector4d::Zero();
        for (int j = 0; j < i; j++)
        {
            term -= Dot_product(arr[i], b[j]) / Dot_product(b[j], b[j]) * b[j];
        }
        b[i] = arr[i] + term;
    }
    return b;
}

double Dot_product(Eigen::Vector4d& a, Eigen::Vector4d& b)
{
    double c = 0;
    for (int i = 0; i < a.size(); i++)
    {
        c += a[i] * b[i];
    }
    return c;
}
