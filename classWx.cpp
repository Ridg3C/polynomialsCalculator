#include <iostream>
#include "polynomials.h"

using namespace std;

Wx::Wx(string dNS, int d, int h)
{
    //cout<<"Wx constructor called"<<endl;

    degreeStringNum=dNS;
    degree=d;
    helper=h;
    coefficients=nullptr;
    coefficientsStringNum=nullptr;
}

Wx::Wx(const Wx &cWx)      //copy constructor
{
    //cout<<"copyWx constructor called"<<endl;

    degreeStringNum = cWx.degreeStringNum;
    degree = cWx.degree;
    helper = cWx.helper;

    coefficients=new float[cWx.degree+1];
    coefficientsStringNum = coefficientsStringNum=new string[cWx.degree+1];
    copy(cWx.coefficients, cWx.coefficients + degree + 1, coefficients);
    copy(cWx.coefficientsStringNum, cWx.coefficientsStringNum + degree + 1, coefficientsStringNum);
}

Wx& Wx::operator=(const Wx& cWx)    //copy assignment operator
{
    //cout<<"copy assignment Wx operator called "<<endl;

    if (this != &cWx)
    {
        delete [] coefficients;
        delete [] coefficientsStringNum;

        degreeStringNum = cWx.degreeStringNum;
        degree = cWx.degree;
        helper = cWx.helper;

        coefficients = new float[cWx.degree + 1];
        coefficientsStringNum = new string[cWx.degree + 1];
        copy(cWx.coefficients, cWx.coefficients + degree + 1, coefficients);
        copy(cWx.coefficientsStringNum, cWx.coefficientsStringNum + degree + 1, coefficientsStringNum);
    }
    return *this;
}

Wx::Wx(Wx &&mWx) //move constructor
{
    //cout<<"moveWx constructor called"<<endl;
    degreeStringNum = mWx.degreeStringNum;
    degree = mWx.degree;
    helper = mWx.helper;

    mWx.degreeStringNum="0";
    mWx.degree = 0;
    mWx.helper = 0;

    mWx.coefficients = nullptr;
    mWx.coefficientsStringNum = nullptr;
}

Wx& Wx::operator=(Wx&& mWx)      //move assignment operator
{
    //cout<<"move assignment Wx operator called"<<endl;

    if (this!=&mWx)
    {
        delete [] coefficients;
        delete [] coefficientsStringNum;

        degreeStringNum = mWx.degreeStringNum;
        degree = mWx.degree;
        helper = mWx.helper;
        coefficients = mWx.coefficients;
        coefficientsStringNum = mWx.coefficientsStringNum;

        mWx.degreeStringNum = "0";
        mWx.degree = 0;
        mWx.helper = 0;

        mWx.coefficients = nullptr;
        mWx.coefficientsStringNum = nullptr;
    }
    return *this;
}

Wx::~Wx()
{
    delete [] coefficients;
    //cout<<"Wx destructor called"<<endl;
}
