#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m, k;
    cin>>n>>m>>k;

    int count = 0;
    vector<int>arr(n+1);
    vector<int>apt(m+1);

    for(int i =1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i =1;i<=m;i++){
        cin>>apt[i];
    }

    sort(arr.begin(), arr.end());
    sort(apt.begin(), apt.end());


    int applicant = 1;
    int apartment = 1; 

    while(applicant<=n && apartment<=m){
        if(abs(arr[applicant] - apt[apartment]) <=k){
            applicant++;
            apartment++;
            count++;
  
        }
        else{
            if(arr[applicant] >apt[apartment]){
                apartment++;
            }
            else applicant++;
        }
    }
    cout<<count;

    return 0;
}