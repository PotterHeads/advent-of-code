#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in2.txt", "r", stdin);
    string p1,p2,p1pos,p2pos;getline(cin,p1);getline(cin,p2);
    p1pos = p1.substr(p1.find(':')+2);
    p2pos = p2.substr(p2.find(':')+2);
    int p1_pos = stoi(p1pos);
    int p2_pos = stoi(p2pos);
    long long p1score = 0;
    long long p2score = 0;
    int count = 0;
    long long ans = 0;
    int n = 3;
    while(true){
        int p1_roll_value = (3*n)-3;
        int p1_val = p1_roll_value + p1_pos;
        if(p1_val > 10 or p1_val == 0){
            p1_val = p1_val%10;
            if(p1_val = 0){
                p1_val = 1;
            }
        }
        p1score += p1_val;
        p1_pos = p1_val;
        count+=3;
        n+=3;
        cout<<"P1 ROLL VALUE "<<p1_roll_value<<" "<<p1score<<" "<<p1_pos<<"\n";
        if(p1score >= 1000){
            break;
        }
        int p2_roll_value = (3*n)-3;
        int p2_val = p2_roll_value + p2_pos;
        if(p2_val > 10 or p2_val == 0){
            p2_val = p2_val%10;
            if(p2_val == 0){
                p2_val = 1;
            }
        }
        p2score += p2_val;
        p2_pos = p2_val;
        cout<<"P2 ROLL VALUE "<<p2_roll_value<<" "<<p2score<<" "<<p2_pos<<"\n";         
        n+=3;
        count+=3;
        if(p2score >= 1000){
            break;
        }
    }
    if(p1score < 1000){
        cout<<"P1 "<<p1score<<" "<<count<<"\n";
        cout<<"P2 "<<p2score<<" "<<count<<"\n";
        ans = p1score*count;
    }
    else{
        cout<<"P1 "<<p1score<<" "<<count<<"\n";
        cout<<"P2 "<<p2score<<" "<<count<<"\n";
        ans = p2score*count;
    }
    cout<<ans<<"\n";
    return 0;
}