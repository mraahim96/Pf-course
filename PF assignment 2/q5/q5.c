//M.Raahim //24k-0543  //q5
#include<stdio.h>
int count, values[100];
int i,j;
int tvalues()
{
	printf("Enter the count of integers in the array (<100): ");
	scanf("%d", &count);
	printf("Enter values:\n");
	for(int i=0; i<count; i++)
	{
		scanf("%d", &values[i]);
		while(values[i]<0)
		{
			printf("Enter either a positive value or 0: ");
			scanf("%d", &values[i]);
		}
	}
}
int hist_h()
{
	printf("\nHorizontal Histogram:\n");
	for(i=0; i<count; i++)
	{
		printf("\nValue %d: ", i+1);
		for(j=0; j<values[i]; j++)
		{
			printf("*");
		}
	}
}
int hist_v()
{
	 int max_value=values[0];
    for( i = 1; i < count; i++) 
	{
        if(values[i]>max_value) 
		{
            max_value=values[i];
        }
    }
    printf("\n\nVertical Histogram:\n");
    for( i=max_value;i>0;i--) 
	{
        for ( j=0; j<count; j++)
		{
            if (values[j]>=i)
			{
                printf("* ");
            }
			else
			{
                printf("  ");
            }
        }
        printf("\n");
    }
    for( i=0; i<count; i++)
	{
        printf("%d ", values[i]);
    }
    printf("\n");
}
int main()
{
	int count, values[count];
	tvalues();
	hist_h();
	hist_v();
}