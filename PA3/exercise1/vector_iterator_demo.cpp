/*  Program: Exercise 1
    Author: Mathieu Partain-Martinez
    Class: CSCI 240
    Date: 09/21/2024  
    Description: adding in print and removeElement based on string give, adding to the Vector class 
    I certify that the code below is my own work.
    Exception(s): N/A
*/

#include <cstdlib>  // provides EXIT_SUCCESS
#include <iostream>
#include <string>

#include "vector.h"

using namespace std;
using namespace dsac::array;

// void print()  {
//          for (const T& elem : *this) { // read only to print elements in vector
//              std::cout << elem << " ";
//      }
//      std::cout << std::endl;
//     }

// void removeElem(const T& elem){ // read omly to elements
//          for(int i = 0; i < sz; i++){  // loop through vector
//              if(data[i] == elem){   // element at index to specific element
//                  erase(i);  // use orignal class method
//                  return;
//              }
                
//         }
//    }

int main() {

    Vector<string> myList;       
    myList.insert(0, "Two");
    myList.insert(1, "Three");
    myList.insert(0, "One");
    myList.insert(3, "Four");
    myList.print();
    myList.erase(0);
    myList.removeElem("Two");
    myList.removeElem("Four");
    myList.insert(1, "Mathieu");
    myList.print();
   
}