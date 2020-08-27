#include <iostream>
#include "polynomials.h"
using namespace std;

void Result::addition(const Wx &w, const Px &p)
{
    if (w.degree>=p.degree)
    {
        resultHelper=w.degree;
        resultDegree=w.degree;

        resultCoefficients = new float [w.degree+1];

        for (int i=w.degree; i>p.degree; i--)
        {
            resultCoefficients[i]=w.coefficients[i];
        }
        for (int i=p.degree; i>=0; i--)
        {
            resultCoefficients[i]=w.coefficients[i]+p.coefficients[i];
        }
    }
    else
    {
        resultHelper=p.degree;
        resultDegree=p.degree;
        resultCoefficients = new float [p.degree+1];

        for (int i=p.degree; i>w.degree; i--)
        {
            resultCoefficients[i]=p.coefficients[i];
        }

        for (int i=w.degree; i>=0; i--)
        {
            resultCoefficients[i]=w.coefficients[i]+p.coefficients[i];
        }

    }
}
