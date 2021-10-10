// //https://dmoj.ca/problem/dmopc17c4p3
// #include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace std;
// using namespace __gnu_pbds;
// #define int long long
// #define string std::string

// int n; 
// int mx = 0;
// bool mult = false;
// int START = 0;
// vector<vector<pair<int, int>>>adj;
// vector<int>colour;
// vector<int>parent;
// vector<int>dis;
// int dia = 0;

// void clear(){
//     fill(parent.begin(), parent.end(), 0);
//     fill(colour.begin(), colour.end(), 0);
//     fill(dis.begin(), dis.end(), 0);
//     mx = 0;

// }
// void dfs(int v){
//     colour[v] = 1;

//     for(auto p: adj[v]){
//         int w = p.first;
//         int u = p.second;

//         if(colour[u] == 0){
//             dis[u] = dis[v] + w;
//             parent[u] = v;
//             if(dis[u] == mx){
//                 mult = true;
//             }
//             if(dis[u]>mx){
//                 mx = dis[u];
//                 START = u;
//                 mult = false;
//             }

//             dfs(u);
//         }
//     }

//     colour[v] = 2;
// }
// signed main(){
//     cin.tie(nullptr)->sync_with_stdio(false);

//     cin>>n;

//     adj.resize(n+1);
//     colour.resize(n+1);
//     dis.resize(n+1);
//     parent.resize(n+1);

//     for(int i=1;i<n;i++){
//         int x, y, w;
//         cin>>x>>y>>w;

//         adj[x].push_back({w,y});
//         adj[y].push_back({w,x});
//     }

//     dfs(1);

//     clear();
//     int a = START;
//     dfs(START);
    
//     int b = START;
//     int nxt = 
//     b = parent[b];

    
//     while(true){
//         if(parent[nxt] == a){
//             break;
//         }
//         nxt = parent[nxt];
//     }
//     a = nxt;

//     dia = dis[START];

//     if(mult)cout<<dia<<"\n";
//     else cout<<max(dis[b], dia-dis[a])<<"\n";
    



//     return 0;
// }