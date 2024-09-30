// Write a C++ function that takes an array containing the set of all integers in the range 1 to 52 and shuffles it into random order. Use the rand() function from the <cstdlib> header, which returns a pseudorandom integer each time it is called. 
// Your function should produce each possible order with equal probability.


#include <iostream>
#include <cstdlib>

using namespace std;


int main(){
    
     while (!D.empty()) {
        Q.push(D.front());
        D.pop_front();
    }

   
    while (!Q.empty()) {
        D.push_back(Q.front());
        Q.pop();
    }

    for (const auto& num : D) {
       cout << num << " ";
}