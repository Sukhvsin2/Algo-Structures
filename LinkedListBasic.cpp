#include <iostream>

using namespace std;

class Linkedlist{
    struct Node{
        int data;
        Node* link;
    } *head;
    
    public:
        Linkedlist();
        void append(int);
        void addAtBeg(int);
        void addAfter(int, int);
        void display();
        int count();
        void del(int);
        //~Linkedlist();
};

Linkedlist :: Linkedlist(){
    head = nullptr;
}
void Linkedlist::append(int num){
    Node *temp = head;
    if(temp == nullptr || temp->link == nullptr){
        temp = new Node();
        temp->data = num;
        temp->link = nullptr;
        head == nullptr ? head = temp : head->link = temp;
    }else{
        Node *newTemp = new Node();
        newTemp->data = num;
        newTemp->link = nullptr;
        while(temp->link != nullptr){
            temp = temp->link;
        }
        temp->link = newTemp;
    }
}

void Linkedlist::addAtBeg(int num){
    Node *temp = new Node();
    temp->data = num;
    if(temp == nullptr){
        temp->link = nullptr;
        head = temp;
    }else{
        temp->link = head;
        head = temp;
    }
}

void Linkedlist::addAfter(int loc, int num){
    Node* curr = head, *temp;
    loc--;
    while(curr->link!=nullptr && loc--){
        curr = curr->link;
    }
    
    temp = new Node();
    temp->data = num;
    temp->link = curr->link;
    curr->link = temp;
}

void Linkedlist::display(){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->link;
    }
}

void del(int num){
    Node *temp = head, *prev;
    while(temp!=nullptr && temp->link != nullptr && temp->data != num){
        prev = temp;
        temp = temp->link;
    }
    
}

int main()
{
    Linkedlist l1;
    l1.append(10);
    l1.append(20);
    l1.append(30);
    l1.append(40);
    l1.addAfter(4, 33);
    l1.addAtBeg(0);
    l1.addAtBeg(-100);
    l1.display();

    return 0;
}






