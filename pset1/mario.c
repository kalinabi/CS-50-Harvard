#include<stdio.h>
int main()
{
    int n,j,k,l,i;
    scanf("%d",&n);
    for( i=0;i<n;i++)
	{
		for( k=0;k<n-i;k++) 
		{
			printf(" ");
		}
						
		for( j=0;j<=i;j++)
		{
			printf("#");
		}
		 printf(" ");
		for( l=0;l<=i;l++)
		{
			printf("#");
		}
					
			printf("\n");
		}
			
}
// two pyramidswow
