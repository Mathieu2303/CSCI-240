#include <iostream>

using namespace std;


int findingTargetSumInArray(int arr[], int size, int goal){
    int sum;
    for(int i = 0; i < size; i++){
        for(int j = 1; i < size; i++){

            if (arr[i] + arr[j] == goal){
                sum = arr[i] + arr[j];
                cout << "goal has been satisfed " << endl;
                cout << "Index: " << i << " Value: " << arr[i] << endl; 
                cout << "Index: " << j << " Value:" << arr[j] << endl;;
            }

        }

    }
    return sum;
}

int main(){
    int const SIZE = 10;
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int goal;
    cout << "Enter in target sum for the array " << endl;
    for(int i = 0; i < SIZE; i++){
        cout << " " << arr[i];
    }
    cout << endl;
    cout << "Goal: ";
    cin >> goal;
    findingTargetSumInArray(arr, SIZE, goal); 
}