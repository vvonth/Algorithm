#include <iostream>
using namespace std;
char arr[10][10];
int N;
int M;
void print(){
    printf("------------------------\n");
    for(int r=0;r<N;r++){
        for(int c=0;c<M;c++){
            printf("%c",arr[r][c]);
        }
        printf("\n");
    }
}
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
bool visit[10][10][10][10];
int result;
bool chk;
void dfs(int rr, int rc, int br, int bc, int cnt){
    //종료 조건....
    if(cnt>10){
        return;
    }
    if(arr[br][bc]=='O'){
        return;
    }
    if(arr[rr][rc]=='O'){
        result=min(result,cnt);
        chk=true;
        return;
    }
    for(int k=0;k<4;k++){
        int nrr=rr;
        int nrc=rc;
        int nbr=br;
        int nbc=bc;
        
        while(true){
            if(arr[nrr][nrc]=='.'){
                nrr+=dx[k];
                nrc+=dy[k];
            }
            if(arr[nrr][nrc]=='#'){
                nrr-=dx[k];
                nrc-=dy[k];
                break;
            }
            if(arr[nrr][nrc]=='O'){
                break;
            }
        }
        while(true){
            if(arr[nbr][nbc]=='.'){
                nbr+=dx[k];
                nbc+=dy[k];
            }
            if(arr[nbr][nbc]=='#'){
                nbr-=dx[k];
                nbc-=dy[k];
                break;
            }
            if(arr[nbr][nbc]=='O'){
                break;
            }
        }
        if(nrr==nbr&&nrc==nbc&&arr[nbr][nbc]!='O'){
            if(k==0){
                if(rr>br){
                    nrr+=1;
                }
                else{
                    nbr+=1;
                }
            }
            else if(k==1){
                if(rr>br){
                    nbr-=1;
                }else{
                    nrr-=1;
                }
            }else if(k==2){
                if(rc>bc){
                    nrc+=1;
                }
                else{
                    nbc+=1;
                }
            }
            else{
                if(rc>bc){
                    nbc-=1;
                }
                else{
                    nrc-=1;
                }
            }
        }
        if(!visit[nrr][nrc][nbr][nbc]){
            visit[nrr][nrc][nbr][nbc]=true;
            dfs(nrr,nrc,nbr,nbc,cnt+1);
            visit[nrr][nrc][nbr][nbc]=false;
        }
    }
}
int main(void){
    int rr,rc,br,bc;
    scanf("%d %d",&N,&M);
    for(int r=0;r<N;r++){
        for(int c=0;c<M;c++){
            scanf(" %c",&arr[r][c]);
            if(arr[r][c]=='R'){
                rr=r;
                rc=c;
                arr[r][c]='.';
            }
            else if(arr[r][c]=='B'){
                br=r;
                bc=c;
                arr[r][c]='.';
            }
        }
    }
    result=0x4fffff;
    dfs(rr,rc,br,bc,0);
    if(!chk){
        printf("-1\n");
    }
    else
        printf("%d\n",result);
    return 0;
}
