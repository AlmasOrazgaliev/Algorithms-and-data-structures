#include<bits/stdc++.h>
using namespace std;
int cnt=0;
struct node{
    int val;
    node* right;
    node * left;
    node(int val){
        this->val=val;
        left=right=nullptr;
    }
};
class bst{
private:
    node * root;
    node * insert(node * cur,int val){
        if(cur==nullptr) return new node(val);
        if(val>cur->val) cur->right=insert(cur->right,val);
        if(val<cur->val) cur->left=insert(cur->left,val);
        return cur;
    }
    void triangle(node * cur){
        if(cur==nullptr) return;
        if(cur->left!=nullptr && cur->right!=nullptr){
            cnt++;
        }
        triangle(cur->left);
        triangle(cur->right);
    }
public:
    bst(){
        root=nullptr;
    }
    void insert(int val){
        root=insert(root,val);
    }
    void triangle(){
        triangle(root);
    }
};
int main(){
    int n;
    cin>>n;
    int x;
    bst tree;
    for(int i=0;i<n;i++){
        cin>>x;
        tree.insert(x);
    }
    tree.triangle();
    cout<<cnt;
}