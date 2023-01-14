#include<bits/stdc++.h>
using namespace std;
struct node{
    char val;
    node * next;
    node * prev;
    int cnt;
    node(char val){
        this->val = val;
        next = nullptr;
        prev = nullptr;
        cnt=0;
    }
};
class LinkedList{
private:
    node * head;
    node * tail;
public:
    LinkedList(){
        head = nullptr;
        tail = nullptr;
    }
    void push_back(char val){
        node * newNode = new node(val);
        if(head==nullptr){
            head = tail = newNode;
        }else{
            node * cur = head;
            while(cur!=nullptr){
                if(newNode->val==cur->val){
                    cur->cnt++;
                    newNode->cnt++;
                }
                else if(cur->next==nullptr){
                    cur->next=newNode;
                    return;
                }
                cur=cur->next;
            }
        }
    }
    void getNonRep(){
        node * cur = head;
        while(cur!=nullptr){
            if(cur->cnt==0){
                cout<<cur->val<<" ";
                return;
            }
            else if(cur->next==nullptr){
                cout<<"-1"<<" ";
                return;
            }
            cur=cur->next;
        }
    }
};
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        LinkedList list;
        char c;
        for(int j=0;j<x;j++){
            cin>>c;
            list.push_back(c);
            list.getNonRep();
        }
        cout<<endl;
    }
}