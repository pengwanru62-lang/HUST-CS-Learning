#include <stdio.h>
#include <stdlib.h>

int rollDie(){
	 return rand()%6+1;
}

void diceGame(int randSeed){
	srand(randSeed);
	
	int round = 1;
	int die1=rollDie();
	int die2=rollDie();
	int score=die1+die2;
	
	if(score==7||score==11){
		printf("\'Round 1:  Score:%d  Success!\'\n", score);
		return;
	} else if(score==2||score==3||score==12){
		printf("\'Round 1:  Score:%d  Failed!\'\n",score);
		return;
	}else {
		printf("\'Round 1:  Score:%d  Continue!\'\n", score);
	}
	
	int now=score;
	printf("\'Next rounds: Score %d:Success, Score 7:Failed, others:Continue\'\n",now);
	
	while(1){
		die1=rollDie();
		die2=rollDie();
		score=die1+die2;
		round++;
		
		if(score==now){
			printf("\'Round %d:  Score:%d  Success!\'\n",round, score);
			break;//实际上return也可以 
		}	else if(score == 7){
			printf("\'Round %d:  Score:%d  Failed!\'\n", round, score);
			break;
			} else{
				printf("\'Round %d:  Score:%d  Continue!\'\n", round, score);
			}
		}
	}
	int main(){
		int seed;
		scanf("%d",&seed);
		diceGame(seed);
		return 0;
	}
	
