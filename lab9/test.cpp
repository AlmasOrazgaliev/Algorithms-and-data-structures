#include<bits/stdc++.h>
using namespace std;
vector<int> prefix(string s){
    vector<int> res(s.size());
    res[0]=0;
    for(int i=1;i<s.size();i++){
        int j=res[i-1];
        while(j>0 && s[j]!=s[i]){
            j=res[j-1];
        }
        if(s[j]==s[i]){
            res[i]=j+1;
        }else{
            res[i]=0;
        }
    }
    return res;
}
#include<iostream>
using namespace std;
 
vector<int> create_resarr(string str)
{
    int n = str.length();
    vector<int> res(n);
    int left, right, k;
 
    // [left,right] make a window which matches with prefix of str
    left = right = 0;
    for (int i = 1; i < n; ++i)
    {
        // if i>right nothing matches so we will calculate.
        // res[i] using naive way.
        if (i > right)
        {
            left = right = i;
 
            // right-left = 0 in starting, so it will start
            // checking from 0'th index. 
            while (right<n && str[right-left] == str[right])
                right++;
            res[i] = right-left;
            right--;
        }
        else
        {
            // k = i-left so k corresponds to number which
            // matches in [left,right] interval.
            k = i-left;
 
            // if res[k] is less than remaining interval
            // then res[i] will be equal to res[k].
            
            if (res[k] < right-i+1)
                res[i] = res[k];
 
            
            else
            {
                // else start from right and check manually
                left = i;
                while (right<n && str[right-left] == str[right])
                    right++;
                res[i] = right-left;
                right--;
            }
        }
    }
    return res;
}
int main(){
    string s;
    cin>>s;
    vector<int> res = prefix(s);
    for(int i=0;i<s.size();i++){
        cout<<i;
    }
    cout<<endl;
    for(int i=0;i<s.size();i++){
        cout<<res[i];
    }
    cout<<endl;
    vector<int> n = create_resarr(s);
    for(int i=0;i<s.size();i++){
        if(n[i]==32){
            cout<<n[i]<<" "<<i;
        }
    }
}