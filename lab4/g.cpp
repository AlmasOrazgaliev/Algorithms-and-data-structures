#include<bits/stdc++.h>
using namespace std;
int max_d=0;
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
        if(val<cur->val) cur->left=insert(cur->left,val);
        if(val>cur->val) cur->right=insert(cur->right,val);
        return cur;
    }
    int depth(node * cur){
        if(cur==nullptr) return 0;
        return max(depth(cur->left),depth(cur->right))+1;
    }
    void max_depth(node * cur){
        if(!cur) return;
        int height=depth(cur->left)+depth(cur->right)+1;
        if(max_d<height){
            max_d=height;
        }
        max_depth(cur->left);
        max_depth(cur->right);
    }
public:
    bst(){
        root=nullptr;
    }
    void insert(int val){
        root=insert(root,val);
    }
    void depth(){
        depth(root);
        max_depth(root);
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
    tree.depth();
    cout<<max_d;
}