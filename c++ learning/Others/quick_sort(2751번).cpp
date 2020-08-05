//
//  quick_sort(2751번).cpp
//  c++ learning
//
//  Created by 원태희 on 04/04/2019.
//  Copyright © 2019 원태희. All rights reserved.
//

#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
void quick(int*,int,int);
int part(int*,int,int);
int main(void)
{
    int n;
    scanf("%d",&n);
    int *p=(int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    quick(p,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<p[i]<<'\n';
    }
}
void quick(int *p,int low, int high)
{
    if(low<high)
    {
        int pivot=part(p,low, high);//pivot을 계속 바꿔줘야하므로
        quick(p,low,pivot-1);
        quick(p,pivot+1,high);
    }
}

int part(int *p,int low, int high)
{
    
    int pivot=low;
    int pvalue=p[pivot];
    int i=low+1;
    int j=high;
    do
    {
        while(pvalue>p[i]&&i<=high)
            i++;
        while(pvalue<p[j]&&j>=low)
            j--;
        if(i<j)
        swap(p[i],p[j]);
    }while(i<j);
    swap(p[pivot],p[j]);
    return j;
    
}
