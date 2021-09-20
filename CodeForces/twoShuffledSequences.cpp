//https://codeforces.com/problemset/problem/1144/C
#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;
    vector<int>freq(2e5+1);
    multiset<int>s1;
    vector<int>s2;

    for(int i=1;i<=n;i++){
        int x; cin>>x;
        s1.insert(x);
        freq[x]++;
        if(freq[x]>2){
            cout<<"NO";
            return 0;
        }
    }
    for(int i=0;i<=2e5;i++){
        if(freq[i]==2){
            s2.push_back(i);
            s1.erase(s1.find(i));
        }
    }
    sort(s2.begin(), s2.end(), greater<int>());

    cout<<"YES"<<"\n";

    cout<<s1.size()<<"\n";
    for(auto x:s1){
        cout<<x<< " ";
    }
    cout<<"\n";
    cout<<s2.size()<<"\n";
    for(int i=0;i<s2.size();i++){
        cout<<s2[i]<<" ";
    }
    return 0;
}