//
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
struct edge{
    int d, c, y;
};
class Compare{
    public:
        bool operator() (edge a, edge b){
            if(a.d == b.d){
                return a.c > b.c;
            }
            else return a.d > b.d;
        }
};
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    //sort edges by d, break ties with c, y
    //{distance, edge count, cur node}

    
    priority_queue<edge, vector<edge>, Compare>q;

    q.push({53,6,1});
    q.push({53,324,1});
    q.push({53,-1352,345});
    q.push({254,5313,54});
    q.push({-1,-1,-1});

    while(!q.empty()){
        int d = q.top().d;
        int c = q.top().c;
        int y = q.top().y;

        q.pop();
        cout<<d<<" "<<c<<" "<<y<<"\n";
    }


    return 0;
}
