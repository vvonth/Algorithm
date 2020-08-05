#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
//메모리 계산하기
vector<pair<int,int>> map[100001];
int visited[100001];
int main(void)
{
    int n,m;
    int a1,a2,a3;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a1>>a2>>a3;
        map[a1].push_back(make_pair(a2,a3));
        map[a2].push_back(make_pair(a1,a3));
    }
    for(int i=0;i<m;i++)
        sort(map[i].begin(),map[i].end());
    int start,end;
    cin>>start>>end;
    int min=map[start][0].second;
    int max=min;
    for(int i=1;i<map[start].size();i++)
    {
        if(map[start][i].second>max)
        {
            max=map[start][i].second;
        }
        if(map[start][i].second<min)
        {
            min=map[start][i].second;
        }
    }
    
    int left=0;
    int right=max;
    while(left<=right)
    {
        //여기 부분 조심하기
        int mid=left+(right-left)/2;
        //bfs 잘 생각하기
                bool check=false;
                memset(visited,0,sizeof(visited));
                visited[start]=1;
                queue<int>q;
                q.push(start);
                while(!q.empty())
                {
                    int x=q.front();
                    q.pop();
                    if(x==end)
                        check=true;
                    //break넣어도 맞음
                    for(int i=0;i<map[x].size();i++)
                    {
                        if((!visited[map[x][i].first])&&(map[x][i].second>=mid))
                        {
                            visited[map[x][i].first]=1;
                            q.push(map[x][i].first);
                        }
                    }
                }
        if(check)
            left=mid+1;
        else
            right=mid-1;
        
    }
    cout<<left-1<<'\n';
    return 0;
}
