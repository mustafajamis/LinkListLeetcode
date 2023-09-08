#include <iostream>

using namespace std;

class Node {
    public:
        int value;
        Node* next;
        Node* prev;

    Node(int value){
        this->value = value;
        next = nullptr;
    }
};

class LinkList {
    private:
        Node* head;
        Node* tail;
        int length;
    public:
    LinkList(int value){
        Node* newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length  = 1;
    }
    ~LinkList(){
        Node* temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        // we creat a varable temp to set to head
        Node* temp = head;
        while (temp != nullptr) {
            cout<< temp->value<<endl; // value node that temp is point it to.
            temp = temp->next;
        }
    }
    void getHead() {
        if(head == nullptr){
            cout<<"head: nullptr"<<endl;
        } else {
            cout<< "head: "<<head->value<<endl;
        }
    }
    void getTail() {
        if(tail == nullptr){
            cout<<" tail: nullptr"<<endl;
        } else {
            cout<<"tail: "<<tail->value<<endl;
        }
    }

    void getLength(){
        cout<<"Length: "<<length<< endl;
    }
    void append(int value){
        Node* newNode = new Node(value);
        if( length == 0){
            tail = newNode;
            head = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }
    void deleteLast() {
    if (length == 0) return;
    Node* temp = head;
    if (length == 1) {
        head = nullptr;
        tail = nullptr;
    } else {
        Node* pre = head;
        while(temp->next) {
            pre = temp;
            temp = temp->next;
        }
        tail = pre;
        tail->next = nullptr;
    }
    delete temp;
    length--;
    }
    void Prepend(int value){
        Node* newNode = new Node(value);
        if( length == 0 ) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
            length++;
    }
    void deleteFirst(){
        if (length ==0) return;
        Node* temp =head;
        if (length == 1){
            head = nullptr;
            tail = nullptr;
        } else {
            head = head-> next;
        }
        delete temp;
        length--;
    }
    //return the pointer to the node at the particullar index
    Node* get(int index){
    if (index < 0 || index >= length) return nullptr;
    Node* temp = head;
    if (index < length/2) {
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
    } else {
        temp = tail;
        for (int i = length - 1; i > index; --i) {
            temp = temp->prev;
        }
    }
    return temp;
}
};


main () {
    LinkList* myLinkList = new LinkList(2);
    myLinkList->append(3);
    myLinkList->Prepend(1);
    myLinkList->printList();

   /* cout << "LL before deleteLast():\n";
    myLinkList->printList();


    myLinkList->deleteLast();
    cout << "\n\nLL after 1st deleteLast():\n";
    myLinkList->printList();


    myLinkList->deleteLast();
    cout << "\n\nLL after 2nd deleteLast():\n";
    myLinkList->printList();


    myLinkList->deleteLast();
    cout << "\n\nLL after 3rd deleteLast():\n";
    myLinkList->printList();
*/
}