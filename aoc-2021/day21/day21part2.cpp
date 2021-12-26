#include <bits/stdc++.h>
using namespace std;

pair<long long,long long> get_wins(int &p1_pos,int &p1_score,int &p2_pos,int &p2_score, map<tuple<int,int,int,int>,pair<long long,long long>> &m_dp){
    if(p1_score >= 21){
        return {1,0}; //p1 wins
    }
    if(p2_score >= 21){
        return {0,1}; //p2 wins
    }
    if(m_dp.find({p1_pos,p1_score,p2_pos,p2_score}) != m_dp.end()){ // check hash
        return m_dp[{p1_pos,p1_score,p2_pos,p2_score}]; // return the pair of ans that tells me the no of wins of p1 and p2 based on the pos and score
    }
    pair<long long,long long> wins = {0LL,0LL};  // p1_wins,p2_wins
    for(int i = 1;i<=3;i++){
        for(int j = 1;j<=3;j++){
            for(int k = 1;k<=3;k++){
                int die_roll = i + j + k;
                int new_p1_pos = (die_roll + p1_pos);
                if(new_p1_pos > 10){
                    new_p1_pos%=10;
                }
                int new_p1_score = p1_score + new_p1_pos;
                pair<long long,long long> intermediate = get_wins(p2_pos,p2_score,new_p1_pos,new_p1_score,m_dp); // flip p1 and p2 to compute
                wins = {wins.first+intermediate.second,wins.second+intermediate.first}; // p1 and p2 swap based on get_wins recursive calls
            }
        }
    }
    m_dp[{p1_pos,p1_score,p2_pos,p2_score}] = wins; // update the map to cache the results
    return wins;
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    string p1,p2,p1pos,p2pos;getline(cin,p1);getline(cin,p2);
    p1pos = p1.substr(p1.find(':')+2);
    p2pos = p2.substr(p2.find(':')+2);
    int p1_pos = stoi(p1pos);
    int p2_pos = stoi(p2pos);
    int p1score = 0;
    int p2score = 0;
    map<tuple<int,int,int,int>,pair<long long,long long>> m_dp; // store states that have been calculated before and its ans
    pair<long long,long long> ans = get_wins(p1_pos,p1score,p2_pos,p2score,m_dp);
    cout<<ans.first<<" "<<ans.second<<"\n";
    cout<<max(ans.first,ans.second)<<"\n";
}