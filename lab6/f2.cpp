#include<bits/stdc++.h>
using namespace std;
int partition(double a[], string **&s,int low,int high){
    double pivot=a[high];
    int i=(low-1);
    for(int j=low;j<high;j++){
        if(a[j]<pivot){
            i++;
            swap(a[i],a[j]);
            swap(s[i],s[j]);
        }
    }
    swap(a[i+1],a[high]);
    swap(s[i+1],s[high]);
    return (i+1);
}
void quickSort(double a[],string **&s,int low,int high){
    if(low<high){
        int pi=partition(a,s,low,high);
        quickSort(a,s,low,pi-1);
        quickSort(a,s,pi+1,high);
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
    quickSort(a,s,0,n-1);
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