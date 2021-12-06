#include <bits/stdc++.h>
using namespace std;

int main(){
    clock_t begin = clock();
    long long counter = 0;
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    vector<long long> sim (9,0);
    string line,num;cin>>line;
    stringstream ss(line);
    while(getline(ss,num,',')){
        sim[stoll(num)]++;
    }
    for(int i = 0;i<80;i++){
        long long temp = sim[0];
        for(int j = 1;j<sim.size();j++){
            counter++;
            sim[j-1] = sim[j]; 
        }
        sim[6]+=temp;
        sim[8] = temp;
    }
    long long ans = 0;
    for(int i = 0;i<sim.size();i++){
        ans+=sim[i];
    }
    cout<<ans<<"\n";
    printf("counter = %lld, computed in = %.12fs\n", counter, (double)(clock()-begin)/CLOCKS_PER_SEC);
    return 0;
}