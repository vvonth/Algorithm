//
//  graph(1707번).cpp
//  c++ learning
//
//  Created by 원태희 on 20/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<int> v[20001];
int check[20001];
bool dfs(int,int);
int main(void)
{
    int k,v3,e,v1,v2;
    cin>>k;
    for(int t=0;t<k;t++)
    {
        bool c=true;

        for(int i=0;i<20001;i++)
        {
            v[i].clear();
            check[i]=0;
        }
        cin>>v3>>e;
        for(int i=0;i<e;i++)
        {
            cin>>v1>>v2;
            v[v1].push_back(v2);
            v[v2].push_back(v1);
        }
        for(int i=1;i<=v3;i++)
        {
            if(check[i]==0)
            {
                if(dfs(i,1)==false)
                {
                    c=false;
                    break;
                }
            }
        }
       
        if(c==true)
            cout<<"YES"<<'\n';
        else
            cout<<"NO"<<'\n';
    }
    return 0;
}
bool dfs(int a,int c)
{
    check[a]=c;
    for(int i=0;i<v[a].size();i++)
    {
        int x= v[a][i];
        
        if(check[x]==0)
        {   //check[x]=3-c;//blue;
            //cout<<"x1:"<<x<<' '<<"check[x]:"<<check[x]<<'\n';
            if(dfs(x,3-c)==false)
            {
                return false;
            }
            //cout<<"x2:"<<x<<' '<<"check[x]:"<<check[x]<<'\n';
        }else if(check[x]==check[a])
        {
            return false;
        }
        
    }
    return true;
}
