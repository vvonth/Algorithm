
#include <cstdio>
#include<vector>
using namespace std;
typedef struct rTree{
    vector<int> next;
    vector<int> dist;
    int visit;
}Tree;
int max_distance(int);
int max_sum;
Tree arr[100001];
//정점번호/간선의정점번호/거리/
int main(){
    int V,n,d,j;
    scanf("%d",&V);
    for(int i=1;i<=V;i++)
    {
        scanf("%d",&j);
        while(1)
        {
            scanf("%d",&n);
            if(n==-1)
                break;
            scanf("%d",&d);
            
            arr[j].next.push_back(n);
            arr[j].dist.push_back(d);
        }
    }

    max_distance(1);
    printf("%d",max_sum);
    return 0;
}

int max_distance(int n)
{
    int max1=0, max2=0,m1;
//    if(arr[n].visit)
//        return -1;
    arr[n].visit=1;
    for(vector<int>::iterator itr=arr[n].next.begin(),itr2=arr[n].dist.begin();itr!=arr[n].next.end();itr++,itr2++)
    {
        if(arr[*itr].visit==1)
            continue;
        m1=max_distance(*itr)+*itr2;
        if(max1<m1){
            max2=max1;
            max1=m1;
        }
        else if(max2<m1)
            max2=m1;
            
    }
    if(max1+max2>max_sum)
        max_sum=max1+max2;
    return max1;
}
