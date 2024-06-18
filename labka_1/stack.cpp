#include <iostream>
#include <vector>
#include <stdexcept> // For std::out_of_range exception

template <typename T>
class Stack {
private:
    std::vector<T> elements;

public:
    // Check if the stack is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Push element onto the stack
    void push(const T& value) {
        elements.push_back(value);
    }

    // Remove and return the top element
    T pop() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        T top = elements.back();
        elements.pop_back();
        return top;
    }

    // Return the top element without removing it
    T& peek() {
        if (isEmpty()) {
            throw std::out_of_range("Stack is empty");
        }
        return elements.back();
    }
};

int main() {
    // Create a stack of integers
    Stack<int> myStack;

    // Push elements onto the stack
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // Print the top element
    std::cout << "Top element: " << myStack.peek() << std::endl;

    // Pop elements from the stack
    std::cout << "Popping elements: ";
    while (!myStack.isEmpty()) {
        std::cout << myStack.pop() << " ";
    }
    std::cout << std::endl;

    return 0;
}
