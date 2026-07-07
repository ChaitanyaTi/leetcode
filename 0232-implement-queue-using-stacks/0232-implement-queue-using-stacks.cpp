#include <stack>

class MyQueue {
private:
    std::stack<int> input;
    std::stack<int> output;

    void shiftStacks() {
        if (output.empty()) {
            while (!input.empty()) {
                output.push(input.top());
                input.pop();
            }
        }
    }

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        input.push(x);
    }
    
    int pop() {
        shiftStacks();
        int frontElement = output.top();
        output.pop();
        return frontElement;
    }
    
    int peek() {
        shiftStacks();
        return output.top();
    }

    bool empty() {
        return input.empty() && output.empty();
    }
};