#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    int copy;
    node * right;
    node * left;
    node(int val){
        this->val=val;
        this->copy=1;
        left=right=nullptr;
    }
};
class bst{
private:
    node * root;
    node * insert(node * cur,int val){
        if(cur==nullptr) return new node(val);
        if(cur->val==val){
            cur->copy++;
            return cur;
        }
        if(val>cur->val) cur->right=insert(cur->right,val);
        if(val<cur->val) cur->left=insert(cur->left,val);
        return cur;
    }

    void remove(node* cur,int val){
        if(cur==nullptr) return;
        if(val>cur->val) remove(cur->right,val);
        else if(val<cur->val) remove(cur->left,val);
        else{
            if(val==cur->val && cur->copy==1){
                cur->copy=0;
                return;
            }else{
                cur->copy--;
                return;
            }
        }
    }
    void print(node * cur,int val){
        if(cur==nullptr){
            cout<<0<<endl;
            return;
        }
        if(cur->val==val){
            cout<<cur->copy<<endl;
        }
        else if(val<cur->val) print(cur->left,val);
        else if(val>cur->val) print(cur->right,val);
    }
    void printAll(node * cur){
        if(cur==nullptr){
            return;
        }
        printAll(cur->left);
        cout<<cur->val<<" "<<cur->copy<<endl;
        printAll(cur->right);
    }
public:
    bst(){
        root=nullptr;
    }
    void insert(int val){
        root=insert(root,val);
    }
    void remove(int val){
        remove(root,val);
    }
    void print(int val){
        print(root,val);
    }
    void printAll(){
        printAll(root);
    }
};
int main(){
    int n;
    cin>>n;
    bst tree;
    string s;
    int x;
    for(int i=0;i<n;i++){
        cin>>s>>x;
        if(s=="insert"){
            tree.insert(x);
        }
        else if(s=="cnt"){
            tree.print(x);
        }
        else if(s=="delete"){
            tree.remove(x);
        }
    }
    //tree.printAll();
}