#include<bits/stdc++.h>
using namespace std;
struct node{
    string val;
    node * next;
    node * prev;
    node(string val){
        this->val=val;
        next = prev = nullptr;
    }
};
class LinkedList{
public:
    node * head;
    node * tail;
    LinkedList(){
        head=nullptr;
        tail=nullptr;
    }
    void add_front(string val){
        node* newNode = new node(val);
        if(!head){
            head = tail = newNode;
        }
        else{
            newNode -> next = head;
            head -> prev = newNode;
            head = newNode;
        }
    }
    void add_back(string val){
        node * newNode = new node(val);
        if(!head){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void erase_front(){
        if(head == nullptr){
            cout<<"error"<<endl;
            return;
        }
        cout<<front()<<endl;
        if(!head -> next){
            head = tail = nullptr;
        }else{
            head = head -> next;
            head -> prev = nullptr;
        }
    }
    void erase_back(){
        if(head == nullptr){
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
    }
    string front(){
        if(head != nullptr )return head->val;
        else return "error";
    }
    string back(){
        if(head != nullptr )return tail->val;
        else return "error";   
    }
    void clear(){
        head = nullptr;
        tail = nullptr;
    }
};
int main(){
    LinkedList list;
    string s,c;
    while(true){
        cin>>s;
        if(s=="add_front"){
            cin>>c;
            list.add_front(c);
            cout<<"ok"<<endl;
        }
        else if(s=="add_back"){
            cin>>c;
            list.add_back(c);
            cout<<"ok"<<endl;
        }
        else if(s=="erase_front"){
            list.erase_front();
        }
        else if(s=="erase_back"){
            list.erase_back();
        }
        else if(s=="front"){
            cout<<list.front()<<endl;
        }
        else if(s=="back"){
            cout<<list.back()<<endl;
        }
        else if(s=="clear"){
            list.clear();
            cout<<"ok"<<endl;
        }
        else if(s=="exit"){
            cout<<"goodbye";
            return 0;
        }
    }
}