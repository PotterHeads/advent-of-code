#include <bits/stdc++.h>
using namespace std;

// immediately edit the string to remove unecessary bits 
string parse (string &binary,long long &version){
    string packet_version = binary.substr(0,3);
    version+=stoll(packet_version,0,2);
    binary = binary.substr(3);
    string packet_id= binary.substr(0,3);
    long long id = stoll(packet_id,0,2);
    binary = binary.substr(3);
    if(id == 4){
        string num;
        while(true){
            num+=binary.substr(1,4);
            char bit = binary[0];
            binary = binary.substr(5);
            if(bit == '0'){
                break;
            }
        }
    }
    else{
        char bit = binary[0];
        binary = binary.substr(1);
        if(bit == '0'){
            string length = binary.substr(0,15);
            binary = binary.substr(15);
            long long size = stoll(length,0,2);
            string new_binary = binary.substr(0,size);
            while(new_binary.size() != 0){
                new_binary = parse(new_binary,version);
            }
            binary = binary.substr(size);
        }
        else{
            string length = binary.substr(0,11);
            binary = binary.substr(11);
            long long size = stoll(length,0,2);
            for(long long i = 0;i<size;i++){
                binary = parse(binary,version);
            }
        }
    }
    return binary;
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    long long version = 0;
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
    parse(binary,version);
    cout<<version<<"\n";
    return 0;
}