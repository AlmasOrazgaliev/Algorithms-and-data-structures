#include<bits/stdc++.h>
using namespace std;
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
        head = nullptr;
        tail = nullptr;
    }
    void push_back(int val){
        node * newNode = new node(val);
        if(head==nullptr){
            head = tail = newNode;
        }else{
            tail->next=newNode;
            tail = tail->next;
        }
    }
    int getMaxSub(){
        node * first = head;
        int max = -9999;
        while(first!=nullptr){
            int sum = first->val;
            if(max<sum){
                max= sum;
            }
            node * second = first->next;
            while(second!=nullptr){
                sum+=second->val;
                if(max<sum){
                    max=sum;
                }
                second=second->next;
            }
            first=first->next;
        }
        return max;
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
    cout<<list.getMaxSub();
}