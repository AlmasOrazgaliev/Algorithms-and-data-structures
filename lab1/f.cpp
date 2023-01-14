#include<bits/stdc++.h>
using namespace std;
int primeIndex(int n){
    int index=0;
    int i=1;
    while(index!=n){
        i++;
        bool ok=true;
        for(int j=2;j<=sqrt(i);j++){
            if(i%j==0){
                ok=false;
            }
        }
        if(ok){
            index++;
        }
    }
    return i;
}
int main(){
    int n;
    cin>>n;
    cout<<primeIndex(n);
}