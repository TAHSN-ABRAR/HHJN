#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<string.h>

void showFriend ();
void gotoxy (int ,int);
void message (char *str[]);
typedef struct FriendLIST
{
    char str [1000];
} F_LIST;

void message (char *str[])
{
    printf("\n----- ");
    printf("%s ",str);
    printf("-----\n\n");
}

void gotoxy (int a, int b)
{
    COORD c;
    c.X = a;
    c.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void showFriend ()
{
    F_LIST p[100];
    int i=0, j, x = 30, y= 50,nof,k,f;
    char a;
    FILE *db;
    db = fopen ("friend_List.txt", "r");
    if (!db) printf("Error..!");
    else
    {
        while ( fgets (p[i].str, 50, db) != 0)
        {
            i++;
        }
        fclose(db);
        nof = i;
        k = 2;
        while (f)
        {
            system("cls");

            gotoxy(1,k);
            printf("\t   >>>");
            gotoxy(8,0);
            printf("---- # # LIST OF FRIEND # # ----\n\n");
            printf("\t\tBACK\n\n");
            for (i=0; i<nof; i++)
                printf("\t\t%s\n",p[i].str);
            a = getch();
            if (a == 80)
            {
                if ((nof+1)*2 == k)
                    k = 2;
                else
                    k += 2;
            }
            else if (a == 72)
            {
                if (k == 2)
                    k = (nof+1)*2 ;
                else
                    k -= 2;
            }
            else if ( a == 13 && k == 2 )
                f = 0;
        }
    }

}

int main()
{

    showFriend ();

    return 0;
}


aazazazazazazaZ
