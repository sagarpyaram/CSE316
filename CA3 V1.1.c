#include<stdio.h>
#include<conio.h>
main()
{
	int n_pro,i;
	char sf;
	printf("------------MESS SYSTEM-------------\nEnter number of people\n");
	scanf("%d",&n_pro);
	int pid[n_pro], arr[n_pro], bst[n_pro], pty[n_pro];
	for(i=0;i<n_pro;i++)
	{
		printf("\n\nEnter Identification Number (ID)\n",i+1);
		scanf("%d",&pid[i]);
		printf("Enter arrival time of %d\n",pid[i]);
		scanf("%d",&arr[i]);
		printf("Enter burst time %d\n",pid[i]);
		scanf("%d",&bst[i]);
		printf("Enter if %d is student(S) or faculty(F)\n",pid[i]);
		scanf(" %c",&sf);
		if(sf=='s'||sf=='S')
		{
		pty[i]=1;	
		}
		else if(sf=='f'||sf=='F')
		{
		pty[i]=3;	
		}		
	}
	/*
	Show all PIDs, Arrival Times, Burst Times, Priorities
	for(i=0;i<n_pro;i++)
	{
		printf("\n| %d | %d | %d | %d |", pid[i],arr[i],bst[i],pty[i]);
	}
	*/ 
}
