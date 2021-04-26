#include <string>
#include <vector>
#include <iostream>
using namespace std;

int gcd(int a, int b){
    while(b!=0){
        int r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int lcm(int a, int b){
    return a * b/ gcd(a,b); 
}

int solution(vector<int> arr) {
    int answer = 0;
    int lcm1 = arr[0];
    for(int i = 0;i<arr.size();i++){
        lcm1 = lcm(lcm1, arr[i]);
    }
    
    return lcm1;
}

int main(){
    vector<int> v;
    v.push_back(12);
    cout<<solution({2,6,8,14});
}