//https://dmoj.ca/problem/dmopc14ce1p4
#include <bits/stdc++.h>
using namespace std;
struct edge{
    int x;
    int used;
    double time;
};
struct TIME{
    int used;
    double time;
};
class Compare{
    public:
        bool operator() (edge a, edge b){
            if(a.time == b.time){
                return a.used > b.used;
            }
            return a.time > b.time; 
        }
};
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin>>n;
    int m; cin>>m;
    vector<vector<pair<double, int>>>adj(n+1);
    vector<TIME>ans(n+1);
    vector<TIME>ans2(n+1);
    for(auto &nxt: ans){
        nxt.used = 1e9;
        nxt.time = 1e9;
    }
    for(auto &nxt: ans2){
        nxt.used = 1e9;
        nxt.time = 1e9;
    }
    ans[1].used = ans[1].time = 0;
    ans2[1].used = ans2[1].time = 0;

    for(int i=1;i<=m;i++){
        int x, y;
        cin>>x>>y;
        double d, s;
        cin>>d>>s;
        adj[x].push_back({d/s, y});
        adj[y].push_back({d/s, x});
    }
    double fact = 60.0000000000000000;
    priority_queue<edge, vector<edge>, Compare>q;
    q.push({1,0,0});
    while(!q.empty()){
        int cur = q.top().x;
        int used = q.top().used; 
        double t = q.top().time;
        q.pop();    
        for(auto PPP: adj[cur]){
            double newt = PPP.first * fact; 
            int nxt = PPP.second; 
            if(ans[nxt].time > t + newt){ 
                ans[nxt].time = t + newt;
                ans[nxt].used = used + 1;
                q.push({nxt, ans[nxt].used, ans[nxt].time});
            }
            else if(ans[nxt].time == t + newt && used + 1 < ans[nxt].used){
                ans[nxt].used = used + 1;
                q.push({nxt, ans[nxt].used, ans[nxt].time});
            }
        }
    }
    fact = 80.00000000000000;
    q.push({1,0,0});
    while(!q.empty()){
        int cur = q.top().x; 
        int used = q.top().used; 
        double t = q.top().time;
        q.pop();    
        for(auto PPP: adj[cur]){
            double newt = PPP.first * fact; 
            int nxt = PPP.second; 
            if(ans2[nxt].time > t + newt){ 
                ans2[nxt].time = t + newt;
                ans2[nxt].used = used + 1;
                q.push({nxt, ans2[nxt].used, ans2[nxt].time});
            }
            else if(ans2[nxt].time == t + newt && used + 1 < ans2[nxt].used){
                ans2[nxt].used = used + 1;
                q.push({nxt, ans2[nxt].used, ans2[nxt].time});
            }
        }
    }
    cout<<ans[n].used<<"\n"<<round(ans2[n].time - ans[n].time)<<"\n";
    return 0;
}
