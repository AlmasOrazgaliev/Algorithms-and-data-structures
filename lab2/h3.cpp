#include <iostream>
 
using namespace std;
 
struct Node{
    int val;
    Node* next;
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(Node* next): val(0), next(next) {}
    Node(int x, Node* next): val(x), next(next) {}
};
int lastPop=0;
int size=0;
Node* insert(Node* head, Node* node, int p){
    /* write your code here */
    if(head==nullptr){
        head = node;
    }else{
        int cnt=0;
        Node * cur = head;
        if(p==0){
            node->next=head;
            head=node;
            return head;
        }
        while(cur!=nullptr){
            if(cnt+1==p){
                node->next=cur->next;
                cur->next=node;
                return head;
            }
            cnt++;
            cur=cur->next;
        }
    }
    return head;
}
 
Node* remove(Node* head, int p){
    /* write your code here */
    if(p==0){
        lastPop=head->val;
        head=head->next;
    }else{
        Node  * cur=head;
        Node * prev = nullptr;
        int cnt=0;
        while(cur!=nullptr){
            if(cnt==p){
                prev->next=cur->next;
                lastPop=cur->val;
                delete cur;
                return head;
            }
            prev = cur;
            cur=cur->next;
            cnt++;
        }
    }
    return head;
}
 
Node* replace(Node* head, int p1, int p2){
    /* write your code here */
    head= remove( head,p1);
    head=insert( head, new Node(lastPop),p2);
    return head;   
}
 
Node* reverse(Node* head){
    Node  * next = nullptr;
    Node * prev = nullptr;
    Node * cur=head;
    while(cur!=nullptr){
        next = cur->next;
        cur->next=prev;
        prev = cur;
        cur=next;
    }
    head= prev;
    return head;
}
 
void print(Node* head){
    /* write your code here */
    Node * cur=head;
    while(cur!=nullptr){
        cout<<cur->val<<" ";
        cur=cur->next;
    }
}
 
Node* cyclic_left(Node* head, int x){
    /* write your code here */
    if(x==0 || x==size){
        return head;
    }
    int cnt=0;
    Node  * tail=head;
    while(tail->next!=nullptr){
        tail=tail->next;
    }
    while(cnt!=x){
        Node * cur = head;
        tail->next=cur;
        head=head->next;
        cur->next=nullptr;
        tail=tail->next;
        cnt++;
    }
    return head;
}
 
Node* cyclic_right(Node* head, int x){
    /* write your code here */
    int n = size-x;
    head=cyclic_left(head,n);
    return head;
}
 
int main(){
    Node* head = nullptr;
    while (true)
    {
        int command; cin >> command;
        if (command == 0){
            break;
        }else if(command == 1){
            int x, p; cin >> x >> p;
            head = insert(head, new Node(x), p);
            size++;
        }else if (command == 2){
            int p; cin >> p;
            head = remove(head, p);
            size--;
        }else if (command == 3){
            print(head);
        }else if (command == 4){
            int p1, p2; cin >> p1 >> p2;
            head = replace(head, p1, p2);
        }else if (command == 5){
            head = reverse(head);
        }else if (command == 6){
            int x; cin >> x;
            head = cyclic_left(head, x);
        }else if (command == 7){
            int x; cin >> x;
            head = cyclic_right(head, x);
        }   
    }
    return 0;
}