#include<iostream>
using namespace std;
int a[1000];
int width=0;
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
    node * insert(node* cur,int val){
        if(cur==nullptr) return new node(val);
        return cur;
    }
    void insert(node * cur,int x,int y,int z){
        if(cur==nullptr) return;
        if(cur->val==x){
            if(z==1){
                cur->right=new node(y);
                return;
            }else{
                cur->left=new node(y);
                return;
            }
        }
        insert(cur->left,x,y,z);
        insert(cur->right,x,y,z);
    }
    void levelUp(node * cur,int level){
        if(cur==nullptr){
            return;
        }
        //cout<<cur->val<<" "<<level<<" we are here "<<endl;
        a[level]++;
        if(width<a[level]){
            width=a[level];
        }
        //cout<<" width:"<<width<<endl;
        level++;
            levelUp(cur->left,level);
            levelUp(cur->right,level);
    }
    void print(node * cur){
        if(cur==nullptr) return;
        cout<<" we in print ";
        print(cur->left);
        cout<<cur->val;
        print(cur->right);
    }
public:
    bst(){
        root=nullptr;
    }
    void insert_mult(int x,int y,int z){
        insert(root,x,y,z);
    }
    void insert(int val){
        root=insert(root,val);
    }
    void level(){
        levelUp(root,1);
    }
    void print(){
        print(root);
    }
};
int main(){
    bst tree;
    int n;
    cin>>n;
    int x,y,z;
    tree.insert(1);
    //tree.insert_mult(x,y,z);
    for(int i=0;i<n-1;i++){
        cin>>x>>y>>z;    
        tree.insert_mult(x,y,z);
    }
    tree.level();
    //tree.print();
    cout<<width;
}