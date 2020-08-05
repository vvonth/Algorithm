//
//  String.cpp
//  c++ learning
//
//  Created by 원태희 on 24/02/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    while(getline(cin,s)){
        int bcount=0;
        int scount=0;
        int space=0;
        int ncount=0;
        
        
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i]>='A'&&s[i]<='Z')
                bcount++;
            else if(s[i]>='a'&&s[i]<='z')
                scount++;
            else if(s[i]==' ')
                space++;
            else
                ncount++;
        }
        printf("%d %d %d %d\n",scount,bcount,ncount,space);
    }
}
