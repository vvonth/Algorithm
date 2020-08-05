//
//  Stack(10799번).cpp
//  c++ learning
//
//  Created by 원태희 on 02/02/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
using namespace std;
int main(){
    string str;
    stack<char> p;
    int count=0;
    cin >> str;
    for(int j=0;j<str.length();j++)
    {
        if(str[j]=='(')
        {
            p.push(str[j]);
            count++;
        }
        else if(str[j-1]=='('&&str[j]==')')
        {
            count--;
            p.pop();
            count+=p.size();
        }
        else
        {
            p.pop();
        }
    }
    
    printf("%d",count);
}
