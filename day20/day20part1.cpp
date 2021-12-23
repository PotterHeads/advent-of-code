#include <bits/stdc++.h>
using namespace std;

tuple<int,int,int,int> boundaries (const set<pair<int,int>> &light){
    int max_r = -1e9;
    int min_r = 1e9;
    int max_c = -1e9;
    int min_c = 1e9;
    for(auto &[r,c]:light){
        max_r = max(max_r,r);
        min_r = min(min_r,r);
        max_c = max(max_c,c);
        min_c = min(min_c,c);
    }
    return  {max_r,min_r,max_c,min_c};
}

set<pair<int,int>> steps(const set<pair<int,int>> &light,const string &algo,const vector<int> &r,const vector<int> &c, int &max_r,int &min_r,int &max_c,int &min_c){
    set<pair<int,int>> output;
    // cout<<max_r<<" "<<min_r<<" "<<max_c<<" "<<min_c<<"\n";
    for(int i = min_r-5;i<max_r+10;i++){
        for(int j = min_c-5;j<max_c+10;j++){
            string binary;
            for(int k = 0;k<8;k++){
                int new_r = i + r[i];
                int new_c = j + c[i];
                if(light.find({new_r,new_c}) == light.end()){
                    binary+="0";
                }
                else{
                    binary+="1";
                }
            }
            int index = stoi(binary,0,2);
            if(algo[index] == '#'){
                output.insert({i,j});
            }
        }
    }
    return output;
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in2.txt", "r", stdin);
    string algo;cin>>algo;cin.get();
    set<pair<int,int>> light;
    set<pair<int,int>> output;
    tuple<int,int,int,int> bounds;
    for(int i = 0;i<5;i++){
        for(int j = 0;j<5;j++){
            char c;cin>>c;
            if (c == '#'){
                light.insert({i,j});
            }
        }
    }
    vector<int> r = {-1,-1,-1,0,0,0,1,1,1};
    vector<int> c = {-1,0,1,-1,0,1,-1,0,1};
    for(int i = 0;i<1;i++){
        bounds = boundaries(light);
        light = steps(light,algo,r,c,get<0>(bounds),get<1>(bounds),get<2>(bounds),get<3>(bounds));
    }
    // for(auto &[u,v]:output){
    //     cout<<u<<" "<<v<<"\n";
    // }
    for(auto &[u,v]:light){
        cout<<u<<" "<<v<<"\n";
    }
    cout<<light.size()<<"\n";

}