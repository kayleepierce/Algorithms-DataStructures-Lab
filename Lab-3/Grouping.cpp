/*
 * Name: Kaylee Pierce
 * Date Submitted: 09/25/2023
 * Lab Section: 002
 * Assignment Name: Lab 3 - Finding Groups Using Recursion
 */

#include "Grouping.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Implement the (parameterized) constructor and findGroup functions below

// Const function used to read in file and initalize grid/groups
Grouping::Grouping(string filename) : groups() {
    ifstream inputFile(filename);
    if(!inputFile.is_open()) {
        return; // Stop if file cannot be opened
    }
    
    // Below is used to initalize grid with 0s and 1s
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            char pos;
            inputFile >> pos;
            grid[i][j] = (pos == '.') ? 0 : 1;
        }
    }

    inputFile.close();

    // Form groups using the findGroup function
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            if(grid[i][j] == 1) {
                vector<GridSquare> group;
                findGroup(i, j, group);
                groups.push_back(group);
            }
        }
    }
}

// Recursive funciton 
void Grouping::findGroup(int r, int c, vector<GridSquare>& group) {
    if(r < 0 || r >= 10 || c < 0 || c >= 10 || grid[r][c] == 0) {
        return; // Stop if out of bounds
    }

    // Adds current cell to group
    group.push_back(GridSquare(r, c));
    grid[r][c] = 0;

    // Use recursion to search in all directions
    findGroup(r - 1, c, group); // UP
    findGroup(r + 1, c, group); // DOWN
    findGroup(r, c - 1, group); // LEFT
    findGroup(r, c + 1, group); // RIGHT
}




//Simple main function to test Grouping
//Be sure to comment out main() before submitting
/* int main()
{
    Grouping input1("input1.txt");
    input1.printGroups();
    
    return 0;
} */

//Do not modify anything below

GridSquare::GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square

GridSquare::GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square

//Compare with == operator, used in test cases
bool GridSquare::operator== (const GridSquare r) const
{
    if ((row == r.row) && (col == r.col))
    {
        return true;
    }
    return false;
}

int GridSquare::getRow() //return row value
{
    return row;
}

int GridSquare::getCol() //return column value
{
    return col;
}

//Output using << operator, used in Grouping::printGroups()
//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

Grouping::Grouping() : grid{},groups() {} //Default constructor, no groups

void Grouping::printGroups() //Displays grid's groups of squares
{
    for(int g=0; g<groups.size(); g++)
    {
        cout << "Group " << g+1 << ": ";
        for(int s=0; s<groups[g].size(); s++)
        {
            cout << " " << groups[g][s];
        }
        cout << endl;
    }
}

vector<vector<GridSquare> > Grouping::getGroups() //Needed in unit tests
{
    return groups;
}