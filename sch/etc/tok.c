#include <stdio.h>
#include <string.h>

int main(){
	char s[100];
	char *p;

	strcpy(s,"id=135235");
	p=strtok(s,"=");
	printf("key=%s\n",p);

	p=strtok(NULL,"=");
	printf("value=%s\n",p);
}
