#include<bits/stdc++.h>
using namespace std;
int sum=0;
struct node{
    int val;
    node * right;
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
    void rename(node * cur){
        if(cur==nullptr){
            return ;
        }
        rename(cur->left);
        int prev=cur->val;
        cur->val=sum;
        sum-=prev;
        rename(cur->right);
    }
    void print_des(node * cur){
        if(cur==nullptr){
            return;
        }
        print_des(cur->right);
        cout<<cur->val<<" ";
        print_des(cur->left);
    }
public:
    bst(){
        root=nullptr;
    }
    void insert(int val){
        root=insert(root,val);
    }
    void rename(){
        rename(root);
    }
    void print_des(){
        print_des(root);
    }
};
int main(){
    bst tree;
    int n;
    cin>>n;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        tree.insert(x);
        sum+=x;
    }
    tree.rename();
    tree.print_des();
}