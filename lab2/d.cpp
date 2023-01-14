#include<bits/stdc++.h>
using namespace std;
int maxMode=1;
struct node{
    int val;
    node * next;
    int cnt;
    node(int val){
        this->val=val;
        next=nullptr;
        cnt=1;
    }
};
class LinkedList{
private:
    node * head;
    node * cur;
public:
    LinkedList(){
        head = nullptr;
        cur= head;
    }
    void push_back(int val){
        node * newNode = new node(val);
        if(head== nullptr){
            head=newNode;
        }else{
            node * cur = head;
            while(cur!=nullptr){
                if(cur->val==val){
                    cur->cnt++;
                    if(cur->cnt>=maxMode){
                        maxMode = cur->cnt;
                    }
                    return;
                }
                else if(cur->next == nullptr){
                    cur->next = newNode;
                    return;
                }
                cur=cur->next;
            }
        }
    }
    void mod(){
        //cout<<maxMode<<endl;
        node * first = head;
        node * second = nullptr;
        while(first->next!=nullptr){
            second=first->next;
            while(second!=nullptr){
                if(second->val>first->val){
                    swap(second->val,first->val);
                    swap(second->cnt,first->cnt);
                }
                second = second->next;
            }
            first=first->next;
        }
        node * cur = head;
        while(cur!=nullptr){
            if(cur->cnt==maxMode){
                cout<<cur->val<<" ";
            }
            cur=cur->next;
        }
    }
    void print(){
        node * cur = head;
        while(cur!=nullptr){
            cout<<cur->val<<" "<<cur->cnt<<endl;
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
    list.mod();
    //list.print();
}