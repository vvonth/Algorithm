//
//  Prime factorization.cpp
//  c++ learning
//
//  Created by 원태희 on 04/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

/*#include <iostream>
using namespace std;
int main(void)
{
    int n,i;
    scanf("%d",&n);
        for(i=2;i*i<=n;i++)
        {   while(n%i==0)
            {
                cout<<i<<'\n';
                n/=i;
            }
        }
    if(n>1)
        cout<<n<<'\n';
    return 0;
}*/
/*#include <iostream>
using namespace std;
int main(void)
{
    int n,i;
    scanf("%d",&n);
    while(n!=1)
    {
        for(i=2;i<=n;i++)
        {   if(n%i==0)
            {
                cout<<i<<'\n';
                n/=i;
                break;
            }
    }
    }
    return 0;
}*/
#include<iostream>
#include<algorithm>
using namespace std;
int main(void)
{
    int n,m;
    int count1=0;
    int count2=0;
    int count3=0;
    int count4=0;
    cin>>n>>m;
    for(long long i=2,j=5;i<=n;i*=2,j*=5)
    {
        count1+=n/i;
        if(j<=n)
        count2+=n/j;
    }
    for(long long i=2,j=5;i<=m;i*=2,j*=5)
    {
        count3+=m/i;
        if(j<=m)
        count4+=m/j;
    }
    for(long long i=2,j=5;i<=n-m;i*=2,j*=5)
    {
        count3+=(n-m)/i;
        if(j<=n-m)
        count4+=(n-m)/j;
    }
    cout<<min(count1-count3,count2-count4);
}
