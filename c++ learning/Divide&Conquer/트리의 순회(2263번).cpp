//
//  트리의 순회(2263번).cpp
//  c++ learning
//
//  Created by 원태희 on 11/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include<vector>
using namespace std;
int in[100001];
int post[100001];
int position[100001];
vector<int>pre;
int n;
void solve(int,int,int,int);
int main(void)
{
    
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>in[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>post[i];
        position[in[i]]=i;
    }
    //루트를 post에서 찾는다(항상 맨뒤)->in에서 나눈다(왼쪽 오른쪽)
    
    
    
    int ps=0;
    int pe=n-1;
    int is=0;
    int ie=n-1;
    solve(ps,pe,is,ie);
    for(auto x: pre)
    {
        cout<<x<<' ';
    }
    cout<<'\n';
}
void solve(int ps, int pe, int is, int ie)//index
{
    if(is>ie||ps>pe)
        return;
    int ir;
    pre.push_back(post[pe]);
    /*for(int i=is;i<=ie;i++)
    {
        if(post[pe]==in[i])
        {
            ir=i;
            break;
        }
    }*/
    ir=position[post[pe]];
    
    solve(ps,ps+ir-is-1,is,ir-1);
    solve(ps+ir-is,pe-1,ir+1,ie);
    
}
