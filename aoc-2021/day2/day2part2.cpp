#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    int horizontal = 0;
    int depth = 0;
    int aim = 0;
    while(!cin.eof()){
        int instructions;
        string s;cin>>s>>instructions;
        if(s == "forward"){
            horizontal+=instructions;
            depth +=(aim*instructions);
        }
        else if (s == "up"){
            aim-=instructions;
        }
        else{
            aim+=instructions;
        }
    }
    cout<<horizontal*depth<<"\n";
    return 0;
}