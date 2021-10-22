//https://cses.fi/problemset/task/1194
#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin>>n>>m;

    vector<vector<char>>arr(n+1, vector<char>(m+1));
    vector<vector<int>>dis(n+1, vector<int>(m+1));

    pair<int, int>M_START, A_START;
    bool first = true;

    vector<vector<vector<pair<int, pair<int, int>>>>>adj(n+1, vector<vector<pair<int, pair<int, int>>>>(m+1));

    for(int i=1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
            if(arr[i][j] == 'M' ){
                dis[i][j] = -1;
                if(first){
                    first = false;
                    M_START = {i,j};
                }
                else{
                    adj[M_START.first][M_START.second].push_back({0,{i,j}});
                }
            }
            if(arr[i][j] == 'A'){
                A_START = {i,j};
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr[i][j]=='A' && (i==1 || i==n || j==1 || j==m)){
                cout<<"YES\n0\n";
                return 0;
            }
            if(dis[i][j]==0)dis[i][j] = 1e18;
            if(dis[i][j]==-1)dis[i][j] = 0;
            if(arr[i][j]=='#')continue;
            if(i-1>=1 && arr[i-1][j]!='#') adj[i][j].push_back({1,{i-1,j}});
            if(i+1<=n && arr[i+1][j]!='#') adj[i][j].push_back({1,{i+1,j}});
            if(j-1>=1 && arr[i][j-1]!='#') adj[i][j].push_back({1,{i,j-1}});
            if(j+1<=m && arr[i][j+1]!='#') adj[i][j].push_back({1,{i,j+1}});
        }
    }
    bool good = false;
    int X = A_START.first;
    int Y = A_START.second;

    if(X+1<=n){
        if((arr[X+1][Y]=='.'))good = true;
    }
    if(X-1>=1){
        if((arr[X-1][Y]=='.'))good = true;
    }
    if(Y+1<=m){
        if((arr[X][Y+1]=='.'))good = true;
    }
    if(Y-1>=1){
        if((arr[X][Y-1]=='.'))good = true;
    }
    if(!good){
        cout<<"NO\n";
        return 0;
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>q;
   
    q.push({0, M_START});

    while(!q.empty()){
        int w = q.top().first;
        int x = q.top().second.first;
        int y = q.top().second.second;
        q.pop();
        if(dis[x][y]<w)continue;
        for(auto p: adj[x][y]){
            int neww = p.first;
            int newx = p.second.first;
            int newy = p.second.second;
            if(dis[newx][newy] >= dis[x][y] + neww){
                dis[newx][newy] = dis[x][y] + neww;
                q.push({dis[newx][newy], {newx, newy}});
            }
        }
    }

    vector<vector<int>>run(n+1, vector<int>(m+1));
    vector<vector<bool>>vis(n+1, vector<bool>(m+1));
    vector<vector<pair<int, int>>>parent(n+1, vector<pair<int, int>>(m+1));
    vector<int>dx{0,0,1,-1};
    vector<int>dy{-1,1,0,0};
    queue<pair<int, int>>qu;
    qu.push(A_START);
    vis[A_START.first][A_START.second] = true;
    while(!qu.empty()){
        int curx = qu.front().first;
        int cury = qu.front().second;
        qu.pop();

        
        for(auto p: adj[curx][cury]){
            int newx = p.second.first;
            int newy = p.second.second;
            if(dis[newx][newy]>run[curx][cury]+1 && !vis[newx][newy]){
                vis[newx][newy] = true;
                run[newx][newy] = run[curx][cury] + 1;
                parent[newx][newy] = {curx, cury};
                qu.push({newx, newy});
            }
        }
    }
    string ans = "";
    for(int j=1;j<=m;j++){
        if(vis[1][j]){
            cout<<"YES\n";
            pair<int, int>cur = {1,j};
            pair<int, int>nxt = {1,j};

            while(true){
                nxt = parent[cur.first][cur.second];
                if(nxt.first<cur.first)ans += 'D';
                if(nxt.first>cur.first)ans += 'U';
                if(nxt.second<cur.second)ans += 'R';
                if(nxt.second>cur.second)ans += 'L';
                if(nxt == A_START)break;
                cur = nxt;
            }
            reverse(ans.begin(), ans.end());
            cout<<ans.length()<<"\n";
            cout<<ans<<"\n";
            return 0;

        }
        if(vis[n][j]){
            cout<<"YES\n";
            pair<int, int>cur = {n,j};
            pair<int, int>nxt = {n,j};

            while(true){
                nxt = parent[cur.first][cur.second];
                if(nxt.first<cur.first)ans += 'D';
                if(nxt.first>cur.first)ans += 'U';
                if(nxt.second<cur.second)ans += 'R';
                if(nxt.second>cur.second)ans += 'L';
                if(nxt == A_START)break;
                cur = nxt;
            }
            reverse(ans.begin(), ans.end());
            cout<<ans.length()<<"\n";
            cout<<ans<<"\n";
            return 0;
        }
    }
    for(int i=1;i<=n;i++){
        if(vis[i][1]){
            cout<<"YES\n";
            pair<int, int>cur = {i,1};
            pair<int, int>nxt = {i,1};

            while(true){
                nxt = parent[cur.first][cur.second];
                if(nxt.first<cur.first)ans += 'D';
                if(nxt.first>cur.first)ans += 'U';
                if(nxt.second<cur.second)ans += 'R';
                if(nxt.second>cur.second)ans += 'L';
                if(nxt == A_START)break;
                cur = nxt;
            }
            reverse(ans.begin(), ans.end());
            cout<<ans.length()<<"\n";
            cout<<ans<<"\n";
            return 0;
        }
        if(vis[i][m]){
            cout<<"YES\n";
            pair<int, int>cur = {i,m};
            pair<int, int>nxt = {i,m};

            while(true){
                nxt = parent[cur.first][cur.second];
                if(nxt.first<cur.first)ans += 'D';
                if(nxt.first>cur.first)ans += 'U';
                if(nxt.second<cur.second)ans += 'R';
                if(nxt.second>cur.second)ans += 'L';
                if(nxt == A_START)break;
                cur = nxt;
            }
            reverse(ans.begin(), ans.end());
            cout<<ans.length()<<"\n";
            cout<<ans<<"\n";
            return 0;
        }
    }
    cout<<"NO\n";
    return 0;
}
