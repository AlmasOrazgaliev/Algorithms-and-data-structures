#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

struct Node{
    string val;
    int cnt;
    Node* next;
    Node* prev;
    Node(string v){
        val = v;
        next = nullptr;
        prev = nullptr;
    }
    
};

int mx = -9999;
int cnt2=0;

class LinkedList{
public:
    Node* head;
    int sz;
    LinkedList(){
        head = nullptr;
        sz=0;
    }
    void pushfront(string val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
            sz++;
        }else{
            if(newNode->val == head->val){ 
                return ; 
            }
            else{
                newNode -> next = head;
                head = newNode;
                sz++;
            }
            
        }
    }
    // void pushfront(string val){
    //     Node* newNode = new Node(val);
    //     if(head == nullptr){
    //         head = newNode;
    //         sz++;
    //     }else{
    //         Node* cur = head;
    //         while(cur){
    //             if(cur -> val == val){
    //                 return;
    //             }
    //             cur = cur -> next;
    //         }
    //         sz++;
    //         head -> prev = newNode;
    //         newNode -> next = head;
    //         head = newNode;
    //     }
    // }
    int size(){
        return sz;
    }
    void print(){
        Node* cur = head;
        while(cur!=nullptr){
            cout<<cur->val<<endl;
            cur = cur -> next;
        }

    }
};

int main(){
    LinkedList arr;
    int n;
    cin>>n;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        arr.pushfront(s);
    }
    cout<<"All in all: "<<arr.size()<<endl;
    cout<<"Students:"<<endl;
    arr.print();
}
