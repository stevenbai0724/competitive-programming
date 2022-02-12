//https://dmoj.ca/problem/coci19c3p1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define double long double
#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;

    vector<int>arr(n+1);
    int tie = 1;
    vector<pair<int,int>>score(n+1);

    for(int i=1;i<=n;i++){
        
        cin>>arr[i];
        score[i] = score[i-1];
        if(arr[i] == 1)score[i].first++;
        else score[i].second++;
        if(score[i].first == score[i].second)tie++;

    }
    int mx = 0;
    for(int i=1;i<=n;i++){
        int j = i;

        while(j < n && arr[j+1] == arr[i]){
            j++;
        }

        if(score[j].first > score[j].second && score[i-1].first < score[i-1].second){
            mx = max(mx, j-i+1);
        }
        if(score[j].second > score[j].first && score[i-1].second < score[i-1].first){
            mx = max(mx, j-i+1);
        }
        i = j;
    }
    cout<<score[n].first<<" "<<score[n].second<<"\n";
    cout<<tie<<"\n";
    cout<<mx<<"\n";
    


    return 0;
}