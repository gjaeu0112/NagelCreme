#include <stdio.h>
#include <string.h>

int main(){
	FILE *fp=fopen("/root/hello.c","r");
	char str[60];
	
	while(fgets(str,60,fp)!=NULL){
		str[strlen(str)-1]='\0';
		puts(str);
	}
	fclose(fp);
}
