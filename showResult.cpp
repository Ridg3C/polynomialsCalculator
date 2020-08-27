#include <iostream>
#include "polynomials.h"
using namespace std;

void Result::showResult(const Wx &w, const Px &p)
{
    if(choice==1 || choice==2 || choice==3 || choice==4 && w.degree>=p.degree && ((p.degree!=0 && p.coefficients[0]!=0) || (p.degree==0 && p.coefficients[0]!=0)) || choice==5)
    {
        for (int i=resultDegree; i>=0; i--)
        {
            if (resultCoefficients[i]>0 && i!=resultHelper)
            {
                cout<<"+";
            }
            if (resultCoefficients[i]==-1 && i!=0)
            {
                cout<<"-";
            }
            if (resultCoefficients[i]!=0)
            {
                if ((resultCoefficients[i]!=1 && resultCoefficients[i]!=-1) || i==0)
                {
                    cout<<resultCoefficients[i];
                }
                if (i!=0)
                {
                    cout<<"x";
                }
                if (i!=0 && i!=1)
                {
                    cout<<"^"<<i;
                }
            }
            else if (resultCoefficients[i]==0)
            {
                resultHelper--;
            }
            if (i<=0 && resultHelper==-1)
            {
                cout<<"0";
            }
        }
    }
    cout<<endl;



    if (choice==4 && remainder!=nullptr)
    {
        int zero=0;
        cout<<"Remainder: ";
        for (int i=loopRemainderHelper; i>=0; i--)
        {
            if (remainder[i]==0)
                zero++;
        }
        for (int i=loopRemainderHelper; i>=0; i--)
        {
            if (remainder[i]>0 && i!=loopRemainderHelper)
            {
                cout<<"+";
            }
            if (remainder[i]==-1 && i!=0)
            {
                cout<<"-";
            }
            if (remainder[i]!=0)
            {
                if ((remainder[i]!=1 && remainder[i]!=-1) || i==0)
                {
                    cout<<remainder[i];
                }
                if (i!=0)
                {
                    cout<<"x";
                }
                if (i!=0 && i!=1)
                {
                    cout<<"^"<<i;
                }
            }
        }
    }
    cout<<endl;
    cout<<endl;
    cout<<"Press enter";
    getchar();
    system("cls");
}

