// To solve the findingMiddleNode we're using the Hare and TorTios Algorithm which basically Hare is moving by one step and Tortios moving two steps
// when the Tortios reach the end of the node and Hare will step one more and that location will be the middle of Node. Remember it's O(1)

#include <iostream>

using namespace std;
// creating node
class Node{
    public: 
        int value;
        Node* next;
    Node(int value){
        this->value = value;
        next = nullptr;
    }
};
// LinkList class
class LinkList {
    private:
        Node* head;
        Node* tail;
    public:
       LinkList(int value){
            Node* newNode = new Node(value);
            head = newNode;
            tail = newNode;
       }
       ~LinkList(){
        Node* temp = head;
            while(head){
            head = head->next;
            delete temp;
            temp = head;
            }
       }
        // PrintList function to print the value
        void PrintList(){
        Node* temp = head;
        while (temp != nullptr){
            cout<<temp->value<<endl;
            temp = temp->next;
        }
       }
       // getHead Function
        void getHead() {
        if(head == nullptr){
            cout<<"head: nullptr"<<endl;
        } else {
            cout<< "head: "<<head->value<<endl;
            }
        }
        // getTail Function
        void getTail(){
            if(head == nullptr){
                cout<<"tail: nullptr"<<endl;
            } else {
                cout<<"tail: "<<tail->value<<endl;
            }
        }
        // append function to add Node at end of linklist 
        void append(int value){
            Node* newNode = new Node(value);
            if(head == nullptr){
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        Node* findMiddleNode(){
            Node* slow = head;
            Node* fast = head;
            while(fast != nullptr && fast->next != nullptr){
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
};

int main(){
    LinkList* myLinkList = new LinkList(1);
    myLinkList->append(2);
    myLinkList->append(3);
    myLinkList->append(4); 
    myLinkList->append(5); 
    cout<<"The Orginal list: ";
    myLinkList->PrintList();
    
    Node* middle = myLinkList->findMiddleNode();
    cout<<"Middle is: "<<middle->value;
}