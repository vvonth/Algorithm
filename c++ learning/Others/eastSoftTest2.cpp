
#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> digitSum[100];

int getDigitSum(int num){
    int sum=0;
    while(num>0){
        sum+=num%10;
        num/=10;
    }
    return sum;
}
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    for(auto x:A)
        digitSum[getDigitSum(x)].push_back(-x);
    int maximum=-1;
    for(int i=1;i<100;i++){
        if(digitSum[i].size()<2)
            continue;
        sort(digitSum[i].begin(),digitSum[i].end());
        if(maximum<-(digitSum[i][0]+digitSum[i][1]))
            maximum=-(digitSum[i][0]+digitSum[i][1]);
    }
    return maximum;
}
int main(void){
    vector<int> A;
    A.push_back(51);
    A.push_back(32);
    A.push_back(43);
    cout<<solution(A)<<'\n';
    return 0;
}
