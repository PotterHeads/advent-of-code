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
        int curr_p1 = (3*n)-3;
        int p1_value = curr_p1 + p1_pos;
        if(p1_value > 10){
            p1_value %=10;
        }
        // cout<<"P1 VALUE "<<p1_value<<"\n";
        p1score += p1_value;
        p1_pos =  p1_value;
        if(p1score >= 1000){
            break;
        }
        // cout<<"P1 SCORE "<<p1score<<"\n";
        // cout<<"P1 POS "<<p1_pos<<"\n";
        n+=3;
        count +=3;
        int curr_p2 = (3*n)-3;
        int p2_value = curr_p2 + p2_pos;
        if(p2_value > 10){
            p2_value%=10;
        }
        p2score += p2_value;
        p2_pos =  p2_value;
        count+=3;
        n+=3;
        if(p2score >= 1000){
            break;
        }
        // cout<<"P2 SCORE "<<p2score<<"\n";
        // cout<<"P2 POS "<<p2_pos<<"\n";
        // break;
    }
    if(p1score < 1000){
        cout<<"P1 "<<p1score<<" "<<count<<"\n";
        ans = p1score*count;
    }
    else{
        cout<<"P2 "<<p2score<<" "<<count<<"\n";
        ans = p2score*count;
    }
    cout<<ans<<"\n";
    return 0;
}