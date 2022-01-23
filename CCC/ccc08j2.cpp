//https://dmoj.ca/problem/ccc08j2
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define double long double
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >
//order_of_key
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    deque<char>s;
    s.push_back('A');
    s.push_back('B');
    s.push_back('C');
    s.push_back('D');
    s.push_back('E');

    while(true){
        int x; cin>>x;
        int t; cin>>t;
        while(t--){
            if(x == 4){
                while(!s.empty()){
                    cout<<s.front()<<" ";
                    s.pop_front();
                }
                cout<<"\n";
                return 0;
            }
            if(x == 1){
                char c = s.front();
                s.pop_front();
                s.push_back(c);
            }
            if(x == 2){
                char c = s.back();
                s.pop_back();
                s.push_front(c);
            }
            if(x == 3){
                char a = s.front();
                s.pop_front();
                char b = s.front();
                s.pop_front();

                s.push_front(a);
                s.push_front(b);
            }
        }
    }

    return 0;
}
