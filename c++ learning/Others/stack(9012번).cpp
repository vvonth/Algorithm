//
//  stack(9012번).cpp
//  c++ learning
//
//  Created by 원태희 on 10/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
#include<iostream>
#include<string>
using namespace std;
int main(){
    int n;
    
    for(scanf("%d",&n);n>0;n--)
    {
        int count=0;
        string s;
        cin>>s;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                count++;
            else
                count--;
        }
        if(count<0||count>0)
            printf("NO\n");
        else
            printf("YES\n");
        
    }
}
