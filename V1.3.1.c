#include<stdio.h>
#include<conio.h>
#include<windows.h>
main()
{
	int n,i,j,tmp;
	char sf;
	printf("------------MESS SYSTEM-------------\nEnter number of people\n");
	scanf("%d",&n);
	int st[n][5],sc=0,fc=0;
	for(i=0;i<n;i++)
	{
		system("cls");
		printf("Is customer a student(S) or faculty(F)?\n");
		scanf(" %c",&sf);
		if(sf=='s'||sf=='S')
		{
		st[i][0]=i+1;
		printf("Enter student ID\n");
		scanf("%d",&st[i][1]);
		st[i][4]=1;
		st[i][5]=1;
		sc++;
		}
		else if(sf=='f'||sf=='F')
		{
		st[i][0]=i+1;
		printf("Enter faculty ID\n");
		scanf("%d",&st[i][1]);
		st[i][4]=3;
		st[i][5]=3;
		fc++;
		}
		printf("Enter arrival time\n");
		scanf("%d",&st[i][2]);
		printf("Enter burst time\n");
		scanf("%d",&st[i][3]);	
	}
	//Sorting according to arrival times
	{
		for (i = 0; i < n; i++)         //Sorting            
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
					tmp = st[i][4];        
					st[i][4] = st[j][4];            
					st[j][4] = tmp; 
					tmp = st[i][5];        
					st[i][5] = st[j][5];            
					st[j][5] = tmp;         
				}  
			}
		}
		/*for (i = 0; i < sc; i++)              //Faculty Sorting #V1.2 Code      
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
		}*/
	}
	//Printing list of students and faculty
	system("cls");
	printf("Student List\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<6;j++)
		{
			printf("%d ",st[i][j]);
		}
		printf("\n");
	}
	/*printf("\n\nFaculty List\n");
	for(i=0;i<fc;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%d ",st[i][j]);
		}
		printf("\n");
	}*/
	/*
	system("cls");
	//DEJAI-NE :) Dis ij cho tuff
	int sgui=sc,fgui=fc,max;
	if(sgui>fgui)
	max=sgui;
	else
	max=fgui;
	int na=0,m=0,x=0,z=0;
	for(j=0;j<100;j++)
	{
		system("cls");
		if(st[x][2]==j)
		{
			na++;
			x++;
		}
		else if(ft[z][2]==j)
		{
			m++;
			z++;
		}
		sgui=na;
		fgui=m;
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
		Sleep(300);
	}*/
}
