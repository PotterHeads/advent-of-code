#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int row = 10;
    int col = 10;
    int flash = 0;
    vector<vector<int>> grid(row,vector<int>(col));
    vector<int> r = {-1,-1,-1,0,0,1,1,1};
    vector<int> c = {-1,0,1,-1,1,-1,0,1};
    for(int i = 0;i<row;i++){
        for(int j = 0;j<col;j++){
            char c;cin>>c;
            grid[i][j] = c-'0';
        }
    }
    for(int k = 0;k<100;k++){
        queue<pair<int,int>> q;
        for(int i = 0;i<row;i++){
            for(int j = 0;j<col;j++){
                grid[i][j]+=1;
                if(grid[i][j] == 0){
                    continue;
                }
                else if(grid[i][j] == 10){
                    grid[i][j] = 0;
                    flash++;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int curr_r = q.front().first;
            int curr_c = q.front().second;
            q.pop();
            for(int p = 0;p<8;p++){
                int new_r = curr_r + r[p];
                int new_c = curr_c + c[p];
                if(new_r < row and new_c < col and new_r >= 0 and new_c >=0){
                    if(grid[new_r][new_c] == 0){
                        continue;
                    }
                    grid[new_r][new_c]+=1;
                    if(grid[new_r][new_c] == 10){
                        flash++;
                        grid[new_r][new_c] = 0;
                        q.push({new_r,new_c});
                    }

                }
            }
        }
    }
    cout<<flash<<"\n";
    return 0;
}