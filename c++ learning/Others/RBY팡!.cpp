//
//  RBY팡!.cpp
//  c++ learning
//
//  Created by 원태희 on 10/08/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int n;
    cin>>n;
    int arr[10001];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int min=10001;
    for(int i=0;i<n;i++){
        for(int j=1;j<=3;j++){
            if(arr[i]!=j){
                int tmp=arr[i];
                arr[i]=j;
                int left=i;
                int right=i;
                int target=arr[i];
                int target1=arr[i];
                int result=n;
                int cnt=-1;
                while(left>=0&&right<n&&arr[left]==arr[right]){
                    while(left>=0&&target==arr[left]){
                        left--;
                        cnt++;
                    }
                    while(right<n&&target1==arr[right]){
                        right++;
                        cnt++;
                    }
                    if(cnt>=4){
                        result-=cnt;
                    }
                    target=arr[right];
                    target1=arr[left];
                    cnt=0;
                }
                if(min>result)
                    min=result;
                 arr[i]=tmp;
            }
           
        }
    }
    cout<<min<<'\n';
    return 0;
}
