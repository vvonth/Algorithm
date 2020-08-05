//
//  잃어버린 괄호(1541번).cpp
//  c++ learning
//
//  Created by 원태희 on 02/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(void)
{
    vector<int> number_s;
    vector<int> number;
    vector<char> operation;
    string s;
    int minus_sum=0;
    cin>>s;
    int num=1;
    int result=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='-'||s[i]=='+')
            operation.push_back(s[i]);
    }
    for(int i=0;i<s.size();i++)
    {
        
        if(s[i]=='-'||s[i]=='+')
        {
            for(int j=number_s.size()-1;j>=0;j--)
            {
                result+=number_s[j]*num;
                num*=10;
            }
            number.push_back(result);
            num=1;
            number_s.clear();
            result=0;
        }
        else
            number_s.push_back(s[i]-'0');
    }
    for(int j=number_s.size()-1;j>=0;j--)
    {
        result+=number_s[j]*num;
        num*=10;
    }
    number.push_back(result);
    
   /* for(int i=0;i<number.size();i++)
    {
        printf("%d\n",number[i]);
    }*/
    
    for(int i=1;i<operation.size();i++)
    {
        if(operation[i-1]=='-')
        {
            operation[i]='-';
        }
    }
    int count=number[0];
    for(int i=0;i<operation.size();i++)
    {
        if(operation[i]=='+')
        {
            count+=number[i+1];
            //printf("%d\n",count);
        }
        else
        {
            minus_sum+=number[i+1];
            //printf("%d\n",minus_sum);
        }
    }
    cout<<count-minus_sum<<'\n';
}
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    string s;
    cin >> s;
    vector<int> num;
    vector<int> sign;
    bool minus = false;
    int cur = 0;
    sign.push_back(1);
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            if (s[i] == '+') {
                sign.push_back(1);
            } else {
                sign.push_back(-1);
            }
            num.push_back(cur);
            cur=0;
        } else {
            cur = cur * 10 + (s[i] - '0');//이부분 훨신 편함@@@
        }
    }
    num.push_back(cur);
    int ans = 0;
    minus = false;
    for (int i=0; i<num.size(); i++) {
        if (sign[i] == -1) {
            minus = true;
        }
        if (minus) {
            ans -= num[i];
        } else {
            ans += num[i];
        }
    }
    cout << ans << '\n';
    return 0;
}
*/
