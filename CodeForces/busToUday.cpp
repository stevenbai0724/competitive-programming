#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin>>n;
    bool yes = false;
    vector<vector<char>>arr(n+1, vector<char>(6));
   
    for(int i =1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=5;j++){
            arr[i][j] = s[j-1];
        }
    }
    for(int i =1;i<=n;i++){
        for(int j=1;j<=5;j++){
            if(arr[i][j] == 'O' && arr[i][j-1] =='O'){
                yes = true;
                arr[i][j] = '+';
                arr[i][j-1] = '+';
                break;
            }
            if(yes)break;
        }
    }
    if(!yes) cout<<"NO";
    else{
        cout<<"YES"<<"\n";
        for(int i =1;i<=n;i++){
            for(int j=1;j<=5;j++){
                cout<<arr[i][j];
            }
            cout<<"\n";
        }
    }
    return 0;
}