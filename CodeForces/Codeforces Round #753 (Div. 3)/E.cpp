//https://codeforces.com/contest/1607/problem/E
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        string s; cin>>s;

        int x = 0;
        int y = 0;
        int top = 0;
        int bottom = 0;
        int left = 0;
        int right = 0;
        int width = 1;
        int height = 1;


        for(auto c: s){

            if(c=='L'){
                y--;
                left = min(left, y);
                width = right-left+1;
                if(width>m){
                    left++;
                    break;
                }

            }
            if(c=='R'){
                y++;
                right = max(right, y);
                width = right-left+1;
                if(width>m){
                    right--;
                    break;
                }
            }
            if(c=='U'){
                x--;
                top = min(top, x);
                height = bottom-top + 1;
                if(height>n){
                    top++;
                    break;
                }
            }
            if(c=='D'){
                x++;
                bottom = max(bottom, x);
                height = bottom-top+1;
                if(height>n){
                    bottom--;
                    break;
                }

            }
        }

        cout<<(-top)+1<<" "<<(-left)+1<<"\n";

    }


    return 0;
}