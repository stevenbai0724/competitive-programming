//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n; cin>>n;
    vector<string>arr(4);
    int GRrow = 0, BGrow = 0, BRrow = 0, GGrow = 0, RRrow = 0, BBrow = 0;
    int GRcol = 0, BGcol = 0, BRcol = 0, GGcol = 0, RRcol = 0, BBcol = 0;

    for(int i=0;i<4;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        string temp = "";
        temp += arr[1][i];
        temp += arr[3][i];
        string temp2 = "";
        temp2 += arr[0][i];
        temp2 += arr[2][i];
        sort(temp.begin(), temp.end());
        sort(temp2.begin(), temp2.end());
        if(temp == "GR"){
            GRrow++;
        }
        else if(temp == "BG"){
            BGrow++;
        }
        else if(temp == "BR"){
            BRrow++;
        }
        else if(temp == "BB"){
            BBrow++;
        }
        else if(temp == "RR"){
            RRrow++;
        }
        else{
            GGrow++;
        }


        if(temp2 == "GR"){
            GRcol++;
        }
        else if(temp2 == "BG"){
            BGcol++;
        }
        else if(temp2 == "BR"){
            BRcol++;
        }
        else if(temp2 == "BB"){
            BBcol++;
        }
        else if(temp2 == "RR"){
            RRcol++;
        }
        else{
            GGcol++;
        }
    }
    int cnt = 0;

    for(int i=0;i<n;i++){
        string check = "";
        check += arr[0][i];
        check += arr[2][i];
        sort(check.begin(), check.end());

        if(check == "GR"){
            cnt += BBrow + BRrow + BGrow;
        }
        else if(check == "BG"){
            cnt += GRrow + RRrow + BRrow;
        }
        else if(check == "BR"){
            cnt += GRrow + GGrow + BGrow;
        }
        else if(check == "BB"){
            cnt += GRrow;
        }
        else if(check == "RR"){
            cnt += BGrow;
        }
        else{
            cnt += BRrow;
        }

    }
    for(int i=0;i<n;i++){
        string check = "";
        check += arr[1][i];
        check += arr[3][i];
        sort(check.begin(), check.end());

        if(check == "GR"){
            cnt += BBcol + BRcol + BGcol;
        }
        else if(check == "BG"){
            cnt += GRcol + RRcol + BRcol;
        }
        else if(check == "BR"){
            cnt += GRcol + GGcol + BGcol;
        }
        else if(check == "BB"){
            cnt += GRcol;
        }
        else if(check == "RR"){
            cnt += BGcol;
        }
        else{
            cnt += BRcol;
        }

    }
    cout<<cnt/2<<"\n";

    return 0;
}