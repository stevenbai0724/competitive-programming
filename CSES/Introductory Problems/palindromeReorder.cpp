//https://cses.fi/problemset/task/1755
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string s; cin>>s;
    vector<int>arr(91);
    vector<int>ans;
    int oddCount = 0;
    int oddIndex = 0;

    for(int i=0;i<s.length();i++){
        arr[(int)(s[i])]++;
    }
    for(int i=65;i<=90;i++){
        if(arr[i]%2==1){
            oddIndex = i;
            oddCount++;
        }
    }
    if(oddCount>1){
        cout<<"NO SOLUTION";
        return 0;
    }
    for(int i=65;i<=90;i++){
        if(arr[i]!=0 && i!=oddIndex){
            for(int j=1;j<=arr[i]/2;j++){
                cout<<(char)i;
            }
            arr[i]/=2;
        }
    }
    for(int i =1;i<=arr[oddIndex];i++){
        cout<<(char)oddIndex;
    }
    for(int i=90;i>=65;i--){
        if(arr[i]!=0 && i!=oddIndex){
            for(int j=1;j<=arr[i];j++){
                cout<<(char)i;
            }
        }
    }
    return 0;
}