//
//  Record Keeping(9872번).cpp
//  c++ learning
//
//  Created by 원태희 on 25/07/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(void){
    int n;
    int max=0;
    string k;
    cin>>n;
    priority_queue<string> q;
    vector<string> v;
    vector<int>v2;
    for(int row=0;row<n;row++){
        string s="";
        
        for(int col=0;col<3;col++){
            cin>>k;
            q.push(k);
        }
        for(int k=0;k<3;k++){
            s+=q.top()+",";
            q.pop();
        }
        v.push_back(s);
    }
    for(int i=0;i<v.size();i++){
        int cnt=1;
        for(int j=i+1;j<v.size();j++){
            if(!(v[i].compare(v[j]))){
                cnt++;
            }
        }
        if(max<cnt)
            max=cnt;
    }
    cout<<max<<'\n';
    return 0;
}

