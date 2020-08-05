//
//  min_heap(1927번).cpp
//  c++ learning
//
//  Created by 원태희 on 20/02/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int main(){
    
    priority_queue<int> pq;
    int x,y;
    for(scanf("%d",&x);x>0;x--)
    {
        scanf("%d",&y);
        if(y==0)
        {
            if(pq.empty())
            {
                printf("%d\n",0);
            }
            else
            {
                cout<<-pq.top()<<'\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(-y);
        }
    }
}
