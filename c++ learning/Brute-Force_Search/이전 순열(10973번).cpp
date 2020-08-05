//
//  이전 순열(10973번).cpp
//  c++ learning
//
//  Created by 원태희 on 26/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
/*
#include <iostream>
using namespace std;
int arr[10001];
bool perm(int n)
{
    int i=n-1;
    while(i>0&&arr[i-1]<=arr[i])//전보다 큰 것
        i--;
    if(i<=0)
        return false;
    int j=n-1;
    while(j>=i&&arr[i-1]<=arr[j])
        j--;
    swap(arr[i-1],arr[j]);
    
    j=n-1;
    while(i<=j)
    {
        swap(arr[i],arr[j]);
        i++;j--;
    }
    return true;
}
int main(void)
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    if(perm(n))
        for(int i=0;i<n;i++)
        {
            printf("%d ",arr[i]);
        }
    else
        printf("-1\n");
}*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    if(prev_permutation(v.begin(), v.end()))
    {
        for(auto x: v)
            cout<<x<<' ';
        cout<<'\n';
    }
    else
        cout<<-1<<'\n';
    return 0;
    
}
