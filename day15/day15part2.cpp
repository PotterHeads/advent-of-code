#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int row = 100;
    int col = 100;
    int multiple = 5;
    int new_row = multiple*row;
    int new_col = multiple*col;
    vector<vector<int>> grid(row,vector<int>(col,0));
    vector<int> r = {-1,1,0,0};
    vector<int> c = {-0,0,-1,1};
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            char n;cin>>n;
            grid[i][j] = n - '0';
        }
    } 
    vector<vector<int>> large_grid(new_row,vector<int>(new_col,0));
    for(int k = 0;k<5;k++){
        for(int i = 0;i<new_row;i++){
            for(int j = 0;j<new_col;j++){
                if(k == 0){
                    large_grid[i][j] = grid[i%row][j%col];
                }              
                else{
                    if(i >= k*row){
                    large_grid[i][j]++;
                    if(large_grid[i][j] == 10){
                        large_grid[i][j] = 1; 
                        }                         
                    }
                    if(j >= k*col){
                    large_grid[i][j]++;
                    if(large_grid[i][j] == 10){
                        large_grid[i][j] = 1; 
                        }                         
                    }                      
                }
            }
        }
    }
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
    vector<vector<int>> dist(new_row,vector<int>(new_col,1e9));
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
            if(new_r < new_row and new_c < new_col and new_r >= 0 and new_c >=0){
                if(d + large_grid[new_r][new_c] >= dist[new_r][new_c]){
                    continue;
                }
                dist[new_r][new_c] = d + large_grid[new_r][new_c];
                pq.push({dist[new_r][new_c],{new_r,new_c}});
            }
        }
    }
    cout<<dist[new_row-1][new_col-1]<<"\n";
    // for(int i = 0;i<new_row;i++){
    //     for(int j = 0;j<new_col;j++){
    //         cout<<large_grid[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
}