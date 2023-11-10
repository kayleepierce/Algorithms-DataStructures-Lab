/*
 * Name: Kaylee Pierce
 * Date Submitted: 10/18/2023
 * Lab Section: 002
 * Assignment Name: Lab 5 - Spell Checker Using a Hash Table
 */
 
 #include "stringset.h"
 #include <iostream>
 #include <fstream>
 
 void testStringset(Stringset& words);
 void loadStringset(Stringset& words, string filename);
 vector<string> spellcheck(const Stringset& words, string word);
 
 /*int main()
 {
     Stringset wordlist;
     testStringset(wordlist);
     return 0;
 }
 
 void testStringset(Stringset& words)
 {
     string choice;
     string word;
     do
     {
         cout << "I: insert word" << endl;
         cout << "F: find word" << endl;
         cout << "R: remove word" << endl;
         cout << "P: print words in stringset" << endl;
         cout << "Q: quit" << endl;
         cin >> choice;
         switch (choice[0])
         {
             case 'I':
             case 'i':
                cout << "Enter word to insert: ";
                cin >> word;
                words.insert(word);
                break;
             case 'F':
             case 'f':
                cout << "Enter word to find: ";
                cin >> word;
                if (words.find(word))
                {
                    cout << word << " in stringset" << endl;
                }
                else
                {
                    cout << word << " not in stringset" << endl;
                }
                break;
             case 'R':
             case 'r':
                cout << "Enter word to remove: ";
                cin >> word;
                words.remove(word);
                break;
             case 'P':
             case 'p':
                vector<list<string> > t = words.getTable();
                int numWords = words.getNumElems();
                int tSize = words.getSize();
                for(int i=0; i<tSize; ++i)
                {
                    list<string>::iterator pos;
                    for (pos = t[i].begin(); pos != t[i].end(); ++pos)
                    {
                        cout << *pos << endl;
                    }
                }
                cout << "Words: " << numWords << endl;
         }
     } while (choice[0] != 'Q' && choice[0] != 'q');
 } */
 
 void loadStringset(Stringset& words, string filename)
 {
     //Implement this function
    ifstream inFile(filename);
    string word;
    while(getline(inFile, word)) {
        words.insert(word);
        cout << word << endl;
    }
 }
 
 vector<string> spellcheck(const Stringset& words, string word)
 {
     //Implement this function
     vector<string> alternative;
     string test;
     int wordSize = word.size();

     for(int i = 0; i < wordSize; ++i) {
        test = word;
        char letter = test[i];

        int alphabet = letter + 1;
        while(alphabet != letter) {
            if(alphabet > 122) {
                alphabet = alphabet - 26;
            }
            if(alphabet != letter) {
                char newLet = alphabet;
                test[i] = newLet;
                if(words.find(test)) {
                    alternative.push_back(test);
                }
                alphabet++;
            }
        }
     }
     return alternative;
 }