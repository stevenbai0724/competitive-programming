#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k; 
    cin>>n>>k;
    vector<int>arr(n+1);
    int count =0;
    for(int i =1;i<=n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

    int l, r;
    l = 1;
    r = n;
    while(l<=r){
        if(l==r){
            count++;
            break;
        }
        if(arr[l]+arr[r]>k){
            count ++;
            r--;
        }
        else{
            count++;
            r--;
            l++;
        }
    }
    cout<<count;
    return 0;
}