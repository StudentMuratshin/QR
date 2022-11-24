#include <iostream>
#include "function.h"
#include <vector>

using namespace std;
int main()
{
    Matrix mat = { 3,3,{
        3,2,2,
        2,3,-2,
        3,-2,21
    } };
    Matrix e = Eigen_Values(mat);
    cout << e << endl;

    cout << "A: " << endl << mat << endl;

    pair<Matrix,Matrix> res = mat.QR();

    cout << "Q: " << endl << res.first << endl;

    cout << "R: " << endl << res.second << endl;
    
    Matrix ans = res.first * res.second;
    
    cout << "Q*R: " << endl << ans;
}