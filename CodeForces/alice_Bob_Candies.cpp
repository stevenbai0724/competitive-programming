#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int t; cin>>t;

    for(t; t>0;t--){

        int n; cin>>n;
        int sum = 0;
        int curAlice = 0;
        int curBob = 0;
        int totalAlice = 0;
        int turns = 1;
        vector<int>arr;

        for(int i=1;i<=n;i++){
            int x; cin>>x;
            arr.push_back(x);
            sum+=x;
        }
        curAlice = arr.front();
        totalAlice+=curAlice;
        arr.erase(arr.begin());

        while(!arr.empty()){
            if(!arr.empty()){
                while(curBob<=curAlice){
                    if(arr.empty())break;
                    curBob+= arr.back();
                    arr.pop_back();
                }
                turns++;
                curAlice = 0;
            }

            if(!arr.empty()){
                while(curAlice<=curBob){
                    if(arr.empty())break;
                    curAlice+=arr.front();
                    arr.erase(arr.begin());
                }
                totalAlice+=curAlice;
                curBob =0;
                turns++;
            }
        }

        cout<<turns<<" "<<totalAlice<<" "<<sum-totalAlice<<"\n";
    }

    return 0;
}