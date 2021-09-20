#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    string str;
    cin>>str;   
    int streak, ans;
    streak = 1;
    ans = 0;

    for(int i = 0;i<str.length()-1; i++){
        if (str[i] ==str[i+1]){
            streak++;
        }
        else{
            ans = max(ans, streak);
            streak = 1;
        }
    }
    ans = max(ans, streak);

    cout<<ans;
    return 0;
}