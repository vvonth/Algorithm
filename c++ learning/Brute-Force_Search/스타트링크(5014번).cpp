//
//  스타트링크(5014번).cpp
//  c++ learning
//
//  Created by 원태희 on 25/06/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <queue>
int visited[1000001];
int dist[1000001];
using namespace std;
/*int main(void)
{
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;
    int MAX=f;
    int MIN=1;
    int gangho=s;
    int startlink=g;
    queue<int> q;
    q.push(gangho);
    visited[gangho]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(x+u<=MAX&&!visited[x+u])
        {
            q.push(x+u);
            visited[x+u]=1;
            dist[x+u]=dist[x]+1;
        }
        if(x-d>=MIN&&!visited[x-d])
        {
            q.push(x-d);
            visited[x-d]=1;
            dist[x-d]=dist[x]+1;
        }
    }
    if(startlink!=gangho&&dist[startlink]==0)
    {
        cout<<"use the stairs"<<'\n';
    }
    else
        cout<<dist[startlink]<<'\n';
    return 0;
}*/
int main(void)
{
    int f,s,g,u,d;
    cin>>f>>s>>g>>u>>d;
    for(int i=0;i<1000001;i++)
    {
        if(s==g)
        {
            printf("%d",i);
            return 0;
        }
        if(s>g&&s>0||s<g&&s+u>f)s-=d;
        else
            s+=u;
    }
    printf("use the stairs");
    return 0;
}
