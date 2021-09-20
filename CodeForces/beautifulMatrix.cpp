#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<vector<int>>arr(6, vector<int>(6));
    int x, y;

    for(int i =1;i<=5;i++){
        for(int j =1;j<=5;j++){
            cin>>arr[i][j];
            if(arr[i][j]==1){
                x = i;
                y = j;
            }
        }
    }
    cout<<abs(x-3)+abs(y-3);

    return 0;
}