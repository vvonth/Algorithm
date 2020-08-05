//
//  set(10816번).cpp
//  c++ learning
//
//  Created by 원태희 on 19/02/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <set>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<int,int> m;
    int n,x;
    for(scanf("%d",&n);n>0;n--)
    {
        
        pair<unordered_map<int,int>::iterator,bool>pr;
        scanf("%d",&x);
        pr=m.insert(pair<int,int>(x,1));
        if(pr.second!=true)
            m[x]++;
    }
    
    for(scanf("%d",&n);n>0;n--)
    {
        scanf("%d",&x);
        printf("%d ",m[x]);
    }
    return 0;
}
