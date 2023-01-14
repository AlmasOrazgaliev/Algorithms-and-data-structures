#include<bits/stdc++.h>
using namespace std;
int comp2(string **&s, int i,int j){
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
int comp(string **&s, int i, int j){
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
        return comp2(s,i,j);
    }
}
void merge(double a[],string **&s,int n, int low,int high,int mid){
    int i,j,k;
    double b[n];
    string **c = new string *[n];
    for(int i=0;i<n;i++){
        c[i]=new string[2];
    }
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high){
        if(a[i]<a[j]){
            b[k]=a[i];
            c[k][0]=s[i][0];
            c[k][1]=s[i][1];
            k++;i++;
        }
        else if(a[i]>a[j]){
            b[k]=a[j];
            c[k][0]=s[j][0];
            c[k][1]=s[j][1];
            k++;j++;
        }else{
            if(comp(s,i,j)==j){
                b[k]=a[i];
                c[k][0]=s[i][0];
                c[k][1]=s[i][1];
                k++;i++;
            }else{
                b[k]=a[j];
                c[k][0]=s[j][0];
                c[k][1]=s[j][1];
                k++;j++;
            }
        }
    }
    while(i<=mid){
        b[k]=a[i];
        c[k][0]=s[i][0];
        c[k][1]=s[i][1];
        k++;i++;
    }
    while(j<=high){
        b[k]=a[j];
        c[k][0]=s[j][0];
        c[k][1]=s[j][1];
        k++;j++;
    }
    for(i=low;i<k;i++){
        a[i]=b[i];
        s[i][0]=c[i][0];
        s[i][1]=c[i][1];
    }
}
void merge_sort(double a[],string **&s,int n,int low,int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        merge_sort(a,s,n,low,mid);
        merge_sort(a,s,n,mid+1,high);
        merge(a,s,n,low,high,mid);
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
    merge_sort(a,s,n,0,n-1);
    for(int i=0;i<n;i++){
        string c=to_string(a[i]);
        if(c.size()<5){
            string c=to_string(a[i]);
            if(c.size()==1){
                c=c+".000";
            }else{
                for(int j=c.size();j<5;j++){
                    c+='0';
                }
            }
            cout<<s[i][0]<<" "<<s[i][1]<<" "<<c<<endl;
            
        }else{
            cout<<s[i][0]<<" "<<s[i][1]<<" "<<fixed<<setprecision(3)<<a[i]<<endl;
        }
        
        delete []s[i];
    }
    delete []s;
}