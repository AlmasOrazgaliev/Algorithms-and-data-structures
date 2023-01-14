#include<iostream>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int a[n][n];
	for( int i = 0; i<n; i++){
		for( int j = 0; j<n; j++){
			cin>>a[i][j];
		}
	}
	int u,v,w;
	for( int i = 0; i<m; i++){
		cin>>u>>v>>w;
		if( a[u-1][v-1]==1 && a[u-1][w-1]==1 && a[v-1][w-1]==1  ){
			cout<<"YES"<<endl;	
		}else{
			cout<<"NO"<<endl;
		}
	}
}