#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
class LinkedList{
public:
    Node* head;
    int size;
    LinkedList(){
        head = NULL;
        size = 0;
    }
    void insertAtEnd(int val){
        Node* temp = new Node(val);
        Node* t = head;
        if(size==0){
            head=temp;
        }
        else{
            while(t->next!=NULL){
                t = t->next;
            }
            t->next = temp;
        }
        size++;
    }
    void insertAtHead(int val){
        Node* temp = new Node(val);
        if(size==0){
            head=temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void insertAtIndex(int idx,int val){
        if(idx<0 || idx>=size){
            cout<<"Invalid Idx";
        }
        else if(idx==0) insertAtHead(val);
        else if(idx==size) insertAtEnd(val);
        else{
            Node* temp = new Node(val);
            Node* t = head;
            for(int i=1;i<=idx-1;i++){
                t=t->next;
            }
            temp->next = t->next;
            t->next = temp;
            size++;
        }
    }
    int getAtIdx(int idx){
        if(idx<0 || idx>=size){
            cout<<"Invalid Idx";
            return -1;
        }
        else if(idx==0) return head->val;
        else{
            Node* temp = head;
            for(int i=1;i<=idx;i++){
                temp = temp->next;
            }
            return temp->val;
        }
    }
    void deleteAtHead(){
        if(size==0){
            cout<<"list is empty";
        }
        else{
            head = head->next;
            size--;
        }
    }
    void deleteAtTail(){
        if(size==0){
            cout<<"list is empty";
        }
        else{
            Node* temp = head;
            while(temp->next->next!=NULL){
                temp = temp->next;
            }
            temp->next = NULL;
            size--;
        }
    }
    void deleteAtIdx(int idx){
        if(idx<0 || idx>=size){
            cout<<"Invalid Idx";
        }
        else if(idx==0) deleteAtHead();
        else if(idx==size-1) deleteAtTail();
        else{
            Node* temp = head;
            for(int i=1;i<=idx-1;i++){
                temp = temp->next;
            }
            temp->next = temp->next->next;
            size--;
        }
    }
    void display(){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};
int main(){
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.display();
    ll.insertAtEnd(20);
    ll.display();
    ll.insertAtEnd(30);
    ll.display();
    ll.insertAtHead(40);
    ll.display();
    ll.insertAtHead(50);
    ll.display();
    ll.insertAtIndex(2,60);
    ll.display();
    ll.insertAtIndex(3,70);
    ll.display();
    cout<<ll.getAtIdx(3)<<endl;
    ll.deleteAtHead();
    ll.display();
    ll.deleteAtTail();
    ll.display();
    ll.deleteAtIdx(3);
    ll.display();
    cout<<ll.size;
}