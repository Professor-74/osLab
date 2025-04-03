#include <stdio.h>

int main()
{
	printf("\nBankers Algorithm\n\n");
	int n,m;
	printf("\nEnter the no:of processes:\t");
	scanf("%d", &n);
	printf("\nEnter the no:of resources:\t");
	scanf("%d", &m);
	int alloc[n][m],max[n][m],avail[m],finish[n],work[m],ss[n], index=0, need[n][m];
	printf("\nEnter the allocation matrix:\n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			scanf("%d", &alloc[i][j]);
		}	}
			
			printf("\nEnter the Max matrix:\n");
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			scanf("%d", &max[i][j]);
			}}
			
			printf("Enter the availible matrix:\t");
			for(int j=0; j<m; j++)
		{
			scanf("%d", &avail[j]);
			}
			
			for(int j=0; j<m; j++)
		{
			work[j] = avail[j] ;
			}
			
			for(int i=0; i<n;i++)
			{
				finish[i]=0;
				}
				
				for(int i=0; i<n; i++)
				{
					for(int j=0; j<m; j++)
					{
						need[i][j] = max[i][j] - alloc[i][j];
						}
					}
					
					for(int k=0; k<n; k++)
					{
						for(int i=0; i<n; i++)
						{
							if (finish[i]==0)
							{
								int flag=0;
								
								for(int j=0; j<m;j++)
								{
									if (need[i][j]> work[j])
									{
										flag=1;
										break;
										}
										
									}
									
									if (flag==0)
										{
											ss[index++] = i;
							for(int j=0; j<m; j++)
							{
								work[j] = work[j] + alloc[i][j];
								finish[i] =1;
								}
											}
								}
							}
						}
			
			printf("\n\n");
			for(int i=0; i<n; i++)
			{
				printf("p%d\t", ss[i]);
				}
		
		return 0;
	}
