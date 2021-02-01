/*! \file       main.cpp
 *  \author     Sergey Shershakov
 *  \version    0.1
 *  \date       20.11.2019
 *
 *  References in C++
 */

#include <iostream>

using std::cout;

void refsSamples()
{
    int x = 10;
    cout << x << '\n';                      // 10

    int& x1 = x;                            // binding
    cout << x1 << '\n';                     // 10


    x1 = 15;
    cout << x1 << '\n';                     // 15
    cout << x << '\n';                      // 15


    x = 42;
    cout << x << '\n';                      // 42
    cout << x1 << '\n';                     // 42
}


void constRefsSamples()
{
    int x = 10;                             // x == 10

    int& x1 = x;                            // binding
    x1 = 15;

    cout << x1 << '\n';                     // 15
    cout << x << '\n';                      // 15

    const int& x2 = x;                      // binding const

    //x2 = 20;                              // compilation error!
    cout << x2 << '\n';                     // 15
}


int main()
{
    cout << "Hello world!\n\n";

    refsSamples();
    constRefsSamples();

    return 0;
}
