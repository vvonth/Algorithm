#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int bdivide(long long,long long);
vector<long long> v;
long long n;
int main(){
    long long k,m,left,right=1;
    int count=0;
    scanf("%lld %lld",&k,&n);
    for(int i=0;i<k;i++)
    {
        scanf("%lld",&m);
        v.push_back(m);
        if(v[i]>right)
            right=v[i];
    }
    left=1;
    count=bdivide(left,right);
    printf("%lld\n",count-1);
}

int bdivide(long long left,long long right)
{
    int c=0;
    int mid=(left+right)/2;
    if(left>right)
        return left;
    for(auto x : v)
        c+=x/mid;
    
    if(c<n)
        return bdivide(left, (long long)mid-1);
    return bdivide((long long)mid+1, right);
}
