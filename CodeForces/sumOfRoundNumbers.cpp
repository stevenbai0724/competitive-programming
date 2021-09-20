#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n; cin>>n;
    vector<int>mult{1,1,10,100,1000,10000};
    for(int i =1;i<=n;i++){

        int x; cin>>x;
        vector<int>arr;
        vector<int>ans;
        if(x>=1 && x<=9){
            cout<<1<<"\n"<<x<<"\n";
        }
        else{

            for(int j = 1;j<=5;j++){
                int m = (x/mult[j])%10;
                arr.push_back(m*mult[j]);
            }
            for(int i=0;i<arr.size();i++){
                if(arr.at(i)!=0)ans.push_back(arr.at(i));
            }
            cout<<ans.size()<<"\n";
            for(int i =0; i<ans.size();i++){
                cout<<ans.at(i)<<" ";
            }
            cout<<"\n";
        }
        
        


    }
    



    return 0;
}
