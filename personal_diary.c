#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int insert();
int view();

int main()
{
    FILE *fp;
    char press;
    int num;
First:
    printf("\n\n---- Press ----- operation ------\n\n");
    printf("     'a' ------ add new note     \n");
    printf("     'v' ------ View Previous     \n");
    printf("     'e' ------ Exit Program     \n\n");
    printf("-------------------------------\n\n");

while(1)
{
    scanf("%c",&press);

    if (press == 'a'){
        insert();
        printf("Press '1' for continue\n'0' for Exit\n");
        scanf("%d",&num);
        if (num == 1){
            goto First;
        }
        else{
            break;
        }
    }
    else if (press == 'v'){
        view();
        printf("Press '1' for continue\n'0' for Exit\n");
        scanf("%d",&num);
        if (num == 1){
            goto First;
        }
        else{
            break;
        }
    }
    else if (press == 'e'){
        return 0;
    }
    else{
        printf("Please press correct key.\n");
    }
}
    return 0;
}

int insert(){
    FILE *fp;
    char note[2000], date[20] ;
    printf("---***---***----***----***----***---\n\n");
    printf("|<--     Welcome to our Diary    -->|\n\n");
    printf("---***---***----***----***---***---\n\n");
    printf("Enter date of your note : ");
    scanf("%s",date);
    //printf("%s",date);
    printf("\n");
    printf("Just write your note from here....\n---->>");
    scanf(" %[^\n]s",note);
    fp = fopen("diary.txt", "w");
    fprintf(fp, note);
    printf("\nSuccessfully Copied.....:)\n");
    fclose(fp);
    return 0;
}

int view(){
    FILE *fp;
    char ch;
    fp = fopen("diary.txt", "r");
    if (fp == NULL){
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    printf("\nYour previous note : \n\n");
    printf("===============================================================================\n");

    while( ( ch = fgetc(fp) ) != EOF ){
        printf("%c",ch);
    }
    printf("\n");
    printf("===============================================================================\n");
    fclose(fp);
    return 0;
}
