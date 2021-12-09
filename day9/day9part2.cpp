#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int row = 100;
    long long sum = 1;
    string grid[row];
    vector<int> r = {0,0,1,-1};
    vector<int> c = {1,-1,0,0};
    vector<pair<int,int>> basins;
    priority_queue<int> pq;
    for(int i = 0;i<row;i++){
        getline(cin,grid[i]);
    }
    int col = grid[0].size();
    vector<vector<int>> visited(row,vector<int>(col,0));
    queue<pair<int,int>> q;
    q.push({0,0});
    visited[0][0] = 1;
    while(!q.empty()){
        int curr_r = q.front().first;
        int curr_c = q.front().second;
        int curr_val = grid[curr_r][curr_c] - '0';
        q.pop();
        bool flag = false;
        for(int i = 0;i<4;i++){
            int new_r = curr_r + r[i];
            int new_c = curr_c + c[i];
            if(new_r < row and new_c < col and new_r >= 0 and new_c >= 0){
                int val = grid[new_r][new_c] - '0';
                if(curr_val >= val){
                    flag = true;
                }
                if(visited[new_r][new_c] == 0){
                    q.push({new_r,new_c});
                    visited[new_r][new_c] = 1;
                }
            }
        }
        if(!flag){
            basins.push_back({curr_r,curr_c});
        }
    }
    visited.clear();
    visited.resize(row,vector<int>(col,0));
    for(auto &[u,v]:basins){
        int count = 1;
        queue<pair<int,int>> q;
        q.push({u,v});
        visited[u][v] = 1;
        while(!q.empty()){
            int curr_r = q.front().first;
            int curr_c = q.front().second;
            int curr_val = grid[curr_r][curr_c] - '0';
            q.pop();
            for(int i = 0;i<4;i++){
                int new_r = curr_r + r[i];
                int new_c = curr_c + c[i];
                if(new_r < row and new_c < col and new_r >= 0 and new_c >= 0 and visited[new_r][new_c] == 0){
                    int val = grid[new_r][new_c] - '0';
                    if(val != 9){
                        count++;
                        q.push({new_r,new_c});
                        visited[new_r][new_c] = 1;
                    } 
                }
            }
        }
        pq.push(count);
    }
    int i = 1;
    while(i <= 3){
        i++;
        sum*=pq.top();
        pq.pop();
    }
    cout<<sum<<"\n";
    return 0;
}