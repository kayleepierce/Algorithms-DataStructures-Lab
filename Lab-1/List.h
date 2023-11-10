/*
 * Name: Kaylee Pierce
 * Date Submitted: 09/10/2023
 * Lab Section: 002
 * Assignment Name: Lab 1 - Linked List Based on Stacks and Queues
 */

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)

//Implement all of the functions below
//Construct an empty list by initializing this list's instance variables
template <class T>
List<T>::List(){
  start = nullptr;
  mySize = 0;
}

//Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List(){
  while(start != nullptr) {                // Loop until the list is empty
    Node<T> *temp = start;
    start = start->next;
    delete temp;                           // Delete the old start node to free memory
  }
}

//Return the size of this list
template <class T>
int List<T>::size(){
  return mySize;                            // Returns the current size of the list
}

//Return true if this list is empty
//Otherwise, return false
template <class T>
bool List<T>::empty(){
  return size() == 0;                       // Returns TRUE if the size is 0
}

//Create a new node with value, and insert that new node
//into this list at start
template <class T>
void List<T>::insertStart(T value){
  Node<T> *newNode = new Node<T>(value);    // Create a new node with value
  newNode->next = start;
  start = newNode;
  mySize++;
}

//Create a new node with value, and insert that new node
//into this list at end
template <class T>
void List<T>::insertEnd(T value){
  Node<T> *newNode = new Node<T>(value);
  if(start == nullptr) {                  // If the list is empty, set start pointer to new node
    start = newNode;
  } else {                                // If not empty, create an iterator starting at first node
    Node<T>* iterator = start;
    while(iterator->next != nullptr) {
      iterator = iterator->next;
    }
    iterator->next = newNode;
   }
   mySize++;
}

//Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j){
  if(j < 0 || j > mySize) {             // Check to see if position is valid
    return;
  }
  if(j == 0) {                          // If position is 0, insert at start
    insertStart(value);
  } else if(j == mySize) {              // If position is at end, insert at end
    insertEnd(value);
  } else {
    Node<T> *newNode = new Node<T>(value);
    Node<T> *iterator = start;
    for(int i = 0; i < j - 1; i++) {    // Go through list to find the node before the desired position
      iterator = iterator->next;
    }
    newNode->next = iterator->next;
    iterator->next = newNode;
    mySize++;
  }
}

//Remove node at start
//Make no other changes to list
template <class T>
void List<T>::removeStart(){
  if(start != nullptr) {              // Is list empty?
    Node<T> *temp = start;
    start = start->next;
    delete temp;                      // Free memory
    mySize--;
  }
}

//Remove node at end
//Make no other changes to list
template <class T>
void List<T>::removeEnd(){
  if (start != nullptr) {            
    if (start->next == nullptr) {     // If there is only ONE node in the list
      delete start;
      start = nullptr;                // Set start to nullptr (empty list)
      } else {
        Node<T> *iterator = start;
        while (iterator->next->next != nullptr) {
          iterator = iterator->next;
          }
          delete iterator->next;
          iterator->next = nullptr;
        }
        mySize--;
    }
}

//Remove node at position j
//Make no other changes to list
template <class T>
void List<T>::removeAt(int j){
  if (j < 0 || j >= mySize) {
    return;
    }
    if (j == 0) {                     // If position == 0, remove start node
      removeStart();
    } else if (j == mySize - 1) {     // If position is at end, remove end node
        removeEnd();
    } else {
        Node<T> *iterator = start;
        for (int i = 0; i < j - 1; i++) { 
            iterator = iterator->next;
        }
        Node<T> *temp = iterator->next;
        iterator->next = temp->next;
        delete temp;
        mySize--;
    }
}

//Return the value of the first node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst(){
  if(start != nullptr) {
    return start->value;          // Return the value of the first node
  }
  return T();                     // Return default value of const type T
}

//Return the value of the last node in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast(){
  if (start != nullptr) {
    Node<T> *iterator = start;
    while (iterator->next != nullptr) {
      iterator = iterator->next;
    }
    return iterator->value;       // Return the value of the last node
  }
  return T();                     // Return default value of const type T
}

//Return the value of the node at position j in the Linked List,
//If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j){
  if (j >= 0 && j < mySize) {
    Node<T> *iterator = start;
    for (int i = 0; i < j; i++) {
      iterator = iterator->next;
    }
    return iterator->value;     // Return the value of node at specified position
  }
  return T();                   // Return default value of const type T
}

//Return the position of the (first) node whose value is equal to the key
//Otherwise, return -1
template <class T>
int List<T>::find(T key){
  Node<T> *iterator = start;
  int position = 0;
  while (iterator != nullptr) {
    if (iterator->value == key) {
      return position;          // Return the position of node with matching value
    }
    iterator = iterator->next;
    position++;
  }
  return -1;                    // Return -1 if key was not found in list
}
