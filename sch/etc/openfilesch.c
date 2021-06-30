#include <stdio.h>
#include <string.h>

int main(){
	FILE *sch=fopen("/root/sch.txt","r");
	char todo[7][10][100]={0,};
	char p[100];
	int i=-1,j=1,k=0;

	while(fgets(p,100,sch)!=NULL){
		if(p[0]=='#'){
			strcpy(todo[++i][0],p);
			j=1;
		}
		else
			strcpy(todo[i][j++],p);
	}
	for(i=0;i<7;i++){
		for(j=0;j<10;j++){
			if(todo[i][j][0]==0)
				break;
			printf("%s",todo[i][j]);
		}
		printf("===============================================\n");
	}
	fclose(sch);
}
