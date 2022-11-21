#include <iostream>
#include "function.h"
#include <vector>

using namespace std;
int main()
{
    Matrix mat = { 3,3,{
        1,2,3,
        4,5,6,
        7,8,9
    } };
    
    pair<Matrix,Matrix> res = mat.QR();

    cout << res.first << endl;

    cout << res.second << endl;
    
    Matrix ans = res.first * res.second;
    
    cout << ans;
}