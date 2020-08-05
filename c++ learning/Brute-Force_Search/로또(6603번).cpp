//
//  로또(6603번).cpp
//  c++ learning
//
//  Created by 원태희 on 06/06/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
//순열은 안의 내용물 정렬이 무엇보다 중요!!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void)
{
    while(1)
    {
        int n;
        cin>>n;
        if(n==0)
            break;
        
        vector<int> v(n);
        for(int i=0;i<v.size();i++)
        {
            cin>>v[i];
        }
        vector<int> b(n);
        for(int i=0;i<n;i++)
        {
            if(i<6)
                b[i]=1;
            else
                b[i]=0;
        }
        do{
            for(int i=0;i<b.size();i++)
            {
                if(b[i]==1)
                    cout<<v[i]<<' ';
            }
            cout<<'\n';
        }while(prev_permutation(b.begin(),b.end()));
        cout<<'\n';
    }
    return 0;
}
