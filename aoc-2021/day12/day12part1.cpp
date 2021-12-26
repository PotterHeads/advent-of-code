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
    queue<pair<string,unordered_set<string>>> q;
    q.push({"start",{"start"}});
    while(!q.empty()){
        string input = q.front().first;
        for(auto &v:AL[input]){
            unordered_set<string> us = q.front().second;
            char c = v[0];
            if (v == "end"){
                us.insert(v);
                // for(auto &v:us){
                //     cout<<v<<" "; 
                // }
                // cout<<"\n";
                path++;
            }
            else if(islower(c)){
                if(us.find(v) == us.end()){
                    us.insert(v);
                    q.push({v,us});
                }
            }
            else{
                us.insert(v);
                q.push({v,us});
            }
        }
        q.pop();

    }
    cout<<path<<"\n";
    return 0;
}