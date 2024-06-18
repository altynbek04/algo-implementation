#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
    }

    void insertAtBeginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* last = head;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = newNode;
    }

    void deleteNode(int key) {
        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            return;
        }

        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) return;

        prev->next = temp->next;
        delete temp;
    }

    void printList() {
        Node* node = head;
        while (node != nullptr) {
            std::cout << node->data << " ";
            node = node->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    LinkedList list;

    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtBeginning(0);
    list.insertAtEnd(3);

    std::cout << "Linked list: ";
    list.printList();

    list.deleteNode(2);
    std::cout << "Linked list after deletion: ";
    list.printList();

    return 0;
}
