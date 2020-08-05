//
//  거스름돈(5585번).cpp
//  c++ learning
//
//  Created by 원태희 on 2019/11/24.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
int arr[]={500,100,50,10,5,1};
using namespace std;
int main(void){
    int n;
    cin>>n;
    int money=1000-n;
    int cnt=0;
    for(int i=0;i<6;i++){
        if(money/arr[i]>0){
            cnt+=money/arr[i];
            money%=arr[i];
        }
    }
    cout<<cnt<<'\n';
    return 0;
}
