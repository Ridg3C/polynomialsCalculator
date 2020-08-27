#include <iostream>
#include "polynomials.h"
using namespace std;

void Wx::show()
{
    cout<<"W(x)= ";              //show W(x)
    for (int i=degree; i>=0; i--)
    {
        if (coefficients[i]>0 && i!=helper)
        {
            cout<<"+";
        }
        if (coefficients[i]==-1 && i!=0)
        {
            cout<<"-";
        }
        if (coefficients[i]!=0)
        {
            if ((coefficients[i]!=1 && coefficients[i]!=-1) || i==0)
            {
                cout<<coefficients[i];
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
        else if (coefficients[i]==0)
        {
            helper--;
        }
        if (i<=0 && helper==-1)
        {
            cout<<"0";
        }
    }
    cout<<endl;
    cout<<endl;
}
