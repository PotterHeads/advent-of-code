#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    vector<string> grid;
    while(!cin.eof()){
        string line;
        getline(cin,line);
        grid.push_back(line);
    }
    int rows = grid.size();
    int cols = grid[0].size();
    int steps = 0;
    while(true){
        steps++;
        set<pair<int,int>> s;
        bool moved = false;
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(grid[i][j] == '>'){
                    int new_j = (j+1)%cols;
                    if(grid[i][new_j] == '.'){
                        moved = true;
                        // Unable to change the values of the grid co-currently
                        s.insert({i,j}); // add into a set first before changing the values of the grid. 
                    }
                }        
            }
        }
        if(s.size() != 0){
            for(auto&[i,j]:s){
                grid[i][j] = '.';
                grid[i][(j+1)%cols] = '>';
            }
        }
        s.clear();
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(grid[i][j] == 'v'){
                    int new_i = (i+1)%rows;
                    if(grid[new_i][j] == '.'){
                        moved = true;
                        s.insert({i,j});
                    }
                }
            }
        }
        if(s.size() != 0){
            for(auto&[i,j]:s){
                grid[i][j] = '.';
                grid[(i+1)%rows][j] = 'v';
            }
        }        
        if(!moved){
            break;
        }
    }
    cout<<steps<<"\n";
    return 0;
}