#include<stdio.h>
#include<stdlib.h>
void red(char**,int,int,int);
void blue(char**,int,int,int);
void green(char**,int,int,int);
char arr[101][101];
int main()
{
	int N,m,n,count=0,count1=0;
	scanf("%d",&N);
	
	char **d;
	d=(char**)malloc(sizeof(char*)*(N));
	for(int i=0;i<N;i++)
		d[i]=(char*)malloc(sizeof(char)*N);
	for(int i=0;i<N;i++)
		scanf("%s",d[i]);
		
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			arr[i][j]=d[i][j];
			if(arr[i][j]=='G')
				arr[i][j]='R';
		}
	}

	for(m=0;m<N;m++)
	{
		for(n=0;n<N;n++)
		{
			if(d[m][n]=='R')
			{
				red(d,N,m,n);
				count++;	
			}
			else if(d[m][n]=='B')
			{
				blue(d,N,m,n);
				count++;
			}
			else if(d[m][n]=='G')
			{
				green(d,N,m,n);
				count++;
			}
		}
	}

	printf("%d ",count);
	for(m=0;m<N;m++)
	{
		for(n=0;n<N;n++)
		{
			d[m][n]=arr[m][n];}
	}

	for(m=0;m<N;m++)
	{
		for(n=0;n<N;n++)
		{
			if(d[m][n]=='R')
			{
				red(d,N,m,n);
				count1++;
			}
			else if(d[m][n]=='B')
			{
				blue(d,N,m,n);
				count1++;
			}
		}
	}
			
	printf("%d",count1);
}

void red(char**d,int N, int m, int n)
{
	if(d[m][n]==0)
		return;
		d[m][n]=0;
	if(m-1>=0&&d[m-1][n]=='R')
		red(d,N, m-1, n);
	if(n-1>=0&&d[m][n-1]=='R')
		red(d, N, m, n-1);
	if(m+1<N&&d[m+1][n]=='R')
		red(d, N, m+1, n);
	if(n+1<N&&d[m][n+1]=='R')
		red(d, N, m, n+1);
	return;
}

void blue(char** d, int N, int m, int n)
{
	if(d[m][n]==0)
		return;
		d[m][n]=0;
	if(m-1>=0&&d[m-1][n]=='B') 
	         blue(d, N, m-1,  n);
	         if(n-1>=0&&d[m][n-1]=='B') 
	                 blue(d, N,  m,  n-1);
	         if(m+1<N&&d[m+1][n]=='B')
	                blue(d, N,  m+1, n);
	      if(n+1<N&&d[m][n+1]=='B')
		   blue(d, N, m,n+1);
	            return;
}

void green(char**d, int N, int m, int n)
{
	if(d[m][n]==0)
		return;
	d[m][n]=0;
	if(m-1>=0&&d[m-1][n]=='G') 
	         green(d, N, m-1, n);
	   if(n-1>=0&&d[m][n-1]=='G') 
                   green(d,N, m, n-1);
          if(m+1<N&&d[m+1][n]=='G')
	                 green(d, N, m+1, n);
          if(n+1<N&&d[m][n+1]=='G')
                green(d, N, m, n+1);
	             return;
}
