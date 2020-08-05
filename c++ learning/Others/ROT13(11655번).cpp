//
//  ROT13(11655번).cpp
//  c++ learning
//
//  Created by 원태희 on 15/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>

using namespace std;
int main(){
    
    string s;
    getline(cin,s);
   
    for(int i=0;i<s.size();i++)
    {
        if((s[i]>='A'&&s[i]<='M')||(s[i]>='a'&&s[i]<='m')) //ABCDEFGHIJKLMNOPQRSTOVWXYZ
           {
               s[i]=s[i]+13;
           }
        else if((s[i]>='N'&&s[i]<='Z')||(s[i]>='n'&&s[i]<='z'))
        {
            s[i]=s[i]-13;
        }
    }
    cout<<s<<"\n";
}
