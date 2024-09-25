#include <iostream>
#include <string>

using namespace std;

struct Node
{
    string name;
    Node* next;
   
};

Node* head = nullptr;
Node* tail = nullptr;
int numElements = 0; 

void insertRear(const std::string& name) {
    Node* newNode = new Node{name, nullptr}; // creates new node 
    if(head ==  nullptr){
        head = newNode;  //setting new head to the new node if there are no other elements
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;       // Update tail to the new node

    }
    numElements ++;
}

void insertFront(const std::string& name) {
    Node* newNode = new Node{name, head};  //creating a new node with data string and points to the head
    head = newNode;

    if (tail == nullptr){
        tail = newNode;
    }

    numElements++;
}

void removeElement(const std::string& name) {
    Node* temp = head;
    Node* prev = nullptr;

        if(temp->name == name && temp != nullptr){ // if head node set head to temp->next
          head = temp->next;  
          if(head == nullptr){ 
            tail = nullptr;
        }
        delete temp;
        numElements--;
        return;
        }
        while (temp != nullptr && temp->name != name){ // loop through nodes until name is found
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next; // sets previous node address to temp then delete temp
        

        delete temp;
        numElements--;
        
}

void printAll() { 
    Node* temp = head; // temp varible held at the head
    while(temp != nullptr){ // loop for every node not null
        cout << temp->name << " ";  //cout name of current node name 
        temp = temp->next;   //temp is then switched to next node address
    }
    cout << endl;
}


int main(){
    insertFront("Joe");
    insertRear("Jane");
    insertFront("John");
    insertRear("Bob");
    printAll();
  
    cout << "Number of elements: " << numElements << endl; 

    removeElement("Joe"); 
    removeElement("Bob"); 

    printAll(); 

}