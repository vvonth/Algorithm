//
//  set(10815번).cpp
//  c++ learning
//
//  Created by 원태희 on 19/02/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <set>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
/*
int main()
{
    set<int> s;
    int N;
    int Z,Y;
    int M;
    scanf("%d",&N);
    
    for(int i=0;i<N;i++)
    {
        scanf("%d",&Z);
        s.insert(Z);
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++)
    {
        scanf("%d",&Y);
       printf("%d ",s.count(Y));
    }
    printf("\n");
}*/
int main(){
    int n,z;
    vector<int> v;
    for(scanf("%d",&n);n>0;n--)
    {
        scanf("%d",&z);
        v.push_back(z);
    }
    sort(v.begin(),v.end());
    for(scanf("%d",&n);n>0;n--)
    {
        scanf("%d",&z);
        auto l=lower_bound(v.begin(), v.end(),z);
        auto r=upper_bound(v.begin(), v.end(), z);
        //printf("%d ",binary_search(v.begin(), v.end(),z));
        printf("%d ",r-v.begin());
        printf("%d ",l-v.begin());
    }
    printf("\n");
}
