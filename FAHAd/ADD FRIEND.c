#include<stdio.h>
#include<string.h>
struct friendinfo
{
    char name[100],pass[100];
};
void printmassage(char *str)
{
    printf("\n\n***");
    printf("%s", str);
    printf("***\n\n");
}

int menu()
{
    int choice;
    printf("1. ADD FRINDS.\n");
    scanf("%d",&choice);
    printf("\n\n");
    return choice;
}
void addfrnd()
{
    int i=0,td,choice,flag;
    char nm[100],pass[100];
    FILE * db;
    struct friendinfo flist[100];
    db=fopen("friendfile.txt","a");
    if(!db)
    {
        printf("File openning error\n Please try again\n\n");
        return;
    }
    fclose(db);
    db=fopen("friendfile.txt","r");
    if(!db)
    {
        printf("File openning error\n Please try again\n\n");
        return;
    }
    while(fscanf(db,"%s",flist[i].name)==1)
    {
        fscanf(db,"%s",flist[i].pass);
        i++;
    }
    td=i;

    while(1)
    {
        printf("Enter Your Friend Name : ");
        scanf("%s",nm);
        printf("Enter password : ");
        scanf("%s",pass);
        for(i=0,flag=0; i<td; i++)
        {

            if(strcmp(nm,flist[i].name)==0)
            {
                printmassage("This Friend is Already added");
                printf("#Do You Want To Add Again??\n");
                printf("  1.YES\n");
                printf("  2.NO\n");
                scanf("%d",&choice);
                if(choice==1)
                    flag=1;
                else
                    flag=2;
                break;

            }
        }
        if(flag==2)break;
        if(flag==0)
        {

            db=fopen("friendfile.txt","a");
            fprintf(db,"%s\n",nm);
            fprintf(db,"%s\n",pass);
            printmassage("successfully added");
            fclose(db);
            break;
        }
    }

    fclose(db);
}

int main()
{
    int choice;
    do
    {
        choice = menu();
        switch(choice)
        {
        case 1:
            addfrnd();
            break;
        }

    }
    while(choice!=2);
}
