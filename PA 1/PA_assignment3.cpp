/*  Program: Exercise 2
    Author: Mathieu Partain-Martinez
    Class: CSCI 240
    Date: 09/012024  
    Description: Created 2 fucntions 1 that stores random values 1-365 in an array and filter the array to find duplicates
    I certify that the code below is my own work.
    Exception(s): N/A
*/

#include <iostream>
#include <cstdlib>

using namespace std;

class Progression {
  protected:
    long current;

    // Advances the current value to the next value of the progression
    virtual void advance() {               // we declare this virtual, expecting it to be overridden
        current++;
    }

  public:
    // Constructs a progression with given start value (default: 0)
    Progression(long start = 0) : current{start} {}

    // Destructs the progression                                                                                                                   
    virtual ~Progression() {};             // virtual destructor

    // Returns the next value of the progression
    long next_value() {
        long answer{current};
        advance();                         // the protected call updates the current value
        return answer;
    }

    // Prints the next n values of the progression, separate by spaces
    void print_progression(int n) {
        cout << next_value();              // print the first value without leading space                                                      
        for (int j = 1; j < n; j++)
            cout << " " << next_value();   // print leading space before others                                                                
        cout << endl;
    }
};

int main(){

    
}