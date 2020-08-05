//
//  bitset(12813번).cpp
//  c++ learning
//
//  Created by 원태희 on 21/02/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <bitset>

using namespace std;

int main(){
    
    string A;
    string B;
    cin>>A>>B;
    bitset<100000> ba(A), bb(B);
    
    cout<<(ba & bb)<<'\n';
    cout<<(ba | bb)<<'\n';
    cout<<(ba ^ bb)<<'\n';
    cout<<(~ba)<<'\n';
    cout<<(~bb)<<'\n';
}
