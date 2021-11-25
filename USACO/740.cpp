//http://www.usaco.org/index.php?page=viewproblem2&cpid=644
//USACO 2017 Open Contest Silver P3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
struct point{
    int a, b, c, d;
};
bool comp(point x, point y){
    int a1 = abs(x.a - x.c) * abs(x.a - x.c) + abs(x.d - x.b) + abs(x.d - x.b);
    int a2 = abs(y.a - y.c) * abs(y.a - y.c) + abs(y.d - y.b) + abs(y.d - y.b);
    return a1 > a2;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    freopen("where.in", "r", stdin);
    freopen("where.out", "w", stdout);

    int n; cin>>n;
    
    vector<vector<char>>arr(n+1, vector<char>(n+1));

    vector<point>rect;

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=n;j++){
            arr[i][j] = s[j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=i;k<=n;k++){
                for(int l=j;l<=n;l++){
                    rect.push_back({i,j,k,l});
                }
            }
        }
    }
    sort(rect.begin(), rect.end(), comp);
    vector<point>good;

    for(auto r: rect){
        int a = r.a;
        int b = r.b;
        int c = r.c;
        int d = r.d;
        set<char>s;
        for(int i=a;i<=c;i++){
            for(int j=b;j<=d;j++){
                s.insert(arr[i][j]);
            }
        }
        if(s.size() != 2)continue;
        map<char, int>mp;
        vector<vector<bool>>vis(n+1, vector<bool>(n+1));
        int cnt = 0;
        vector<int>dx{-1,1,0,0}, dy{0,0,-1,1};

        for(int i=a;i<=c;i++){
            for(int j=b;j<=d;j++){
                if(!vis[i][j]){
                    vis[i][j] = true;
                    char cur = arr[i][j];
                    mp[cur]++;
                    queue<pair<int, int>>q;
                    q.push({i,j});
                    cnt++;
                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(int k=0;k<4;k++){
                            int newx = x + dx[k];
                            int newy = y + dy[k];
                            if(newx >= a && newx <= c && newy>=b && newy<=d){
                                if(!vis[newx][newy] && arr[newx][newy] == cur){
                                    vis[newx][newy] = true;
                                    q.push({newx, newy});
                                    
                                }
                            }
                        }
                        
                    }
                }
            }
        }
        int one = 0;
        for(char ch: s)one += mp[ch] == 1;

        if(one == 1){
            bool use = true;
            for(point p: good){
                if(p.a <=a && a<=p.c && p.a <= c && c <= p.c && p.b <= b && b <= p.d && p.b <= d && d <= p.d)use = false;
            }
            if(use)good.push_back(r);
        }

    }
    cout<<good.size()<<"\n";




   


    return 0;
}