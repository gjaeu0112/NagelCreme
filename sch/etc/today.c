#include <stdio.h>
#include <time.h>

int dayofweek(int y, int m, int d);

int main() {
	time_t sec;
	struct tm *st_date;

	sec=time(NULL);

	st_date=localtime(&sec);

	int dof=dayofweek(st_date->tm_year+1900, st_date->tm_mon+1, st_date->tm_mday);

	printf("year = %d\n",st_date->tm_year+1900);
	printf("month = %d\n",st_date->tm_mon+1);
	printf("day = %d\n",st_date->tm_mday);
	printf("hour = %d\n",st_date->tm_hour);
	printf("min = %d\n",st_date->tm_min);
	printf("sec = %d\n",st_date->tm_sec);

	printf("%d.%02d.%02d\n",st_date->tm_year+1900, st_date->tm_mon+1, st_date->tm_mday);

	printf("week = (%d)\n", dof); 

	sec-= dof*24*60*60;
	st_date=localtime(&sec);

	printf("SUN = (%d.%02d.%02d)\n",st_date->tm_year+1900, st_date->tm_mon+1, st_date->tm_mday); 

	printf("WHERE SELECT * FROM sch\n");
	printf("WHERE dd='%d.%02d.%02d'\n",st_date->tm_year+1900, st_date->tm_mon+1, st_date->tm_mday); 
	for(int i=1;i<7;i++){
		sec+= 24*60*60;
		st_date=localtime(&sec);
		printf("OR dd='%d.%02d.%02d'\n",st_date->tm_year+1900, st_date->tm_mon+1, st_date->tm_mday); 
	}
}

int dayofweek(int y, int m, int d)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return ((y + y/4 - y/100 + y/400 + t[m-1] + d) % 7);
}
