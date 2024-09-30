#include <iostream>
#include "doubly_linked.h"

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

            
         }
         void right() {
            if(cursor != text.end()){
                cursor++;
            }
         } 
       void insert(char c) {
        if (cursor == text.end()) {
            text.push_back(c); // Insert at the end if cursor is at the end
        } else {
            cursor = text.insert(cursor, c); // Insert at the cursor position
        }
    }

         void remove()  {
            if (cursor != text.begin()){
        auto removeCursor = cursor;
                removeCursor--;
                text.erase(removeCursor);
            }
         }
         void first() {
            cursor =  text.begin();
         } 
         void last() {
            cursor = text.end();
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
    
    TextEditor editor("hHello Word"); // Create a TextEditor object with “hHello Word”
    
   editor.display();
    
    editor.right();   // 2. Move cursor right (nothing happens)
    
    editor.left();    // 3. Move cursor left
    editor.insert('l'); // 4. Insert 'l'
    
    editor.display(); // 5. Display current information (“hHello Worl|d”)
    
    editor.first();   // 6. Move cursor to the beginning
    editor.left();    // 7. Move cursor left (nothing happens)
    
    editor.right();   // 8. Move cursor right
    editor.remove();  // 9. Remove character
    
    editor.last();    // 10. Move cursor to the end
    editor.display(); // 11. Display current information (“Hello World|”)
}