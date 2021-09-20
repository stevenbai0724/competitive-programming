//https://codeforces.com/problemset/problem/1088/B
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;   
    cin>>n>>k;
    int sum = 0;
    vector<int>arr(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr.begin(), arr.end());

    int count = 0;

    for(int i=1;i<=n;i++){
        arr[i] -=sum;
        if(arr[i]!=0){
            count++;
            cout<<arr[i]<<"\n";
            sum+=arr[i];
        }
        if(count==k){
            break; 
            return 0;
        }
    }
    for(int i =1;i<=(k-count);i++){
        cout<<0<<"\n";
    }
    return 0;
}