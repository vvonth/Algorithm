#include <iostream>
#include <cstdio>
#include <set>
#include <algorithm>
#include <vector>
#include <cmath>
//개수를 파악 vs end를 줄이는 것을 파악
using namespace std;

bool cmp(const pair<int,int> &p1, const pair<int,int> &p2)
{
    return p1.second<p2.second;
}
int calculate(int x1, int y1,int x2,int y2)
{
    int nx=x2-x1;
    int ny=y2-y1;
    int result=nx*nx+ny*ny;
    return result;
}
int solve(vector<pair<int,int>> &v,int start,int end)
{
    int n=end-start+1;
    if(n<=3)
    {
        int ans=-1;
        for(int i=start;i<=end-1;i++)
        {
            for(int j=i+1;j<=end;j++)
            {
                int m=calculate(v[i].first, v[i].second,v[j].first,v[j].second);
                if(ans==-1||ans>m)
                    ans=m;
            }
        }
        return ans;
    }
    int mid=(start+end)/2;
    int left=solve(v,start,mid);
    int right=solve(v,mid+1,end);
    int m=min(left,right);
    vector<pair<int,int>> v2;
    for(int i=start;i<=end;i++)
    {
        int d=v[mid].first-v[i].first;
        if(d*d<m)
        {
            v2.push_back(make_pair(v[i].first, v[i].second));
        }
    }
    sort(v2.begin(),v2.end(),cmp);
    int k=v2.size();
    for(int i=0;i<k-1;i++)
    {
        for(int j=i+1;j<k;j++)
        {
            if((v2[i].second-v2[j].second)*(v2[i].second-v2[j].second)<m)
            {
                int m1=calculate(v2[i].first, v2[i].second, v2[j].first, v2[j].second);
                if(m>m1)
                    m=m1;
            }
            else
                break;
        }
    }
    return m;
}

int main(void)
{
    int n,y,x;
    cin>>n;
    set<pair<int,int>> s;
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        s.insert(make_pair(x, y));
    }
    
    for(auto x:s)
    {
        v.push_back(make_pair(x.first, x.second));
    }
    
    if(v.size()>1)
    {
        cout<<solve(v,0,v.size()-1)<<'\n';
    }
    else
    {
        cout<<0<<'\n';
    }
    return 0;
}


