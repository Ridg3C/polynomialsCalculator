#include <iostream>
#include "polynomials.h"
using namespace std;

void Result::menu(Wx &w, Px &p)
{
    cout<<"Main menu"<<endl;
    cout<<"---------------------"<<endl;
    cout<<"1.Addition"<<endl;
    cout<<"2.Subtraction"<<endl;
    cout<<"3.Multiplication"<<endl;
    cout<<"4.Division"<<endl;
    cout<<"5.Exit"<<endl;
    cout<<endl;
    cout<<"Choose an operation: ";
    w.isPositiveInteger(choiceStringNum, choice);
    while (choice!=1 && choice!=2 && choice!=3 && choice!=4 && choice!=5)
    {
        cout<<"There is no such option, try again: ";
        w.isPositiveInteger(choiceStringNum, choice);
    }

    switch(choice)
    {
    case 1:
    {
        cout<<"W(x)+P(x) = ";
        addition(w, p);
    }
    break;
    case 2:
    {
        cout<<"W(x)-P(x) = ";
        subtraction(w, p);
    }
    break;
    case 3:
    {
        cout<<"W(x)*P(x) = ";
        multiplication(w, p);
    }
    break;
    case 4:
    {
        cout<<"W(x):P(x) = ";
        division(w, p);
    }
    break;
    case 5:
    {
        cout<<"Goodbye";
        exit(0);
    }
    break;
    default:
    {
        cout<<"There is no such option";
    }
    }
}
