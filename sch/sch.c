#include <stdio.h>
#include <sqlite3.h>
#include <time.h>

void pr();
void nt();
int dayofweek(int y, int m, int d);


int main(void)
{
    sqlite3* db;
    sqlite3_stmt* res;

	time_t sec;
	struct tm *st_date;
	char dayd[7][30];

    sec=time(NULL);
    st_date=localtime(&sec);
    
    int rc = sqlite3_open("/home/q9/sch/sqlite/sch.db", &db);
    int dof=dayofweek(st_date->tm_year+1900, st_date->tm_mon+1, st_date->tm_mday);

	sec -= dof*24*60*60;
	st_date= localtime(&sec);
	for(int i=0;i<7;i++){
	    sprintf(dayd[i],"%d.%02d.%02d",st_date->tm_year+1900, st_date->tm_mon+1, st_date->tm_mday);

	    sec+= 24*60*60;
	    st_date=localtime(&sec);
	}

    
	pr();
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }

    char sql[1024];
	sprintf(sql,"SELECT * FROM sch\nWHERE dd=\'%s\'\n OR dd=\'%s\'\nOR dd=\'%s\'\nOR dd=\'%s\'\nOR dd=\'%s\'\n OR dd=\'%s\'\nOR dd=\'%s\'\n",dayd[0],dayd[1], dayd[2],dayd[3],dayd[4],dayd[5],dayd[6]); 
    rc = sqlite3_prepare_v2(db, sql, -1, &res, 0);    
    
    if (rc != SQLITE_OK) 
    {
        fprintf(stderr, "Failed to fetch data: %s\n", sqlite3_errmsg(db));
        sqlite3_close(db);
        
        return 1;
    }
    
	while(1){
			rc = sqlite3_step(res);
			if (rc == SQLITE_ROW)
			{
				printf("<tr>\n<th>\n%s\n</th>\n", sqlite3_column_text(res, 0));
				printf("<th>\n%s\n</th>\n</tr>\n", sqlite3_column_text(res, 1));
			}
			else break;
	}
    
    sqlite3_finalize(res);
    sqlite3_close(db);
    
	nt();
    return 0;
}

void pr(){

    printf("    <style>\n");
    printf("       table.type08 {\n");
    printf("       border-collapse: collapse;\n");
    printf("       text-align: left;\n");
    printf("       line-height: 0.5;\n");
    printf("       border-left: 1px solid #ccc;\n");
    printf("       margin: 20px 10px;\n");
    printf("       }\n");
    printf("   table.type08 thead th {\n");
    printf("       padding: 8px;\n");
    printf("       font-weight: bold;\n");
    printf("       border-top: 1px solid #ccc;\n");
    printf("       border-right: 1px solid #ccc;\n");
    printf("       border-bottom: 2px solid #c00;\n");
    printf("       background: #dcdcd1;\n");
    printf("   }\n");
    printf("   table.type08 tbody th {\n");
    printf("       padding: 8px;\n");
    printf("       font-weight: bold;\n");
    printf("       vertical-align: top;\n");
    printf("       border-right: 1px solid #ccc;\n");
    printf("       border-bottom: 1px solid #ccc;\n");
    printf("       background: #ececec;\n");
    printf("   }\n");
    printf("   table.type08 td {\n");
    printf("       padding: 8px;\n");
    printf("       vertical-align: top;\n");
    printf("       border-right: 1px solid #ccc;\n");
    printf("       border-bottom: 1px solid #ccc;\n");
    printf("   }\n");
    printf("    </style>\n");
    printf("<html>\n");
    printf("    <body>\n");
    printf("    <table class=\"type08\">\n");
}

void nt(){
	printf("</table>\n");
	printf("</body>\n");
	printf("</html>\n");	
}
int dayofweek(int y, int m, int d)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return ((y + y/4 - y/100 + y/400 + t[m-1] + d) % 7);
}

