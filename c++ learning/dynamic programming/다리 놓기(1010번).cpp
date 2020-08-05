#include <iostream>
using namespace std;
int dp[31][31];
int main(void){
    int T;
    cin>>T;
    for(int i=1;i<31;i++){
        dp[1][i]=i;
        dp[i][i]=1;
    }
    for(int i=2;i<31;i++){
        for(int j=i+1;j<31;j++){
            dp[i][j]=dp[i-1][j-1]+dp[i][j-1];
        }
    }
    
    for(int tc=1;tc<=T;tc++){
        int left;
        int right;
        cin>>left>>right;
        cout<<dp[left][right]<<'\n';
    }
    return 0;
}
