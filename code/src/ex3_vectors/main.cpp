////////////////////////////////////////////////////////////////////////////////
/// \file
/// \brief      Main module for Vector Samples.
/// \author     Sergey Shershakov
/// \version    0.1.0
/// \date       01.02.2021
///             This code is for educational purposes of the course "Introduction
///             to programming" provided by the Faculty of Computer Science
///             at the Higher School of Economics.
///
/// Dealing with std::vector
///
////////////////////////////////////////////////////////////////////////////////


#include <iostream>
#include <vector>

// a relative path to a header that consists of utilities for working with vectors
#include "../common/vect_utils.h"


using std::cout;

void basics()
{
    cout << "Samples 1\n";

    std::vector<int> v1;
    size_t v1Sz = v1.size();
    size_t v1Cap = v1.capacity();

    v1.push_back(10);
    v1Sz = v1.size();
    v1Cap = v1.capacity();

    v1.push_back(20);
    v1Sz = v1.size();
    v1Cap = v1.capacity();

    v1.push_back(30);
    v1Sz = v1.size();
    v1Cap = v1.capacity();


    int a = v1[0];
    a = v1[1];
    a = v1[2];
    //a = v1[3];                    // undefined bahaviour

    int b = v1.at(0);
    b = v1.at(1);
    b = v1.at(2);
    //b = v1.at(3);                 // exception

    v1.resize(5);
    v1Sz = v1.size();
    v1Cap = v1.capacity();

    v1.resize(2);
    v1Sz = v1.size();
    v1Cap = v1.capacity();

    cout << "\n\n";
}


// exploring how change size() and capacity() while adding elements
void addingElementsSizeAndCapacity()
{
     std::vector<int> v;                      // sz  cap
     size_t vSz = v.size();                   // 0   0
     size_t vCap = v.capacity();              // 1   1
                                              // 2   2
     for (size_t i = 0; i < 10; ++i)          // 3   4
     {                                        // 4   4
         v.push_back(i);                      // 5   8
         vSz = v.size();                      // 6   8
         vCap = v.capacity();                 // 7   8
     }                                        // 8   8
                                              // 9   16
     // so, here ve have 5 memory allocations, which involves insufficient
     // copying

     // if we know that we are going to add 10 elements, we can allocate enough
     // memory in advance
     std::vector<int> v2;
     v2.reserve(10);
     size_t v2Sz = v2.size();
     size_t v2Cap = v2.capacity();

     for (size_t i = 0; i < 11; ++i)        // mention 11 here! what happens with
     {                                      // the last element?
         v2.push_back(i);
         v2Sz = v2.size();
         v2Cap = v2.capacity();
     }

}

void makeRandomVector()
{
    cout << "Samples 2: making a random vector\n";

    std::vector<int> v;
    fillRandomVec(v, 10);           // passing v as a reference
    printVec(v);

    cout << "\n\n";
}


void iteratingThroughVector()
{
    cout << "Samples 3: approaches for iterating through a vector\n";

    std::vector<int> v;
    fillRandomVec(v, 10);           // passing v as a reference

    // approach 1: Using for loop and the subscript operator[]
    for(size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << ", ";
    cout << "\n";

    // approach 2: Using range-based for loop
    for(int el : v)
        std::cout << el << ", ";
    cout << "\n";

    // approach 3: Using iterators
    for(std::vector<int>::const_iterator it = v.begin();
        it != v.end();
        ++it)
    {
        int val = *it;              // dereferencing the iterator
        std::cout << val << ", ";
    }

    cout << "\n\n";
}


void inputAndPrintVector()
{
    cout << "Samples 4: input a vector and print it\n";

    std::vector<int> v;
    cout << "Input numbers of a vector: ";
    inputVectorFromStream(v, std::cin);
    printVec(v);

    cout << "\n\n";
}


void finMinElFromVector()
{
    cout << "Samples 5: search for a min el of a vector\n";

    std::vector<int> v;
    fillRandomVec(v, 10);           // passing v as a reference
    printVec(v);
    cout << "\n";

    int minVal;                     // passing this variable by reference
                                    // it will be changed directly in the method
    int ind = findMilEl(v, minVal);
    cout << "The min el is: " << minVal << ", its index is: " << ind;

    cout << "\n\n";
}


int main()
{
    cout << "Hello world!\n\n";

    basics();
    addingElementsSizeAndCapacity();
    makeRandomVector();
    iteratingThroughVector();
    inputAndPrintVector();
    finMinElFromVector();

    return 0;
}
