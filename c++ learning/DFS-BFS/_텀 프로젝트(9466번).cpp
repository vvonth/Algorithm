//
//  텀 프로젝트(9466번).cpp
//  c++ learning
//
//  Created by 원태희 on 23/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
/*난이도 있는 문제!!!
시작번호에 대해서 생각을 깊게 해야한다.
cycle이란 시작번호가 같고 방문을 해야한다.
cycle이 아닌곳에서 시작을해서 사이클이 나오는 경우 cnt-check[current] 즉, 현재 cnt에서 재방문한 곳에 cnt를 빼준다.
모든 노드는 for문을 돌면서 시작번호를 저장하게 된다. 따라서 시작번호가 다르다=> 이전에 사이클이 생기지 않았다 라는 뜻으로 return 0을 해준다.
 */
#include <iostream>
using namespace std;
int arr[100001];
int check[100001];//cnt 저장
int s[100001];//시작번호 저장***
int dfs(int,int,int);
int main(void)
{
    int t;
    for(scanf("%d",&t);t>0;t--)
    {
        int count=0;
        for(int i=0;i<100001;i++)
        {
            arr[i]=0;
            check[i]=0;
            s[i]=0;
        }
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&arr[i]);
            /*if(arr[i]==i)
            {
                check[i]=-1;
                count++;
                //cout<<"count: "<<count<<'\n';
            }*/
        }
        
        for(int j=1;j<=n;j++)
        {
                if(!check[j])
                {   int cnt=1;
                    //count+=dfs(j,j,1);
                    //cout<<"j: "<<j<<'\n';
                    int k=j;
                    while(1)
                    {
                        if(!check[k])
                        {
                            check[k]=cnt;
                            s[k]=j;
                            k=arr[k];
                            cnt++;
                        }
                        else
                        {
                            if(s[k]!=j)
                            {
                                cnt=0;
                                break;
                            }
                            
                            cnt=cnt-check[k];
                            break;
                        }
                    }
                count+=cnt;
                }
        }
        cout<<n-count<<'\n';
    }
        return 0;
}
/*
int dfs(int start, int current , int cnt)
{
    if(check[current])//방문했으면
    {
        if(s[current]!=start)//방문했는데 시작번호가 다르면??
        {
                       return 0;//사이클이 아니라는 소리
        }
        return cnt-check[current];//방문했는데 시작번호가 같으면? -> 사이클 O
    }
    check[current]=cnt;
    s[current]=start;
    return dfs(start,arr[current],cnt+1);
}*/
/* cout<<"start1: "<<start<<'\n';
 cout<<"s1[current]: "<<s[current]<<'\n';
 cout<<"check1[current]: "<<check[current]<<'\n';*/
