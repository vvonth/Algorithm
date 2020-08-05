//
//  지뢰찾기(2140번).cpp
//  c++ learning
//
//  Created by 원태희 on 25/07/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
char bomb[100][100];
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={0,1,-1,1,-1,0,1,-1};
int calc(int row, int col,int N){
        int check=0;
        for(int i=0;i<8;i++){
            int nrow=row+dx[i];
            int ncol=col+dy[i];
            if(bomb[nrow][ncol]=='0')//지뢰가 없다.
            {   bomb[row][col]=' ';
                check=1;
                break;
            }
        }
        if(!check){//지뢰가 있다.
            bomb[row][col]='*';
            for(int i=0;i<8;i++){
                int nrow=row+dx[i];
                int ncol=col+dy[i];
                if(bomb[nrow][ncol]>='1'&&bomb[nrow][col]<'9'){
                    bomb[nrow][ncol]--;
                }
            }
        }
    return check;
}
int main(void){
    int N;
    cin>>N;
    
    for(int row=0;row<N;row++){
        for(int col=0;col<N;col++){
            scanf(" %c",&bomb[row][col]);
        }
    }
    if(N>2){
    int cnt=(N-2)*(N-2);
    for(int row=1;row<N-1;row++)
    {
        for(int col=1;col<N-1;col++){
            if(bomb[row][col]=='#'){
                if(calc(row, col, N))
                    cnt--;
            }
        }
    }
    cout<<cnt<<'\n';
    }
    else
        cout<<0<<'\n';

    return 0;
}
