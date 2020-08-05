#include<stdio.h>
int arr[20];
void change(int);
int compare(int,int);
int main()
{	int n,t;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		change(n);
	}
}


void change(int n)
{	int k,result,i;
	for(int j=2;j<65;j++)
	{	
		for( i=0;i<20;i++)
			 arr[i]=0;
		i=0;
		k=n;
		while(k>=j)

		{	arr[i]=k%j;
			k=k/j;
			i++;
		}
		arr[i]=k;
		result=compare(n,i);
			if(result)
				break;
		
	}
	printf("%d\n",result);
}

int  compare(int n,int i)
{	
	int j=0 ;
	int t=(j+i+1)/2;
	for(j=0;j<=t;j++)
	{
		if(arr[j]==arr[i])
			i--;
			
		else if(arr[j]!=arr[i])
			return 0;
		if(j>=i)
			break;
	}
	
	return 1;
}


