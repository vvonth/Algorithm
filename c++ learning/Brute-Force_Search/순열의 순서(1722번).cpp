#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    int n,a;
    cin>>n;
    vector<int> v(n);
    vector<int> v2(n);
    vector<bool> v3(n);
    for(int i=0;i<n;i++)
    {
        v[i]=i+1;
        v3[i]=false;
    }
    cin>>a;
    if(a==1)
    {
        
        long long k;
        cin>>k;
        int t=0;
        int b=n;
        
        while(t!=n)
        {
            for(int i=0;i<n;i++)
            {
                if(v3[i]==true)
                    continue;
                long long sum=1;
                for(int j=2;j<b;j++)
                {
                    sum*=j;
                }
                if(k>sum)
                    k-=sum;
                else
                {
                    v3[i]=true;
                    b--;
                    v2[t++]=v[i];
                    break;
                }
                // cout<<"sum:"<<sum<<'\n';
                // cout<<"k:"<<k<<'\n';
            }
        }
        for(auto x:v2)
            cout<<x<<' ';
        cout<<'\n';
        
    }
    else
    {
        long long count=0;
        int b=n;
        int k=0;
        for(int i=0;i<n;i++)
            cin>>v2[i];
        while(k!=n)
        {
            for(int i=0;i<n;i++)
            {
                if(v3[i]==true)
                    continue;
                if(v[i]!=v2[k])
                {
                    long long sum=1;
                    for(int j=1;j<b;j++)
                    {
                        sum*=j;
                    }
                    count+=sum;
                }
                else
                {
                    b--;
                    k++;
                    v3[i]=true;
                    break;
                }
            }
        }
        cout<<count+1<<'\n';
    }
    return 0;
}
/*
#include<iostream>
#include<vector>
using namespace std;
int main(void)
{
    long long fac[21]={1,};
    bool c[21];
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        fac[i]=fac[i-1]*i;
    }
    int a;
    cin>>a;
    if(a==1)
    {
        long long k;
        cin>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(c[j]==true)
                    continue;
                if(fac[n-i-1]<k)
                    k-=fac[n-i-1];
                else
                {
                    a[i]=j;
                    c[j]=true;
                    break;
                }
            }
        }
        for(auto x:a)
            cout<<x<<' ';
        cout<<'\n';
    }
    else
    {
        long long count=0;
        vector<int>a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<a[i];j++)
            {
                if(c[j]==false)
                    count+=fac[n-i-1];
            }
            c[a[i]]=true;
        }
        cout<<count+1<<'\n';
    }
    return 0;
}*/
