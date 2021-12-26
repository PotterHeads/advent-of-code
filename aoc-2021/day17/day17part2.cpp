#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    // target area: x=282..314, y=-80..-45
    set<pair<int,int>> s;
    int ans = 0;
    int count = 0;
    for(int dx = 0;dx<315;dx++){ //dx is the x-velocity
        for(int dy = -100;dy<1000;dy++){ //dy is the y-velocity
            int x = 0;
            int y = 0;
            int change_x = dx;
            int change_y = dy;
            int max_y = 0;
            for(int i = 0;i<200;i++){ // brute force 200 times
                x+=change_x;
                y+=change_y;
                max_y = max(max_y,y);
                if(change_x >0){
                    change_x--;
                }
                else if(change_x <0){
                    change_x++;
                }
                change_y--;
                if(x >= 282 and x <= 314 and y >= -80 and y <= -45){
                // if(x >= 20 and x <= 30 and y >= -10 and y <= -5){
                    s.insert({dx,dy});
                }
            }
        }
    }
    cout<<s.size()<<"\n";
    return 0;
}