#include <stdio.h>
#include <string.h>


int main()
{
    int N,i,j,x,y;
    char num[1000][5];
	char tmp[5];
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%s",num[i]);
    }
    
    for(i=0;i<N;i++)
        for (j=0;j<N-i-1;j++)
        {
            if((strcmp(num[j],num[j+1]))>0)
            {
                strcpy(tmp,num[j]);
                strcpy(num[j],num[j+1]);
                strcpy(num[j+1],tmp);
            }
            if((strcmp(num[j],num[j+1]))<0&&(strlen(num[j])<strlen(num[j+1])))
            {
                strncpy(tmp,num[j+1],strlen(num[j]));
                
                for(;(strcmp(num[j],tmp))==0;)
                {
                    x=0;
                    y=strlen(num[j]);
                    do
                    {
                        tmp[x]=num[j+1][y];
                        x++,y++;
                    }while(num[j+1][y]!='\0');
                    tmp[x]='\0';
                }
                if(strcmp(num[j],tmp)>0)
                {
                    strcpy(tmp,num[j]);
                    strcpy(num[j],num[j+1]);
                    strcpy(num[j+1],tmp);
                }
            }
        }
    for(i=N;i>0;i--){
        printf("%s",num[i-1]);
    }
    return 0;
}