#include "STD_Types.h"
#include<stdlib.h>
u8 win(u8 arr[3][3]);
void main(void)
{  u8 XO [3][3] = {{'*','*','*'},
				   {'*','*','*'},
				   {'*','*','*'}};
				   
	u8 flag_BreakWin=0;	
    u8 xo[2]={'x','o'};
	u8 Row[3];	u8 Col[3];
	printf("The first player will play x and the second o \n");
	fflush(stdout);u8 j=-1;
	for(u8 i=0;i<9;i++)
	{
						

		for(u8 i=0;i<3;i++)
		{
			for(u8 c=0;c<3;c++)
			{
			//	system("cls");
				printf("%c   ",XO[i][c]);
			}
		    printf("\n");
		}	
	    j++;//0  1  
		if(j==2)j=0;  	
		aa:	
		printf("PLAY %c in which Row? then in which Column ? \n",xo[j]);
		fflush(stdout);
		scanf("%d %d",&Row[i],&Col[i]);			
		
		if(Row[i]>2 || Col[i] >2 || Row[i]<0 || Col[i]<0)
		{
			printf("You have entered a nonvalid input  please try again ^^\n");            
			goto aa;
		} 
		if(i>0)
		{
			if(Row[i]==Row[i-1] && Col[i]==Col[i-1])
			{
				printf("There is %c in this location already!  please try again \n",XO[Row[i-1]][Col[i-1]]);
				goto aa;
			}

		}		
		XO[Row[i]][Col[i]]=xo[j];
		if(i>3)
		{
			if(!win(XO))
			{
			flag_BreakWin=1; break;				
			}
		}

	}
	
	for(u8 i=0;i<3;i++)
	{
		for(u8 c=0;c<3;c++)
		{
			printf("%c   ",XO[i][c]);
		}
		printf("\n");
	}	
	if(flag_BreakWin==0)
	printf("No one has won!\n");
    else
	{
		printf("Congratulations ! \n");
	} 
}
u8 win(u8 arr[3][3])
{   
	u8 winarr[20] ={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	u8 winarr2[20]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	for(u8 i=0;i<3;i++)
	{   
		for(u8 j=0;j<3;j++)
		{
		        //for rows:
				if(j!=2&&(arr[i][0] ==arr[i][j+1])) 
				{
					winarr[i]++;winarr2[i]=arr[i][0];
				}
				//for columns:
				if(j!=2&&(arr[0][i] ==arr[j+1][i])) 
				{
					winarr2[i+4]=arr[0][i];
					//
					winarr[i+4]++;	
				//	printf("winarr[%d]=%d   i= %d  j =%d  at %c\n",i+4,winarr[i+4],i,j,winarr2[i]);
				}	
                //for main diameter:
                if(i!=2 && i==j&&arr[i][j]==arr[i+1][j+1]){winarr2[8]=arr[i][j];winarr[8]++;}
                //for sub diameter:
				if(i!=2 &&(i+j==2)&& arr[i][j]==arr[i+1][j-1]){winarr2[9]=arr[i][j];  winarr[9]++;
					}//arr[0,1]=arr[1,1]   arr[1,1]=arr[2,0]
					if((arr[0][0]==arr[1][1])&&(arr[2][2]==arr[1][1]))
					{
						winarr[10]=2;winarr2[10]=arr[0][0];break;
					}
	    }
	}
	for(u8 c=0;c<20;c++)
	{
		if(winarr[c]==2 && (winarr2[c]=='x' || winarr2[c]=='o'))
		{
			printf("%c Win !!\n",winarr2[c]);
			return 0;
		}
	}
	return 1;
	/*diameters:
	  arr[0,0]==arr[1,1]  arr[0,2]==arr[1,1]  
	  arr[1,1]==arr[2,2]  arr[1,1]==arr[2,0]
	  columns:
	  arr[0,0]=arr[1,0]  arr[0,1]=arr[1,1]  arr[0,2]=arr[1,2]
      arr[0,0]=arr[2,0]  arr[0,1]=arr[2,1]  arr[0,2]=arr[2,2]
    */
	
}
/*
  0 1 2       0,0   0,1   0,2
  3 4 5   ==  1,0   1,1   1,2
  6 7 8       2,0   2,1   2,2
*/