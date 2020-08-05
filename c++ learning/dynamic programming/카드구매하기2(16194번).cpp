#include <iostream>
using namespace std;
int arr[1001];
int dp[1001];
int main(void){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>arr[i];
        dp[i]=arr[i];
    }
    for(int i=2;i<=N;i++){
        for(int j=1;j<=i;j++){
            dp[i]=min(dp[i], dp[i-j]+arr[j]);
        }
    }
    cout<<dp[N]<<'\n';
    return 0;
}
