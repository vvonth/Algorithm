//
//  map(1076번).cpp
//  c++ learning
//
//  Created by 원태희 on 19/02/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{   long long k=1;
    vector<int> v;
    map<string,int>m={{"black",0},{"brown",1},{"red",2},{"orange",3},{"yellow",4},{"green",5},{"blue",6},{"violet",7},{"grey",8},{"white",9}};
    string n;
    for(int i=0;i<3;i++)
    {
        cin>>n;
        v.push_back(m[n]);
    }
    for(int i=0;i<v.at(2);i++)
        k*=10;
    long long sum=(v.at(0)*10+v.at(1))*k;
    cout<<sum<<'\n';
}
