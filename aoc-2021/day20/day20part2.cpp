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

set<pair<int,int>> enhance(const set<pair<int,int>> &light,const string &algo,int &max_r,int &min_r,int &max_c,int &min_c,bool &num){
    set<pair<int,int>> output;
    for(int i = min_r-3;i<max_r+3;i++){
        for(int j = min_c-3;j<max_c+3;j++){
            string binary;
            for(int k = -1;k<2;k++){
                for(int l = -1;l<2;l++){
                    int new_r = i + k;
                    int new_c = j + l;
                    if((light.find({new_r,new_c}) != light.end()) == num){
                        binary+="1";
                    }
                    else{
                        binary+="0";
                    }                        
                }
            }
            int index = stoi(binary,0,2);
            if((algo[index] == '#') != num){
                output.insert({i,j});
            }
        }
    }
    return output;
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    string algo;cin>>algo;cin.get();
    set<pair<int,int>> light;
    set<pair<int,int>> output;
    tuple<int,int,int,int> bounds;
    for(int i = 0;i<100;i++){
        for(int j = 0;j<100;j++){
            char c;cin>>c;
            if (c == '#'){
                light.insert({i,j});
            }
        }
    }

    for(int i = 0;i<50;i++){
        bounds = boundaries(light);
        bool num = false;
        if(i%2 == 0){
            num = true;
            light = enhance(light,algo,get<0>(bounds),get<1>(bounds),get<2>(bounds),get<3>(bounds),num);
            continue;
        }
        light = enhance(light,algo,get<0>(bounds),get<1>(bounds),get<2>(bounds),get<3>(bounds),num);
    }
    cout<<light.size()<<"\n";
}