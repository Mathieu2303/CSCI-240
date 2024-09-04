/*  Program: Exercise 1 
    Author: Mathieu Partain-Martinez
    Class: CSCI 240 
    Date: 08/28/2024  
    Description: 
    I certify that the code below is my own work.
    Exception(s): N/A
*/
#include <iostream>

using namespace std;

int filteringArrayData(int arr[], int limitAmount){
    bool duplicate = false;
    int count;
    for(int i = 0; i < limitAmount; i++){
      for(int j = i + 1; j < limitAmount; j++){
            if(arr[i] == arr[j]){
                count++;
            }
      }
    }
    return count;
}


int main()
{
    int sample_array1[] = {5, 7, 2, 6, 4};
    int array_size1 = sizeof(sample_array1) / sizeof(int);
    int sample_array2[] = {5, 7, 2, 2, 5,6,4,2};
    int array_size2 = sizeof(sample_array2) / sizeof(int);
    int results_for_array1 = filteringArrayData(sample_array1, array_size1);
    int results_for_array2 = filteringArrayData(sample_array2, array_size2);
    cout << "Duplicates for Array 1: " << results_for_array1 << endl;
    cout << "Duplucates for Array 2: " << results_for_array2 << endl;
    return 0;
}