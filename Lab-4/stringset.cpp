/*
 * Name: Kaylee Pierce
 * Date Submitted: 10/18/2023
 * Lab Section: 002
 * Assignment Name: Lab 5 - Spell Checker Using a Hash Table
 */

#include "stringset.h"

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

void Stringset::insert(string word)
{
    //Implement this function
    if(!find (word)) {
        num_elems++;
        hash<string> stringhash;
        int put = stringhash(word) % size;

        table[put].push_back(word);

        if(num_elems == size) {
            vector<list<string> > new_table;
            size = size * 2;
            new_table.resize(size);
            for(int i = 0; i < size / 2; i++) {
                for(auto it = table[i].begin(); it!= table[i].end(); it++) {
                    string temp = *it;
                    hash<string> temphash;
                    int put = temphash(temp) % size;
                    new_table[put].push_back(temp);
                }
            }
            table = new_table;
        }
    }
}

bool Stringset::find(string word) const
{
    //Implement this function
    hash<string> stringhash;
    int put = stringhash(word) % size;
    for(auto it = table[put].begin(); it!= table[put].end(); ++it) {
        string temp = *it;
        if(temp.compare(word) == 0) {
            return true;
        }
    }
    return false;
}

void Stringset::remove(string word)
{
    //Implement this function
    if(find(word)) {
        hash<string> stringhash;
        int put = stringhash(word) % size;
        table[put].remove(word);
        num_elems--;
    }
}