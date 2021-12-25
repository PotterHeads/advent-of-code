#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen("in2.txt", "r", stdin);
    int rows = 9;
    int cols = 10;
    int steps = 0;
    string grid[rows];
    for(int i = 0;i<cols;i++){
        getline(cin,grid[i]);
    }
    deque<tuple<int,int,int>> dq;
    set<pair<int,int>> s;
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            if(grid[i][j] == '>'){
                dq.push_front({steps,i,j});
            }
            else if(grid[i][j] == 'v'){
                dq.push_back({steps,i,j});
            }
        }
    }
    int original = dq.size();
    while(!dq.empty()){
        int curr_steps = get<0>(dq.front());
        int curr_r = get<1>(dq.front());
        int curr_c = get<2>(dq.front());
        curr_steps++;
        steps = curr_steps;
        if(grid[curr_r][curr_c] == '>'){
            int new_r = curr_r + 1;
            if(new_r >= cols){
                new_r%=cols;
            }
            if(grid[new_r][curr_c] == '.'){
                grid[new_r][curr_c] == '>';
                grid[curr_r][curr_c] == '.';
                dq.pop_front();
                dq.push_back({new_r,curr_c,steps});
            }
            // else{
            //     s.insert()
            // }
        }
        // else{} 
        // if(!mark){}
    }
    // cout<<steps<<"\n";
    return 0;
}