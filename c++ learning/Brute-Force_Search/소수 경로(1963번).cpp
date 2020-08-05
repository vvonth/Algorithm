//
//  소수 경로(1963번).cpp
//  c++ learning
//
//  Created by 원태희 on 07/06/2019.
//  Copyright © 2019 원태희. All rights reserved.
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
int visited[10001];
int dist[10001];
bool prime[10001];
int main(void)
{
    for(int i=2;i<10001;i++)
    {
        if(prime[i]==false)
        {
            for(int j=i*i;j<10001;j+=i)
            {
                prime[j]=true;
            }
        }
    }
    
    int T;
    cin>>T;
    for(int i=0;i<T;i++)
    {
        memset(visited,0,sizeof(visited));
        memset(dist,0,sizeof(dist));
        queue<int> q;
        int start,end;
        cin>>start>>end;
        q.push(start);
        visited[start]=1;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            for(int i=1000;i<=9000;i+=1000)
            {
                int k=(x%1000)+i;
                if(x==k)
                    continue;
                else
                {
                    if(prime[k]==false&&!visited[k])
                    {
                        q.push(k);
                        visited[k]=1;
                        dist[k]=dist[x]+1;
                        // printf("dist[%d]: %d\n",k,dist[k]);
                    }
                }
            }
            for(int i=0;i<=900;i+=100)
            {
                int k=(x/1000)*1000+x%100+i;
                
                if(x==k)
                    continue;
                else
                {
                    if(prime[k]==false&&!visited[k])
                    {
                        
                        q.push(k);
                        visited[k]=1;
                        dist[k]=dist[x]+1;
                        //printf("dist[%d]: %d\n",k,dist[k]);
                    }
                }
            }
            for(int i=0;i<=90;i+=10)
            {
                int k=(x/100)*100+x%10+i;
                if(x==k)
                    continue;
                else
                {
                    if(prime[k]==false&&!visited[k])
                    {
                        q.push(k);
                        visited[k]=1;
                        dist[k]=dist[x]+1;
                        // printf("dist[%d]: %d\n",k,dist[k]);
                    }
                }
            }
            for(int i=0;i<=9;i++)
            {
                int k=x/10*10+i;
                if(x==k)
                    continue;
                else
                {
                    if(prime[k]==false&&!visited[k])
                    {
                        q.push(k);
                        visited[k]=1;
                        dist[k]=dist[x]+1;
                    }
                }
            }
        }
        cout<<dist[end]<<'\n';
    }
    return 0;
}
/*
int change(int num,int digit, int index)
{
    if(index==0&&digit==0) return -1;
    string s=to_string(num);
    s[index]=digit+'0';
    return stoi(s);
    
}
 소수 에라토스테네스의 체
 bool prime[10001];
 for(int i=2;i<10000;i++)
 {
   if(prime[i]==false)
    {
        for(int j=i*i;j<10000;j+=i)
        {
            prime[j]=true;
        }
    }
 }
 
 */
