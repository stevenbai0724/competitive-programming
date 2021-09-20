#include <bits/stdc++.h>
using namespace std;

vector<int>roomCords;
vector<int>changeX{-1,1,0,0};
vector<int>changeY{0,0,-1,1};

int binarySearch(int num){

    int l = 0;
    int r = roomCords.size();

    while(l<r){
        int m = (l+r)/2;

        if(roomCords.at(m)>num){
            r = m;
        }
        if(roomCords.at(m)<num){
            l = m;
        }
        if(roomCords.at(m)==num){
            return m;
        }
    }

}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int count = 0;
    int n, m;
    cin>>n>>m;
    vector<vector<char>>arr(n+1, vector<char>(m+1));

    for(int i =1;i<=n;i++){
        string s; cin>>s;
        for(int j=1;j<=m;j++){
            arr[i][j] = s[j-1];
            if(s[j-1]=='.'){
                roomCords.push_back(i*2000+j);
            }
        }   
    }
    sort(roomCords.begin(), roomCords.end());

    while(!roomCords.empty()){

        int x = roomCords.back()/2000;
        int y = roomCords.back()%2000;
        vector<vector<bool>>vis(n+1, vector<bool>(m+1));
        vis[x][y] = true;
        queue<int>q;
        q.push(roomCords.back());
        roomCords.pop_back();

   
        while(!q.empty()){
            int curx = q.front()/2000;
            int cury = q.front()%2000;
            q.pop();
            for(int i =0;i<4;i++){
                int newx = curx + changeX[i];
                int newy = cury + changeY[i];

                if(newx>0 && newx<=n && newy>0 && newy<=m){
                    if(arr[newx][newy]!='#' && !vis[newx][newy]){
                        vis[newx][newy] = true;
                        q.push(newx*2000 + newy);
                        roomCords.erase(roomCords.begin()+binarySearch(newx*2000+newy));
                    }
                }
            }
        }
        count++;

    }
    cout<<count;

    return 0;
}