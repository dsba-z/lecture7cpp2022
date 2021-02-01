/*! \file       main.cpp
 *  \author     Sergey Shershakov
 *  \version    0.1
 *  \date       21.11.2019
 *
 *  Dealing with matrices: let's go to a cinema!
 */


#include <iostream>
#include <vector>
#include <sstream>

// TODO: uncomment this for a home exercise
// #include "../common/vect_utils.h"


using std::cout;
using std::cin;

// Define datatypes for representing
typedef std::vector<int> Row;
typedef std::vector<Row> SittingPlan;
typedef unsigned short UShort;

//------------------------------------------------------------------------------


/*!
 * \brief   inputRow() reads an information about a single row from stdin object.
 * \return  a row object. An empty row means the end of the input process.
 */
Row inputRow()
{
    // string representation of a row
    std::string rowStr;
    std::getline(std::cin, rowStr);

    Row row;
    // what about an empty string? — simply return an "empty row",
    // which indicates that the input is over
    if(rowStr.empty())
        return row;


    // parse using stringstream (don't forget #include <sstream>)
    std::stringstream ss(rowStr);

    char ch;
    while( ss >> ch )
    {
        // can check here whether it is proper or not
        row.push_back(ch);
    }

    return row;
}


//------------------------------------------------------------------------------


/*!
 * \brief   inputSittingPlan() inputs a sitting plan of a cinema theater row by row.
 *          Empty row terminates the input.
 * \return  The sitting plan as a vector of vectors of ints, which is a matrix of a
 *          jagged array.
 */
SittingPlan inputSittingPlan()
{
    SittingPlan sitPlan;            // prepare an object for input data

    Row r = inputRow();             // reads the very first row
    while(r.size() /* != 0 */)      // repeat the loop while another row is not empty
    {
        sitPlan.push_back(r);       // add another row to the sitting plan
        r = inputRow();             // read the next row
    }

    return sitPlan;
}


//------------------------------------------------------------------------------

bool isSold(char seat)
{
    return (seat == '1');

    //return (seat == '1') ? true : false;
//    if(seat == '1')
//        return true;

//    return false;
}


//------------------------------------------------------------------------------

void printRow(const Row& row)
{
    int sold = 0;
    int total = 0;

    for(char el : row)
    {
        ++total;
        char symb;

        //if(el == '1')   // DONE: to improve the logic of checking
        if(isSold(el))
        {
            ++sold;
            symb = '*';
        }
        else
            symb = '.';

        std::cout << symb;
    }

    // output statistics
    // we are not going to add a newline char
    std::cout << "\t\t(" << sold << '/' << total <<')';
}


//------------------------------------------------------------------------------

void printSittingPlan(const SittingPlan& sp)
{
    for( const Row& row : sp )
    {
        printRow(row);
        std::cout << '\n';
    }
}

//------------------------------------------------------------------------------

// Looks for a sequence of k free seats ...
int findFreeSeq(const Row& row, UShort k)
{
    UShort freeCnt = 0;
    //
    for(UShort i = 0; i < row.size(); ++i)
    {
        if(!isSold(row[i]))     // if a seat is free
        {
            ++freeCnt;
            if(freeCnt == k)
                return (i - k + 1);
        }
        else
            freeCnt = 0;
    }

    return -1;
}

//------------------------------------------------------------------------------

int findFreeRow(const SittingPlan& sp, UShort k, int& seat)
{
    int rowCount = 0;
    // iterate all over rows and looking for a first suitable
    for(const Row& row : sp)
    {
        int res = findFreeSeq(row, k);
        if(res >= 0)
        {
            seat = res;             // seat num
            return rowCount;        // row num
        }
        ++rowCount;
    }
    return -1;                      // not found
}


int main()
{
    cout << "Hello world! Let's go to a cinema!\n\n";

    // test inputing sitting plan
    cout << "Input sitting plan row by row (empty line to stop):\n\n";
    SittingPlan sp = inputSittingPlan();

    cout << "\n";

    // test printing the whole sitting plan
    printSittingPlan(sp);

    cout << "\nInput seat num k = ";
    UShort k;
    cin >> k;
    int rowNum, seatNum;
    rowNum = findFreeRow(sp, k, seatNum);
    if(rowNum >= 0)
    {
        cout << "\nFound row num " << rowNum
             << ", seats starting at " << seatNum;
    }
    else
        cout << "\nNothing found";

    cout << "\n\n";

    return 0;
}



//// test inputRow() method
////Row r = inputRow();

//// test inputing sitting plan
//SittingPlan sp = inputSittingPlan();

//// test printing a row
////printRow(sp.at(0));

//// test printing the whole sitting plan
//printSittingPlan(sp);

//// test searching a sequence of free seats
////int res = findFreeFreq(sp.at(0), 2);
