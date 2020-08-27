#include <iostream>
#include "polynomials.h"
#include <ctype.h> // isdigit()
#include <sstream> // stringstream
using namespace std;

void Wx::isFloat(string &s, float &f, int iI)
{
    int isFlt=0;
    int decimalCount=0;
    int stringZero=0;

    bool isFltBool=false;
    bool containsSpaces = false;

    do
    {
        getline(cin >> ws, s);
        for (int i=0; i<s.size(); i++)
        {
            if  (s[i]=='0')
                stringZero++;
        }
        for (int i=0; i<s.size(); i++)
        {
            if (isspace(s[i]))
                containsSpaces=true;
        }
        if (s[0]=='-')
        {
            isFlt=1;
        }
        if (s[0]=='-' && s[1]=='0' && s[2]=='.' && s.size()-2==stringZero)
        {
            isFlt=0;
        }
        else if (s[0]=='0' && s[1]=='.' && s.size()-1==stringZero)
        {
            isFlt=-1;
        }
        else if (s[0]=='0' && s[1]=='0')
        {
            isFlt=-1;
        }
        else if (s[1]=='0' && s[2]=='0')
        {
            isFlt=0;
        }
        else if ((s[0]=='0' && isdigit(s[1])))
        {
            isFlt = -1;
        }
        stringZero=0;

        for (int i=0; i<s.size(); i++)
        {
            if (isdigit(s[i]))
                isFlt++;
            if (s[i]=='.')
            {
                decimalCount++;
                isFlt++;
            }
        }
        if (isFlt==s.size() && containsSpaces==false && (decimalCount==0 || decimalCount==1) && (s[0]!='.' && s[s.size()-1]!='.'))
        {
            stringstream str_stream_object(s);
            str_stream_object>>f;

            isFltBool=1;
        }

        else
        {
            cout<<"It is not a floating point numer, try again: ";
            cout<<endl;
            cout<<"x^"<<iI<<": ";

            isFltBool=0;
            isFlt=0;
            decimalCount=0;
            containsSpaces=false;
        }

    }
    while (isFltBool==0);
}
