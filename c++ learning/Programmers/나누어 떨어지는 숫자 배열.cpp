#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    for(auto x: arr){
        if(x%divisor==0){
            answer.push_back(x);
        }
    }
    if(answer.empty())
        answer.push_back(-1);
    sort(answer.begin(), answer.end());
    return answer;
}
int main(void){
    vector<int> arr={5, 9, 7, 10};
    int divisor=5;
    for(auto x: solution(arr,divisor)){
        cout<<x<<'\n';
    }
    return 0;
}
