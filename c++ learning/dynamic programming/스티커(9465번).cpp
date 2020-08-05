#include <iostream>
using namespace std;
int dp[100001][3];//!!중요 경우의 수를 생각할 것 /열을 생각할게 아니라
int s[2][100001];
int main(){
    int t, n;
    for(scanf("%d",&t);t>0;t--)
    {
        scanf("%d",&n);
        for(int i=0;i<2;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&s[i][j]);
            }
        }
        dp[1][1]=s[1][0];
        dp[1][2]=s[0][0];
        for(int i=2;i<=n;i++)
        {
            dp[i][0]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
            dp[i][1]=max(dp[i-1][0],dp[i-1][2])+s[1][i-1];
            dp[i][2]=max(dp[i-1][0],dp[i-1][1])+s[0][i-1];
        }
        printf("%d\n",max({dp[n][0],dp[n][1],dp[n][2]}));
    }
}
