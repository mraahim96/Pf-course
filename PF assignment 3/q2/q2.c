#include <stdio.h>

struct Player{
	char name[20];
	int ballScore[12];
	int score;
};
void playGame(struct Player *p);
int validateScore(int a);
void Winner(struct Player p1, struct Player p2);
void displayMatchScoreboard(struct Player p1, struct Player p2);


int main(){
	struct Player p1,p2;
	printf("\n Enter details for Player 1 :-");
	playGame(&p1);
	printf("\n Enter details for Player 2 :-");
	playGame(&p2);
	Winner(p1,p2);
	displayMatchScoreboard(p1,p2);
	return 0;
}
void playGame(struct Player *p){
	printf("\n Enter Name : ");
	gets(p->name);
	fflush(stdin);
	p->score=0;
	int i;
	for( i=0;i<12;i++){
		printf("\n Enter score for ball %d : ",i+1);
		scanf("%d",&p->ballScore[i]);
		fflush(stdin);
		p->ballScore[i]=validateScore(p->ballScore[i]);
		p->score+=p->ballScore[i];
	}
}
int validateScore(int a){
	if(a>=0 && a<=6)	return a;
	else{
		printf("\n Invalid score");
		return 0;
	} 
}
void Winner(struct Player p1, struct Player p2){
	if(p1.score>p2.score)	printf("\n %s is winner",p1.name);
	else if(p1.score<p2.score)	printf("\n %s is winner",p2.name);
	else printf("\n It is a tie!");
}
void displayMatchScoreboard(struct Player p1, struct Player p2){
	float avg1=p1.score/12.0, avg2=p2.score/12.0;
	printf("\n\t  %20s %20s",p1.name,p2.name);
	int i;
	for(i=0;i<12;i++){
		printf("\n Ball %2d%20d %20d",i+1,p1.ballScore[i],p2.ballScore[i]);
	}
	printf("\n TotalScore%18d %20d",p1.score,p2.score);
	printf("\n Average %20.2f %20.2f",avg1,avg2);
}
