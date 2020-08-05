//
//  하노이 탑 이동 순서.cpp
//  c++ learning
//
//  Created by 원태희 on 10/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include<iostream>
using namespace std;
void solve(int,int,int,int);
void solve2(int,int,int);
int main(void)
{
    int n;
    cin>>n;
    cout<<(1<<n)-1<<'\n';
    //solve(n,1,2,3);
    solve2(n,1,3);
}
/*void solve(int n, int x,int y, int z)
{
    if(n==1)
    {
        printf("%d %d\n",x,z);
        return ;
    }
    solve(n-1,x,z,y);
    printf("%d %d\n",x,z);
    solve(n-1,y,x,z);
}*/

void solve2(int n, int x, int z)
{
    if(n==0)
    {
        return ;
    }
    solve2(n-1,x,6-x-z);
    printf("%d %d\n",x,z);
    solve2(n-1,6-x-z,z);
   
}
