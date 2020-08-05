//
//  폭죽쇼(1773번).cpp
//  c++ learning
//
//  Created by 원태희 on 25/07/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
int arr[100];
using namespace std;
int main(void){
    int N,C;
    cin>>N>>C;

    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    int cnt=0;
    for(int i=1;i<=C;i++){
        for(int k=0;k<N;k++){
            if(i%arr[k]==0){
                cnt++;
                break;
            }
        }
    }
    cout<<cnt<<'\n';
}
