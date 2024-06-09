#include<iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = nullptr;
    }
};

class linkedList {
public:
    Node* head;
    Node* tail;
    int size;

    linkedList() {
        head = tail = nullptr;
        size = 0;
    }

    void insertAtEnd(int val) {
        Node* temp = new Node(val);
        if (size == 0) 
            head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void insertAtHead(int val){
        Node* temp = new Node(val);
        if(size == 0){
            head = tail = temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void insert(int idx, int val){
        if(idx < 0 || idx > size) cout<<"invalid index!!"<<endl;
        else if(idx == 0) insertAtHead(val);
        else if(idx == size) insertAtEnd(val);
        else{
            Node* temp = head;
            Node* t = new Node(val);
            for(int i = 0;i<idx-1;i++){
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            size++;
            // if(idx == (size - 1)){
            //     tail = tail->next;
            // }
        }
    }
    int getAtIdx(int idx){
        if(idx < 0 || idx >= size) {
            cout<<"invalid index!!"<<endl;
            return -1;
        }
        else if(idx == 0) return head->val;
        else if(idx == size) return tail->val;
        else{
            Node* temp = head;
            for(int i = 0;i<idx;i++){
                temp = temp->next;
            }
            return temp->val;
    }
    }
        void deleteAtHead(){
            if(size == 0){
                cout<<"list is empty"<<endl;
                return;
            }
            head = head->next;
            size --;
        }
        void deleteAtTail(){
            if(size == 0){
                cout<<"list is empty"<<endl;
                return;
            }
            Node* temp = head;
            while(temp->next!= tail){
                temp = temp->next;
            }
            temp->next = NULL;
            tail = temp;
            size--;
        }
        void deleteAtIdx(int idx){
            if(idx < 0 || idx >= size ){
                cout<<"invalid index!!"<<endl;
                return;
            }
            else if(idx == 0) deleteAtHead();
            else if(idx == size-1) deleteAtTail();
            else{
                Node* temp = head;
                for(int i = 0;i<idx-1;i++){
                    temp = temp->next;
                }
                temp->next = temp->next->next;
                size--;
            }
        }
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
