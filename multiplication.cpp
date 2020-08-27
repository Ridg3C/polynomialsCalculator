#include <iostream>
#include "polynomials.h"
using namespace std;

void Result::multiplication(const Wx &w, const Px &p)
{
    resultHelper=w.degree+p.degree;
    resultDegree=w.degree+p.degree;

    resultCoefficients = new float [resultDegree+1];

    for (int i=resultDegree; i>=0; i--)
    {
        resultCoefficients[i]=0;
    }

    for (int i=w.degree; i>=0; i--)
    {
        for (int j=p.degree; j>=0; j--)
        {
            resultCoefficients[i+j]+=w.coefficients[i]*p.coefficients[j];
        }
    }
}

