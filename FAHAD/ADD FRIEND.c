#include<stdio.h>
#include<string.h>
struct friendinfo
{
    char name[100];
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
    printf("1. MESSAGE\n");
    printf("2. SHOW FRIENDS\n");
    printf("3. ADD FRIEND\n");
    printf("4. LOGOUT\n>>>");
    scanf("%d",&choice);
    return choice;
}
void Login()
{

}
void Registration()
{

}
void messages(int n)
{
    printf("Returning value %d\n\n",n);
}
void showfriend(int n)
{

}
void logout(int n)
{

}
void addfrnd()
{
    int i=0,td,choice,flag;
    char nm[100];
    FILE * db;
    struct friendinfo flist[100];
    db=fopen("friend_name.txt","a");
    if(!db)
    {
        printf("File openning error\n Please try again\n\n");
        return;
    }
    fclose(db);
    db=fopen("friend_name.txt","r");
    if(!db)
    {
        printf("File openning error\n Please try again\n\n");
        return;
    }
    while(fscanf(db,"%s",flist[i].name)==1)
    {
        i++;
    }
    td=i;

    while(1)
    {
        printf("Enter Your Friend's User Name : ");
        scanf("%s",nm);
        for(i=0,flag=0; i<td; i++)
        {

            if(strcmp(nm,flist[i].name)==0)
            {
                printmassage("This name is currently in use***\n***Please Try Again");
                printf("#Do You Want To Add Again??\n");
                printf("  1.YES\n");
                printf("  2.NO\n>>>");
                scanf("%d",&choice);
                if(choice==1)
                    flag=1;
                else
                    flag=2;
                break;

            }
        }
        if(flag==2)
            break;
        if(flag==0)
        {

            db=fopen("friend_name.txt","a");
            fprintf(db,"%s\n",nm);
            printmassage("successfully added");
            fclose(db);
            break;
        }
    }

    fclose(db);
}
int firstmenu()
{
    int choice;
    printf("1.LOGIN\n");
    printf("2.REGISTRATION\n>>>");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
        Login();
        break;
    case 2:
        Registration();
        break;
    }
    return ;
}
int main()
{
    int choice;
    choice=firstmenu();
    do
    {
        choice = menu();
        switch(choice)
        {
        case 1:
            messages(choice);
            break;
        case 2:
            showfriend(choice);
            break;
        case 3:
            addfrnd();
            break;
        case 4:
            logout(choice);
            break;

        }
    }
    while(choice!=5);
}
