#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    vector<int> v;
    vector<int> arr;
    int count = 0;
    while(!cin.eof()){
        int n;cin>>n;
        arr.push_back(n);
    }
    for(int i = 0;i<arr.size();i++){
        if(i == arr.size()-2){
            break;
        }
        int first = arr[i];
        int second = arr[i+1];
        int third = arr[i+2];
        int final = first+second+third;
        v.push_back(final);
    }
    for(int i = 1;i<v.size();i++){
        if(v[i] > v[i-1]){
            count++;
        }
    }
    cout<<count<<"\n";
    return 0;
}