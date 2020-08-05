#include <iostream>
#include <vector>
#include<utility>
#include <algorithm>
using namespace std;
typedef struct Point {
    string s;
    int k;
    int e;
    int m;
}P;
bool cmp(P &u,P &v)
{
    return make_tuple(-u.k,u.e,-u.m,u.s)<make_tuple(-v.k,v.e,-v.m,v.s);
}

int main(){
    int n;
    vector<P> v;
    P u;
    for(scanf("%d",&n);n>0;n--)
    {
        cin>>u.s>>u.k>>u.e>>u.m;//이름, 국어, 영어, 수학
        v.push_back(u);
    }
    sort(v.begin(),v.end(),cmp);
    for(auto &x : v)
        cout<<x.s<<endl;
    return 0;
}
