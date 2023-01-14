#include<bits/stdc++.h>
using namespace std;
int size=0;
struct node{
    string val;
    node * next;
    node(string val){
        this->val=val;
        next=nullptr;
    }
};
class LinkedList{
private:
    node * head;
public:
    LinkedList(){
        head= nullptr;
    }
    void push_front(string val){
        node * newNode = new node(val);
        if(head==nullptr){
            head = newNode;
            size++;
        }else{
            if(newNode->val == head->val){
                return ;
            }else{
                newNode->next= head;
                head = newNode;
                size++;
            }
        }
    }
    void print(){
        cout<<"All in all: "<<size<<endl;
        cout<<"Students:"<<endl;
        node * cur=head;
        while(cur!=nullptr){
            cout<<cur->val<<endl;
            cur=cur->next;
        }
    }
};
int main(){
    LinkedList list;
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        list.push_front(s);
    }
    list.print();
}