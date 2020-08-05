//
//  주사위 굴리기(14499번).cpp
//  c++ learning
//
//  Created by 원태희 on 04/08/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
int dice[6];//뒷면:0,앞면:4,왼쪽면:1,오른쪽면:3,윗면:2,밑면 5
int tmp;
void east(){
    tmp=dice[5];
    dice[5]=dice[3];
    dice[3]=dice[2];
    dice[2]=dice[1];
    dice[1]=tmp;
}
void west(){
    tmp=dice[5];
    dice[5]=dice[1];
    dice[1]=dice[2];
    dice[2]=dice[3];
    dice[3]=tmp;
}
void north(){
    tmp=dice[5];
    dice[5]=dice[0];
    dice[0]=dice[2];
    dice[2]=dice[4];
    dice[4]=tmp;
}
void south(){
    tmp=dice[5];
    dice[5]=dice[4];
    dice[4]=dice[2];
    dice[2]=dice[0];
    dice[0]=tmp;
}
int main(void){
    int n,m,x,y,k;
    cin>>n>>m>>x>>y>>k;
    int map[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }
    //시작위치 x,y
    //명령어 k
    for(int i=0;i<k;i++){
        int cmd;
        cin>>cmd;
        
        switch (cmd) {
            case 1://동쪽
                if(y+1<m)
                {
                    east();
                    if(map[x][y+1]==0){
                        map[x][y+1]=dice[5];
                    }
                    else{
                        dice[5]=map[x][y+1];
                        map[x][y+1]=0;
                    }
                    y++;
                    printf("%d\n",dice[2]);
                }
                break;
            case 2://서쪽
                if(y-1>=0)
                {
                    west();
                    if(map[x][y-1]==0){
                        map[x][y-1]=dice[5];
                    }
                    else{
                        dice[5]=map[x][y-1];
                        map[x][y-1]=0;
                    }
                    y--;
                    printf("%d\n",dice[2]);
                }
                break;
            case 3://북쪽
                if(x-1>=0){
                    north();
                    if(map[x-1][y]==0){
                        map[x-1][y]=dice[5];
                    }
                    else{
                        dice[5]=map[x-1][y];
                        map[x-1][y]=0;
                    }
                    x--;
                    printf("%d\n",dice[2]);
                }
                break;
            default://남쪽
                if(x+1<n)
                {
                    south();
                    if(map[x+1][y]==0){
                        map[x+1][y]=dice[5];
                    }
                    else{
                        dice[5]=map[x+1][y];
                        map[x+1][y]=0;
                    }
                    x++;
                    printf("%d\n",dice[2]);
                }
                break;
        }
    }
    return 0;
}
