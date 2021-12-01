#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    vector<int> v;
    int count = 0;
    while(!cin.eof()){
        int n;cin>>n;
        if(v.empty()){
            v.push_back(n);
        }
        else{
            if(n>v.back()){
                count++;
            }
            v.push_back(n);
        }
    }
    cout<<count<<"\n";
    return 0;
}