#include <bits/stdc++.h>
using namespace std;

bool checkboard(const vector<vector<bool>> &visited, const vector<vector<int>> &board){
    for(int i = 0;i<5;i++){
        int count = 0;
        for(int j = 0;j<5;j++){
            if(visited[i][j] != true){
                break;
            }
            count++;
        }
        if(count == 5){
            return true;
        }

    }
    for(int i = 0;i<5;i++){
        int count = 0;
        for(int j = 0;j<5;j++){
            if(visited[j][i] != true){
                break;
            }
            count++;
        }
        if(count == 5){
            return true;
        }
    }
    return false;
}

void calculate(const vector<vector<bool>> &visited, const vector<vector<int>> &board, int &num_drawn){
    int sum = 0;
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            if(!visited[i][j]){
                sum+=board[i][j];
            }
        }
    }
    cout<<sum*num_drawn<<"\n";
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    vector<int> num;
    vector<vector<vector<int>>> board;
    vector<vector<vector<bool>>> visited;
    vector<vector<bool>> check(5,vector<bool>(5,false));
    while(true){
        string line,digit;getline(cin,line);
        istringstream iss(line);
        while(getline(iss,digit,',')){
            num.push_back(stoi(digit));
        }
        break;
    }
    while(!cin.eof()){
        cin.get();
        vector<vector<int>> arr(5,vector<int> (5));
        for(int i = 0;i<5;i++){
            string line,intermediate;getline(cin,line);
            istringstream iss(line);
            for(int j = 0;j<5;j++){
                iss>>intermediate;
                int value = stoi(intermediate);
                arr[i][j] = value;
            }
        }
        board.push_back(arr);
        visited.push_back(check);
    }
    for(int i = 0;i<num.size();i++){
        int num_drawn = num[i];
        for(int h = 0;h<board.size();h++){
             for(int j = 0;j<5;j++){
                for(int k = 0;k<5;k++){
                    if (board[h][j][k] == num_drawn){
                        visited[h][j][k] = true;
                        if(checkboard(visited[h],board[h])){
                            calculate(visited[h],board[h],num_drawn);
                            return 0;
                        }
                    }
                }
             }
        }
    }
    return 0;
}