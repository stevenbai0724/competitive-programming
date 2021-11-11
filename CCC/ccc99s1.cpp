//https://dmoj.ca/problem/ccc99s1
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string


signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    map<string, int>mp;
    mp["ace"] = 4;
    mp["king"] = 3;
    mp["queen"] = 2;
    mp["jack"] = 1;

    vector<int>psa(53);
    vector<string>cards(53);

    for(int i=1;i<=52;i++){
        string s; cin>>s;
        cards[i] = s;
        psa[i] = psa[i-1];
        psa[i] += (mp[s]>0);
    }
    int A = 0;
    int B = 0;
    for(int i=1;i<=52;i++){
        if(i&1){
            if(cards[i]=="ace" && i<=48){
                if(psa[i+4]-psa[i]==0){
                    A+=4;
                    cout<<"Player A scores "<<4<<" point(s).\n";
                }
            }
            if(cards[i]=="king" && i<=49){
                if(psa[i+3]-psa[i]==0){
                    A+=3;
                    cout<<"Player A scores "<<3<<" point(s).\n";
                }
            }
            if(cards[i]=="queen" && i<=50){
                if(psa[i+2]-psa[i]==0){
                    A+=2;
                    cout<<"Player A scores "<<2<<" point(s).\n";
                }
            }
            if(cards[i]=="jack" && i<=51){
                if(psa[i+1]-psa[i]==0){
                    A++;
                    cout<<"Player A scores "<<1<<" point(s).\n";
                }
            }
        }
        else {
            if(cards[i]=="ace" && i<=48){
                if(psa[i+4]-psa[i]==0){
                    B+=4;
                    cout<<"Player B scores "<<4<<" point(s).\n";
                }
            }
            if(cards[i]=="king" && i<=49){
                if(psa[i+3]-psa[i]==0){
                    B+=3;
                    cout<<"Player B scores "<<3<<" point(s).\n";
                }
            }
            if(cards[i]=="queen" && i<=50){
                if(psa[i+2]-psa[i]==0){
                    B+=2;
                    cout<<"Player B scores "<<2<<" point(s).\n";
                }
            }
            if(cards[i]=="jack" && i<=51){
                if(psa[i+1]-psa[i]==0){
                    B++;
                    cout<<"Player B scores "<<1<<" point(s).\n";
                }
            }
        }
    }
    cout<<"Player A: "<<A<<" point(s).\n";
    cout<<"Player B: "<<B<<" point(s).\n";


    return 0;
}