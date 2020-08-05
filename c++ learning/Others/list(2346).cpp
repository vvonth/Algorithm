#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<pair<int,int>> arr;
    int n,j;
    pair<int,int> m;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>j;
        m=make_pair(i, j);
        arr.push_back(m);
    }
    auto it=arr.begin();
    for(int i=1;i<n;i++)
    {
        cout<<(it->first)<<' ';//first가 인덱스 second 가 값
        int step =it->second;
        if(step>0)
        {
            
            it=arr.erase(it);
            for(;step>1;step--)
            {
                
                if(it==arr.end())
                {
                    it=arr.begin();
                }
                ++it;

            }
            
        }
        else
        {
            auto temp=it;
            if(temp==arr.begin())
                temp=arr.end();
            --temp;
            arr.erase(it);
            it=temp;
            for(;step<-1;step++)
            {
                if(it==arr.begin())
                    it=arr.end();
                --it;
            }
        }
    }
    cout<<arr.front().first<<'\n';
    
}

