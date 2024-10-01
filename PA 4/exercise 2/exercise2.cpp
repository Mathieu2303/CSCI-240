#include <iostream>


using namespace std;

template <typename T>
class MyArrayStack{
private:
    int const SIZE = 10;
    int array[SIZE];
public:


    void size(){
        
        int counter = 0;
        
            }
                
        }
    }
    void empty(){}
    void top(){}
    void push(template T){}
    void pop(){}
    
    int evaluatePostfix(const std::string &expression) {
    MyArrayStack<int> stack;
    std::stringstream ss(expression);
    std::string token;

    while (ss >> token) {
        if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1)) {
            stack.push(std::stoi(token));
        } else {
            int op2 = stack.pop();
            int op1 = stack.pop();
            if (token == "+") stack.push(op1 + op2);
            else if (token == "-") stack.push(op1 - op2);
            else if (token == "*") stack.push(op1 * op2);
            else if (token == "/") stack.push(op1 / op2);
        }
    }

    return stack.top();
}
};
int main(){

}