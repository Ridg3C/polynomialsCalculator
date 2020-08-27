#include <iostream>
#include "polynomials.h"
using namespace std;

void Wx::gather()
{
    cout<<"Input degree of polynomial W(x): ";
    isPositiveInteger(degreeStringNum, degree);
    helper=degree;

    coefficientsStringNum = new string[degree+1];
    coefficients = new float[degree+1];

    cout<<"Input coefficients and constant of polynomial W(x): ";
    cout<<endl;
    for (int i=degree; i>=0; i--)
    {
        if (i!=0)
            cout<<"x";
        if (i!=1 && i!=0)
            cout<<"^"<<i;
        if (i==0)
            cout<<"constant";
        cout<<": ";
        isFloat(coefficientsStringNum[i], coefficients[i], i);
    }
}
