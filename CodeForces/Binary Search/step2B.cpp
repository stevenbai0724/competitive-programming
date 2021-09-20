/*
ropes https://codeforces.com/edu/course/2/lesson/6/2/practice/contest/283932/problem/B

solution
-f(x) is a function: if it is possible to make k pieces of length x from all the ropes. 1 = possible, 0 = not possible
                    we are looking for the index of this
                                    v
f(x) =  1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0  0 0 0......

-since the length can be a double value of precision eps, the pointers l and r must run a minimum of log(maxValue/eps) times
-let s be the numbers of pieces of ropes and m is the midpoint of l and r
    -if s (each length m) is greater than k, the length is too small and we need to increase m so l=m
    -if s (each length m) is less than k, the length is too big so r = m
    -repeat this ~100 times 




*/

#include <bits/stdc++.h>
using namespace std;

int n, k; //n ropes, k pieces
vector<int>arr;

bool good(double x){
    int s = 0;

    for(int i =1;i<=n;i++){
        s+= (int)(arr[i]/x);
    }
    return (s>=k);
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    cin>>n>>k;
    arr.resize(n+1);

    for(int i =1;i<=n;i++){
        cin>>arr[i];
    }
    double l, r;
    l = 0, r = 1e18;

    for(int i =1;i<=100;i++){
        double m = (l+r)/2;
        if(good(m)){
            l = m;
        }
        else r = m;

    }
    cout<<setprecision(8)<<r;

    return 0;
}


