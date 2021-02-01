/*! \file       vect_utils.cpp
 *  \author     Sergey Shershakov
 *  \version    0.1
 *  \date       20.11.2019
 *
 *  Utilities for std::vector
 */

#include "vect_utils.h"

#include <random>       // generators of random numbers
#include <ctime>        // time
#include <sstream>


/// fills a given vector of integers with randomly generated numbers
void fillRandomVec(std::vector<int>& v, unsigned int k)
{
    // preparing the generator
    //std::default_random_engine gen();

    std::mt19937 gen(time(nullptr));                    // needed for initialization
    std::uniform_int_distribution<int> distr(0, 90);    // distribution

    v.clear();
    for(size_t i = 0; i < k; ++i)
    {
        v.push_back(distr(gen));
    }
}


/// outputs vector's elements to a given stream
void outputVec(const std::vector<int>& v, std::ostream& ostr)
{
    for(size_t i = 0; i< v.size(); ++i)
        ostr << v[i] << ", ";
}


/// a shortcut for printing vector's elements
void printVec(const std::vector<int>& v)
{
    outputVec(v, std::cout);
}


// input a vector from a stream
void inputVectorFromStream(std::vector<int>& v, std::istream& istr)
{
    // we have to use stringstream to read a whole line
    std::string s;
    std::getline(istr, s);
    std::stringstream ss(s);

    while(ss.good() && !ss.eof())
    {
        int  cur;
        ss >> cur;
        v.push_back(cur);
    }
}


/// searches a minimal element of a given vector and returns its index,
/// and the value of the element through the ref param
/// if the vector is empty, returns -1
int findMilEl(const std::vector<int>& v, int& val)
{
    if(v.size() == 0)
        return -1;

    int ind = 0;
    int curMin = v[0];
    for(int i = 1; i < v.size(); ++i)   // we've already checked the 1st el
    {
        if(v[i] < curMin)
        {
            curMin = v[i];
            ind = i;
        }
    }

    // passing the actual minimal value by ref
    val = curMin;
    return ind;                         // return the index of the min el by value
}

