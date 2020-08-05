//
//  리모컨(1107번).cpp
//  c++ learning
//
//  Created by 원태희 on 31/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
//접근 방식... 고려할 것
//N의 근사값 고려 못했음, 처음부터 근사값을 찾으려 하다보니 최소값 다 고려를 하지 못했다.
//브루드 포스 방식으로 처음부터 모든 경계 다 고려하면 된다.
#include <iostream>
using namespace std;
int main(void)
{
    bool remote[10];
    for(int i=0;i<10;i++)
    {
        remote[i]=true;
    }
    int N;
    cin>>N;
    
    int broken,k;
    cin>>broken;
    for(int i=0;i<broken;i++)
    {
        cin>>k;
        remote[k]=false;
    }
    int c;
    int min=abs(100-N);
    bool ch=false;
    for(int i=0;i<10;i++)
    {
        if(remote[i]==true)
            ch=true;
    }
    for(int i=0;i<=1000000;i++)
    {
        bool check =true;
        int result=0;
        int cnt=0;
        c=i;
       
        if(c==0)
            {
                if(remote[c%10]==false)
                    check=false;
                cnt=1;
            }
            while(c>0)
            {
                if(remote[c%10]==false)
                {
                    check=false;
                    break;
                }
                    c/=10;
                    cnt++;
            }
            if(check==true)
            {
                result=cnt;
                result+=abs(N-i);
                if(min>result)
                    min=result;
            }
        }
    
    cout<<min<<'\n';
    return 0;
}
