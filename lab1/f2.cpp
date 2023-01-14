#include<iostream>
#include<cmath>
#include<vector>
using namespace std ; 


bool primeNumber(int x){
int ER = 0 ; 
for(int i = 2 ; i <= sqrt(x); i++  )
{
    if(x%i == 0){
        ER++ ;
    }
}    

if(ER == 0){
    return true ; 
}
} 

int main()
{
    int n ; 
    cin >> n ; 
    vector<int> v  ; 
    for(int i = 2 ; i <= 8000 ; i++)
    {
        if(primeNumber(i)){
            v.push_back(i) ; 
            
        }
    }

    cout << v[n-1] ; 


}