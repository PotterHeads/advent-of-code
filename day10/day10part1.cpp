#include <bits/stdc++.h>
using namespace std;

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    unordered_map<char,int> score = {
        {')',3},
        {']',57},
        {'}',1197},
        {'>',25137}
    };
    long long sum = 0;
    while(!cin.eof()){
        stack<char> chunks;
        string line;cin>>line;
        for(int i = 0;i<line.size();i++){
            if(line[i] == '[' or line[i] == '<' or line[i] == '{' or line[i] == '('){
                chunks.push(line[i]);
            }
            else{
                if(line[i] == ')'){
                    if(chunks.top() == '('){
                        chunks.pop();
                    }
                    else{
                        sum+=score[line[i]];
                        break;
                    }
                }
                else if(line[i] == ']'){
                    if(chunks.top() == '['){
                        chunks.pop();
                    }
                    else{
                        sum+=score[line[i]];
                        break;
                    }
                }
                else if(line[i] == '}'){
                    if(chunks.top() == '{'){
                        chunks.pop();
                    }
                    else{
                        sum+=score[line[i]];
                        break;
                    }
                }
                else {
                    if(chunks.top() == '<'){
                        chunks.pop();
                    }
                    else{
                        sum+=score[line[i]];
                        break;
                    }
                }
            }
        }
    }
    cout<<sum<<"\n";
    return 0;
}