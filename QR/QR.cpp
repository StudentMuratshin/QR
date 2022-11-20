#include <iostream>
#include "function.h"
#include <vector>
#include <Eigen/Dense>

using namespace std;
int main()
{
    int n = 3;
    Matrix mat = { 3,4,{
        1,2,2,-1,
        1,1,-5,3,
        3,2,8,-7
    } };

    Matrix res = Gram_Schmidt(n, mat);

    for (int i = 0; i < res.getH(); i++)
    {
        for (int j = 0; j < res.getW(); j++)
        {
            cout << res.get(i, j) << " ";
        }
        cout << endl;
    }
}