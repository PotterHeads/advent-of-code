#include <bits/stdc++.h>
using namespace std;

// immediately edit the string to remove unecessary bits 
pair<string,long long> parse (string &binary){
    string packet_version = binary.substr(0,3);
    binary = binary.substr(3);
    string packet_id= binary.substr(0,3);
    long long id = stoll(packet_id,0,2);
    binary = binary.substr(3);
    if(id == 4){
        string num;
        while(true){
            num+=binary.substr(0,5);
            char bit = binary[0];
            binary = binary.substr(5);
            if(bit == '0'){
                break;
            }
        }
        long long value = stoll(num,0,2);
        return {binary,value};
    }
    else{
        vector<long long> storage;
        char bit = binary[0];
        binary = binary.substr(1);
        if(bit == '0'){
            string length = binary.substr(0,15);
            binary = binary.substr(15);
            long long size = stoll(length,0,2);
            string new_binary = binary.substr(0,size);
            while(new_binary.size() != 0){
                pair<string,long long> p = parse(new_binary);
                storage.push_back(p.second);
                new_binary = p.first;
            }
            binary = binary.substr(size);
        }
        else{
            string length = binary.substr(0,11);
            binary = binary.substr(11);
            long long size = stoll(length,0,2);
            for(long long i = 0;i<size;i++){
                pair<string,long long> p = parse(binary);
                storage.push_back(p.second);
                binary = p.first;
            }
        }
        if(id == 0){
            long long total = 0;
            for(long long i = 0;i<storage.size();i++){
                total += storage[i];
            }
            return {binary,total};
        }
        if(id == 1){
            long long total = 1;
            for(long long i = 0;i<storage.size();i++){
                total *= storage[i];
            }
            return {binary,total};            
        }
        if(id == 2){
            long long min_value = 1e18;
            for(long long i = 0;i<storage.size();i++){
                min_value = min(min_value,storage[i]);
            }            
            return {binary,min_value};
        }
        if(id == 3){
            long long max_value = 0;
            for(long long i = 0;i<storage.size();i++){
                max_value = max(max_value,storage[i]);
            }            
            return {binary,max_value};
        }
        if(id == 5){
            if(storage[0] > storage[1]){
                return {binary,1LL};
            }
            return {binary,0LL};
        }
        if(id == 6){
            if(storage[0] < storage[1]){
                return {binary,1LL};
            }
            return {binary,0LL};
        }
        if(id == 7){
            if(storage[0] == storage[1]){
                return {binary,1LL};
            }
            return {binary,0LL};            
        }
    }
    return {binary,0LL};
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in2.txt", "r", stdin);
    unordered_map<char,string> um = {
        {'0',"0000"},
        {'1', "0001"},
        {'2', "0010"},
        {'3', "0011"},
        {'4', "0100"},
        {'5', "0101"},
        {'6', "0110"},
        {'7', "0111"},
        {'8', "1000"},
        {'9', "1001"},
        {'A', "1010"},
        {'B', "1011"},
        {'C', "1100"},
        {'D', "1101"},
        {'E', "1110"},
        {'F', "1111"}
    };
    string line,binary,test;cin>>line;
    for(int i = 0;i<line.size();i++){
        binary+=um[line[i]];
    }
    pair<string,long long> p = parse(binary);
    cout<<"FINAL "<<p.second<<"\n";
    return 0;
}