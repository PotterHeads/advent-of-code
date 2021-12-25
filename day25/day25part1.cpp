#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen("in2.txt", "r", stdin);
    vector<string> grid;
    while(!cin.eof()){
        string line;
        getline(cin,line);
        grid.push_back(line);
    }
    int rows = grid.size();
    int cols = grid[0].size();
    int steps = 0;
    set<pair<int,int>> s;
    while(true){
        steps++;
        s.clear();
        bool moved = false;
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(grid[i][j] == '>' and s.find({i,j}) == s.end()){
                    int new_j = (j+1)%cols;
                    if(grid[i][new_j] == '.'){
                        moved = true;
                        grid[i][new_j] = '>';
                        s.insert({i,new_j});
                        grid[i][j] = '.';
                    }
                }        
            }
        }
        // cout<<"######"<<"\n";
        // for(int i = 0;i<rows;i++){
        //     for(int j = 0;j<cols;j++){
        //         cout<<grid[i][j];
        //     }
        //     cout<<"\n";
        // }
        // cout<<"######"<<"\n";
        s.clear();
        // for(int i = 0;i<cols;i++){
        //     for(int j = 0;j<rows;j++){
        //         if(grid[j][i] == 'v' and s.find({j,i}) == s.end()){
        //             int new_j = (j+1)%rows;
        //             if(grid[new_j][i] == '.'){
        //                 moved = true;
        //                 grid[new_j][i] = 'v';
        //                 grid[j][i] = '.';
        //                 s.insert({new_j,i});
        //             }
        //         }
        //     }
        // }
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(grid[i][j] == 'v' and s.find({i,j}) == s.end()){
                    int new_i = (i+1)%rows;
                    if(grid[new_i][j] == '.'){
                        moved = true;
                        grid[new_i][j] = 'v';
                        grid[i][j] = '.';
                        s.insert({new_i,j});
                    }
                }
            }
        }
        if(!moved){
            break;
        }
        if(steps == 2){
            break;
        }
    }
    // for(int i = 0;i<rows;i++){
    //     for(int j = 0;j<cols;j++){
    //         cout<<grid[i][j];
    //     }
    //     cout<<"\n";
    // }
    cout<<steps<<"\n";
    return 0;
}