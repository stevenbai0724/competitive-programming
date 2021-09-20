//
#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define string std::string
signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);


    vector<int>K1, K2;


    for(int num=1;num<=9;num++){
        for(int j=1;j<=9;j++){
            int add = num;
            for(int k=1;k<j;k++){
                add *= 10;
                add += num;
                
            }
            K1.push_back(add);
        }
    }
    sort(K1.begin(), K1.end());

    for(int first=0;first<9;first++){
        for(int second=first+1;second<=9;second++){ //second is good

            for(int len = 1; len<= 9; len++){
                for(int i=1;i<(1<<len);i++){
                    string add = "";

                    for(int j=1;j<=len;j++){
                        add += (char)(first+48);
                    }
                    for(int j=0;j<len;j++){
                        if((1<<j)&i ){
                            add[j] = (char)(second+48);
                        }
                    }

                    K2.push_back(stoi(add));
                }
            }

        }
    }
    sort(K2.begin(), K2.end());


    int t; cin>>t;

    while(t--){
        int n, k;
        cin>>n>>k;

        if(n==1e9 &&k==1){
            cout<<"1111111111\n";
            continue;
        }
        if(n==1e9 &&k==2){
            cout<<1000000000<<"\n";
            continue;
        }
        if(k==1){
            cout<<*lower_bound(K1.begin(), K1.end(), n);
        }
        else{
            cout<<min(*lower_bound(K1.begin(), K1.end(), n), *lower_bound(K2.begin(), K2.end(), n));
        }
        cout<<"\n";
    }


    return 0;
}