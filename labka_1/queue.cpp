#include <iostream>
#include <queue> // Include the standard queue library

template <typename T>
class Queue {
private:
    std::queue<T> elements; // Underlying container is std::queue

public:
    // Check if the queue is empty
    bool isEmpty() const {
        return elements.empty();
    }

    // Add an element to the back of the queue
    void enqueue(const T& value) {
        elements.push(value);
    }

    // Remove and return the front element
    T dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        T front = elements.front();
        elements.pop();
        return front;
    }

    // Return the front element without removing it
    T& peek() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty");
        }
        return elements.front();
    }
};

int main() {
    // Create a queue of integers
    Queue<int> myQueue;

    // Enqueue elements into the queue
    myQueue.enqueue(10);
    myQueue.enqueue(20);
    myQueue.enqueue(30);

    // Print the front element
    std::cout << "Front element: " << myQueue.peek() << std::endl;

    // Dequeue elements from the queue
    std::cout << "Dequeueing elements: ";
    while (!myQueue.isEmpty()) {
        std::cout << myQueue.dequeue() << " ";
    }
    std::cout << std::endl;

    return 0;
}
