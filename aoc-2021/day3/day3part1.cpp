#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    unordered_map<int,pair<int,int>> um;
    vector<char> ans;
    string gamma,epsilon;
    while(!cin.eof()){
        string n;cin>>n;
        for(int i = 0;i<n.length();i++){
            if(n[i] == '0'){
                um[i].first++;
            }
            else{
                um[i].second++;
            }
        }
    }
    for(int i = 0;i<um.size();i++){
        if(um[i].first > um[i].second){
            ans.push_back('0');
        }
        else{
            ans.push_back('1');
        }
    }

    for(int i = 0;i<ans.size();i++){
        gamma+=ans[i];
        if(ans[i] == '0'){
            epsilon+='1';
        }
        else{
            epsilon+='0';
        }
    }
    
    int gamma_dec = stoi(gamma,nullptr,2);
    int epsilon_dec = stoi(epsilon,nullptr,2);
    cout<<epsilon_dec*gamma_dec<<"\n";
    return 0;
}