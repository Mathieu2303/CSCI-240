#include <iostream>

#include "singly_linked.h"

using namespace std;
using dsac::list::SinglyLinkedList;



int main(){

    SinglyLinkedList<string> myList;
    SinglyLinkedList<string>::iterator it;

    myList.push_front("Two");
    myList.push_back("Three");
    myList.push_front("One");
    myList.push_back("Four");
    it = myList.begin(); //declare iterator at the beginning of the list;
    for(it; it != myList.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
    it = myList.begin();
    it++;
    it++;
    myList.insert_after(it, "Mathieu");
    it++;
    myList.pop_front();
    myList.erase_after(it);
   
    it = myList.begin();

   for(it; it != myList.end(); it++){
        cout << *it << " ";
    }
    cout << endl;
}