#include <iostream>
#include <vector>
#include <algorithm>
//시작시간과 끝나는 시간이 같은 경우를 생각해서 정렬해야 한다.
using namespace std;
vector<pair<int,int>> v;
bool cmp(pair<int, int> a, pair<int,int> b)
{
    if(a.second==b.second)
    {
        return a.first<b.first;
    }
    else
        return a.second<b.second;
}
int main(void)
{
    int n,a,b,start;
    int count1=0;
    int now=0;
    int m1=0x7fffff;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(),v.end(),cmp);
    
    for(int i=0;i<n;i++)
    {
        if(now<=v[i].first)
        {
            count1++;
            now=v[i].second;
        }
    }
    cout<<count1<<'\n';
}


