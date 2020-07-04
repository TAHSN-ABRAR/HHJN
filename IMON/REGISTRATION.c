#include<stdio.h>
#include<string.h>
#include<conio.h>

struct regi
{
    char  phone[12],name[20],pass[50];
};

void registration()
{
    system("color 0D");
    struct regi Old[1000],New;
    char filepath[100]="registration.txt" ;
    FILE *regiDB;
    regiDB=fopen(filepath,"r");
    int i=1;
    while(fscanf(regiDB,"%s",&Old[i].phone)==1)
    {
        fscanf(regiDB,"%s%s",&Old[i].name,&Old[i].pass);
        i++;
    }
    int noclient=i;
    fclose(regiDB);
    regiDB=fopen(filepath,"a");
    printf("Enter your phone Number : ");
start1:
    scanf("%s",New.phone);
    for(i=1; i<noclient; i++)
    {
        if(strcmp(Old[i].phone,New.phone)==0)
        {
            printf("\aThe Number have already an account.\nEnter a New Number again : ");
            goto start1 ;
        }
    }
    printf("Enter your Name : ");
    scanf("%s",New.name);
    printf("Enter a Password : ");
start2:
    i=0;
    char ch,confirmPasss[50];
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


    printf("\nConfirm Your Password : ");
start3 :
    i=0;
    while(1)
    {
        ch=getch();
        if(ch==13)
        {
            confirmPasss[i]='\0';
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
            confirmPasss[i]=ch;
            i++;
            printf("*");
        }
    }
    if(strcmp(New.pass,confirmPasss)!=0)
    {
        printf("\nPassword Not match.\n");
start4:
        printf("Do you forget your password :\n1.Yes\n2.No\n");
        printf("Enter Your choice (1 or 2) : ");
        int c;
        scanf("%d",&c);
        if(c==1)
        {
            printf("Enter a New Password : ");
            goto start2 ;
        }
        else if(c==2)
        {
            printf("Confirm Your Password again : ");
            goto start3;
        }
        else
            goto start4;

    }
    else
    {
        fprintf(regiDB,"%s\n%s\n%s\n",New.phone,New.name,New.pass);
    }
    printf("\n***************************Registration Completed***************************\n");
    fclose(regiDB);
}
int main()
{
    registration();
}

