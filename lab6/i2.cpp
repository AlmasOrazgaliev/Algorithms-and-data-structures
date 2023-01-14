#include<bits/stdc++.h>
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
    string s;
    cin>>s;
    quickSort(s,0,s.size()-1);
    cout<<s;
}