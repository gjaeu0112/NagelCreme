#include <stdio.h>
#include <string.h>


int main(){
	FILE *fp;
	char str[60];
	char *p;
	char str2[100];

	fp= fopen("/root/hello.txt","r");
	p=fgets(str, 60, fp);
	printf("p= %x\n",p);

	p=fgets(str, 60, fp);
	printf("p= %x\n",p);
	printf("%s\n",str);
	fclose(fp);
	strcpy(str2,str);
	printf("str2= %s\n",str2);

	strcat(str2,str);
	printf("str2=## %s\n",str2);

}
