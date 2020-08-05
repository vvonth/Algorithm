//
//  알파벳(1987번).cpp
//  c++ learning
//
//  Created by 원태희 on 14/07/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include <iostream>
using namespace std;
char arr[21][21];
int check[26];
int m;
void alphago(int row, int col,int count,int all_row,int all_col)
{
    check[arr[row][col]-'A']=1;
    if(row+1< all_row&&!check[arr[row+1][col]-'A'])
        alphago(row+1,col,count+1,all_row,all_col);
    if(row-1>=0&&!check[arr[row-1][col]-'A'])
        alphago(row-1, col,count+1, all_row, all_col);
    if(col+1<all_col&&!check[arr[row][col+1]-'A'])
        alphago(row, col+1,count+1,all_row,all_col);
    if(col-1>=0&&!check[arr[row][col-1]-'A'])
        alphago(row,col-1,count+1,all_row,all_col);
    check[arr[row][col]-'A']=0;
    if(m<count)
        m=count;
    
}
int main(void)
{
    int row, col;
    cin>>row>>col;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf(" %c",&arr[i][j]);
        }
    }
    alphago(0,0,1,row,col);
    printf("%d",m);
    return 0;
}
