#include<bits/stdc++.h>
using namespace std;
void merge(vector<string> &v,int low, int high,int mid){
    int i,j,k;
    vector<string> a(v.size());
    i=low;
    k=low;
    j=mid+1;
    while(i<= mid && j<=high){
        if(v[i].size()<=v[j].size()){
            a[k]=v[i];
            k++;
            i++;
        }
        else{
            a[k]=v[j];
            k++;
            j++;
        }
    }
    while(i<=mid){
        a[k]=v[i];
        k++;
        i++;
    }
    while(j<=high){
        a[k]=v[j];
        k++;
        j++;
    }
    for(i=low;i<k;i++){
        v[i]=a[i];
    }
}
void merge_sort(vector<string> &v,int low, int high){
    int mid;
    if(low<high){
        mid=(low+high)/2;
        merge_sort(v,low,mid);
        merge_sort(v,mid+1,high);
        merge(v,low,high,mid);
    }
}

int main(){
    int n;
    cin>>n;
    cin>>ws;
    string s;
    for(int i=0;i<n;i++){
        getline(cin,s);
        vector<string> v;
        string g="";
        for(int j=0;j<s.size();j++){
            if(s[j]!=' '){
                g+=s[j];
            }else{
                v.push_back(g);
                g="";
            }
        }
        v.push_back(g);
        merge_sort(v,0,v.size()-1);
        for(int j=0;j<v.size();j++){
            cout<<v[j]<<" ";
        }
        cout<<endl;
    }

}