#include <bits/stdc++.h>
using namespace std;
  
int partition(string &c, int low, int high)
{
    char pivot = c[high]; 
    int i= (low- 1); 
  
    for (int j = low; j < high ; j++) {
        if((int)c[j]<(int)pivot){
            i++;
            swap(c[i],c[j]);
        }
    }
    swap(c[i + 1], c[high]);
    return (i + 1);
}
  
void quickSort(string &c, int low, int high)
{
    if (low < high) {
        int pi = partition(c, low, high);

        quickSort(c, low, pi - 1);
        quickSort(c, pi + 1, high);
    }
}
  

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    string vowel;
    string con;
    for(int i=0;i<n;i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ){
            vowel+=s[i];
        }else{
            con+=s[i];
        }
    }
    quickSort(vowel,0,vowel.size()-1);
    quickSort(con,0,con.size()-1);
    cout<<vowel<<con;
}
  