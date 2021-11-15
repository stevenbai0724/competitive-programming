//https://dmoj.ca/problem/fhc15c2p1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

void print(int t, string s){
    cout<<"Case #"<<t<<":"<<" "<<s<<"\n";
}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int bruh; cin>>bruh;
    for(int t=1;t<=bruh;t++){
        int n; cin>>n;
        deque<int>START, END, TEMP;

        for(int i=1;i<=n;i++){
            int x; cin>>x;
            START.push_back(x);
        }
        TEMP = START;

        END.push_back(START.front());
        START.pop_front();

        while(!START.empty()){
            int L = START.front();
            int R = START.back();
            int needR = END.back()+1;
            int needL = END.front()-1;
            bool found = false;
            if(L == needL){
                START.pop_front();
                END.push_front(needL);
                found = true;
                continue;
            }
            if(L == needR){
                START.pop_front();
                END.push_back(needR);
                found = true;
                continue;
            }
            if(R== needL){
                START.pop_back();
                END.push_front(needL);
                found = true;
                continue;
            }
            if(R == needR){
                START.pop_back();
                END.push_back(needR);
                found = true;
                continue;
            }

            if(!found){
                goto nxt;
            }
        }
        print(t, "yes");
        continue;
        nxt:;

        START = TEMP;
        END.clear();
        END.push_back(START.back());
        START.pop_back();

        while(!START.empty()){
            int L = START.front();
            int R = START.back();
            int needR = END.back()+1;
            int needL = END.front()-1;
            bool found = false;
            if(L == needL){
                START.pop_front();
                END.push_front(needL);
                found = true;
                continue;
            }
            if(L == needR){
                START.pop_front();
                END.push_back(needR);
                found = true;
                continue;
            }
            if(R== needL){
                START.pop_back();
                END.push_front(needL);
                found = true;
                continue;
            }
            if(R == needR){
                START.pop_back();
                END.push_back(needR);
                found = true;
                continue;
            }

            if(!found){
                print(t, "no");
                goto nxt2;
            }
        }
        print(t, "yes");
        nxt2:;

    }

    return 0;
}