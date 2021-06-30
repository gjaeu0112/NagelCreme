#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(){
	char dayd[7][30];
	time_t sec;
    struct tm *st_date;

    sec=time(NULL);
    st_date=localtime(&sec);

	for(int i=0;i<7;i++){
	    sprintf(dayd[i],"%d.%02d.%02d",st_date->tm_year+1900, st_date->tm_mon+1, st_date->tm_mday);

		sec+= 24*60*60;
		st_date=localtime(&sec);
	}
	printf("%s\n%s\n%s\n%s\n%s\n%s\n%s",dayd[0],dayd[1],dayd[2],dayd[3],dayd[4],dayd[5],dayd[6]);

}
