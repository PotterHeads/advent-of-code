#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    vector<int> locations;
    string line,num;cin>>line;
    stringstream ss(line);
    int sum = 1e9;
    while(getline(ss,num,',')){
        locations.push_back(stoi(num));
    }
    // brute force
    for(int i = 0;i<locations.size();i++){
        int curr_value = locations[i];
        int curr_sum = 0;
        for(int j = 0;j<locations.size();j++){
            curr_sum+= abs(locations[j]-curr_value);
        }
        sum = min(sum,curr_sum);
    }
    // smarter way (using median)
    
    cout<<sum<<"\n";
    return 0;
}