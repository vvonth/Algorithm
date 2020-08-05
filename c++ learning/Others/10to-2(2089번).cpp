//
//  10to-2.cpp
//  c++ learning
//
//  Created by 원태희 on 02/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
vector<char> v;
int main(void)//****나중에 다시 풀어보기
{
    int n;
    
    scanf("%d",&n);//나머지는 양수
    if(n==0)
    { v.push_back('0');
        return 0;
    }
    while(n!=0)
    {
        if(n%2==0)
        {
            v.push_back('0');
            n=-(n/2);
        }
        else{
            if(n>0)
            {
                n=-(n/2);
            }
            else{
                n=(-n+1)/2;
            }
            v.push_back('1');
        }
    }
    reverse(v.begin(),v.end());
    for(auto x: v)
        cout<<x;
    

}
