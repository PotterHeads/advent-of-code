#include <bits/stdc++.h>
using namespace std;

int partition(vector<long long> &arr,int low,int high){ // low and high are idx
    long long pivot = arr[low];
    int next_idx = low + 1; 
    for(int i = next_idx;i<=high;i++){ // i <= high because high is a idx 
        if (pivot > arr[i]){
            swap(arr[next_idx],arr[i]);
            next_idx++;
        }
        else{
            continue;
        }
    }
    int last_idx = next_idx - 1; // subtract 1 from next_idx to find the last element that is smaller than pivot
    swap(arr[low],arr[last_idx]); // swap the pivot pos and the last element pos
    return last_idx; // return the idx of the pivot to know where to split the array
}

void quick_select(vector<long long> &ans,const int &k,const int &low,const int &high){
    int idx = partition(ans,low,high);
    if(idx+1 == k){
        cout<<ans[k]<<"\n";
    }
    else if (idx+1 > k){
        quick_select(ans,k,low,idx-1);
    }
    else{
        quick_select(ans,k,idx+1,high);
    }
}

int main(){
    std::ios::sync_with_stdio(false); std::cin.tie(NULL);
    freopen("in.txt", "r", stdin);
    unordered_map<char,int> score = {
        {'(',1},
        {'[',2},
        {'{',3},
        {'<',4}
    };
    vector<long long> ans;
    while(!cin.eof()){
        long long sum = 0;
        bool incomplete = false;
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
                        incomplete = true;
                        break;
                    }
                }
                else if(line[i] == ']'){
                    if(chunks.top() == '['){
                        chunks.pop();
                    }
                    else{
                        incomplete = true;
                        break;
                    }
                }
                else if(line[i] == '}'){
                    if(chunks.top() == '{'){
                        chunks.pop();
                    }
                    else{
                        incomplete = true;
                        break;
                    }
                }
                else {
                    if(chunks.top() == '<'){
                        chunks.pop();
                    }
                    else{
                        incomplete = true;
                        break;
                    }
                }
            }
        }
        if(incomplete){
            continue;
        }
        while(!chunks.empty()){
            sum*= 5;
            sum+=score[chunks.top()];
            chunks.pop();
        }
        ans.push_back(sum);
    }
    int median_idx = (ans.size() + 1) /2 -1;
    quick_select(ans,median_idx,0,ans.size()-1);
    return 0;
}