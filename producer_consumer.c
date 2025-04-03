#include <stdio.h>

int mutex=1, full=0, empty=5, x=0;

void producer()
{
	--mutex;
	++full;
	--empty;
	x++;
	printf("\nProducer added an item");
	++mutex;
	}
	
	void consumer()
	{
		--mutex;
		--full;
		++empty;
		x--;
		printf("\nConsumer consumed an item");
		++mutex;
		}
		
		int main()
		{
			printf("\nEnter 1 for producer\nEnter 2 for consumer\nEnter 3 to exit\n");
			
			for(int i=100; i>0; i--)
			{
				int c;
				printf("\n\nEnter your choice:\t");
				scanf("%d", &c);
				
				switch(c)
				{
					case 1: if (mutex==1 && empty!=0)
					         {
									producer();
									}
									else{
										printf("\nBuffer is full....!");}
										break;
										
										
					case 2:   			if (mutex==1 && full!=0)
											{
												consumer();
												}
												
												else{
													printf("\nBuffer is empty...!");}
													break;
													
													
						case 3: return 0;
					}
				}
				
				return 0;
			}
