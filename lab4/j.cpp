#include<bits/stdc++.h>
using namespace std;
vector<int> v;
vector<int> a;
//1 2 3 4 |5| 6 7 8 9
void bal(int l,int r){
    if(l>r) return;
    int mid=(l+r)/2;
    a.push_back(v[mid]);
    bal(l,mid-1);
    bal(mid+1,r);
    return;
}
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
    void inOrder(node * cur){
        if(cur==nullptr) return;
        inOrder(cur->left);
        v.push_back(cur->val);
        inOrder(cur->right);
    }
    void print(node * cur){
        if(cur==nullptr) return;
        cout<<cur->val<<" ";
        print(cur->left);
        print(cur->right);
    }
public:
    bst(){
        root=nullptr;
    }
    void insert(int val){
        root=insert(root,val);
    }
    void inOrder(){
        inOrder(root);
    }
    void print(){
        print(root);
    }
};
int main(){
    int n;
    int p=1;
    cin>>n;
    for(int i=0;i<n;i++){
        p*=2;
    }
    int x;
    bst tree;
    for(int i=0;i<p-1;i++){
        cin>>x;
        tree.insert(x);
    }
    tree.inOrder();
    int l=0;
    int r=v.size()-1;
    bst tree2;
    bal(l,r);
    for(int i=0;i<a.size();i++){
        tree2.insert(a[i]);
    }
    tree2.print();
}