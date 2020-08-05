//
//  감시(15683번).cpp
//  c++ learning
//
//  Created by 원태희 on 2019/11/09.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
int R,C;
char map[8][8];
char copy_map[8][8];
typedef struct cctv{
    int num;
    int r;
    int c;
}cctv;
cctv cv[8];
int sel[8];
int cv_cnt;
int total;
int dx[]={1,-1,0,0};//하,상,우,좌
int dy[]={0,0,1,-1};
void check(int nr, int nc,int x, int y){
    while(true){
        if(nr<0||nr>=R||nc<0||nc>=C)
            break;
        if(map[nr][nc]=='0'){
            map[nr][nc]='#';
        }else if(map[nr][nc]=='6'){
            break;
        }
        nr+=x;
        nc+=y;
    }
}
void shoot(int r, int c, int num,int rotate){
    switch (num) {
        case 1:
            //기본 0일 경우 dx[2],dy[2]
            if(rotate==0){
                check(r+dx[2],c+dy[2],dx[2],dy[2]);//우
            }else if(rotate==1){
                check(r+dx[0],c+dy[0],dx[0],dy[0]);//하
            }else if(rotate==2){
                check(r+dx[3],c+dy[3],dx[3],dy[3]);//좌
            }else{
                check(r+dx[1],c+dy[1],dx[1],dy[1]);//상
            }
            break;
        case 2:
            if(rotate==0){
                check(r+dx[2],c+dy[2],dx[2],dy[2]);
                check(r+dx[3],c+dy[3],dx[3],dy[3]);
            }else if(rotate==1){
                check(r+dx[0],c+dy[0],dx[0],dy[0]);
                check(r+dx[1],c+dy[1],dx[1],dy[1]);
            }else if(rotate==2){
                check(r+dx[2],c+dy[2],dx[2],dy[2]);
                check(r+dx[3],c+dy[3],dx[3],dy[3]);
            }else{
                check(r+dx[0],c+dy[0],dx[0],dy[0]);
                check(r+dx[1],c+dy[1],dx[1],dy[1]);
            }
            break;
        case 3:
            if(rotate==0){
                check(r+dx[1],c+dy[1],dx[1],dy[1]);//상
                check(r+dx[2],c+dy[2],dx[2],dy[2]);//우
            }else if(rotate==1){
                check(r+dx[2],c+dy[2],dx[2],dy[2]);//우
                check(r+dx[0],c+dy[0],dx[0],dy[0]);//하
            }else if(rotate==2){
                check(r+dx[0],c+dy[0],dx[0],dy[0]);//하
                check(r+dx[3],c+dy[3],dx[3],dy[3]);//좌
            }else{
                check(r+dx[3],c+dy[3],dx[3],dy[3]);//좌
                check(r+dx[1],c+dy[1],dx[1],dy[1]);//상
            }
            break;
        default:
            if(rotate==0){
                check(r+dx[1],c+dy[1],dx[1],dy[1]);//상
                check(r+dx[2],c+dy[2],dx[2],dy[2]);//우
                check(r+dx[3],c+dy[3],dx[3],dy[3]);//좌
            }else if(rotate==1){
                check(r+dx[1],c+dy[1],dx[1],dy[1]);//상
                check(r+dx[2],c+dy[2],dx[2],dy[2]);//우
                check(r+dx[0],c+dy[0],dx[0],dy[0]);//하
            }else if(rotate==2){
                check(r+dx[2],c+dy[2],dx[2],dy[2]);//우
                check(r+dx[0],c+dy[0],dx[0],dy[0]);//하
                check(r+dx[3],c+dy[3],dx[3],dy[3]);//좌
            }else{
                check(r+dx[0],c+dy[0],dx[0],dy[0]);//하
                check(r+dx[3],c+dy[3],dx[3],dy[3]);//좌
                check(r+dx[1],c+dy[1],dx[1],dy[1]);//상
            }
            break;
    }
}
void reperm(int idx){
    if(idx==cv_cnt){
        for(int i=0;i<cv_cnt;i++){
            shoot(cv[i].r, cv[i].c, cv[i].num,sel[i]);//좌표, cctv번호, 회전
        }
        int cnt=0;
        for(int r=0;r<R;r++){
            for(int c=0;c<C;c++){
                if(map[r][c]=='0')
                    cnt++;
            }
        }
        total=min(total,cnt);
        memcpy(map, copy_map, sizeof(map));
        return;
    }
    for(int i=0;i<5;i++){
        sel[idx]=i;
        reperm(idx+1);
    }
}

int main(void){
    cin>>R>>C;
    
    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            scanf(" %c",&map[r][c]);
            copy_map[r][c]=map[r][c];
            if(map[r][c]>='1'&&map[r][c]<'5'){
                cv[cv_cnt].num=map[r][c]-'0';
                cv[cv_cnt].r=r;
                cv[cv_cnt++].c=c;
            }
        }
    }
    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            if(map[r][c]=='5'){
                for(int k=0;k<4;k++){
                    int nr=r+dx[k];
                    int nc=c+dy[k];
                    while(true){
                        if(nr<0||nr>=R||nc<0||nc>=C)
                        break;
                        if(map[nr][nc]=='0'){
                            map[nr][nc]='#';
                            copy_map[nr][nc]=map[nr][nc];
                        }else if(map[nr][nc]=='6'){
                            break;
                        }
                        nr+=dx[k];
                        nc+=dy[k];
                    }
                }
            }
        }
    }
    total=70;
    reperm(0);
    cout<<total<<'\n';
    return 0;
}
