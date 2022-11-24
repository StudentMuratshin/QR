#include <iostream>
#include "function.h"
#include <vector>

using namespace std;
int main()
{
    Matrix mat = { 3,3,{
        2,3,-1,
        7,3,3,
        -1,-2,4
    } };
    Matrix eigen = Eigen_Values(mat);
    cout << eigen << endl;
    cout << mat;

    //pair<Matrix,Matrix> res = mat.QR();

    //cout << res.first << endl;

    //cout << res.second << endl;
    //
    //Matrix ans = res.first * res.second;
    //
    //cout << ans;
}