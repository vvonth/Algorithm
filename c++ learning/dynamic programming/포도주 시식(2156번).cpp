
#include <iostream>
#include <algorithm>
using namespace std;
int dp[10001][3];
int grape[10001];
int d[10001];
/*int main(void){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&grape[i]);
    }
    dp[1][1]=grape[0];
    
    for(int i=2;i<=n;i++)
    {
        dp[i][0]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
        dp[i][1]=dp[i-1][0]+grape[i-1];
        dp[i][2]=dp[i-1][1]+grape[i-1];
    }
    printf("%d\n",max({dp[n][0],dp[n][1],dp[n][2]}));
}*/
int main(void){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&grape[i]);
    }
    d[1]=grape[0];
    d[2]=grape[0]+grape[1];
    for(int i=3;i<=n;i++)
    {
        d[i]=max({d[i-1],d[i-2]+grape[i-1],d[i-3]+grape[i-2]+grape[i-1]});
    }
    printf("%d\n",d[n]);
}
