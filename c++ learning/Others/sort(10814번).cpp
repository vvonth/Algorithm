//
//  sort(10814번).cpp
//  c++ learning
//
//  Created by 원태희 on 05/03/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
typedef struct Point{
    int age;
    string name;
}P;
bool cmp(const P &u,const P &v)
{
    return u.age<v.age;
}
int main(){
    int n;
    vector<P> v;
    P u;
    for(scanf("%d",&n);n>0;n--)
    {
        cin>>u.age>>u.name;
        v.push_back(u);
    }
    stable_sort(v.begin(),v.end(),cmp);
    for(auto x : v)
        cout<<x.age<<' '<<x.name;
}
