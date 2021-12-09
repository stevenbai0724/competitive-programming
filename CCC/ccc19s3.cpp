//https://dmoj.ca/problem/ccc19s3
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <cmath>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define string std::string
//#define set tree < long long ,  null_type ,  less<long long> ,  rb_tree_tag ,  tree_order_statistics_node_update >

signed main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int n = 3;
    vector<vector<string>>arr(4, vector<string>(4));
    int Xs = 0;
    int num = 1;
    for(int i=1;i<=3;i++){
        for(int j=1;j<=3;j++){
            cin>>arr[i][j];
            Xs += (arr[i][j] == "X");
            if(arr[i][j] != "X")num = stoi(arr[i][j]);
        }
    }
    if(Xs >= 7){
        if(Xs == 9 || Xs == 8){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    cout<<num<<" ";
                }
                cout<<"\n";
            }
            return 0;
        }
        vector<int>row(4), col(4);
        vector<bool>visR(4), visC(4);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(arr[i][j]!="X"){
                    int x = stoi(arr[i][j]);
                    visR[i] = true;
                    visC[j] = true;
                    row[i] = x;
                    col[j] = x;
                }
            }
        }
        if(!visR[1] && visR[2] && visR[3]){
            int b = row[2];
            int c = row[3];
            int a = 2*b - c;

            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i == 1)arr[i][j] = to_string(a);
                    else if(i == 2)arr[i][j] = to_string(b);
                    else arr[i][j] = to_string(c);
                }
            }

        }
        else if(!visR[2] && visR[1] && visR[3]){
            int a = row[1];
            int c = row[3];
            int b = (a+c)/2;

            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i == 1)arr[i][j] = to_string(a);
                    else if(i == 2)arr[i][j] = to_string(b);
                    else arr[i][j] = to_string(c);
                }
            }

        }
        else if(!visR[3] && visR[1] && visR[2]){
            int a = row[1];
            int b = row[2];
            int c = 2*b - a;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(i == 1)arr[i][j] = to_string(a);
                    else if(i == 2)arr[i][j] = to_string(b);
                    else arr[i][j] = to_string(c);
                }
            }
        }
        else if(!visC[1] && visC[2] && visC[3]){
            int b = col[2];
            int c = col[3];
            int a = 2*b - c;

            for(int j=1;j<=n;j++){
                for(int i=1;i<=n;i++){
                    if(j == 1)arr[i][j] = to_string(a);
                    else if(j == 2)arr[i][j] = to_string(b);
                    else arr[i][j] = to_string(c);
                }
            }

        }
        else if(!visC[2] && visC[1] && visC[3]){
            int a = col[1];
            int c = col[3];
            int b = (a+c)/2;

            for(int j=1;j<=n;j++){
                for(int i=1;i<=n;i++){
                    if(j == 1)arr[i][j] = to_string(a);
                    else if(j == 2)arr[i][j] = to_string(b);
                    else arr[i][j] = to_string(c);
                }
            }
        }
        else if(!visC[3] && visC[1] && visC[1]){
            int a = col[1];
            int b = col[2];
            int c = 2*b - a;
            for(int j=1;j<=n;j++){
                for(int i=1;i<=n;i++){
                    if(j == 1)arr[i][j] = to_string(a);
                    else if(j == 2)arr[i][j] = to_string(b);
                    else arr[i][j] = to_string(c);
                }
            }

        }
        else assert(false);

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<"\n";
        }
        return 0;

    }

    
    for(int t=1;t<=200;t++){
        for(int i=1;i<=n;i++){
            vector<string>temp;
            int cnt = 0;
            for(int j=1;j<=n;j++){
                temp.push_back(arr[i][j]);
                cnt += (arr[i][j] == "X");
            }            
            if(cnt == 1){
                if(temp[0] == "X")temp[0] = to_string(2*(stoi(temp[1])) - stoi(temp[2]));
                else if(temp[1] == "X")temp[1] = to_string (stoi(temp[0]) + (stoi(temp[2])-stoi(temp[0]))/2);
                else temp[2] = to_string((2*stoi(temp[1])) - stoi(temp[0]));
                for(int j=1;j<=n;j++){
                    arr[i][j] = temp[j-1];
                }
            }
        }
        for(int i=1;i<=n;i++){
            vector<string>temp;
            int cnt = 0;
            for(int j=1;j<=n;j++){
                temp.push_back(arr[j][i]);
                cnt += (arr[j][i] == "X");
            }            
            if(cnt == 1){
                if(temp[0] == "X")temp[0] = to_string(2*(stoi(temp[1])) - stoi(temp[2]));
                else if(temp[1] == "X")temp[1] = to_string (stoi(temp[0]) + (stoi(temp[2])-stoi(temp[0]))/2);
                else temp[2] = to_string((2*stoi(temp[1])) - stoi(temp[0]));
                for(int j=1;j<=n;j++){
                    arr[j][i] = temp[j-1];
                }
            }
        }

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

    return 0;
}