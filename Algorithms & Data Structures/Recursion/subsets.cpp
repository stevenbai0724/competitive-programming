//recursive program to print out all subsets of a given array
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
set<vector<int>>st;
void print(vector<int>arr){
    for(auto x: arr){
        cout<<x<<" ";
    }
    cout<<"\n";
}
void solve(int use, vector<int>arr, vector<int>ans ){
    if(use == 5){
        return;
    }
    st.insert(ans);

    vector<int>arr1 = ans;
    vector<int>arr2 = ans;
    arr1.push_back(arr[use]);
    
    solve(use+1, arr, arr1);
    solve(use+1, arr, arr2);

    return ;


}

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int>arr{1,2,3,4};

    solve((int)0,arr,{});

    cout<<st.size()<<"\n";

    for(auto v: st){
        for(auto x: v){
            cout<<x<<" ";

        }
        cout<<"\n";
    }





    return 0;
}