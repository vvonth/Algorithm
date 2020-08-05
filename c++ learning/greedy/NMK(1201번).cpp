//
//  NMK(1201번).cpp
//  c++ learning
//
//  Created by 원태희 on 05/05/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> arr;
int main(void)
{
    int n,m,k;
    cin>>n>>m>>k;
    if(n>m*k||n<m+k-1)
        cout<<-1<<endl;
    else
    {
        for(int i=0;i<n;i++)
        {
            arr.push_back(i+1);
        }
        reverse(arr.begin(),arr.begin()+k);
        
        //현재 개수: n-k, m-1개
        int ele=n-k;
        m=m-1;
        int next=k;
        while(ele>0&&m>0)
        {
            if(ele%m==0)
            {
                reverse(arr.begin()+next,arr.begin()+next+ele/m);
                next=next+ele/m;
                ele=ele-ele/m;
            }
            else
            {
                reverse(arr.begin()+next,arr.begin()+next+(ele/m+1));
                next=next+ele/m+1;
                ele=ele-(ele/m+1);
                cout<<"next: "<<next<<'\n';
            }
            m--;
        }
        for(int i=0;i<n;i++)
        {
            cout<<arr[i]<<' ';
        }
        cout<<endl;
    }
    return 0;
}
