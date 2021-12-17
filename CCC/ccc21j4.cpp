//
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>    
using namespace __gnu_pbds;
using namespace std;

#define int long long
#define string std::string
const int mod = 1e9 + 7;
mt19937_64 rng(std::chrono::system_clock::now().time_since_epoch().count());

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin>>s;
    int n = s.length();
    int large = 0;
    int med = 0;
    int small = 0;

    multiset<int>LM;
    multiset<int>LS;
    multiset<int>ML;
    multiset<int>MS;
    multiset<int>SL;
    multiset<int>SM;

    for(int i=0;i<n;i++){
        char c = s[i];
        large += c=='L';
        med += c=='M';
        small += c=='S';
    }

    for(int i=0;i<large;i++){
        char c = s[i];
        if(s[i]=='M')ML.insert(i);
        if(s[i]=='S')SL.insert(i);
    }
    for(int i=large;i<large+med;i++){
        char c = s[i];
        if(s[i]=='L')LM.insert(i);
        if(s[i]=='S')SM.insert(i);
    }
    for(int i=large+med;i<n;i++){
        char c = s[i];
        if(s[i]=='L')LS.insert(i);
        if(s[i]=='M')MS.insert(i);
    }
    int ans = 0;

    for(int i = 0; i<large; i++){
        if(s[i]=='M'){
            if(!LM.empty()){
                auto ind1 = ML.find(i);
                auto ind2 = LM.begin();

                s[i] = 'L';
                s[*ind2] = 'M';

                ML.erase(ind1);
                LM.erase(ind2);
                ans ++;

            }
            else{
                auto ind1 = ML.find(i);
                auto ind2 = LS.begin();

                s[i] = 'L';
                s[*ind2] = 'M';
                MS.insert(*ind2);
                ML.erase(ind1);
                LS.erase(ind2);
                ans ++;

            }
        }
        if(s[i]=='S'){
            if(!LS.empty()){
                auto ind1 = SL.find(i);
                auto ind2 = LS.begin();

                s[i] = 'L';
                s[*ind2] = 'S';

                SL.erase(ind1);
                LS.erase(ind2);
                ans ++;

            }
            else{
                auto ind1 = SL.find(i);
                auto ind2 = LM.begin();

                s[i] = 'L';
                s[*ind2] = 'S';
                SM.insert(*ind2);
                SL.erase(ind1);
                LM.erase(ind2);
                ans ++;
            }
        }
    }

    for(int i = large; i<large+med; i++){
        if(s[i]=='L'){
            if(!ML.empty()){
                auto ind1 = LM.find(i);
                auto ind2 = ML.begin();

                s[i] = 'M';
                s[*ind2] = 'L';

                LM.erase(ind1);
                ML.erase(ind2);
                ans ++;

            }
            else{
                auto ind1 = LM.find(i);
                auto ind2 = MS.begin();

                s[i] = 'M';
                s[*ind2] = 'L';

                LS.insert(*ind2);
                LM.erase(ind1);
                MS.erase(ind2);
                ans ++;
            }
        }
        if(s[i]=='S'){
            if(!MS.empty()){
                auto ind1 = SM.find(i);
                auto ind2 = MS.begin();

                s[i] = 'M';
                s[*ind2] = 'S';

                SM.erase(ind1);
                MS.erase(ind2);
                ans ++;

            }
            else{
                auto ind1 = SM.find(i);
                auto ind2 = ML.begin();

                s[i] = 'M';
                s[*ind2] = 'S';
                SL.insert(*ind2);
                SL.erase(ind1);
                LM.erase(ind2);
                ans ++;
            }
        }
    }
    cout<<ans<<"\n";




    
    return 0;
}