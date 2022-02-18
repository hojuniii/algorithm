#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {
    int total = brown + yellow;
    vector<int> answer;
    
    for(int i = total/2; i>0;i--){
        //total % i == 0 --> i는 total의 약수
        if(total % i == 0){
            
            int w = i;
            int h = total/i;
            
            //yellow의 w: 양옆 테두리를 제외한 w-2
            //yellow의 h: 상하 테두리를 제외한 h-2
            //(w-2) * (h-2) : yellow의 개수
            if((w-2) * (h-2) == yellow){
                answer.push_back(w);
                answer.push_back(h);
                break;
            }
        }
        
    }
    
    return answer;
}