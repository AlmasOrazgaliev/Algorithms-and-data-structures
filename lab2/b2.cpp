#include <bits/stdc++.h> 
using namespace std; 
int size=0;
struct Node { 
 string word; 
 Node* next; 
 
 Node() {} 
 
 Node(string word) { 
  this->word = word; 
  this->next = NULL; 
 }
}; 
 
// your code goes here 

Node* cyclicShift(Node* head, int k) { 
    Node * cur = head;
    Node * cop = head;
    int cnt=0;
    while(cur->next!=nullptr){
        cur=cur->next;
    }
    for(int i=0;i<k;i++){
        Node * newNode = new Node(cop->word);
        cur->next = newNode;
        cop=cop->next;
        cur = cur->next;
    }
    for(int i=0;i<k;i++){
        head=head->next;
    }
    // while(cnt<k%size){
    //     tail->next = cur;
    //     tail=tail->next;
    //     cout<<tail->word<<endl;
    //     cur=cur->next;
    //     delete head;
    //     head=cur;
    //     cnt++;
    // }
    return head;
    
} 
// void pop_front(){
//     node * newNode = head->next;
//     delete head;
//     head=newNode;
// }
 
void print(Node* head) { 
 Node* cur = head; 
 while (cur != NULL) { 
  cout << cur->word << " "; 
  cur = cur->next; 
 } 
 cout << endl; 
} 
 
int main() { 
 int n; cin >> n; 
 int k; cin >> k; 
 Node* head; 
 Node* cur; 
 for (int i = 0; i < n; i++) { 
    size++;
  string word; cin >> word; 
  if (i == 0) { 
   head = new Node(word); 
   cur = head; 
  } else { 
   cur->next = new Node(word); 
   cur = cur->next; 
  } 
 } 
 
 head = cyclicShift(head, k); 
 print(head); 
}
