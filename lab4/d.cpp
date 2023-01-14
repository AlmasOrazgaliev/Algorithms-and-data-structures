#include<bits/stdc++.h>
using namespace std;
int a[5001];
int maxlevel=0;
struct node
{
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
    node * insert(node *  cur,int val){
        if(cur==nullptr) return new node(val);
        if(val>cur->val) cur->right=insert(cur->right,val);
        if(val<cur->val) cur->left=insert(cur->left,val);
        return cur;
    }
    void levelUp(node * cur,int level){
        if(cur==nullptr){
            return;
        }
        a[level]+=cur->val;
        if(maxlevel<level){
            maxlevel=level;
        }
        level++;
        levelUp(cur->left,level);
        levelUp(cur->right,level);
    }
public:
bst(){
    root=nullptr;
}
    void insert(int val){
        root=insert(root,val);
    }
    void level(){
        levelUp(root,1);
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
    tree.level();
    cout<<maxlevel<<endl;
    for(int i=0;i<5001;i++){
        if(a[i]!=0){
            cout<<a[i]<<" ";
        }
    }
}