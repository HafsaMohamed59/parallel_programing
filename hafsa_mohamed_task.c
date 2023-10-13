#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct User_info
{
    char firstname[50];
    char lastname[50];
    char username[50];
    char password[25];
};

void registration (void)
{
    FILE *reg;

    reg=fopen("reg.txt","w");
    if (reg == NULL)
    {
        fputs("Error at opening File , pleas try again!", stderr);
        exit(1);
    }


    struct User_info u;

    printf("\nEnter your first name:\n");
    scanf("%s",u.firstname);
    printf("\nEnter your last name:\n");
    scanf("%s",u.lastname);
    printf("\nEnter your username:\n");
    scanf("%s",u.username);
    printf("\nEnter your password:\n");
    scanf("%s",u.password);
    fwrite(&u,sizeof(u),1,reg);
    fclose(reg);
    printf("\nYour Registration done Successfully!\n");
     getchar();
    login();
}

void login (void)
{    struct User_info u;
    char username[50],password[25];
    FILE *reg;

    reg = fopen("reg.txt","r");
    if (reg == NULL)
    {
        fputs("Error at opening File pleas try again!", stderr);
        exit(1);
    }

    

    printf("\n your credentials :\n\n");
    printf("Username:  ");
    fgets(username, 50, stdin);
    printf("\nPassword: ");
    printf("\n");
    fgets(password, 25, stdin);

    while(fread(&u,sizeof(u),1,reg))
        {
        if(strcmp(username,u.username)==1 && strcmp(password,u.password)==1)

            { 
                printf("\nYour Login done Successfully.\n");
            }
        else
            {
                printf("\n Wrong password or username , pleas try again.\n");
            }
        }

    fclose(reg);

    return;
}
void registration (void);
void login (void);
int main (void)
{
    int number;

    printf("welcome here , if you need to register pleas press '1'\nIf you need to Login pleas press '2'\n");
    scanf("%d",&number);

    getchar();           

    if(number == 1)
        {
            
            registration();
        }

    else if(number == 2)
        {
            
            login();
        }
}




