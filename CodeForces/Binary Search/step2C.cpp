//Very easy task https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/C
/*

there is one sheet of paper and 2 printers which can be used at the same time
the printers copy 1 sheet of paper every x and y seconds respectively, copies can be copied
what is min time to create n sheets?

solution:

just like all the problems in step 2 of this problem set, we will define a function that has good and bad numbers (1s and 0s)
let f(x) be a function- if at least n copies can be made in x seconds 
good() function: 
    -find min. time to create a second copy. now both printers can be active.
    -(x- min.time) is the time to create copies after we have obtained 2 copies. Set this as T
    -if T/x + T/y + 2 >n, r = m (time can be reduced)
    -else l = m  (not enough time)

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, x, y;

bool good(int time){

    int t = time - min(x,y);
    if (t<=0) return false;
    return ((floor(t/x) + floor(t/y)+2) > n);

}
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);


    cin>>n>>x>>y;

    if(n ==1){
        cout<<min(x,y);
        return 0;
    }
    else{
        int l, r;
        l = 1;
        r = 1e18;

        while(l+1<r){
            int m = (l+r)/2;

            if(good(m)) r = m;
            else l = m;
        }

        cout<<r;

        return 0;
    }
}