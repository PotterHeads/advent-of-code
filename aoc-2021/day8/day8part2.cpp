#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    long long sum = 0;
    while(!cin.eof()){
        string output;
        unordered_map<int,vector<pair<string,set<char>>>> um1;
        unordered_map<string,int> um2;
        string line,before,after,key,value;getline(cin,line);
        before = line.substr(0,line.find('|'));
        after = line.substr(line.find('|')+1);
        stringstream ss(before);
        stringstream ss2(after);
        while(getline(ss,key,' ')){
            sort(key.begin(),key.end());
            set<char> s;
            for(int i = 0;i<key.size();i++){
                s.insert(key[i]);
            }
            if(key.size() != 5 or key.size() != 6){
                if(key.size() == 2){
                    um2[key] = 1;
                }
                else if(key.size() == 3){
                    um2[key] = 7;
                }
                else if(key.size() == 4){
                    um2[key] = 4;
                }
                else{
                    um2[key] = 8;
                }
            }
            um1[key.size()].push_back({key,s});
        }
        for(int i = 0;i<um1[5].size();i++){   
            if(includes(um1[5][i].second.begin(),um1[5][i].second.end(),um1[2].back().second.begin(),um1[2].back().second.end())){
                um2[um1[5][i].first] = 3;
                continue;
            }
            set<int> intersection;
            set_intersection(um1[5][i].second.begin(),um1[5][i].second.end(),um1[4].back().second.begin(),um1[4].back().second.end(),inserter(intersection,intersection.begin()));
            if(intersection.size() == 3){
                um2[um1[5][i].first] = 5;
            }
            else{
                um2[um1[5][i].first] = 2;
            }
        }
        for(int i = 0;i<um1[6].size();i++){   
            if(includes(um1[6][i].second.begin(),um1[6][i].second.end(),um1[4].back().second.begin(),um1[4].back().second.end())){
                um2[um1[6][i].first] = 9;
                continue;
            }
            else if(includes(um1[6][i].second.begin(),um1[6][i].second.end(),um1[3].back().second.begin(),um1[3].back().second.end())){
                um2[um1[6][i].first] = 0;
                continue;
            }
            else{
                um2[um1[6][i].first] = 6;
            }
        }
        while(getline(ss2,value,' ')){
            if(value.empty()){
                continue;
            }
            sort(value.begin(),value.end());
            output+=to_string(um2[value]);
        }
        sum+=stoll(output);
    }
    cout<<sum<<"\n";
    return 0;
}
