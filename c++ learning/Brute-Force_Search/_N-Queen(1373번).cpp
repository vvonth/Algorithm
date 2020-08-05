#include<iostream>
using namespace std;
int check[16][16];
int visit(int row, int col, int n)
{
    for(int i=row-1;i>=0;i--)
    {
        if(check[i][col])
            return 0;
    }
    int x=row-1;
    int y=col-1;
    while(x>=0&&y>=0)
    {
        if(check[x][y])
            return 0;
        x-=1;
        y-=1;
    }
    x=row-1;
    y=col+1;
    while(x>=0&&y<n)
    {
        if(check[x][y])
            return 0;
        x-=1;
        y+=1;
    }
    return 1;
}
void calc(int row,int n,int *ans)
{
    if(row==n)
        (*ans)++;
    for(int col=0;col<n;col++)
    {
        check[row][col]=1;
        if(visit(row,col,n))
            calc(row+1,n,ans);
        check[row][col]=0;
    }
}
int main(void)
{
    int n;
    int ans=0;
    cin>>n;
    calc(0,n,&ans);
    cout<<ans<<'\n';
}
