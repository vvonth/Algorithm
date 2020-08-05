//
//  practice5.cpp
//  c++ learning
//
//  Created by 원태희 on 2018. 9. 12..
//  Copyright © 2018년 원태희. All rights reserved.
//
#include<iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int main()
{
    iii A=make_pair(ii(3,17), -1993);
    iii B=make_pair(ii(11,20), -1994);
    iii C=make_pair(ii(9,21), -2002);
    vector<iii> birthdays;
    vector<iii>::iterator i;
    birthdays.push_back(A); birthdays.push_back(B); birthdays.push_back(C);
    sort(birthdays.begin(),birthdays.end());
    for(i=birthdays.begin();i!=birthdays.end();i++)
    printf("%d %d %d\n",i->first.first, i->first.second, i->second);
}
