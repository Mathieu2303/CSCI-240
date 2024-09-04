/*  Program: Exercise 3
    Author: Mathieu Partain-Martinez
    Class: CSCI 240
    Date: 09/03/2024  
    Description: Created a class derived from progression added in function to see a check to see if prime
    I certify that the code below is my own work.
    Exception(s): N/A
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>

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

class PrimeProgression : public Progression {
    protected:
    virtual void advance() override { 
        current++;  // increment 1 then continues to loop
        while (!checkPrime(current)) { // loop while if not true
            current++;  
        }
    }
        bool checkPrime(long number){ // function to check if number is prime
            if (number < 2){
                return false;
            } 
            for (long i = 2; i <= (static_cast<double>(sqrt(number))); ++i) { // convert into double for a proper sqrt value
                    if (number % i == 0){
                        return false;
                    }             
        }
        return true;
        }
    
    public: 
        PrimeProgression() : Progression(2){} // defaults to starting at 2

        PrimeProgression(long start) : Progression(start) { // starts from a number {
            if(checkPrime(current) == false){ // checks if current number is prime is false, then advance to display number that is false
                advance();
            }
        }
       
};

int main(){
    PrimeProgression start1;
    PrimeProgression start2(97);
    start1.print_progression(5);
    start2.print_progression(5);
    
}


