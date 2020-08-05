#include <iostream>
using namespace std;
int size[5]={5,5,5,5,5};
int arr[10][10];
int check[10][10];
int result;
void dfs(int);
int match(int,int,int);
int main(void){
    for(int row=0;row<10;row++){
        for(int col=0;col<10;col++){
            scanf("%d",&arr[row][col]);
        }
    }
    result=0x4fffff;
    dfs(0);
    if(result==0x4fffff){
        printf("-1\n");
    }else{
        printf("%d\n",result);
    }
    return 0;
}
void dfs(int cnt){
    int start_row=-1;
    int start_col=-1;
    int chk=0;
    for(int row=0;row<10;row++){
        for(int col=0;col<10;col++){
            if(arr[row][col]==1){
                start_row=row;
                start_col=col;
                chk=1;
                break;
            }
        }
        if(chk)
            break;
    }
    if(start_row==-1&&start_col==-1){
        result=min(result, cnt);
        return;
    }
    if(result<=cnt)
        return;
    for(int i=4;i>=0;i--){
        if(start_row+i<10&&start_col+i<10&&match(start_row, start_col, i+1)&&size[i]>0){
            //붙일 수 있으면
            for(int r=start_row;r<start_row+i+1;r++){
                for(int c=start_col;c<start_col+i+1;c++){
                    arr[r][c]=0;
                    //                   cout<<r<<' '<<c<<'\n';
                }
            }
            size[i]--;
            dfs(cnt+1);
            size[i]++;
            for(int r=start_row;r<start_row+i+1;r++){
                for(int c=start_col;c<start_col+i+1;c++){
                    arr[r][c]=1;
                }
            }
        }
    }
}

int match(int row, int col,int cnt){
    for(int r=row;r<row+cnt;r++){
        for(int c=col;c<col+cnt;c++){
            if(arr[r][c]==0)
                return 0;
        }
    }
    return 1;
}
