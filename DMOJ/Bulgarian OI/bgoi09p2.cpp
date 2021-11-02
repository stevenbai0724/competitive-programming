//https://dmoj.ca/problem/bgoi09p2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t = 2;
    while(t--){
        int n; cin>>n;


        vector<int>indegree(n+1);
        vector<vector<int>>adj(n+1), rev(n+1);
        queue<int>q;
        set<int>added;
        set<pair<int, int>>nodes;
        map<int, int>mp;
        map<int, bool>inq;


        for(int i=1;i<=n;i++){
            int x; cin>>x;

            if(x==i){
                inq[i] = true;
                q.push(i);
                continue;
            }

            adj[x].push_back(i);
            rev[i].push_back(x);
            mp[x]++;

            indegree[i]++;


        }
        for(int i=1;i<=n;i++){
            if(indegree[i]==0 && !inq[i])q.push(i);
            nodes.insert({mp[i], i});
            assert(indegree[i]<=1);
        }
        int cnt = q.size();

        while(added.size()!=n){
            if(!q.empty()){
                while(!q.empty()){
                    int cur = q.front();
                    nodes.erase({mp[cur], cur});
                    added.insert(cur);
                    q.pop();
                    for(int nxt: adj[cur]){
                        indegree[nxt]--;
                        if(indegree[nxt]==0)q.push(nxt);
                    }

                }
            }
            else{
                int rando = (*nodes.rbegin()).second;
                vector<bool>vis(n+1);
                queue<int>rq;
                rq.push(rando);

                while(!rq.empty()){
                    int cur = rq.front();
                    vis[cur] = true;
                    rq.pop();
                    for(int nxt: rev[cur]){
                        if(!vis[nxt]){
                            vis[nxt] = true;
                            rq.push(nxt);
                        }
                        else{
                            q.push(cur);
                            cnt++;
                            goto nxt;
                        }
                    }
                }

                nxt:;
            }
        }

        cout<<cnt<<" ";


    }
    cout<<"\n";

    return 0;
}