#include<bits/stdc++.h>
using namespace std;
int ind=0;
struct node{
    long long val;
    long long index;
    long long absVal;
    node * next;
    node(long long val){
        this->val=val;
        index=0;
        absVal=0;
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
    void push_back(long long val){
        if(head==nullptr){
            head=new node(val);
            head->index=ind;
            cur = head;
        }else{
            cur->next=new node(val);
            cur = cur->next;
        }
    }
    long long getClosest(long long val){
        node * cur = head;
        int long long min=INTMAX_MAX;
        int closest=0;
        int index=0;
        while(cur!=nullptr){
            //cout<<index<<endl;
            cur->absVal=abs(cur->val-val);
            //cout<<cur->val<<" "<<cur->absVal<<" "<<cur->index<<endl;
            if(min>cur->absVal){
                min = cur->absVal;
                closest = index;
            }
            index++;
            cur=cur->next;
        }
        return closest;
    }
};
int main(){
    LinkedList list;
    long long n;
    cin>>n;
    long long x;
    for(int i=0;i<n;i++){
        cin>>x;
        list.push_back(x);
    }
    long long k;
    cin>>k;
    cout<<list.getClosest(k);
}