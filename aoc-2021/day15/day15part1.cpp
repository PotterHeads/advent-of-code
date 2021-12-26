#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int row = 100;
    int col = 100;
    vector<vector<int>> grid(row,vector<int>(col));
    vector<vector<int>> dist(row,vector<int>(col,1e9));
    vector<int> r = {-1,1,0,0};
    vector<int> c = {-0,0,-1,1};
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            char n;cin>>n;
            grid[i][j] = n - '0';
        }
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{0,0}});
    dist[0][0] = 0;
    while(!pq.empty()){
        auto[d,corrd] = pq.top();
        int curr_r = corrd.first;
        int curr_c = corrd.second;
        pq.pop();
        if(d > dist[curr_r][curr_c]){
            continue;
        }
        for(int i = 0;i<4;i++){
            int new_r = curr_r + r[i];
            int new_c = curr_c + c[i];
            if(new_r < row and new_c < col and new_r >= 0 and new_c >=0){
                if(d + grid[new_r][new_c] >= dist[new_r][new_c]){
                    continue;
                }
                dist[new_r][new_c] = d + grid[new_r][new_c];
                pq.push({dist[new_r][new_c],{new_r,new_c}});
            }
        }
    }
    cout<<dist[row-1][col-1]<<"\n";
    // for(int i = 0;i<row;i++){
    //     for(int j = 0;j<col;j++){
    //         cout<<dist[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
}