//https://codeforces.com/contest/1551/problem/C
#include <bits/stdc++.h>
using namespace std;
#define int long long 

struct edge{
    int DOM, LEFT, DIFF;
};
bool comp(edge a, edge b){
    return a.DIFF<b.DIFF;
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){

        int n; cin>>n;


        vector<vector<edge>>arr(6);

        for(int i=1;i<=n;i++){
            string s; cin>>s;
            int len = s.length();
            int a = 0;
            int b = 0;
            int c = 0;
            int d = 0;
            int e = 0;

            for(char ch: s){
                if(ch=='a')a++;
                if(ch=='b')b++;
                if(ch=='c')c++;
                if(ch=='d')d++;
                if(ch=='e')e++;
            }

            arr[1].push_back({a, len-a, a+a-len});
            arr[2].push_back({b, len-b, b+b-len});
            arr[3].push_back({c, len-c, c+c-len});
            arr[4].push_back({d, len-d, d+d-len});
            arr[5].push_back({e, len-e, e+e-len});

        }
        for(int i=1;i<=5;i++){
            sort(arr[i].begin(), arr[i].end(), comp);
        }
        int mx = 0;
        for(int i=1;i<=5;i++){
            int dom = 0;
            int left = 0;
            
            for(int j=0;j<n;j++){
                dom += arr[i][j].DOM;
                left += arr[i][j].LEFT;
            }

            if(dom>left){
                mx = n;
                goto nxt;
            }

            for(int j=0;j<n;j++){
                dom -= arr[i][j].DOM;
                left -= arr[i][j].LEFT;
                if(dom>left){
                    mx = max(mx, n-(j+1));
                    break;
                }
            }
        }
        nxt:;
        cout<<mx<<"\n";





    }


    return 0;
}