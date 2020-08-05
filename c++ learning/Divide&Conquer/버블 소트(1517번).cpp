//
//  버블 소트(1517번).cpp
//  c++ learning
//
//  Created by 원태희 on 16/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
long long total;
void merge(int start, int end, vector<int> &v,vector<int>& v2)
{
    int mid=(start+end)/2;
    if(start==end)
        return ;
    merge(start,mid,v,v2);
    merge(mid+1,end,v,v2);
    
    int i=start;
    int j=mid+1;
    int k=start;
    while(i<=mid&&j<=end)
    {
        int count=mid-i+1;
        if(v[i]>v[j])
        {
            v2[k++]=v[j++];
            total+=count;
        }
        else
        {
            v2[k++]=v[i++];
        }
    }
    while(i<=mid)
    {
        v2[k++]=v[i++];
    }
    while(j<=end)
    {
        v2[k++]=v[j++];
    }
    for(int i=start;i<=end;i++)
    {
        v[i]=v2[i];
    }
}

int main(void)
{
    int n,k;
    cin>>n;
    vector<int> v;
    vector<int> v2(n);
    for(int i=0;i<n;i++)
    {   cin>>k;
        v.push_back(k);
    }
    merge(0,n-1,v,v2);
    cout<<total<<'\n';
}

