#include<stdio.h>
#include<conio.h>
#include<windows.h>
main()
{
	//INITIALIZATIONS
	int n;
	system("color 0a");
	printf("Mess System\nEnter number of customers : ");
	scanf("%d",&n);
	int tri[n][7],gc[n]; //ID 0, Arr 1,Burst 2, Priority 3, ID factor(1s,2f) 4, Status (0/1) 5,PID 6
	int i,j,sc=0,fc=0,pri=3,tmp,bst=0;
	char sf;
	//USER INPUT
	for(i=0;i<n;i++)
	{
		LBS:
		system("cls");
		printf("\n\nIs customer a student(S) or a faculty(F)?\n");
		scanf(" %c",&sf);
		system("cls");
		if(sf=='s'||sf=='S')
		{
			printf("Enter student ID : ");
			scanf("%d",&tri[i][0]);
			sc++;
			tri[i][3]=1;
			tri[i][4]=1;				
		}
		else if(sf=='f'||sf=='F')
		{
			printf("Enter faculty ID : ");
			scanf("%d",&tri[i][0]);
			fc++;
			tri[i][3]=pri;
			tri[i][4]=2;				
		}
		else
		{
			printf("Invalid Entry!\nPress any key to continue...\n");
			getch();
			goto LBS;
		}
		AZ:
		system("cls");
		printf("\nEnter arrival time (t) where 0 <= t : ");
		scanf("%d",&tri[i][1]);
		if(tri[i][1]<0)
		{
			printf("\nInvalid Entry!\nPress any key to continue...");
			getch();
			goto AZ;
		}
		BZ:
		system("cls");
		printf("\nEnter time takes by customer (burst time) : ");
		scanf("%d",&tri[i][2]);
		if(tri[i][2]<=0)
		{
			printf("\nInvalid Entry!\nPress any key to continue...");
			getch();
			goto BZ;
		}
		tri[i][5]=0;
		bst=bst+tri[i][2];
		tri[i][6]=i+1;	
	}
	bst=bst+tri[0][1];
	//DEBUG PHASE (Input array check)
	/*
	system("cls");
	for(i=0;i<n;i++)
	{
		printf("|");
		for(j=0;j<6;j++)
		{
			printf(" %d |",tri[i][j]);
		}
		printf("\n");
	}
	printf("Number of faculty is : %d\nNumber of students is : %d",fc,sc);
	getch();*/
	//SORTING
	for (i = 0; i < n; i++)            
	{
		for (j = 0; j < n; j++)             			
		{
			if (tri[j][1] > tri[i][1])                
			{
				tmp = tri[i][1];        
				tri[i][1] = tri[j][1];            
				tri[j][1] = tmp;
				tmp = tri[i][2];        
				tri[i][2] = tri[j][2];            
				tri[j][2] = tmp;
				tmp = tri[i][3];        
				tri[i][3] = tri[j][3];            
				tri[j][3] = tmp;
				tmp = tri[i][4];        
				tri[i][4] = tri[j][4];            
				tri[j][4] = tmp;
				tmp = tri[i][0];        
				tri[i][0] = tri[j][0];            
				tri[j][0] = tmp;      
			}  
		}
	}
	//DEBUG PHASE-2 (sort check)
	/*
	system("cls");
	for(i=0;i<n;i++)
	{
		printf("|");
		for(j=0;j<6;j++)
		{
			printf(" %d |",tri[i][j]);
		}
		printf("\n");
	}
	printf("Number of faculty is : %d\nNumber of students is : %d",fc,sc);
	getch();*/
	//IDK why I did this :)
	int max,sgui=0,fgui=0,x,sg=0,fg=0,zz,xx,mp=0,index,cpu=0,xxx,z=0,m=0,d,b;
	j=0;
	int k=0, fat=tri[0][1], tb=0;//fat=arrival time of first customer
	if(sc>=fc)
	max=sc;
	else
	max=fc;
	int gct=bst;
	bst=bst+10;
	fat=fat+tri[0][2];
	getch();
	//DE-JAINE (geez... this gonna be tough >_< ) #SO_MANY_ERRORS ssksksksksksk
	for(i=0;i<bst;i++)
	{
		system("cls");
		mp=0;		
		if(i==fat)
		{
			if(tri[index][4]==1)
			{
				sg--;
				cpu=0;
			}
			else if(tri[index][4]==2)
			{
				fg--;
				cpu=0;
			}
		}
		if(cpu==0)
		{
			for(xx=0;xx<n;xx++)
			{
				if(tri[xx][3]>mp && tri[xx][1]<=i && tri[xx][5]==0)
				{
					mp=tri[xx][3];
					index=xx;
					/*
					//Selection checker
					if(tri[index][4]==1)
					{
						printf("Student\n");
						printf("%d",tri[index][6]);
					}
					else
					{
						printf("Faculty\n");
						printf("%d",tri[index][6]);
					}
					getch();
					*/
					tb=tri[xx][2];
					cpu=1;
					if(z!=0)
					{
						fat=fat+tb;
					}
					z++;
					tri[xx][5]=1;
					if(tri[index][4]==2)
					{
						for(xxx=0;xxx<n && tri[xxx][1]<=i;xxx++)
						{
							if(tri[xxx][4]==1)
							{
								tri[xxx][3]=tri[xxx][3]+1;
							}
						}
					}
					break;
				}
			}
		}
		//system("cls");
		A:
		if(tri[j][1]==i&&tri[j][4]==1)//If student
		{
			sg++;
			j++;
			goto A;
		}
		else if(tri[j][1]==i&&tri[j][4]==2)//If faculty
		{
			fg++;
			j++;
			goto A;
		}
		printf("\n\n");
		sgui=sg;
		fgui=fg;
		/*
		if(cpu==1)
		printf("CPU Status : Executing process %d\n\n",tri[index][6]);
		else
		printf("CPU Status : Idle\n\n");
		*/
		printf("                     %d",i);
		printf("\n\n                 [  MESS  ]\n");
		for(x=0;x<max;x++)
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
	}
	getch();
	system("cls");
	printf("%d",mp);
	system("cls");
	for(i=0;i<n;i++)
	{
		printf("|");
		for(j=0;j<6;j++)
		{
			printf(" %d |",tri[i][j]);
		}
		printf("\n");
	}
}
