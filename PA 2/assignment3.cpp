#include <iostream>
#include <array>
#include <string>

using namespace std;

int const SIZE = 10;
string arr[SIZE];
int numElements = 0;


void insertRear(const string& input){ //allows for the name to be read only
    if(numElements < SIZE){  //check to see if max capacity
        arr[numElements] = input;
        numElements++;
    }
    
    else{
        cout << "array at max" << endl;
    }
}
void insertAt(int index, string input){
    if(SIZE > numElements && index <= numElements){
        for(int i = numElements; i > index; i--){ // starting from the end and incrimenting down 
            arr[i] = arr[i - 1]; // arr new index will be one behind
        }
    arr[numElements] = input; // arr at index will be inserted
    numElements++;
    }
    else{
       cout << "Array is full." << endl;
    }
    
}
void removeAt(int index){
    if(index < numElements){
        for(int i = index; i < numElements - 1; i++){ //starting from the index point and working down 
            arr[numElements] = arr[numElements + 1];
    }
    arr[numElements - 1].clear(); // get rid of last element
    numElements--;
    }
    
}

void printAll(){
    for (int i = 0; i < SIZE; i++){
        cout <<" " << arr[i];
    }
    cout << endl;
}

int main(){
 

    insertRear("John");
    insertRear("Amy");
    insertRear("Alice");
    insertAt(2, "Cris");
    printAll();
    removeAt(2);
    insertRear("Collin");
    printAll();
}
