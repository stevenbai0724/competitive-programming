//https://codeforces.com/problemset/problem/119/A
#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);

    int a,b,k;
    cin>>a>>b>>k;

    while(true){

        

        int gcda = 1;
        for(int i =1;i<=min(a,k);i++){
            if(a%i==0 && k%i==0) gcda = i;
        }
        k-=gcda;


        if(k<0){
            cout<<1;
            return 0;
        }
        int gcdb = 1;
        for(int i=1;i<=min(b,k);i++){
            if(b%i==0 && k%i==0) gcdb =i;
        }
        k-=gcdb;
        
        if(k<0){
            cout<<0;
            return 0;
        }
    }




    return 0;
}
