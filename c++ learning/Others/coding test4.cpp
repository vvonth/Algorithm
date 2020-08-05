#include <iostream>
#define MAX 500001
using namespace std;
int arr1[MAX];
int arr2[MAX];
int main(void) {
    int sister,n,t;
    int *dp,*s;
    s=arr1;
    dp=arr2;
    scanf("%d",&n);
    scanf("%d",&sister);
    s[n]=1;
    if(n==sister)
    {    printf("0");
        return 0;
    }
    for(t=1;;t++)
    {
        sister+=t;
        if(sister>=MAX)
        {
            printf("-1");
            return 0;
        }
        for(int i=0;i<MAX;i++)
        {
            if(s[i]==t)
            {
                if(i-1>=0)
                {
                    dp[i-1]=t+1;
                }
                if(i+1<MAX)
                {
                    dp[i+1]=t+1;
                }
                if(2*i<MAX)
                {
                    dp[2*i]=t+1;
                }
            }
        }
        int *tmp;
        tmp=dp;
        dp=s;
        s=tmp;
        if(s[sister]==t+1)
            break;
    }
    
    printf("%d\n",s[sister]-1);
}
