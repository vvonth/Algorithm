//
//  스도쿠(2580번).cpp
//  c++ learning
//
//  Created by 원태희 on 08/07/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#define MAX 9
using namespace std;
int r[MAX][MAX];//
int c[MAX][MAX];
int ch[MAX][MAX];
int a[MAX][MAX];
int main(void)
{
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            cin>>a[i][j];
            if(a[i][j]!=0)
            {
                r[i][a[i][j]]=1;
                c[a[i][j]][j]
            }
            
        }
    }
}
