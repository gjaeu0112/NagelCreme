#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	srand(time(NULL));
	int random=0;
	char todo[4]={'a','b','c','d'};

	
	for(int i=0;i<10;i++){
		random= rand()%4;
		printf("todo = (%c)\n",todo[random]);
	}
}
