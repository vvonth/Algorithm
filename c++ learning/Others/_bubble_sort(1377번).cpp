//
//  bubble_sort(1377번).cpp
//  c++ learning
//
//  Created by 원태희 on 17/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;//***pair 사용 생각 못했음......원래 인데스를 저장하고 소트한 후 인덱스를 저장한 것을 뺀다..pair 사용하면 편하다.
int main(void)
{
    int N;
    cin>>N;
    vector<pair<int,int>> p(N);
    for(int i=0;i<N;i++)
    {
        scanf("%d",&p[i].first);
        p[i].second=i;
    }
    sort(p.begin(),p.end());
    int ans=p[0].second-0;
    for(int i=0;i<N;i++)
    {
        if(ans<p[i].second-i)
        {
            ans=p[i].second-i;
        }
    }
    cout<<ans+1<<'\n';
}
