#include <bits/stdc++.h>
using namespace std;

string parse (string &binary,long long &version){
    long long idx = 0;
    string packet_version = binary.substr(0,3);
    version+=stoll(packet_version,0,2);
    cout<<packet_version<<"\n";
    cout<<"version "<<version<<"\n";
    string packet_id= binary.substr(3,3);
    long long id = stoll(packet_id,0,2);
    idx+=6;
    if(id == 4){
        char bit = binary[6];
        while(bit!='0'){
            idx+=5;
            bit = binary[idx];
        }
        idx+=5;
        string new_str = binary.substr(idx);
        binary = new_str;
    }
    else{
        char bit = binary[6];
        if(bit == '0'){
            // cout<<"HERE"<<"\n";
            // cout<<"BINARY SDFSD654 "<<binary<<"\n";
            string length = binary.substr(7,15);
            // cout<<"BINARRSDFASD SD "<<length<<"\n";
            long long size = stoll(length,0,2);
            // cout<<"SIZE DSF "<<size<<"\n";
            string new_binary = binary.substr(22,size);
            // cout<<"HERE 2345 "<<new_binary<<"\n";
            // cout<<"HERE? "<<new_binary.size()<<"\n";
            while(new_binary.size() != 0){
                // cout<<"HERE OR THERE? "<<new_binary.size()<<"\n";
                // cout<<new_binary<<"\n";
                new_binary = parse(new_binary,version);
            }
            string new_str = binary.substr(22+size);
            binary = new_str;
        }
        // if(bit == '1'){
        else{
            string length = binary.substr(7,11);
            // cout<<"LENGTH "<<length<<"\n";
            long long size = stoll(length,0,2);
            // cout<<"SIZE "<<size<<"\n";
            for(int i = 0;i<size;i++){
                string new_str = binary.substr(18);
                // cout<<"NEW STR "<<new_str<<"\n";
                binary = parse(new_str,version);
            }
            // return parse(binary,version);
        }
    }
    // cout<<"PARSE FUNC "<<binary<<"\n";
    return binary;
    // return parse(binary,version); 
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in2.txt", "r", stdin);
    long long version = 0;
    int i = 0;
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
    cout<<"BINARY VALUE FIRST "<<binary<<"\n";
    parse(binary,version);
    cout<<"AFTER "<<binary<<"\n";
    cout<<"VERSION VALUE "<<version<<"\n";
    return 0;
}