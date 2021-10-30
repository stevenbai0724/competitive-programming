//https://dmoj.ca/problem/coci08c6p4
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>arr(n+1);
    deque<int>one, two, three;

    for(int i=1;i<=n;i++){
        cin>>arr[i];
        if(arr[i]%3==0)three.push_back(arr[i]);
        if(arr[i]%3==1)one.push_back(arr[i]);
        if(arr[i]%3==2)two.push_back(arr[i]);
    }

    int a = one.size();
    int b = two.size();
    int c = three.size();

    if((b==0 && c==0) ||(a==0 && c==0) ){ //all 1's or all 2's
        for(int i=1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
        return 0;
    }
    if(a==0 && b==0){ //all 3's
        cout<<"impossible\n";
        return 0;
    }
    if(a>0 && b>0 && c==0){ //all 1's and 2's
        cout<<"impossible\n";
        return 0;
    }
    if(a>0 && c>0 && b==0){ //all 1's and 3's
        if(c-1>a){
            cout<<"impossible\n";
            return 0;
        }
        bool pop3 = true;
        for(int i=1;i<=n;i++){
            if(pop3 && !three.empty()){
                cout<<three.back()<<" ";
                three.pop_back();
                pop3 = false;
            }
            else{
                cout<<one.back()<<" ";
                one.pop_back();
                pop3 = true;
            }
        }
        cout<<"\n";
        return 0;
    }
    if(b>0 && c>0 && a==0){ //all 2's and 3's
        if(c-1>b){
            cout<<"impossible\n";
            return 0;
        }
        bool pop3 = true;
        for(int i=1;i<=n;i++){
            if(pop3 && !three.empty()){
                cout<<three.back()<<" ";
                three.pop_back();
                pop3 = false;
            }
            else{
                cout<<two.back()<<" ";
                two.pop_back();
                pop3 = true;
            }
        }
        cout<<"\n";
        return 0;
    }
    if(c-1<=a+b && c>=1){
        int mid = three.back();
        three.pop_back();
        bool pop3 = true;

        while(!one.empty() || !two.empty() || !three.empty()){
            if(pop3 && !three.empty()){
                cout<<three.back()<<" ";
                three.pop_back();
                pop3 = false;      
            }
            else{
                if(!one.empty()){
                    cout<<one.back()<<" ";
                    one.pop_back();
                    pop3 = true;
                    if(one.empty()){
                        cout<<mid<<" ";
                        pop3 = false;
                    }
                }
                else{
                    cout<<two.back()<<" ";
                    two.pop_back();
                    pop3 =true;
                }
            }
        }
        cout<<"\n";
    }
    else cout<<"impossible\n";
    






    return 0;
}