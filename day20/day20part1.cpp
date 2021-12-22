#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in2.txt", "r", stdin);
    string algo;cin>>algo;cin.get();
    set<pair<int,int>> s;
    set<pair<int,int>> all_coord;
    set<pair<int,int>> light;
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            char c;cin>>c;
            if (c == '#'){
                s.insert({i,j});
            }
            all_coord.insert({i,j});
        }
    }
    vector<int> r = {-1,-1,-1,0,0,0,1,1,1};
    vector<int> c = {-1,0,1,-1,0,1,-1,0,1};
    queue<pair<int,int>> q;
    for(auto &[u,v]:all_coord){
        q.push({u,v});
    }
    while(!q.empty()){
        string binary;
        int curr_r = q.front().first;
        int curr_c = q.front().second;
        // cout<<"CURR "<<curr_r<<" "<<curr_c<<"\n";
        q.pop();
        for(int i = 0;i<9;i++){
            int new_r = curr_r + r[i];
            int new_c = curr_c + c[i];
            // cout<<"NEW "<<new_r<<" "<<new_c<<"\n";
            pair<int,int> corrd = {new_r,new_c};
            if(s.find(corrd) == s.end()){
                binary+="0";
            }
            else{
                binary+="1";
            }
        }
        // cout<<"OK "<<binary<<"\n";
        int index = stoi(binary,0,2);
        if(algo[index] == '#'){
            s.insert({curr_r,curr_c});
        }
    }
    cout<<s.size()<<"\n";
    return 0;
}