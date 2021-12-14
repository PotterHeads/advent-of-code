#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in2.txt", "r", stdin);
    unordered_map<int,vector<int>> um;
    queue<pair<char,int>> q;
    int count = 0;
    bool instructions = false;
    int max_x = -1;
    int max_y = -1;
    while(!cin.eof()){
        string line;getline(cin,line);
        if(line.size() == 0){
            instructions = true;
        }
        else if(instructions){
            string order,value;
            istringstream iss(line);
            while(iss>>order){
                if(order[0] == 'x' or order[0] == 'y'){
                    value = line.substr(line.find('=')+1);
                    q.push({order[0],stoi(value)});
                }
            }
        }
        else{
            string x = line.substr(0,line.find(','));
            string y = line.substr(line.find(',')+1);
            int r = stoi(x);
            int c = stoi(y);
            max_x = max(max_x,r);
            max_y = max(max_y,c);
            um[r].push_back(c);
        }
    }
    int col = max_x + 1;
    int row = max_y + 1;
    vector<vector<char>> AM(row,vector<char>(col,'.'));
    for(auto &r:um){
        for(auto &c:um[r.first]){
            AM[c][r.first] = '#';
            count++;
        }
    }
    while(!q.empty()){
        char axis = q.front().first;
        int value = q.front().second;
        q.pop();
        if(axis == 'y'){
            for(int i = 1;i<=value;i++){
                for(int j = 0;j<col;j++){
                    char c = AM[value+i][j];
                    if(c == '#'){
                        char new_space = AM[value-i][j];
                        if(new_space != '#'){
                            count++;
                            AM[value-i][j] = '#';
                        }
                    }
                }
            }
            row = value;
        }
        else{
            for(int i = 0;i<row;i++){
                for(int j = 1;j<=value;j++){
                    char c = AM[i][value+j];
                    if(c =='#'){
                        char new_space = AM[i][value-j];
                        if(new_space != '#'){
                            count++;
                            AM[i][value-j] = '#';
                        }
                    }
                }
            }
            col = value;
        }
    }
    // for(int i = 0;i<row;i++){
    //     for(int j = 0;j<col;j++){
    //         cout<<AM[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    cout<<count<<"\n";
    return 0;
}