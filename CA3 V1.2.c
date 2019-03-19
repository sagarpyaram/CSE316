#include<stdio.h>
#include<conio.h>
#include<windows.h>
main()
{
	int n,i,j,tmp;
	char sf;
	printf("------------MESS SYSTEM-------------\nEnter number of people\n");
	scanf("%d",&n);
	int st[n][5],ft[n][5],sc=0,fc=0;
	for(i=0;i<n;i++)
	{
		system("cls");
		printf("Is customer a student(S) or faculty(F)?\n");
		scanf(" %c",&sf);
		if(sf=='s'||sf=='S')
		{
		st[sc][0]=sc+1;
		printf("Enter student ID\n");
		scanf("%d",&st[sc][1]);
		printf("Enter arrival time\n");
		scanf("%d",&st[sc][2]);
		printf("Enter burst time\n");
		scanf("%d",&st[sc][3]);
		st[sc][4]=1;
		sc++;
		}
		else if(sf=='f'||sf=='F')
		{
		ft[fc][0]=fc+1;
		printf("Enter faculty ID\n");
		scanf("%d",&ft[fc][1]);
		printf("Enter arrival time\n");
		scanf("%d",&ft[fc][2]);
		printf("Enter burst time\n");
		scanf("%d",&ft[fc][3]);
		ft[fc][4]=3;
		fc++;	
		}			
	}
	//Sorting according to arrival times
	{
		for (i = 0; i < sc; i++)         //Student sorting            
		{
			for (j = 0; j < sc; j++)             
			{
				if (st[j][2] > st[i][2])                
				{
					tmp = st[i][2];        
					st[i][2] = st[j][2];            
					st[j][2] = tmp;
					tmp = st[i][0];        
					st[i][0] = st[j][0];            
					st[j][0] = tmp;
					tmp = st[i][1];        
					st[i][1] = st[j][1];            
					st[j][1] = tmp;
					tmp = st[i][3];        
					st[i][3] = st[j][3];            
					st[j][3] = tmp;        
				}  
			}
		}
		for (i = 0; i < sc; i++)              //Faculty Sorting       
		{
			for (j = 0; j < sc; j++)             
			{
				if (ft[j][2] > ft[i][2])                
				{
					tmp = ft[i][2];        
					ft[i][2] = ft[j][2];            
					ft[j][2] = tmp;
					tmp = ft[i][0];        
					ft[i][0] = ft[j][0];            
					ft[j][0] = tmp;
					tmp = ft[i][1];        
					ft[i][1] = ft[j][1];            
					ft[j][1] = tmp;
					tmp = ft[i][3];        
					ft[i][3] = ft[j][3];            
					ft[j][3] = tmp;         
				}  
			}
		}
	}
	/*
	//Printing list of pre entered students and faculty
	system("cls");
	printf("Student List\n");
	for(i=0;i<sc;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d ",st[i][j]);
		}
		printf("\n");
	}
	printf("\n\nFaculty List\n");
	for(i=0;i<fc;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d ",ft[i][j]);
		}
		printf("\n");
	}
	*/
	system("cls");
	int sgui=sc,fgui=fc,max;
	if(sgui>fgui)
	max=sgui;
	else
	max=fgui;
	//Count instances of each until x time and set sgui and fgui to those per every x time iteration
	for(j=0;j<100;j++)
	{
		system("cls");
		sgui=sc;
		fgui=fc;
		printf("                     %d",j);
		printf("\n\n                 [  MESS  ]\n");
		for(i=0;i<max;i++)
		{
			if(sgui==0 && fgui==0)
				continue;
			if(sgui>0)
				{
				printf("                  S");
				sgui--;
				}	
			else
				printf("                   ");
			if(fgui>0)
				{
				printf("      F\n");
				fgui--;
				}
			else
				printf("\n");
		}
		Sleep(500);
	}
}
