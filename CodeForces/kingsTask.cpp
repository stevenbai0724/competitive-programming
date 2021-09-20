//https://codeforces.com/problemset/problem/1510/K
#include <bits/stdc++.h>
using namespace std;
#define int long long 

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

        int n; cin>>n;
        vector<int>arr(2*n + 1);
        vector<int>sorted;
        vector<int>og;
        for(int i=1;i<=2*n;i++){
            cin>>arr[i];
        }
        sorted = arr;
        og = arr;
        sort(sorted.begin(), sorted.end());

        if(arr==sorted){
            cout<<0<<"\n";
            return 0;
        }
        
        int ans1 = 0;
        bool found = false;
        for(int ty = 1;ty<=2*n;ty++){
            
            if(ans1&1){
                for(int i=1;i<=n;i++){
                    int temp = arr[i+n];
                    arr[i+n] = arr[i];
                    arr[i] = temp;
                }
                
            }
            else{
                for(int i=1;i<2*n;i++){
                    if(i&1){
                        int temp = arr[i+1];
                        arr[i+1] = arr[i];
                        arr[i] = temp;
                    }
                }

            }
            ans1++;
            if(arr==sorted){
                found = true;
                break;
            }

        }
        arr = og;
        int ans2 = 0;
        for(int ty = 1;ty<=2*n;ty++){
            
            if(!(ans2&1)){
                for(int i=1;i<=n;i++){
                    int temp = arr[i+n];
                    arr[i+n] = arr[i];
                    arr[i] = temp;
                }
                
            }
            else{
                for(int i=1;i<2*n;i++){
                    if(i&1){
                        int temp = arr[i+1];
                        arr[i+1] = arr[i];
                        arr[i] = temp;
                    }
                }

            }
            ans2++;
            if(arr==sorted){
                found = true;
                break;
            }

        }
        if(!found){
            cout<<-1<<"\n";
            return 0;
        }

        cout<<min(ans1, ans2)<<"\n";



    return 0;
}