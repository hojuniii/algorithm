#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    int idx = 0;
    
    queue<int> q;
    
    while(1){
        int qs = q.size();
        // cout<<"idx : "<<idx<<" , ans : "<<answer<<" , sum : "<<sum << " , Queue : ";
        for(int i=0; i<qs; i++){
            cout<<q.front()<<' ';
            q.push(q.front());
            q.pop();
        }
        cout<<endl;
        if(idx == truck_weights.size()){
            answer+=bridge_length;
            break;
        }
        answer++;
        int curw = truck_weights[idx];
        if(q.size() == bridge_length){
            sum -= q.front();
            q.pop();
        }
        if(curw + sum <= weight){
            sum += curw;
            q.push(truck_weights[idx]);
            idx++;
        }
        else{
            q.push(0);
        }
    }
    return answer;
}

int main(){
    vector<int> truck_weights = {7,4,5,6};
    int res = solution(2,10,truck_weights);
    cout<<res<<endl;
}