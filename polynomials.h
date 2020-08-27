#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace std;

class Polynomial
{
public:
    virtual void gather()=0;
    virtual void show()=0;
};

class Px;
class Wx;

class Result
{
protected:
    string choiceStringNum;
    int resultDegree;
    int resultHelper;
    int choice;
    int loopRemainderHelper;
    float *resultCoefficients;
    float *remainder;
public:
    void menu(Wx &w, Px &p);
    void addition(const Wx &w, const Px &p);
    void subtraction(const Wx &w, const Px &p);
    void multiplication(const Wx &w, const Px &p);
    void division(const Wx &w, const Px &p);
    void showResult(const Wx &w, const Px &p);
    void isPositiveInteger(string &s, int &i);

    Result(string="0", int=0, int=0, int=0, int=0); //constructor
    Result(const Result &copyResult);  //copy constructor
    Result& operator=(const Result& copyOperator); //copy assignment operator
    Result(Result &&moveResult);    //move constructor
    Result& operator=(Result&& moveOperator); //move assignment operator

    ~Result();
};

class Wx :public Polynomial
{
protected:
    string degreeStringNum;
    string *coefficientsStringNum;
    int degree;
    int helper;
    float *coefficients;

public:
    virtual void gather();
    virtual void show();
    void isPositiveInteger(string &s, int &i);
    void isFloat(string &s, float &f, int i);
    friend class Result;

    Wx(string="0", int=1, int=0);


    Wx(const Wx &copyWx);  //copy constructor
    Wx& operator=(const Wx& copyOperator); //copy assignment operator
    Wx(Wx &&moveWx);    //move constructor
    Wx& operator=(Wx&& moveOperator); //move assignment operator

    ~Wx();

};

class Px :public Wx
{
public:
    virtual void gather();
    virtual void show();
    friend class Result;
};



