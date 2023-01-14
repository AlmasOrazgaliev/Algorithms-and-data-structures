#include <iostream>
#include<string>
using namespace std;

int partition(string &c, int low, int high){
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

void quickSort(string &c, int low, int high){
    if (low < high) {
        int pi = partition(c, low, high);

        quickSort(c, low, pi - 1);
        quickSort(c, pi + 1, high);
    }
}

int main(){
    int n;
    cin>>n;

    string s;
    cin>>s;

    string a;
    string b;
    for(int i=0;i<n;i++){
        if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' ){
            a+=s[i];
        }else{
            b+=s[i];
        }
    }
    quickSort(a,0,b.size()-1);
    quickSort(b,0,b.size()-1);
    cout<<a<<b;
}
  