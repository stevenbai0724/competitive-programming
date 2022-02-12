//https://dmoj.ca/problem/coci19c3p3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define double long double
#define int long long
bool good(vector<int>arr1, vector<int>arr2){
    int ans = true;

    int n = arr1.size();
    int m = arr2.size();
    int d1, d2;
    if (n > 1)d1 = arr1[1] - arr1[0];
    if (m > 1)d2 = arr2[1] - arr2[0];

    for(int i=1;i<n;i++){
        if(arr1[i] - arr1[i-1] != d1)ans = false;
    }
    for(int i=1;i<m;i++){
        if(arr2[i] - arr2[i-1] != d2)ans = false;
    }

    return ans;
}
void print(vector<int>arr1, vector<int>arr2){
    if(arr1.empty()){
        cout<<1<<"\n"<<arr2[0]<<"\n";
        cout<<(arr2.size()-1)<<"\n";
        for(int i=1;i<arr2.size();i++){
            cout<<arr2[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    if(arr2.empty()){
        cout<<1<<"\n"<<arr1[0]<<"\n";
        cout<<(arr1.size()-1)<<"\n";
        for(int i=1;i<arr1.size();i++){
            cout<<arr1[i]<<" ";
        }
        cout<<"\n";
        return;
    }
    cout<<arr1.size()<<"\n";
    for(int x: arr1)cout<<x<<" ";
    cout<<"\n";
    cout<<arr2.size()<<"\n";
    for(int x: arr2)cout<<x<<" ";
    cout<<"\n";
    return;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(), arr.end());

        if(n > 300){
        
    }

    for(int START = 0; START < n-1; START++){
        for(int NXT = START+1; NXT<n; NXT++){

            vector<int>check{arr[START], arr[NXT]};
            vector<int>check2 = arr;
            int diff = arr[NXT] - arr[START];

            check2.erase(lower_bound(check2.begin(), check2.end(), arr[START]));
            check2.erase(lower_bound(check2.begin(), check2.end(), arr[NXT]));

            if(good(check, check2)){
                print(check, check2);
                return 0;
            }

            int cand = arr[NXT] + diff;
            auto it = lower_bound(check2.begin(), check2.end(), cand);
            while(it != check2.end() && *it == cand){

                check.push_back(cand);
                check2.erase(it);
                cand += diff;

                if(good(check, check2)){
                    print(check, check2);
                    return 0;
                }

                it = lower_bound(check2.begin(), check2.end(), cand);
            }

        }
    }
    cout<<-1<<"\n";


    return 0;
}