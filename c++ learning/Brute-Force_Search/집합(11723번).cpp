//
//  집합(11723번).cpp
//  c++ learning
//
//  Created by 원태희 on 26/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
//이런 비트연산은 메모리제한 시간제한 생각해서 c언어를 최대한 이용
#include <iostream>
#include <cstring>
using namespace std;
char t[7];
int main(void)
{
    int m,n;
    int s=0;
    for(scanf("%d",&m);m>0;m--)
    {
        scanf("%s",t);
        if(!strcmp(t,"add"))
        {
            scanf("%d",&n);
            if(!(s&(1<<n)))
                s=s|(1<<n);
            printf("s: %d\n",s);
        }
        else if(!strcmp(t,"remove"))
        {
            scanf("%d",&n);
            if(s&(1<<n))
                s=s&~(1<<n);
            printf("s: %d\n",s);
        }
        else if(!strcmp(t,"check"))
        {
            scanf("%d",&n);
            if(s&(1<<n))
                printf("1\n");
            else
                printf("0\n");
        }
        else if(!strcmp(t,"toggle"))
        {
            scanf("%d",&n);
            s=s^(1<<n);
        }
        else if(!strcmp(t,"all"))
        {
            printf("s1: %d\n",s);
            //비트를 21개로 해야하는 이유 (0~20)->21개 비트 x의 기준을 (0~19)또는 (1~20)으로 정해야한다.
            s=(1<<21)-1;
            printf("s2: %d\n",s);
        }
        else
        {
            s=0;
        }
    }
    return 0;
}
