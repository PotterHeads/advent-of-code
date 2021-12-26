#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int count = 0;
    int counter = 0;
    while(!cin.eof()){
        vector<int> ans(26,0);
        string line,intermediate,value;getline(cin,line);
        intermediate = line.substr(line.find('|')+1);
        stringstream ss(intermediate);
        while(getline(ss,value,' ')){
            if(value.empty()){
                continue;
            }
            if(value.size() == 5 or value.size() == 6){
                count++;
            }
            counter++;
        }
    }
    cout<<counter-count<<"\n";
    return 0;
}