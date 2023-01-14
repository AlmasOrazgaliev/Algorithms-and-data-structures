#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin>>n;
    int a[n][8];
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        int cnt=0;
        for(int j=0;j<s.size();j++){
            if(s[j]=='-'){
                continue;
            }else{
                a[i][cnt]=int(s[j])-int('0');
                cnt++;
            }
        }
    }
    for(int i=0;i<n-1;i++){
        for(int k=i+1;k<n;k++){
            bool ok=true;
            bool ok2=true;
            for(int j=4;j<8;j++){
                if(a[i][j]>a[k][j]){
                    swap(a[i],a[k]);
                    ok=false;
                    ok2=false;
                    break;
                }
                else if(a[i][j]<a[k][j]){
                    ok=false;
                    ok2=false;
                    break;
                }
            }
            if(ok){
                for(int j=2;j<4;j++){
                    if(a[i][j]>a[k][j]){
                        swap(a[i],a[k]);
                        ok2=false;
                        break;
                    }
                    else if(a[i][j]<a[k][j]){
                        ok2=false;
                        break;
                    }
                }
            }
            if(ok2){
                for(int j=0;j<3;j++){
                    if(a[i][j]>a[k][j]){
                        swap(a[i],a[k]);
                        break;
                    }
                    else if(a[i][j]<a[k][j]){
                        break;
                    }
                }
            }
           
        }
        
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<8;j++){
            cout<<a[i][j];
            if(j==1 || j==3){
                cout<<"-";
            }
        }
        cout<<endl;
    }
}