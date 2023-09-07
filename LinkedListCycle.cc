// For soloving this problem we gonna use Hare and Tortoise Algor. slow->next and fast->next->next  if both hare and tortoise meet at same node there is a loop

#include <iostream>

using namespace std; 


class Node { 
    public:
        int value;
        Node* next;

        Node(int value) {
            this->value = value;
            next = nullptr;
        }
}; 


class LinkedList {
    private:
        Node* head;
        Node* tail;
        int length;

    public:
        LinkedList(int value) {
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
            length = 1;
        }

        void printList() {
            Node* temp = head;
            while (temp != nullptr) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        Node* getHead() {
            return head;
        }

        Node* getTail() {
            return tail;
        }

        int getLength() {
            return length;
        }

        void append(int value) {
            Node* newNode = new Node(value);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }
        bool hasLoop(){
            Node* slow = head;
            Node* fast = head;
            while (fast != nullptr && fast->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;
                if( slow == fast) { 
                    return true;
                }
            }
            return false;
        }

};

int main() {

    LinkedList list(1);
    list.append(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
 
// Creating a loop by making the next node of the last node (5) point to the second node (2)
    list.getTail()->next = list.getHead()->next;
 
// Calling the hasLoop() function should return true
    bool result = list.hasLoop(); 
}