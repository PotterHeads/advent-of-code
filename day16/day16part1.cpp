#include <bits/stdc++.h>
using namespace std;

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
    string line,binary;cin>>line;
    for(int i = 0;i<line.size();i++){
        binary+=um[line[i]];
    }
    while(i<binary.size()){
        string packet_version = binary.substr(i,i+3);
        if(packet_version == "000" or i+6>binary.size()){
            break;
        }
        version+=stoll(packet_version,0,2);
        string packet_id = binary.substr(i+3,i+6);
        long long id = stoll(packet_id,0,2);
        i+=6; //increase counter
        if(id == 4){
            char bit = binary[i];
            while(bit!='0'){
                i+=5;
                bit = binary[5];
            }
            i+=5;
        }
        else{
            char bit = binary[i];
            if(bit == '0'){
                string length = binary.substr(i,i+14);
                long long size = stoll(length,0,2);
                i+=14;
                while(size){

                }
            }
            else {}
        }  
    }
    // string packet_version = binary.substr(0,0+3);
    // cout<<packet_version;
    // string hello = "000001011";
    // cout<<stoll(hello,0,2)<<"\n";
    return 0;
}