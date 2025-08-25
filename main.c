// 기능 : cd, ls, mkdir, touch, rm

#include <stdio.h>
#include <string.h>


char file[100][100][100]={{"root","mac"},{"mac"}};

char movement[100][100]={"root"};
int move_n=0;

char place[100]="root";

int place_n=0;


int file_c=2;

void cd(char run[]);
void ls(void);
void mkdir(char run[]);
void rm(char run[]);

int main(void){
    while (1){

        int i=0;
        char input[100]="",input_memory[100], code[10][100]={};


        printf("mac@macui-MacBookAir-777 /%s %%",place);
        fgets(input,100,stdin);
        input[strlen(input)-1]='\0';
        strcpy(input_memory,input);

        char *empty=strtok(input," ");

        while (empty!=NULL) {
            strcpy(code[i],empty);
            empty=strtok(NULL," ");
            i++;
        }

        if (strcmp(code[0],"cd")==0 && i <= 2){    
            cd(code[1]);
        }
        
        else if (strcmp(code[0],"ls")==0 && i<=1){
            ls();
        }

        else if ((strcmp(code[0],"touch")==0 || strcmp(code[0],"mkdir")==0) && i<=2){
            mkdir(code[1]);
        }

        else if (strcmp(code[0],"rm")==0 && i <= 2){
            rm(code[1]);
        }

        else if (strcmp(code[0],"exit")==0){
            break;
        }
        else if (strcmp(code[0],"")==0){
            
        }
        else {
            printf("please command reconfirm: %s\n",input_memory);
        }
    }

}

void cd(char run[]){
    if (strcmp(run,"/")==0){
        strcpy(place,"root");
        place_n=0;
        return;
    }
    if (strcmp(run,"..")==0){
        *movement[move_n]='\0';
        move_n--;
        strcpy(place,movement[move_n]);

        for (int i=0; i< 100; i++){
            if (strcmp(place,file[i][0])==0){
                place_n=i;
            }
        }
        return;
    }

    for (int i=1; i<100;i++){
        if (strlen(file[place_n][i])==0){
            break;

        }
        if (strcmp(run,file[place_n][i])==0){
            place_n=i;
            move_n++;
            strcpy(movement[move_n],run);
            strcpy(place,run);
            for (int j=0; j < 100; j++){
                if (strcmp(file[j][0],place)==0){
                    place_n=j;
                }
            }
            return;
        }
    }
    printf("file not founded: %s\n",run);
}

void ls(void){
    for (int i=1; i<100; i++){        
        if (strlen(file[place_n][i])==0){
            return;
        }
        printf("%s\n",file[place_n][i]);
        
        
    }
}

void mkdir(char run[]){
    for (int i=0; i<100; i++){
        if (strcmp(file[place_n][i],run)==0){
            printf("'%s' is [already exists] or [cannot be a file name]\n",run);
            return;
        }
        if (strcmp(file[place_n][i],"")==0){
            strcpy(file[place_n][i],run);
            strcpy(file[file_c][0],run);
            file_c++;
            return;
        }
    }
}

void rm(char run[]){
    for (int i=0; i<100; i++){

        if (strcmp(file[place_n][i],run)==0){
           
            for (int k=i; k<100;k++){
                strcpy(file[place_n][k],file[place_n][k+1]);
            }
            break;
        }
        if (strlen(file[place_n][i])==0){
            printf("file not founded : %s\n",run);
            break;
        }
    }
    
    for (int i=0; i<100; i++){
        if (strcmp(file[i][0],"")==0){
            break;
        }
        if (strcmp(file[i][0],run)==0){
            file_c--;
            for (int j=i; j<100; j++){
                strcpy(file[i][j],file[i+1][j]);
            }
        }
    }
}