#include <iostream>
#include "polynomials.h"

using namespace std;

Result::Result(string chSN, int rD, int rH, int ch, int lRH)     //constructor
{
    //cout<<"Result constructor called"<<endl;

    choiceStringNum=chSN;
    resultDegree=rD;
    resultHelper=rH;
    choice=ch;
    loopRemainderHelper=lRH;
    resultCoefficients=nullptr;
    remainder=nullptr;
}

Result::Result(const Result &cR)      //copy constructor
{
    //cout<<"copyResult constructor called"<<endl;

    choiceStringNum = cR.choiceStringNum;
    resultDegree = cR.resultDegree;
    resultHelper = cR.resultHelper;
    choice = cR.choice;
    loopRemainderHelper = cR.loopRemainderHelper;
    resultCoefficients = nullptr;
    remainder = nullptr;

    resultCoefficients = new float [cR.resultDegree + 1];
    remainder = new float [loopRemainderHelper+1];
    copy(cR.resultCoefficients, cR.resultCoefficients + resultDegree + 1, resultCoefficients);
    copy(cR.remainder, cR.remainder + loopRemainderHelper + 1, remainder);

}

Result& Result::operator=(const Result& cR)    //copy assignment operator
{
    //cout<<"copy assignment operator called "<<endl;

    if (this != &cR)
    {
        delete [] resultCoefficients;
        delete [] remainder;

        choiceStringNum=cR.choiceStringNum;
        resultDegree=cR.resultDegree;
        resultHelper=cR.resultHelper;
        choice=cR.choice;
        loopRemainderHelper = cR.loopRemainderHelper;


        resultCoefficients = new float [cR.resultDegree + 1];
        remainder = new float [loopRemainderHelper+1];
        copy(cR.resultCoefficients, cR.resultCoefficients + resultDegree + 1, resultCoefficients);
        copy(cR.remainder, cR.remainder + loopRemainderHelper + 1, remainder);
    }
    return *this;
}

Result::Result(Result &&mR) //move constructor
{
    //cout<<"moveResult constructor called"<<endl;

    choiceStringNum = mR.choiceStringNum;
    resultDegree = mR.resultDegree;
    resultHelper = mR.resultHelper;
    choice = mR.choice;
    resultCoefficients = mR.resultCoefficients;
    loopRemainderHelper = mR.loopRemainderHelper;

    mR.choiceStringNum = "0";
    mR.resultDegree = 0;
    mR.resultHelper = 0;
    mR.choice = 0;
    mR.loopRemainderHelper = 0;
    mR.resultCoefficients = nullptr;
    mR.remainder = nullptr;

}

Result& Result::operator=(Result&& mR)      //move assignment operator
{
    //cout<<"move assignment operator called"<<endl;

    if (this!=&mR)
    {
        delete [] resultCoefficients;
        delete [] remainder;

        choiceStringNum = mR.choiceStringNum;
        resultDegree = mR.resultDegree;
        resultHelper = mR.resultHelper;
        choice = mR.choice;
        loopRemainderHelper = mR.loopRemainderHelper;
        resultCoefficients = mR.resultCoefficients;
        remainder = mR.remainder;
        mR.resultCoefficients = nullptr;
        mR.remainder = nullptr;
        mR.resultDegree = 0;
        mR.loopRemainderHelper = 0;
    }
    return *this;
}

Result::~Result()
{
    //cout<<"Result destructor called"<<endl;
    delete [] resultCoefficients;
    delete [] remainder;
}





