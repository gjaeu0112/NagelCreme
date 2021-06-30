#include <stdio.h>
#include <string.h>

int main(){
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
	printf("	<table class=\"type08\">\n");
	
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
		printf("<tr><th>%s</th>",todo[i][0]);
		printf("<th>\n");
		for(j=1;j<10;j++){
			if(todo[i][j][0]==0){
				printf("</th>\n");
				break;
			}
			printf("%s\n",todo[i][j]);
			printf("<br><br><br>\n");
		}
		printf("</tr>\n");
	}
	printf("</table>\n");
	printf("</body>\n");
	printf("</html>\n");
    fclose(sch);
}
