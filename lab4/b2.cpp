#include<bits/stdc++.h>  
using namespace std;  
struct node{  
    int val;  
    node * right=NULL;  
    node * left=NULL;  
    node(int val){  
        this->val=val;  
        right=left=NULL;  
    }  
};  
class bst{  
private:  
    node * root;  
    node * insert(node * cur,int val){  
        if(cur==NULL) return new node(val);  
        if(val>cur->val) cur->right=insert(cur->right,val);  
        if(val<cur->val) cur->left=insert(cur->left,val);  
        return cur;  
    }  
    int size(node * cur){ 
        if(cur==NULL){  
            return 0;  
        }  
        return (1 + size(cur->left)  + size(cur->right));  
    }  
    node * find(node * cur,int val){  
        if(cur==NULL || cur->val==val){  
            return cur;  
        }  
        else if(cur->val<val){  
            return find(cur->right,val);  
        }  
        return find(cur->left,val);  
    } 
    void printInorder(node* cur) 
    { 
        if (cur == NULL) 
            return; 
     
        /* first recur on left child */ 
        printInorder(cur->left); 
     
        /* then print the data of node */ 
        cout << cur->val << " "; 
     
        /* now recur on right child */ 
        printInorder(cur->right); 
    } 
 
public:  
    bst(){  
        root=NULL;  
    }  
    void insert(int val){  
        root=insert(root,val);  
    }  
    int size1(int val){  
        return size(find(root,val));  
    } 
    void print(){ 
        printInorder(root); 
    } 
};  
int main(){  
    int n;  
    cin>>n;  
    bst tree;  
    int x;  
    for(int i=0;i<n;i++){  
        cin>>x;  
        tree.insert(x);  
    }  
    int k;  
    cin>>k; 
    cout<<tree.size1(k);  
}
