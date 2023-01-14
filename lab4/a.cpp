#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node * right=nullptr;
    node * left=nullptr;
    node(int val){
        this->val=val;
        right=left=nullptr;
    }
};
class bst{
private:
    node * root=nullptr;
    node * insert(node * cur,int val){
        if(cur==nullptr){
            return new node(val);
        }
        if(val>cur->val) cur->right=insert(cur->right,val);
        if(val<cur->val) cur->left=insert(cur->left,val);
        return cur;
    }
    bool mountains(string s,node * cur){
        node * temp=cur;
        for(int i=0;i<s.size();i++){
            if(s[i]=='L'){
                if(temp->left!=nullptr){
                    temp=temp->left;
                }
                else return false;
            }
            else if(s[i]=='R'){
                if(temp->right!=nullptr){
                    temp=temp->right;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
public:
    bst(){
        root=nullptr;
    }
    void insert(int val){
        root=insert(root,val);
    }
    void mountains(string s){
        if(mountains(s,root)){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
};

int main(){
    bst tree;
    int n,k;
    cin>>n>>k;
    int x;
    for(int i=0;i<n;i++){
        cin>>x;
        tree.insert(x);
    }
    string s;
    for(int i=0;i<k;i++){
        cin>>s;
        tree.mountains(s);
    }
}