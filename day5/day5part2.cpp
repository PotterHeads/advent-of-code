#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in2.txt", "r", stdin);
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
        else if (abs(x2-x1) == abs(y2-y1)){
            for(int i = 0;i<=abs(y2-y1);i++){
                // arr[a + i*(c-a)/abs(c-a)][b + i*(d-b)/abs(d-b)]++;
                int change_x = x1 + i*(x2-x1)/abs(x2-x1);
                int change_y = y1 + i*(y2-y1)/abs(y2-y1);
                cout<<"i "<<i<<" x "<<change_x<<" y "<<change_y<<"\n";
            }
        }
    }
    // cout<<ans<<"\n";
    return 0;
}

 
            // int change_x = abs(x2-x1);
            // int change_y = abs(y2-y1);
            // if(change_x == change_y){
            //     int start_x = min(x1,x2);
            //     int end_x = max(x1,x2);
            //     int start_y = min(y1,y2);
            //     int end_y = max(y1,y2);
            //     for(int i = start_x;i<=end_x;i++){
            //         for(int j = start_y;j<=end_y;j++){
            //             int changex = abs(i-x1);
            //             int changey = abs(j-y1);
            //             if(changex == changey){
            //                 AM[i][j]++;
            //                 if(AM[i][j] == 2){
            //                     ans++;
            //                 }                            
            //             }
            //             // AM[i][j]++;
            //             // if(AM[i][j] == 2){
            //             //     ans++;
            //             // }
            //         }
            //     }
            // }