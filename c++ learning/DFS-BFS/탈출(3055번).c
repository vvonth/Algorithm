#include <stdio.h>
typedef struct que{
    int r;
    int c;
}que;
que water[5000];
que dochi[5000];
int dochi_front;
int dochi_rear;
int water_front;
int water_rear;
char map[51][51];
int R,C;
int go_x;
int go_y;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
int wvisited[51][51];
int gvisited[51][51];
void print(){
    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            printf(" %c ",map[r][c]);
        }
        printf("\n");
    }
}

int main(void){
    scanf("%d %d",&R,&C);
    for(int r=0;r<R;r++){
        for(int c=0;c<C;c++){
            scanf(" %c",&map[r][c]);
            if(map[r][c]=='S'){
                go_x=r;
                go_y=c;
                map[r][c]='.';
                gvisited[r][c]=1;
                dochi[dochi_rear].r=go_x;
                dochi[dochi_rear++].c=go_y;
            }else if(map[r][c]=='*'){
                wvisited[r][c]=1;
                water[water_rear].r=r;
                water[water_rear++].c=c;
            }
        }
    }
    int result=-1;
    int time=0;
    while(dochi_front!=dochi_rear){
        //물 이동
        int size=water_rear;
        int start=water_front;
        for(int i=start;i<size;i++){
            int r=water[water_front].r;
            int c=water[water_front].c;
            water_front++;
            
            for(int k=0;k<4;k++){
                int nr=r+dx[k];
                int nc=c+dy[k];
                if(nr>=0&&nr<R&&nc>=0&&nc<C&&!wvisited[nr][nc]&&map[nr][nc]=='.'){
                    wvisited[nr][nc]=1;
                    water[water_rear].r=nr;
                    water[water_rear++].c=nc;
                    map[nr][nc]='*';
                }
            }
        }
        size=dochi_rear;
        start=dochi_front;
        for(int i=start;i<size;i++){
            int r=dochi[dochi_front].r;
            int c=dochi[dochi_front].c;
            dochi_front++;
            if(map[r][c]=='D')
            {
                result=time;
                break;
            }
            for(int k=0;k<4;k++){
                int nr=r+dx[k];
                int nc=c+dy[k];
                if(nr>=0&&nr<R&&nc>=0&&nc<C&&!gvisited[nr][nc]&&(map[nr][nc]=='.'||map[nr][nc]=='D')){
                    gvisited[nr][nc]=1;
                    dochi[dochi_rear].r=nr;
                    dochi[dochi_rear++].c=nc;
                }
            }
        }
        //고슴도치 이동
        if(result!=-1)
            break;
        time++;
    }
    if(result==-1){
        printf("KAKTUS\n");
    }else{
        printf("%d\n",result);
    }
    return 0;
}
