#include <iostream>
#include "polynomials.h"
using namespace std;

void Result::division(const Wx &w, const Px &p)
{
    float *buffer1;
    float *buffer2;

    int zero=0;

    resultHelper=w.degree-p.degree;
    resultDegree=w.degree-p.degree;
    int divisionHelper=w.degree;
    int resultDegreeHelper=resultDegree;

    resultCoefficients = new float [resultDegree+1];

    for (int i=resultDegree; i>=0; i--)
    {
        resultCoefficients[i]=0;
    }

    buffer1 = new float [w.degree+1];
    buffer2 = new float [w.degree+1];

    for (int i=w.degree; i>=0; i--)
    {
        buffer1[i]=w.coefficients[i];
        buffer2[i]=0;
    }


    if (w.degree>=p.degree && ((p.degree!=0 && p.coefficients[0]!=0) || (p.degree==0 && p.coefficients[0]!=0)))
    {
        for (int i=resultDegree; i>=0; i--)
        {
            if (p.coefficients[p.degree]!=0)
            {
                if (buffer1[divisionHelper]!=0)
                {
                    resultCoefficients[i]+=buffer1[divisionHelper]/p.coefficients[p.degree];
                    for (int j=p.degree; j>=0; j--)
                    {
                        buffer2[resultDegreeHelper+j]+=resultCoefficients[i]*p.coefficients[j];

                    }
                    for (int k=w.degree; k>=0; k--)
                    {
                        buffer1[k]=buffer1[k]-buffer2[k];
                    }
                    //if i==0 break
                    for (int i=w.degree; i>=0; i--)
                    {
                        if (buffer1[i]==0)
                        {
                            zero++;
                        }
                        else
                        {
                            break;
                        }
                    }
                    loopRemainderHelper=w.degree-zero;
                    if (loopRemainderHelper>=p.degree && i>0)/////////////////////oostatni
                    {
                        for (int i=w.degree; i>=0; i--)
                            buffer2[i]=0;
                    }
                    else
                    {
                        if (loopRemainderHelper>=0)
                        {
                            remainder = new float [loopRemainderHelper+1];
                            for(int i=loopRemainderHelper; i>=0; i--)
                            {
                                remainder[i]=buffer1[i];
                            }
                            break;
                        }

                    }
                    zero=0;
                }
                divisionHelper--;
                resultDegreeHelper--;
            }
        }
    }

    else if (w.degree>=p.degree && p.degree==2)//horner
    {
        int root=-p.coefficients[0];
        for (int i=w.degree; i>=0; i--)
        {
            buffer1[i]=w.coefficients[i];
            buffer2[i]=0;
        }
        buffer2[w.degree]=buffer1[w.degree];

        for (int i=resultDegree; i>=0; i--)
        {
            {
                buffer2[i]=(buffer2[i+1]*root)+buffer1[i];
            }
        }
        for (int i=resultDegree; i>=0; i--)
        {
            {
                resultCoefficients[i]=buffer2[i+1];
            }
        }
        remainder[0]=buffer2[0];
    }
    else if (p.degree==0 && p.coefficients[0]==0)
    {
        cout<<"P(x) cannot be 0";
    }
    else if (p.degree>w.degree)
    {
        cout<<"W(x) has to be greater or equal to P(x)";
    }
    delete [] buffer1;
    delete [] buffer2;
}


