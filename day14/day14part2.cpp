#include <bits/stdc++.h>
using namespace std;

int main(){
    clock_t begin = clock();
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    unordered_map<string,string> inputs;
    unordered_map<string,long long> pairings;
    unordered_map<char,long long> quantity;
    long long max_value = -1e18; //long long 
    long long min_value = 1e18;
    long long counter = 0;
    string polymer;getline(cin,polymer);cin.get();
    for(int i = 0;i<polymer.size()-1;i++){
            string value;
            value.push_back(polymer[i]);value.push_back(polymer[i+1]);
            pairings[value]++;
    }
    while(!cin.eof()){
        string before,arrow,after;cin>>before>>arrow>>after;
        inputs[before] = after;
    }
    for(int i = 0;i<40;i++){
        unordered_map<string,long long> temp;
        for(auto &v:pairings){
            counter++;
            string element,first_element,second_element;
            element = inputs[v.first];
            first_element = v.first[0] + element;
            second_element = element + v.first[1];
            temp[first_element] += v.second;
            temp[second_element] += v.second;
        }
        pairings = temp;
    }
    for(auto &v:pairings){
        quantity[v.first[0]]+=v.second;
        quantity[v.first[1]]+=v.second;
    }
    for(auto &v:quantity){
        if(v.second%2==0){
            max_value = max(max_value,v.second/2);
            min_value = min(min_value,v.second/2);
            continue;
        }
        max_value = max(max_value,(v.second+1)/2);
        min_value = min(min_value,(v.second+1)/2);
    }
    // cout<<max_value<<" "<<min_value<<"\n";
    cout<<max_value-min_value<<"\n";
    printf("counter = %lld, computed in = %.12fs\n", counter, (double)(clock()-begin)/CLOCKS_PER_SEC);
    return 0;
}