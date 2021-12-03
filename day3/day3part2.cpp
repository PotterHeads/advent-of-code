#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    unordered_map<string,pair<bool,bool>> um;
    string oxygen,carbon_dioxide;
    while(!cin.eof()){
        string s;cin>>s;
        um[s] = {true,true};
    }
    for(int i = 0;i<12;i++){
        int count = 0; 
        int size = 0;
        for(auto &[key,value] : um){
            if(value.first){
                size++;
            }
            if(key[i] == '1' && value.first){
                count++;
            }
        }

        if(size == 1){
            break;
        }

        if(count >= size-count){
            for(auto &[key,value]:um){
                if(key[i] != '1'){
                    um[key].first = false;
                }
            }
        }
        else{
            for(auto &[key,value]:um){
                if(key[i] != '0'){
                    um[key].first = false;
                }
            }
        }
        // cout<<"\n";
        // cout<<"ROUND "<<i<<" "<<size<<" "<<count<<"\n";
        // cout<<"================================================================="<<"\n";
        // for(auto &[key,value] : um){
        // // if(value > 0){
        //     cout<<key<<" "<<value.first<<"\n";
        // // }
        // }
    }
    for(int i = 0;i<12;i++){
        int count = 0; 
        int size = 0;
        for(auto &[key,value] : um){
            if(value.second){
                size++;
            }
            if(key[i] == '0' && value.second){
                count++;
            }
        }
        if (size == 1){
            break;
        }
        if(count <= size-count){
            for(auto &[key,value]:um){
                if(key[i] != '0'){
                    um[key].second = false;
                }
            }
        }
        else{
            for(auto &[key,value]:um){
                if(key[i] != '1'){
                    um[key].second = false;
                }
            }
        }
        // cout<<"\n";
        // cout<<"ROUND "<<i<<" "<<size<<" "<<count<<"\n";
        // cout<<"================================================================="<<"\n";
        // for(auto &[key,value] : um){
        // // if(value > 0){
        //     cout<<key<<" "<<value.second<<"\n";
        // // }
        // }
    }
    for(auto &[key,value] : um){
        if(value.first > 0){
            oxygen = key;
        }
        if(value.second > 0){
            carbon_dioxide = key;
        }
    }
    int oxygen_dec = stoi(oxygen,nullptr,2);
    int carbon_dioxide_dec = stoi(carbon_dioxide,nullptr,2);
    cout<<oxygen_dec*carbon_dioxide_dec<<"\n";
    return 0;
}