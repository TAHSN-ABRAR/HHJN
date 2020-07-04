#include<stdio.h>

int menu ();
void addNewNote ();
void showPreviousNote ();
void deleteNote ();

//char title [100] = ""

int main()
{
    int n;
    do
    {
        n  = menu ();
        switch (n)
        {
        case 1:
            addNewNote ();
            break;
        case 2:
            showPreviousNote();
            break;
        case 3:
            deleteNote ();
        }
    }
    while (n != 4);

    return 0;
}


void addNewNote ()
{
    system("cls");
    char item_title [100] ,item_dis [10010],a;
    int i=0;
    FILE *tdb, *disdb;
    tdb = fopen("Title.txt", "a");
    if (!tdb) printf("Error..");
    else
    {
        printf("Enter Your Title : ");
        fflush(stdin);
        gets(item_title);
        printf("Enter Your Description [press F2 and Save] : ");
        fprintf( tdb ,"%s\n", item_title);
        fclose(tdb);

        while(1)
        {
            a = getch();
            item_dis [i] = a;
            if ( a == 60 )
                break;
            else if ( a == 13 )
            {
                printf("\n");
                item_dis [i++] = ' ';
            }
            else if ( a == 8 )
            {
                system("cls");
                printf("Enter Your Title : %s\n",item_title);
                printf("Enter Your Description [press F2 and Save] : ");
                i--;
                if (i == -1 )
                    i = 0;
                item_dis [i] = '\0';
                printf("%s", item_dis);
            }
            else
            {
                printf("%c",a);
                i++;
            }
        }
		disdb = fopen("Description.txt", "a");
        if (!disdb) printf("ERROR ..");
        else
			fprintf( disdb,"\n%s\n",item_dis);
		fclose(disdb);
    }
}

void showPreviousNote ()
{

}

void deleteNote ()
{

}

int menu ()
{
    system("color E0");
    system("cls");
    int choice ;
    printf("######## HOME ########\n\n");
    printf("1. Add New Note \n");
    printf("2. Show Previous Note \n");
    printf("3. Delete Note \n");
    printf("4. Exit\n");
    scanf("%d", &choice);
}
