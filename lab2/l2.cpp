# include <iostream>
# include <algorithm>
# include <cassert>
#include<limits.h>
 
using namespace std;
 
struct Node {
  int val;
  Node *next;
 
  Node() {
    val = 0;
    next = NULL;
  }
 
};
 
 
 
int findMaxSum(int n, Node *head) {
    int maxSum= INT_MIN;
    Node * first=head;
    while(first->next!=nullptr){
        Node * second=first->next;
        int sum=first->val;
        if(maxSum<sum){
            maxSum=sum;
        }
        while(second!=nullptr){
            sum+=second->val;
            if(maxSum<sum){
                maxSum=sum;
            }
            second=second->next;
        }
        first=first->next;
    }
    return maxSum;
}
 
int main() {
  int n;
  cin >> n;
 
  Node *head, *tail;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    Node *cur = new Node();
    cur -> val = x;
 
    if (i == 1) {
      head = tail = cur;
    } else {
      tail -> next = cur;
      tail = cur;
    }
  }
 
  cout << findMaxSum(n, head) << "\n";
  return 0;
}
 