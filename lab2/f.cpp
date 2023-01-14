#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node * next;
    node(int val){
        this->val=val;
        next=nullptr;
    }
};
class LinkedList{
private:
    node * head;
    node * cur;
public:
    LinkedList(){
        head=nullptr;
        cur = head;
    }
    void push_back(int val){
        node * newNode = new node(val);
        if(head == nullptr){
            head = newNode;
            cur = head;
        }else{
            cur->next = newNode;
            cur=cur->next;
        }
    }
    void push_inIndex(int val, int index){
        int cnt=0;
        node * newNode = new node(val);
        node * cur = head;
        node * temp = head->next;
        while(cur!=nullptr){
            if(index==0){
                newNode->next = head;
                head = newNode;
                return;
            }
            if(cnt==index-1){
                cur->next = newNode;
                newNode->next=temp;
                return;
            }
            cur=cur->next;
            temp=temp->next;
            cnt++;
        }
    }
    void print(){
        node * cur = head;
        while(cur!=nullptr){
            cout<<cur->val<<" ";
            cur=cur->next;
        }
    }
};
int main(){
    LinkedList list;
    int n;
    cin>>n;
    int c;
    for(int i=0;i<n;i++){
        cin>>c;
        list.push_back(c);
    }
    int val,index;
    cin>>val>>index;
    list.push_inIndex(val,index);
    list.print();
}