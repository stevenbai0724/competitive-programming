//https://codeforces.com/problemset/problem/266/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    string s; cin>>s;
    int sum = 0;
    int streak = 0;
    
    for(int i=0;i<n;i++){
        if(s[i]==s[i+1]){
            streak++;
        }
        if(i==n-1){
            sum+=streak;
            break;
        }
        else{
            sum+=streak;
            streak =0 ;
        }

    }
    cout<<sum;


    return 0;
}
