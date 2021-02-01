/*! \file       vect_utils.h
 *  \author     Sergey Shershakov
 *  \version    0.1
 *  \date       20.11.2019
 *
 *  Headers for utilities for std::vector
 */
 
#include <vector>
#include <iostream>
 
void fillRandomVec(std::vector<int>& v, unsigned int k);
void outputVec(const std::vector<int>& v, std::ostream& ostr);
void printVec(const std::vector<int>& v);
void inputVectorFromStream(std::vector<int>& v, std::istream& istr);
int findMilEl(const std::vector<int>& v, int& val);

