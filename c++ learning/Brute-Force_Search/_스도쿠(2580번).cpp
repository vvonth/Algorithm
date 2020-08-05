//
//  스도쿠(2580번).cpp
//  c++ learning
//
//  Created by 원태희 on 08/07/2019.
//  Copyright © 2019 원태희. All rights reserved.
//
//
//#include <iostream>
//#define MAX 9
//using namespace std;
//int r[MAX][MAX];//
//int c[MAX][MAX];
//int ch[MAX][MAX];
//int a[MAX][MAX];
//
//void go(int z)
//{
//    if(z==81)
//    {
//        for(int i=0;i<MAX;i++)
//        {
//            for(int j=0;j<MAX;j++)
//            {
//                cout<<a[i][j]<<' ';
//            }
//            cout<<'\n';
//        }
//        return;
//    }
//
//    int x=z/9;
//    int y=z%9;
//    if(a[x][y]!=0)
//    {
//        go(z+1);
//    }
//    else
//    {
//        for(int i=1;i<10;i++)
//        {
//                if(!r[x][i]&&!c[y][i]&&!ch[(x/3)*3+(y/3)][i])
//                {
//                    a[x][y]=i;
//                    r[x][i]=c[y][i]=ch[(x/3)*3+(y/3)][i]=1;
//                    go(z+1);
//                    a[x][y]=0;
//                    r[x][i]=c[y][i]=ch[(x/3)*3+(y/3)][i]=0;
//             }
//        }
//    }
//}
//
//
//int main(void)
//{
//    for(int i=0;i<MAX;i++)
//    {
//        for(int j=0;j<MAX;j++)
//        {
//            cin>>a[i][j];
//            if(a[i][j]!=0)
//            {
//                r[i][a[i][j]]=1;
//                c[j][a[i][j]]=1;
//                ch[(i/3)*3+(j/3)][a[i][j]]=1;
//            }
//        }
//    }
//    go(0);
//
//}
#include <iostream>
#define MAX 9
using namespace std;
int puzzle[MAX][MAX];
int check[MAX][MAX];

int find1(int row, int col,int n)
{
    for(int i=0;i<MAX;i++)
    {
        if(i==col)
            continue;
        if(puzzle[row][i]==n)
            return 0;
    }
    return 1;
}

int find2(int row, int col, int n)
{
    for(int i=0;i<MAX;i++)
    {
        if(i==row)
            continue;
        if(puzzle[i][col]==n)
            return 0;
    }
    return 1;
}
int find3(int row, int col, int n)
{
    for(int i=3*(row/3);i<3*(row/3)+3;i++)
    {
        for(int j=3*(col/3);j<3*(col/3)+3;j++)
        {
            if(i==row&&j==col)
                continue;
            if(puzzle[i][j]==n)
                return 0;
        }
    }
    return 1;
}

int calc()
{
    for(int row=0; row<MAX;row++)
    {
        for(int col=0;col<MAX;col++)
        {
            if(puzzle[row][col]==0)
            {   int i;
                for(i=1;i<10;i++)
                {
                    if(find1(row,col,i)&&find2(row,col,i)&&find3(row,col,i))
                    {
                        puzzle[row][col]=i;
                        if(!calc())
                        {
                            puzzle[row][col]=0;
                        }
                        else
                            return 1;
                    }
                }
                    return 0;
            }
        }
    }
    return 1;
}
int main(void)
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            cin>>puzzle[i][j];
            if(puzzle[i][j]==0)
                check[i][j]=1;
        }
    }
    calc();
    for(int i=0;i<MAX;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            cout<<puzzle[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
}
