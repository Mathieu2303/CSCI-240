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

int filteringArrayData(int arr[], int limitAmount){
    int count = 0;
    for(int i = 0; i < limitAmount; i++){
      for(int j = i + 1; j < limitAmount; j++){
            if(arr[i] == arr[j]){
                count++;
            }
      }
    }
    return count;
}

int storingRandomValuesInArray(int numberOfStudents){ //number of students = n
    int studentArray[100];
    for(int i = 0; i <= numberOfStudents; i++){ //pushing random values into array to be filtered
            studentArray[i] = (rand() % 365);
        }
    int count = filteringArrayData(studentArray, numberOfStudents);
    return count;
}

int main(){
    cout << "N" << "\t" << "duplicates after 100 tests" << endl;
    for(int i = 5; i <= 100; i += 5){
        int duplicates = storingRandomValuesInArray(i);
        cout << i << "\t" << duplicates << endl;
    }


}