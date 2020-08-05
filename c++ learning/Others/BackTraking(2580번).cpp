//
//  BackTraking(2580번).cpp
//  c++ learning
//
//  Created by 원태희 on 27/12/2018.
//  Copyright © 2018 원태희. All rights reserved.
//

#include <stdio.h>
#include <stack>

int arr[9][9];
int rch(int r, int n)
{
    for(int i=0;i<9;i++)
        if(arr[r][i]==n)
            return 0;
    return 1;
}
int cch(int c, int n)
{
    for(int i=0;i<9;i++)
    {
        if(arr[i][c]==n)
            return 0;
    }
    return 1;
}
int boxch(int r, int c, int n)
{   r=r/3;
    c=c/3;
    for(int i=3*c;i<c*3+3;i++)
        for(int j=r*3;j<r*3+3;j++)
            if(arr[j][i]==n)
                return 0;
    return 1;
}
int isSafe(int r, int c, int n)
{
    if(rch(r, n)&&cch(c,n)&&boxch(r,c,n))
        return 1;
    return 0;
}

void input(){
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
}

int dfs(int x, int y)
{
    int is0exist=0;
    for(int n=1;n<=9;n++)
    {
        if(isSafe(x, y, n)){
            arr[x][y]=n;
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    if(arr[i][j]==0){
                        is0exist=1;
                        if(dfs(i,j)==0)
                            return 0;
                    }
                }
            }
            if(is0exist==0)
                return 0;//0 is success
        }
    }
    arr[x][y]=0;
    return 1;
    //배열에 0이 있는 자리를 찾는다
}

int main(){
    input();
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++)
        { if(arr[i][j]==0){
                dfs(i,j);
                break;
            }
            
        }
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }
}

