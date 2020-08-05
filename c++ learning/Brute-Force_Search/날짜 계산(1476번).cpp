//
//  날짜 계산(1476번).cpp
//  c++ learning
//
//  Created by 원태희 on 30/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
int main(void)
{
    int E,S,M;
    int year=1;
    cin>>E>>S>>M;
    int e=1;
    int s=1;
    int m=1;
    while(1)
    {
        if(e==E&&s==S&&m==M)
        break;
        e++;
        s++;
        m++;
        if(e>15)
        e=1;
        if(s>28)
        s=1;
        if(m>19)
        m=1;
        year++;
    }
    cout<<year<<'\n';
    
/*    year=1;
    while(1)
    {
        cout<<(year-E)%15<<' '<<(year-S)%28<<' '<<(year-M)%19<<'\n';
        if((year-E)%15==0&&(year-S)%28==0&&(year-M)%19==0)
        {
            
            break;
        }
        year++;
    }
    cout<<year<<'\n';
 */
}

