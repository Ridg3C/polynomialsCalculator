#include <iostream>
#include "polynomials.h"
#include <ctype.h> // isdigit()
#include <sstream> // stringstream
using namespace std;

void Wx::isPositiveInteger(string &s, int &i)
{
    int isInt=0;
    int decimalCount=0;

    bool isIntBool=false;
    bool containsSpaces = false;

    do
    {
        getline(cin >> ws, s);
        for (int i=0; i<s.size(); i++)
        {
            if (isspace(s[i]))
                containsSpaces=true;
        }

        if ((s[0]=='0' && isdigit(s[1])))
            isInt = 0;
        else
        {
            for (int i=0; i<s.size(); i++)
            {
                if (isdigit(s[i]))
                    isInt++;
                if (s[i]=='.')
                    decimalCount++;
            }
        }

        if (decimalCount==1)
            isInt=0;

        if (isInt==s.size() && containsSpaces==false)
        {
            stringstream str_stream_object(s);
            str_stream_object>>i;

            isIntBool=1;
        }

        else
        {
            cout<<endl;
            if (s==degreeStringNum && i==degree)
                cout<<"Degree of polynomial has to be a positive integer, try again: ";
            else
                cout<<"There is no such option, try again: ";

            isIntBool=0;
            isInt=0;
            decimalCount=0;
            containsSpaces=false;
        }

    }
    while (isIntBool==0);
}
