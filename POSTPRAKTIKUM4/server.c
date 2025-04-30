#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_LINE 256
#define MAX_BODY 512

void solution(){
    FILE*input=fopen("request.txt","r"),*output=fopen("response.txt","w");
    char line[MAX_LINE],method[16]="",path[128]="",contentType[64]="N/A",body[MAX_BODY]="";
    int inBody=0;

    while(fgets(line,sizeof(line),input)){
        line[strcspn(line,"\r\n")]=0;

        int kosong=1;
        for(int i=0;line[i];i++){
            if(!isspace(line[i])){
                kosong=0;
                break;
            }
        }

        if(inBody==0){
            if(kosong==1){
                inBody=1;
                continue;
            }

            if(strncmp(line,"GET ",4)==0||strncmp(line,"POST ",5)==0||strncmp(line,"PUT ",4)==0){
                sscanf(line,"%s %s",method,path);
            }
            else{
                if(strncmp(line,"Content-Type:",13)==0){
                    char*pos=strchr(line,':');
                    if(pos!=NULL){
                        while(*pos==' '||*pos==':'){pos++;}
                        strcpy(contentType,pos);
                    }
                }
            }
        }
        else{
            strcat(body,line);
        }
    }

    fprintf(output,"HTTP/1.1 200 OK\n");
    fprintf(output,"Content-Type: text/plain\n\n");
    fprintf(output,"Method: %s\n",method);
    fprintf(output,"Path: %s\n",path);
    fprintf(output,"Content-Type: %s\n",contentType);
    if(strlen(body)>0){
        fprintf(output,"Body: %s\n",body);
    }

    fclose(input);
    fclose(output);
}
