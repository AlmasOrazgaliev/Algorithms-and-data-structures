#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    char c;
    deque<char> d;
    int cntK=0;
    int cntS=0;
    for(int i=0;i<n;i++){
        cin>>c;
        if(c=='K'){
            cntK++;
        }else{
            cntS++;
        }
        d.push_back(c);
    }

    int moveK=0;
    int moveS=0;
    while(cntK!=0 && cntS!=0){
        if(d.front()=='S' && moveK==0){
            moveS++;
            d.push_back(d.front());
            d.pop_front();
        }
        else if(d.front()=='S' && moveK!=0){
            d.pop_front();
            moveK--;
            cntS--;
        }
        else if(d.front()=='K' && moveS==0){
            moveK++;
            d.push_back(d.front());
            d.pop_front();
        }
        else if(d.front()=='K' && moveS!=0){
            d.pop_front();
            moveS--;
            cntK--;
        }
    }
    
    if(d.front()=='K'){
        cout<<"KATSURAGI";
    }else{
        cout<<"SAKAYANAGI";
    }
}