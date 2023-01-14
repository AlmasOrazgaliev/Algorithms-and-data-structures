#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node * right;
    node * left;
    node(int val){
        this->val=val;
        right=left=nullptr;
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
    void print(node * cur){
        if(cur==nullptr) return;
        cout<<cur->val<<" ";
        print(cur->left);
        print(cur->right);
    }
    node * find(node * cur,int val){
        if(cur==nullptr || cur->val==val){
            return cur;
        }
        else if(cur->val<val){
           return find(cur->right,val);
        }
        return find(cur->left,val);
    }
public:
    bst(){
        root=nullptr;
    }
    void insert(int val){
        root=insert(root,val);
    }
    void print(int val){
        print(find(root,val));
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
    tree.print(k);
}