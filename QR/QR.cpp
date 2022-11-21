#include <iostream>
#include "function.h"
#include <vector>

using namespace std;
int main()
{
    Matrix mat = { 3,3,{
        1,1,1,
        0,1,1,
        0,0,1
    } };

    Matrix res = mat.QR();

    for (int i = 0; i < res.getH(); i++)
    {
        for (int j = 0; j < res.getW(); j++)
        {
            cout << res.get(i, j) << " ";
        }
        cout << endl;
    }
}