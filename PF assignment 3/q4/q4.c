#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

struct Employee{
	int **ratings;
	int totalScore;
};
void inputEmployees(int **ratings, int numEmployees, int numPeriods);
void displayEmployees(int **ratings, int numEmployees, int numPeriods);
int EmployeeOfYear(int **ratings, int numEmployees, int numPeriods);
int findHighestRatedPeriod(int **ratings, int numEmployees, int numPeriods);
int worstPerformingEmployee(int **ratings, int numEmployees, int numPeriods);



int main(){
	struct Employee e;
	int numEmployees , numPeriods,i;
	printf("\n Enter number of Employees : ");
	scanf("%d",&numEmployees);
	printf("\n Enter number of Periods : ");
	scanf("%d",&numPeriods);
	e.ratings=(int**)malloc(numEmployees*sizeof(int*));
	for(i=0;i<numEmployees;i++)	e.ratings[i]=(int*)malloc(numPeriods*sizeof(int));
	inputEmployees(e.ratings, numEmployees, numPeriods);
	displayEmployees(e.ratings, numEmployees, numPeriods);
	int eoy=EmployeeOfYear(e.ratings, numEmployees, numPeriods);
	printf("\n Employee %d has highest average rating and is the Employee of the year.",eoy+1);
	int we=worstPerformingEmployee(e.ratings, numEmployees, numPeriods);
	printf("\n Employee  %d has worst average rating.",we+1);
	int hrp=findHighestRatedPeriod(e.ratings, numEmployees, numPeriods);
	printf("\n Period %d has highest average rating.",hrp+1);
	return 0;
}

void inputEmployees(int **ratings, int numEmployees, int numPeriods){
	int i,j;
	for(i=0;i<numEmployees;i++){
		printf("\n Ratings for Employee %d",i+1);
		for( j=0;j<numPeriods;j++){
			printf("\n Enter Rating %d : ",j+1);
			scanf("%d",&ratings[i][j]);
			if(ratings[i][j]>10 || ratings[i][j]<1){
				printf("\n Invalid rating, Enter again!");
				j--;
				continue;
			}
		}
	}
}

void displayEmployees(int **ratings, int numEmployees, int numPeriods){
	int i,j;
	for(i=0;i<numEmployees;i++){
		printf("\n Ratings for Employee %d : ",i+1);
		for(j=0;j<numPeriods;j++){
			printf("%3d",ratings[i][j]);
		}
	}
}
int EmployeeOfYear(int **ratings, int numEmployees, int numPeriods){
	int g=0,gi,i,j;;
	for(i=0;i<numEmployees;i++){
		int sum=0;
		for(j=0;j<numPeriods;j++){
			sum+=ratings[i][j];
		}
		if(sum>g){
			g=sum;
			gi=i;
		}
	}
	return gi;
}

int findHighestRatedPeriod(int **ratings, int numEmployees, int numPeriods){
	int g=0, gi,i,j;;
	for(i=0;i<numPeriods;i++){
		int sum=0;
		for(j=0;j<numEmployees;j++){
			sum+=ratings[j][i];
		}
		if(sum>g){
			g=sum;
			gi=i;
		}
	}
	return gi;
}

int worstPerformingEmployee(int **ratings, int numEmployees, int numPeriods){
	int l=INT_MAX, li;
	int i,j;
	for( i=0;i<numEmployees;i++){
		int sum=0;
		for(j=0;j<numPeriods;j++){
			sum+=ratings[i][j];
		}
		if(sum<l){
			l=sum;
			li=i;
		}
	}
	return li;
}
