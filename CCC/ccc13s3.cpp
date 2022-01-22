//https://dmoj.ca/problem/ccc13s3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
int t;
int solve(int a, int b, int s, vector<vector<int>>&played, vector<int>points, vector<vector<pair<int, int>>>&nxt){
    
    if(played[a][b] && played[a][b] != s){

        return 0;
    }
    if(a == 3 && b == 4){

        if(s == 1){
            points[a]+=3;
        }
        else if(s == 2){
            points[b]+=3;
        }
        else{
            points[a]++;
            points[b]++;
        }
        int r = 1;
        for(int i=1;i<=4;i++){
            if(i == t)continue;
            if(points[i] >= points[t])r = 0;
        }

        return r;
    }
    int nxtA = nxt[a][b].first;
    int nxtB = nxt[a][b].second;

    if(s == 1){
        points[a]+=3;
    }
    else if(s == 2){
        points[b]+=3;
    }
    else{
        points[a]++;
        points[b]++;
    }

    return solve(nxtA, nxtB, 1, played, points, nxt) + solve(nxtA, nxtB, 2, played, points, nxt) + solve(nxtA, nxtB, 3, played, points, nxt);


}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>t;

    vector<vector<int>>played(5, vector<int>(5));
    vector<int>points(5);
    vector<vector<pair<int, int>>>nxt(5, vector<pair<int, int>>(5));

    nxt[1][2] = {1,3};
    nxt[1][3] = {1,4};
    nxt[1][4] = {2,3};
    nxt[2][3] = {2,4};
    nxt[2][4] = {3,4};

    int g; cin>>g;
    for(int i=1;i<=g;i++){
        int a, b, c, d;
        cin>>a>>b>>c>>d;
        if(c > d)played[a][b] = 1;
        if(c < d)played[a][b] = 2;
        if(c == d)played[a][b] = 3;
    }
    cout<<(solve(1, 2, 1, played, points, nxt) + solve(1, 2, 2, played, points, nxt) + solve(1, 2, 3, played, points, nxt))<<"\n";
    



    return 0;
}
