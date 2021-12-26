#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen("in2.txt", "r", stdin);
    vector<string> grid;
    vector<string> grid2;
    vector<string> grid3;
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
        bool moved = false;
        grid2 = grid;
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                if(grid[i][j] == '>' ){
                    int new_j = (j+1)%cols;
                    if(grid[i][new_j] == '.'){
                        moved = true;
                        grid2[i][new_j] = '>';
                        grid2[i][j] = '.';
                    }
                }        
            }
        }
        grid3 = grid2;
        cout<<"######"<<"\n";
        for(int i = 0;i<rows;i++){
            for(int j = 0;j<cols;j++){
                cout<<grid2[i][j];
            }
            cout<<"\n";
        }
        cout<<"######"<<"\n";
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
                if(grid2[i][j] == 'v'){
                    int new_i = (i+1)%rows;
                    if(grid2[new_i][j] == '.'){
                        moved = true;
                        grid3[new_i][j] = 'v';
                        grid3[i][j] = '.';
                    }
                }
            }
        }
        if(!moved){
            break;
        }
        grid = grid3;
        if(steps == 1){
            break;
        }
    }
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            cout<<grid3[i][j];
        }
        cout<<"\n";
    }
    cout<<steps<<"\n";
    return 0;
}