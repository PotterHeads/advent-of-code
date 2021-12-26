#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    unordered_map<string,vector<string>> AL;
    int path = 0;
    while(!cin.eof()){
        string line,before,after;getline(cin,line);
        before = line.substr(0,line.find('-'));
        after = line.substr(line.find('-')+1);
        AL[before].push_back(after);
        AL[after].push_back(before);
    }
    queue<pair<bool,pair<string,unordered_map<string,int>>>> q;
    q.push({false,{"start",{{"start",1}}}});
    while(!q.empty()){
        string input = q.front().second.first;
        for(auto &v:AL[input]){
            unordered_map<string,int> um = q.front().second.second;
            bool twice = q.front().first;
            char c = v[0];
            if(v == "start"){
                continue;
            }
            if (v == "end"){
                um["end"]++;
                path++;
            }
            else if(islower(c)){
                if(!twice){
                    um[v]++;
                    if(um[v] == 2){
                        twice = true;
                    }
                    q.push({twice,{v,um}});
                }
                else if(um.find(v) == um.end()){
                    um[v]++;
                    q.push({twice,{v,um}});
                }
            }
            else{
                um[v]++;
                q.push({twice,{v,um}});
            }
        }
        q.pop();
    }
    cout<<path<<"\n";
    return 0;
}