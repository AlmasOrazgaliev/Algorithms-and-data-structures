#include<bits/stdc++.h>
using namespace std;
bool comp(pair<string,float> a, pair<string,float> b){
 if(a.second==b.second){
  return a.first>b.first;
 }
 return a.second>b.second;
}
int main(){
 //freopen("bad.in","r",stdin);
 //freopen("bad.out","w",stdout);
 int n,m;
 cin>>n>>m;
 vector<pair<string,float > > v;
 string s;
 for(int i=0;i<n;i++){
  cin>>s;
  v.push_back(make_pair(s,0.00));
 }
 vector<pair<string,float > > v2;
 v2.push_back(make_pair("Invalid",0.00));
 char c;
 for(int i=0;i<m;i++){
  int cnt=0;
  int ind=-1;
  for(int j=0;j<n;j++){
   cin>>c;
   if(c=='X'){
    ind=j;
    cnt++;
   }
  }
  if(cnt>1 || cnt<1){
   v2.back().second++;
  }else{
   for(int i=0;i<v.size();i++){
    if(i==ind){
     v[i].second++;
     break;
    }
   }
  }
 }
 sort(v.begin(),v.end(),comp);
 for(int i=0;i<v.size();i++){
  if(v[i].second*100/m==0){
   cout<<v[i].first<<" "<<setprecision(4)<<"0.00"<<"%"<<endl;
   continue;
  }
  cout<<v[i].first<<" "<<setprecision(4)<<float(v[i].second*100/m)<<"%"<<endl;
 }
 if(v2.back().second==0){
    cout<<v2.back().first<<" "<<setprecision(4)<<"0.00"<<"%"<<endl;
 }else{
 cout<<v2.back().first<<" "<<setprecision(4)<<v2.back().second*100/m<<"%"<<endl;
 }
}
