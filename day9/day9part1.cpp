#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int row = 100;
    string grid[row];
    vector<int> r = {0,0,1,-1};
    vector<int> c = {1,-1,0,0};
    int sum = 0;
    for(int i = 0;i<row;i++){
        getline(cin,grid[i]);
    }
    int col = grid[0].size();
    cout<<col<<"\n";
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
            sum+=(curr_val+1);
        }
    }
    cout<<sum<<"\n";
    return 0;
}