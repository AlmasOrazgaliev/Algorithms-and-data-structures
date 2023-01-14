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
        cur=head;
    }
    void push_back(int val){
        if(head == nullptr){
            head = new node(val);
            cur = head;
        }else{
            cur->next = new node(val);
            cur=cur->next;
        }
    }
    void print_even(){
        node * cur = head;
        node * prev = nullptr;
        int index=0;
        while(cur!=nullptr){
            if(index%2==1){
                prev->next=cur->next;
                delete cur;
                cur=prev;
                cur=cur->next;
                index++;
                continue;
            }
            prev=cur;
            cur=cur->next;
            index++;
        }
        print();
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
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        list.push_back(x);
    }
    list.print_even();


}