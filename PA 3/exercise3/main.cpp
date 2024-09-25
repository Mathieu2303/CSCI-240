#include <iostream>
#include "doubly_linked.h"
#include <string>

using namespace std;
using namespace dsac::list;


class TextEditor{
    private:
        dsac::list::DoublyLinkedList<char>text; // from the class doublylinkedlist
        dsac::list::DoublyLinkedList<char>::iterator cursor; // from doubly linked list set up iterator
    public:
        TextEditor(const string& intialInput){ // creates a default constructor for the string that will set the cursor to the end
                for (char c : intialInput){
                    text.push_back(c);
                }
            cursor = text.end();
        }
        void left() {
            if (cursor != text.begin()) //since cursor starts at the end incriment down by 1;
                cursor--;

            cout << "Move left" << endl;
           
         }
         void right() {
            if(cursor != text.end()){
                cursor++;
                cout << "Move right" << endl;
            }
            else{
                cout << " Tried to move right but nothing happened" << endl;
            }
            
         }
       void insert(char c) {
        if (cursor == text.end()) {
            text.push_back(c); // Insert at the end if cursor is at end
        } else {
            text.insert(cursor, c); // Insert at the cursor position
           
        }
    }


         void remove()  {
            if (cursor != text.begin()){
        auto removeCursor = cursor; // allows for object to be defined within a temp variable 
                removeCursor--;
                text.erase(removeCursor);
                cout << "Item removed " << endl;
            }
         }
         void first() {
            cursor =  text.begin();
            cout << "first" << endl;
         }
         void last() {
            cursor = text.end();
            cout << "last" << endl;
         }


        void display() {
           
            auto it = text.begin(); // set an it at the front
            int elementCounter = 0;
            while(it != text.end()){
                if (it == cursor)
                    cout << "|";
                cout << *it;
                it++;
                elementCounter++;
            }
           
            if (cursor == text.end()){
                cout << "|";
            }
            cout << endl;
            cout << "Number of char: " << elementCounter << endl;
         }
};




int main(){
   
    TextEditor editor("hHello Word"); 
   
    editor.display();
    
    editor.right();
    editor.left();  
   
    editor.insert('l'); 
   
    editor.display();
   
    editor.first();   
    editor.left();   
   
    editor.right();   
    editor.remove();  
   
    editor.last();   
    editor.display(); 
}
