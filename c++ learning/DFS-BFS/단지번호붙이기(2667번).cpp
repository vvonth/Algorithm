#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int arr[27][27];
int visited[27][27];
queue<pair<int,int>> q;
int bfs(int y1, int x1)
{
    int count=0;
    q.push(make_pair(y1,x1));
    visited[y1][x1]=1;
    while(!q.empty())
    {
        int y=q.front().first;
        int x=q.front().second;
        count++;
        q.pop();
    if(arr[y+1][x]==1&&!visited[y+1][x])
    {
        q.push(make_pair(y+1, x));
        visited[y+1][x]=1;
    }
    if(arr[y-1][x]==1&&!visited[y-1][x])
    {
        q.push(make_pair(y-1, x));
        visited[y-1][x]=1;
    }
    if(arr[y][x+1]==1&&!visited[y][x+1])
    {
        q.push(make_pair(y, x+1));
        visited[y][x+1]=1;
    }
    if(arr[y][x-1]==1&&!visited[y][x-1])
    {
        q.push(make_pair(y, x-1));
        visited[y][x-1]=1;
    }
    
    }
    return count;
}
int main(void)
{
    int count=0;
    int N;
    vector<int> v;
    scanf("%d",&N);
    for(int i=0;i<=N+1;i++)
    {
        arr[0][i]=-1;
        arr[N+1][i]=-1;
        arr[i][0]=-1;
        arr[i][N+1]=-1;
    }
    for(int i=1;i<=N;i++)
    {
        for(int j=1;j<=N;j++)
        {
            scanf("%1d",&arr[i][j]);
        }
    }
    for(int i=0;i<=N;i++)
    {
        for(int j=0;j<=N;j++)
        {
            if(arr[i][j]==1&&!visited[i][j])
            {
                v.push_back(bfs(i,j));
                count++;
            }
        }
    }
    sort(v.begin(),v.end());
    cout<<count<<'\n';
    for(auto x: v)
        cout<<x<<'\n';
}
