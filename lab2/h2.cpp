#include<bits/stdc++.h>
using namespace std;
int lastPop;
int size;
struct node{
    int val;
    node * next;
    node(int val){
        this->val=val;
        next = nullptr;
    }
};
class LinkedList{
private:
    node * head;
    node * tail;
public:
    LinkedList(){
        head = tail = nullptr;
    }
    void push(int val,int index){
        node * newNode = new node(val);
        if(head==nullptr){
            head = tail = newNode;
            
        }else{
            int cnt=0;
            node * cur =head;
            if(index==0){
                newNode->next=head;
                head=newNode;
                return;
            }
            while(cur!=nullptr){
                if(cnt+1==index){
                    newNode->next=cur->next;
                    cur->next=newNode;
                    return;
                }
                cnt++;
                cur=cur->next;
            }
        }
    }
    void pop(int index){
        if(index==0){
            lastPop=head->val;
            head=head->next;
        }else{
            node * cur = head;
            node * prev = nullptr;
            int cnt=0;
            while(cur!=nullptr){
                if(cnt==index){
                    prev ->next = cur->next;
                    lastPop=cur->val;
                    delete cur;
                    return;
                }
                prev = cur;
                cur=cur->next;
                cnt++;
            }
        }
    }
    void reverse(){
        node * next = nullptr;
        node * prev = nullptr;
        node * cur = head;
        while(cur!=nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        head = prev;
    }
    void change(int index1,int index2){
        pop(index1);
        push(lastPop,index2);
    }
    void print(){
        if(head==nullptr){
            cout<<"-1"<<endl;
            return;
        }
        node * cur=head;
        while(cur!=nullptr){
            cout<<cur->val<<" ";
            cur=cur->next;
        }
        cout<<endl;
    }
    void leftShift(int k){
        if(k==0 || k==size){
            return;
        }
        int cnt=0;
        node * tail = head;
        while(tail->next!=nullptr){
            tail=tail->next;
        }
        while(cnt!=k){
            node * cur = head;
            tail->next=cur;
            head=head->next;
            cur->next=nullptr;
            tail=tail->next;
            cnt++;
        }
    }
    void rightShift(int k){
         int nth=size-k;
         leftShift(nth);
        
    }
};
int main(){
    LinkedList list;
    int n;
    while(true){
        cin>>n;
        if(n==1){
            int val,index;
            cin>>val>>index;
            list.push(val,index);
            size++;
        }
        else if(n==2){
            int index;
            cin>>index;
            list.pop(index);
            size--;
        }
        else if(n==3){
            list.print();
        }
        else if(n==4){
            int index1,index2;
            cin>>index1>>index2;
            list.change(index1,index2);
        }
        else if(n==5){
            list.reverse();
        }else if(n==6){
            int k;
            cin>>k;
            list.leftShift(k);
        }
        else if(n==7){
            int k;
            cin>>k;
            list.rightShift(k);
        }
        else if(n==0){
            break;
        }
    }
}