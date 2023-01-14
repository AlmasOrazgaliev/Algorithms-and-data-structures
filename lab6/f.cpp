#include<bits/stdc++.h>
using namespace std;
int heapify23(double a[], string **&s, int i, int j){
    if(s[i][1].size()<s[j][1].size()){
        for(int k=0;k<s[i][1].size();k++){
            if((int)s[i][1][k]<(int)s[j][1][k]){
                return j;
            }
            else if((int)s[i][1][k]>(int)s[j][1][k]){
                return i;
            }
        }
        return j;
    }else{
        for(int k=0;k<s[j][1].size();k++){
            if((int)s[i][1][k]<(int)s[j][1][k]){
                return j;
            }else if((int)s[i][1][k]>(int)s[j][1][k]){
                return i;
            }
        }
        return i;
    }
}
int heapify2(double a[], string **&s, int i, int j){
    if(s[i][0].size()<s[j][0].size()){
        for(int k=0;k<s[i][0].size();k++){
            if((int)s[i][0][k]<(int)s[j][0][k]){
                return j;
            }
            else if((int)s[i][0][k]>(int)s[j][0][k]){
                return i;
            }
        }
        return j;
    }else if(s[i][0].size()>s[j][0].size()){
        for(int k=0;k<s[j][0].size();k++){
            if((int)s[i][0][k]<(int)s[j][0][k]){
                return j;
            }else if((int)s[i][0][k]>(int)s[j][0][k]){
                return i;
            }
        }
        return i;
    }else{
        for(int k=0;k<s[j][0].size();k++){
            if((int)s[i][0][k]<(int)s[j][0][k]){
                return j;
            }else if((int)s[i][0][k]>(int)s[j][0][k]){
                return i;
            }
        }    
        return heapify23(a,s,i,j);

    }
}
void heapify(double a[], string **&s,int i,int n){
    int largest=i;
    int l=i*2+1;
    int r=2*i+2;
    if(l<n && a[largest]<a[l]){
        largest=l;
    }
    else if(l<n && a[largest]==a[l]){
        largest=heapify2(a,s,largest,l);
    }
    if(r<n && a[largest]<a[r]){
        largest=r;
    }
    else if(r<n && a[largest]==a[r]){
        largest=heapify2(a,s,largest,r);
    }
    if(i!=largest){
        swap(a[i],a[largest]);
        swap(s[i][0],s[largest][0]);
        swap(s[i][1],s[largest][1]);
        heapify(a,s,largest,n);
    }
}


void quickSort(double a[],string **&s,int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(a,s,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(a[i],a[0]);
        swap(s[i][1],s[0][1]);
        swap(s[i][0],s[0][0]);
        heapify(a,s,0,i);
    }
}

int main(){
    int n;
    cin>>n;
    string **s=new string *[n];
    double a[n];
    double m;
    for(int i=0;i<n;i++){
        s[i]=new string[2];
        cin>>s[i][0]>>s[i][1];
        cin>>m;
        string c;
        double x;
        double sum=0;
        double div=0;
        for(int j=0;j<m;j++){
            cin>>c>>x;
            div+=x;
            if(c=="A+"){
                x=(double)x*(double)4;
            }
            if(c=="A"){
                x=x*3.75;
            }
            if(c=="B+"){
                x=x*3.5;
            }
            if(c=="B"){
                x=x*3;
            }
            if(c=="C+"){
                x=x*2.5;
            }
            if(c=="C"){
                x=x*2;
            }
            if(c=="D+"){
                x=x*1.5;
            }
            if(c=="D"){
                x=x*1;
            }
            if(c=="F"){
                x=x*0;
            }
            sum+=x;
        }
        a[i]=sum/div;
    }
    quickSort(a,s,n);

    for(int i=0;i<n;i++){
        cout<<s[i][0]<<" "<<s[i][1]<<" "<<fixed<<setprecision(3)<<a[i]<<endl;
        
        delete []s[i];
    }
    delete []s;
}