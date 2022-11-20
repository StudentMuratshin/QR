#include <iostream>
#include "function.h"
#include <vector>
#include <Eigen/Dense>

using namespace std;

class Matrix {

};

int main()
{
    int n = 3;
    vector<Eigen::Vector4d> arr{ {1,2,2,-1}, {1,1,-5,3}, {3,2,8,-7} };

    vector<Eigen::Vector4d> res = Gram_Schmidt(n, arr);

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << endl << endl;
    }

}