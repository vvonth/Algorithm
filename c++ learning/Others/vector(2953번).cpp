//
//  vector(2953번).cpp
//  c++ learning
//
//  Created by 원태희 on 09/11/2018.
//  Copyright © 2018 원태희. All rights reserved.
//

#include <cstdio>
#include <vector>
//#define max(x,y) (((x)<(y)) ? (y):(x))
using namespace std;
int main() {
    int n,s;
    int m,max_index;
    vector<int>sum;
    sum.reserve(5);
    for(int j=0;j<5;j++)
    {
        s=0;
    for(int i=0;i<4;i++)
    {    scanf("%d",&n);
        s+=n;
    }
        sum.push_back(s);
    }
        
    m=sum.front();
    max_index=0;
    for(int i=1;i<5;i++)
    {
        
        m= max(sum.at(i),m);
        if(m==sum.at(i))
            max_index=i;
    }
    printf("%d %d",max_index+1,m);

}
