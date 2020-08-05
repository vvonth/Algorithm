//
//  외판원 순회 2(10971번).cpp
//  c++ learning
//
//  Created by 원태희 on 05/06/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
//각 가중치가 0인경우 갈수 없는 경우를 생각할 것....
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int w[11][11];
int main(void)
{
    int N;
    cin>>N;
    vector<int>v(N);
    for(int i=1;i<=N;i++)
    {
        v[i-1]=i;
        for(int j=1;j<=N;j++)
        {
            cin>>w[i][j];
        }
    }
    int start=v[0];
    long long m=1000000*20LL;
    
    do{
        bool ch=true;
        long long sum=0;
        int f=v[N-1];
        for(int i=1;i<v.size();i++)
        {
            if(w[v[i-1]][v[i]]==0)
            {
                ch=false;
                break;
            }
            sum+=w[v[i-1]][v[i]];
        }
        if(ch==true&&w[f][start]!=0)
        {
            sum+=w[f][start];
            m=min(m,sum);
        }
        
    }while(next_permutation(v.begin()+1,v.end()));
    cout<<m<<'\n';
    return 0;
}
