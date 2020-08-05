//
//  수 묶기(1744번).cpp
//  c++ learning
//
//  Created by 원태희 on 03/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    int n,a;
    int one=0;
    cin>>n;
    vector<int> plus;
    vector<int> minus;
    int result=0;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        if(a>1)
        {
            plus.push_back(a);
        }
        else if(a<=0)
            minus.push_back(a);
        else
            one++;
        
    }
    sort(plus.begin(),plus.end());
    sort(minus.begin(),minus.end());
    int m=plus.size();
    bool check=false;
    if(m%2==1)
       check=true;
    int multiple=0;
    for(int i=plus.size()-1;i>=1;i-=2)
    {
        if(m>1&&plus[i]!=1&&plus[i-1]!=1)
        {
            multiple+=plus[i]*plus[i-1];
        }
    }
    if(check==true)
        multiple+=plus[0];
    
    bool check2=false;
    if(minus.size()%2==1)
        check2=true;
    int m_mul=0;
    for(int i=1;i<minus.size();i+=2)
    {
        if(minus.size()>1)
        {   m_mul+=minus[i-1]*minus[i];
        }
    }
    if(check2==true)
        m_mul+=minus[minus.size()-1];
    cout<<multiple+m_mul+one<<'\n';
}
