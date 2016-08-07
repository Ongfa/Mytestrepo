#include<stdio.h>
#include<stdbool.h>
int n=2;
int marriage(int[2*n][n]);
bool compare(int[2*n][n],int,int,int);
int main(void)
{
	int prefer[2*n][n],man,wom ;
	printf("Enter the preferences of man:\n");
	for(man=0;man<n;man++)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&prefer[man][i]);
		}
	}
	printf("Enter the preferences of women:\n");
	for(wom=n;wom<2*n;wom++)
	{
		for(int i=0;i<n;i++)
		{
			scanf("%d",&prefer[wom][i]);
		}
	}
	marriage(prefer);
}
int marriage(int prefer[2*n][n])
{
	int freem[10]={0},freew[10]={0},man,wom,count=n;
	printf("\nMatching:\n");
	while(count>0)
	{
		for(man=0;man<n;man++)
		{
			if(freem[man]==0)
				break;
		}
		
		for(int i=0;i<n && freem[man]==0;i++)
		{
			wom=prefer[man][i];
			if(freew[wom-n]==0)
			{
				freew[wom-n]=man;
				freem[man]=1;
				count--;
			}
			else
			{
				int man1=freew[wom-n];
				bool flag=compare(prefer,wom,man,man1);
				if(flag==false)
				{
					freew[wom-n]=man;
					freem[man]=1;
					freem[man1]=0;
				}
			}
		}
	}
	printf("Man\tWoman\n");
	for(int i=0;i<n;i++)
	{
		printf("%d\t%d\n",freew[i],i+n);
	}
}
bool compare(int prefer[2*n][n],int wom,int man,int man1)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(prefer[wom][i]==man1)
		{
			return true ;
		}
		if(prefer[wom][i]==man)
		{
			return false;
		}
	}	
}
