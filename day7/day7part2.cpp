#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    vector<int> locations;
    string line,num;cin>>line;
    stringstream ss(line);
    int sum = 1e9;
    int max_value = -1;
    int min_value = 1e9;
    while(getline(ss,num,',')){
        max_value = max(max_value,stoi(num));
        min_value = min(min_value,stoi(num));
        locations.push_back(stoi(num));
    }
    // brute force
    for(int i = 0;i<max_value-min_value+1;i++){
        int curr_sum = 0;
        for(int j = 0;j<locations.size();j++){
            for(int k = 1;k<=abs(locations[j]-i);k++){
                curr_sum +=k;
            }
        }
        sum = min(sum,curr_sum);
    }
    // smarter way (using mean)
    
    cout<<sum<<"\n";
    return 0;
}