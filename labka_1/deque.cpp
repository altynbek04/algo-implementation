#include <iostream>
#include <deque> // Include the standard deque library

template <typename T>
class Deque {
private:
    std::deque<T> elements; // Underlying container is std::deque

public:
    // Check if the deque is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Add an element to the front of the deque
    void pushFront(const T& value) {
        elements.push_front(value);
    }

    // Remove and return the front element
    T popFront() {
        if (isEmpty()) {
            throw std::out_of_range("Deque is empty");
        }
        T front = elements.front();
        elements.pop_front();
        return front;
    }

    // Add an element to the back of the deque
    void pushBack(const T& value) {
        elements.push_back(value);
    }

    // Remove and return the back element
    T popBack() {
        if (isEmpty()) {
            throw std::out_of_range("Deque is empty");
        }
        T back = elements.back();
        elements.pop_back();
        return back;
    }

    // Return the front element without removing it
    T& front() {
        if (isEmpty()) {
            throw std::out_of_range("Deque is empty");
        }
        return elements.front();
    }

    // Return the back element without removing it
    T& back() {
        if (isEmpty()) {
            throw std::out_of_range("Deque is empty");
        }
        return elements.back();
    }
};

int main() {
    // Create a deque of integers
    Deque<int> myDeque;

    // Push elements to the front and back of the deque
    myDeque.pushFront(10);
    myDeque.pushBack(20);
    myDeque.pushFront(5);

    // Print the front and back elements
    std::cout << "Front element: " << myDeque.front() << std::endl;
    std::cout << "Back element: " << myDeque.back() << std::endl;

    // Pop elements from the front and back of the deque
    std::cout << "Popping front element: " << myDeque.popFront() << std::endl;
    std::cout << "Popping back element: " << myDeque.popBack() << std::endl;

    return 0;
}
