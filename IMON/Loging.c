///Login

#include<stdio.h>
#include<string.h>
#include<conio.h>

struct regi
{
    char pass[50],name[20];
};

//void login(){};
void login()
{
   system("color 0D");
    struct regi Old[1000],New;
    char filepath[100]="registration.txt" ;
    FILE *regiDB;
    regiDB=fopen(filepath,"r");
    int i=1;
    while(fscanf(regiDB,"%s",&Old[i].name)==1)
    {
        fscanf(regiDB,"%s",&Old[i].pass);
        i++;
    }
    int noclient=i;
    fclose(regiDB);
    printf("Enter your User Name : ");
    scanf("%s",New.name);
    printf("Enter a Password : ");
    start2:
    i=0;
    char ch ;
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            New.pass[i]='\0';
            break;
        }
        else if(ch=='\b')
        {
            i--;
            printf("\b \b");

        }
        else if(ch=='\t'||ch==' ')
        {
            continue ;
        }
        else
        {
            New.pass[i]=ch;
            i++;
            printf("*");
        }
    }
    int j;
    for(i=1;i<noclient;i++)
    {
        if(strcmp(Old[i].name,New.name)==0)
            {
                 if(strcmp(Old[i].pass,New.pass)!=0)
                 {
                      printf("\n\a!Wrong password .Try again : ");

                      goto start2 ;
                 }
                 else if(strcmp(Old[i].pass,New.pass)==0)
                 {
                     system("cls");
                     printf("Hi,%s",Old[i].name);
                 }
            }
    }

}
int main(){login();}
