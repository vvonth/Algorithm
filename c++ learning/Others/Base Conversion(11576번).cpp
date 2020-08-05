//
//  Base Conversion(11576번).cpp
//  c++ learning
//
//  Created by 원태희 on 03/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
int arr[26];

int con10(int,int);
void conB(int, int);
int main(void)
{
    int A,B,N,i,C;
    cin>>A>>B;
    cin>>N;
    for(i=0;i<N;i++)
    {
        cin>>arr[i];
        
    }
        C=con10(A,i-1);
        conB(B,C);
}

int con10(int A,int i)
{
    int m=1;
    int sum=0;
    for(int k=i;k>=0;k--)
    {
        sum+=arr[k]*m;
        m*=A;
    }
    return sum;
}

void conB(int B,int C)
{
    stack<int> brr;
    while(C!=0)
    {
        brr.push(C%B);
        C/=B;
    }
    while(!brr.empty())
    {
        cout<<brr.top()<<' ';
        brr.pop();
    }
    cout<<'\n';
}
