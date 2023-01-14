#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=0;i<q;i++){
        int l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;
        int cnt=0;
        if(l2<=l1 && r1<=r2){
            //l2 and r2
            int l=0;
            int r=n-1;
            int mid;
            while(l<r){
                mid=(l+r)/2;
                if(a[mid]==r2){
                    cnt=mid;
                    break;
                }
                if(a[mid]<r2){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            l=0;
            r=n-1;
            while(l<r){
                mid=(l+r)/2;
                if(a[mid]==l2){
                    cnt=cnt-a[mid];
                    break;
                }
                if(a[mid]<l2){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
        }
        else if(l1<=l2 && r2<=r1){
            // l1 and r1
            int l=0;
            int r=n-1;
            int mid;
            while(l<r){
                mid=(l+r)/2;
                if(a[mid]==r1){
                    cnt=mid;
                    break;
                }
                if(a[mid]<r1){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            l=0;
            r=n-1;
            while(l<r){
                mid=(l+r)/2;
                if(a[mid]==l1){
                    cnt=cnt-a[mid];
                    break;
                }
                if(a[mid]<l1){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
        }
        else if(l2<=r2 || r2+1==l2){
            //l1 and r2
            int l=0;
            int r=n-1;
            int mid;
            while(l<r){
                mid=(l+r)/2;
                if(a[mid]==r2){
                    cnt=mid;
                    break;
                }
                if(a[mid]<r2){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            l=0;
            r=n-1;
            while(l<r){
                mid=(l+r)/2;
                if(a[mid]==l1){
                    cnt=cnt-a[mid];
                    break;
                }
                if(a[mid]<l1){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
        }
        else if(l2>l1 && l2>r1){
            //l1 and r1   l2 and r2
            int l=0;
            int r=n-1;
            int mid;
            int l1Index;
            int r1Index;
            int l2Index;
            int r2Index;
            while(l<=r){
                mid=(l+r)/2;
                if(a[mid]==l1){
                    l1Index=mid;
                    break;
                }
                if(a[mid]<l1){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            l=0;
            r=n-1;
            while(l<=r){
                mid=(l+r)/2;
                if(a[mid]==r1){
                    r1Index=mid;
                    break;
                }
                if(a[mid]<r1){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            l=0;
            r=n-1;
            while(l<=r){
                mid=(l+r)/2;
                if(a[mid]==l2){
                    l2Index=mid;
                    break;
                }
                if(a[mid]<l2){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            l=0;
            r=n-1;
            while(l<=r){
                mid=(l+r)/2;
                if(a[mid]==r2){
                    r2Index=mid;
                    break;
                }
                if(a[mid]<l1){
                    l=mid+1;
                }else{
                    r=mid-1;
                }
            }
            cnt=(r1-l1)+(r2-l2);
        }
        cout<<cnt<<endl;
    }
}