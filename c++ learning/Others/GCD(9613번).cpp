#include<iostream>
#include<vector>
using namespace std;
long long GCD(int, int);
int main(void)
{
    int test;
    
    for(scanf("%d",&test);test>0;test--)
    {
        int n;
        long long sum=0;
        scanf("%d",&n);
        vector<int> v(n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&v[i]);
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                sum+=GCD(v[i],v[j]);
            }
        }
        cout<<sum<<'\n';
    }
}
long long GCD(int a,int b)
{
    if(b==0)
        return a;
    else
        return GCD(b,a%b);
}
