/*#include <cstdio>
#include<vector>
using namespace std;
int dist_max(int);
typedef struct  tTree{
     vector<int> next;
     vector<int> dist;
    
}Tree;
int max_sum;
Tree arr[10001];
int main(){
    int n,p,c,d;
    scanf("%d",&n);
    
    for(int i=1;i<n;i++)
    {
        scanf("%d %d %d", &p,&c,&d);
        arr[p].next.push_back(c);
        arr[p].dist.push_back(d);
    }
    dist_max(1);
    printf("%d\n",max_sum);
    return 0;
}

int dist_max(int i)//일직선의 가장 긴 거리
{
    int m;
     int max1=0;
    int max2=0;
    for(vector<int>::iterator iter=arr[i].next.begin(),iter_dist=arr[i].dist.begin();iter!=arr[i].next.end();iter++,iter_dist++){
        m=dist_max(*iter)+*iter_dist;//나의 거리+ 이전까지의 가장 긴 거리
        if(max1<m){
            max2=max1;
            max1=m;
        }
        else if(max2<m){
            max2=m;
        }
    }
    if(max1+max2>max_sum)
        max_sum=max1+max2;
    return max1;
}*/
/*#include<iostream>
#include<vector>
#include <queue>
#include <cstring>
using namespace std;
typedef struct tr{
    vector<int> dist;
    vector<int> edge;
}tree;
void bfs(int );
int check[100001];
tree t[100001];
int dist[100001];
queue<int> q;

int main(void)
{
    int v,a,b,c;
    cin>>v;
    for(int i=1;i<=v;i++)
    {
        scanf("%d",&c);
        while(1)
        {
            cin>>a;
            if(a==-1)
                break;
            cin>>b;
            t[c].edge.push_back(a);
            t[c].dist.push_back(b);
        }
    }
    bfs(1);
    int start=1;

    for(int i=2;i<=v;i++)
    {
        if(dist[start]<dist[i])
        {
            start=i;
        }
            
    }
    bfs(start);
    int max=dist[start];
    for(int i=1;i<=v;i++)
    {
        if(max<dist[i])
            max=dist[i];
    }
    cout<<max<<'\n';
    
    
    return 0;
}
void bfs(int n)
{
    memset(check,0,sizeof(check));
    memset(dist,0,sizeof(dist));
    q.push(n);
    check[n]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<t[x].edge.size();i++)
        {
            if(!check[t[x].edge[i]])
            {
                check[t[x].edge[i]]=1;
                dist[t[x].edge[i]]=dist[x]+t[x].dist[i];
                q.push(t[x].edge[i]);
            }
        }
    }
}*/
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int d[10001];
int check[10001];
vector<int> edge[10001];
vector<int> dist[10001];
queue<int> q;
void bfs(int );
int main(void)
{
    int n,p,ch,w;
    cin>>n;
    if(n==1)
    {
        cout<<0<<'\n';
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        cin>>p>>ch>>w;
        edge[p].push_back(ch);
        edge[ch].push_back(p);
        dist[p].push_back(w);
        dist[ch].push_back(w);
    }
    
    bfs(1);
    int start=1;
    for(int i=2;i<=n;i++)
    {
        if(d[start]<d[i])
            start=i;
    }
    bfs(start);
    
    int ans=d[start];
    for(int i=1;i<=n;i++)
    {
        if(ans<d[i])
            ans=d[i];
    }
    cout<<ans<<'\n';
    
    return 0;
}
void bfs(int n)
{
    memset(check,0,sizeof(check));
    memset(d,0,sizeof(d));
    q.push(n);
    check[n]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<edge[x].size();i++)
        {
            if(!check[edge[x][i]])
            {
                check[edge[x][i]]=1;
                d[edge[x][i]]=dist[x][i]+d[x];
                q.push(edge[x][i]);
            }
        }
    }
}
