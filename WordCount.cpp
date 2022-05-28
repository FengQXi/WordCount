#include <stdio.h>
#include <string.h>
 
int main(int argc, char *argv[])
{
    char *f1 = argv[2]; 
    FILE *fp = fopen(f1, "r+");
	char buf[255];
	int cnt=0;
	if(fp == NULL){
        printf("文件 %s 打开时发生错误", f1);
        return 0;
    }
    fgets(buf,255,fp);
    
	int length = strlen(buf);
	if(argv[1][1] == 'w'){
		printf("%d\n", length);
	}
	else if(argv[1][1] == 'c'){
		for (int i=0;i<length;i++){   
        	if(buf[i]!=' '){
            	cnt++;
            	while(buf[i]!=' '&&buf[i]!='\0'){
                	i++;
            	}
        	}
    	}
		printf("%d\n",cnt);
	}
	
	fclose(fp);
	return 0;
}
