#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    vector<vector<int>> AM(1000,vector<int>(1000,0));
    int x1,y1,x2,y2;
    string s;
    char c;
    int ans = 0;
    while(cin>>x1>>c>>y1>>s>>x2>>c>>y2){
        if(x1 == x2){
            int start = min(y1,y2);
            int end = max(y1,y2);
            for(int i = start;i<=end;i++){
                AM[x1][i]++;
                if(AM[x1][i] == 2){
                    ans++;
                }
            }
        }
        else if(y1 == y2){
            int start = min(x1,x2);
            int end = max(x1,x2);
            for(int i = start;i<=end;i++){
                AM[i][y2]++;
                if(AM[i][y2] == 2){
                    ans++;
                }
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}