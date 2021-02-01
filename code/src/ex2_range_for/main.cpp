/*! \file       main.cpp
 *  \author     Sergey Shershakov
 *  \version    0.1
 *  \date       20.11.2019
 *
 *  Range-based for
 */

#include <iostream>

using std::cout;

void rangeForVal()
{
    double koefs[] = {1.12, 2.13, 3.14, 4.15, 5.16};
    for (double x : koefs)
        cout << x << ", ";//std::endl;

    cout << '\n';

    for (int x : {1, 1, 2, 3, 5})
        cout << x << ", ";

    cout << "\n\n";
}


void rangeForRef()
{
    double koefs[] = {1.12, 2.13, 3.14, 4.15, 5.16};
    for (double x : koefs)
        cout << x << ", ";
    cout << '\n';

    for (double& y : koefs)
        y = y * 2;    // doubles the values
    for (double y : koefs)
        cout << y << ", ";

    cout << "\n\n";
}


int main()
{
    cout << "Hello world!\n\n";

    rangeForVal();
    rangeForRef();

    return 0;
}
