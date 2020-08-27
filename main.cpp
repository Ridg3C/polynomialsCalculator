#include <iostream>
#include "polynomials.h"

using namespace std;

int main()
{
    for (;;)
    {
        Wx w;
        Px p;
        Result r;

        Polynomial *pointer;

        pointer=&w;
        pointer->gather();
        pointer->show();
        pointer=&p;
        pointer->gather();
        pointer->show();
        r.menu(w, p);
        r.showResult(w, p);
    }
}
