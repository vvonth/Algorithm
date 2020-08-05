#include <iostream>
#include <vector>
using namespace std;
vector<int> solution(vector<int> arr)
{
    vector<int> answer;

    arr.erase(unique(arr.begin(), arr.end()),arr.end());
    answer=arr;
    return answer;
}
int main(void){
    vector<int>arr={1,1,3,3,0,1,1};
    for(auto x: solution(arr))
        cout<<x<<'\n';
    return 0;
}


