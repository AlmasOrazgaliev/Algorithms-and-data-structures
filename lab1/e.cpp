#include<bits/stdc++.h>
using namespace std;
int main(){
    deque<int> dq;
    deque<int> bq;
    int x;
    for(int i=0;i<5;i++){
        cin>>x;
        dq.push_back(x);
    }
    for(int i=0;i<5;i++){
        cin>>x;
        bq.push_back(x);
    }
    int cnt=0;
    while(!dq.empty() && !bq.empty()){
        if(dq.front()==0 && bq.front()==9){
            x=dq.front();
            dq.pop_front();
            dq.push_back(x);
            x=bq.front();
            bq.pop_front();
            dq.push_back(x);
        }
        else if(dq.front()==9 && bq.front()==0){
            x=dq.front();
            dq.pop_front();
            bq.push_back(x);
            x=bq.front();
            bq.pop_front();
            bq.push_back(x);
        }
        else if(dq.front()<bq.front()){
            x=dq.front();
            dq.pop_front();
            bq.push_back(x);
            x=bq.front();
            bq.pop_front();
            bq.push_back(x);
        }
        else{
            x=dq.front();
            dq.pop_front();
            dq.push_back(x);
            x=bq.front();
            bq.pop_front();
            dq.push_back(x);
        }
        cnt++;
        if(cnt==1000001){
            cout<<"blin nichya";
            return 0;
        }
    }
    if(dq.empty()){
        cout<<"Nursik"<<" "<<cnt;
    }else{
        cout<<"Boris"<<" "<<cnt;
    }
}