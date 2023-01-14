#include<bits/stdc++.h>
using namespace std;
struct Node{
    string val;
    Node * next;
    Node * prev;
    Node(string val){
        this->val=val;
        next=nullptr;
        prev=nullptr;
    }
};
class Deque{
    int sz;
    public:
    Node* head;
    Node* tail;
    Deque(){
        sz = 0;
        head = nullptr;
        tail = nullptr;
    }
    void add_front(string val){
        Node* newNode = new Node(val);
        if(!head){
            head = tail = newNode;
        }
        else{
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
        ++sz;
    }
    void add_back(string val){
        Node* newNode = new Node(val);
        if(!head){
            head = tail = newNode;
        }
        else{
            tail -> next = newNode;
            newNode -> prev = tail;
            tail = newNode;
        }
        ++sz;
    }
    void erase_front(){
        if(sz==0){
            cout<<"error"<<endl;
            return;
        }
        cout<<front()<<endl;
        if(!head -> next){
            head = tail = nullptr;
        }else {head = head -> next;head -> prev = nullptr;}
        --sz;
    }
    void erase_back(){
        if(sz==0){
            cout<<"error"<<endl;
            return;
        }
        cout<<back()<<endl;
        if(tail -> prev){
            tail = tail -> prev;
            tail -> prev -> next = nullptr;
        }else{
            head = tail = nullptr;
        }
        --sz;
    }
    string front(){
        if(sz!=0)return head->val;
        else return "error";
    }
    string back(){
        if(sz!=0)return tail->val;
        else return "error";
        
    }
    int size(){
        return sz;
    }
    void clear(){
        head = nullptr;
        tail = nullptr;
        sz = 0;
    }
    void print(){
        Node* cur = head;
        while(cur){
            cout<<cur -> val<<" ";
            cur = cur -> next;
        }
    }
};

int main(){
    Deque dq;
    while(true){
        string s;
        cin>>s;
        if(s=="exit"){
            cout<<"goodbye"<<endl;
            return 0;
        }
        if(s=="add_back"){
            string x;
            cin>>x;
            dq.add_back(x);
            cout<<"ok"<<endl;
        }
        else if(s=="add_front"){
            string x;
            cin>>x;
            dq.add_front(x);
            cout<<"ok"<<endl;
        }
        else if(s=="erase_back"){
            dq.erase_back();
        }
        else if(s=="erase_front"){
            dq.erase_front();
        }
        else if(s=="back"){
            cout<<dq.back()<<endl;;
        }
        else if(s=="front"){
            cout<<dq.front()<<endl;
        }
        else if(s=="clear"){
            dq.clear();
            cout<<"ok"<<endl;
        }
    }

}
