//M.RAAHIM //24k-0543 //q9
#include<stdio.h>
#include<conio.h>
char grid[5][5];
char displaygrid(char grid[][5])
{
printf("\n");
for (int i=0; i<5; i++)
{
	printf("\n");
	for (int j=0; j<5; j++)
	{
		printf("%c ", grid[i][j]);
	}
}
}
int main()
{
	char grid[5][5]={
{' ', ' ', 'I', 'X', ' '},
{' ', 'X', ' ', ' ', ' '},
{'I', ' ', 'X', 'X', ' '},
{' ', ' ', ' ', 'I', 'X'},
{' ', 'X', ' ', ' ', 'P'}
};
	char key, m=4, n=4;
	printf("Keys:\nW: Up\tS: Down\nA: Left\tD: Right\nQ: Quit");
	displaygrid(grid);
	while(key!='q' && key!='Q')
	{
		key=getch();
		switch(key)
		{
			case 'w':
			case 'W':
				if(m!=0)
				{
				if(grid[m-1][n]!='X')
				{
				grid[m-1][n]='P';
				grid[m][n]=' ';
				m=m-1;
				}}
				displaygrid(grid);
				break;
			case 's':
			case 'S':
				if(m!=4)
				{
				if(grid[m+1][n]!='X')
				{
				grid[m+1][n]='P';
				grid[m][n]=' ';
				m=m+1;
				}}
				displaygrid(grid);
				break;
			case 'a':
			case 'A':
				if(n!=0)
					{
					if(grid[m][n-1]!='X')
				{
				grid[m][n-1]='P';
				grid[m][n]=' ';
				n=n-1;
				}}
				displaygrid(grid);
				break;
			case 'd':
			case 'D':
				if (n!=4)
				{
				if(grid[m][n+1]!='X')
				{
				grid[m][n+1]='P';
				grid[m][n]=' ';
				n=n+1;
				}}
				displaygrid(grid);
				break;
		}
	}
	return 0;
}
