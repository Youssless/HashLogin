#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//#include<conio.h>


struct AccountInformation
	{
	   char account[20];
	   char password[20];
	   int Exist=0;
	}temp;

FILE *fp;
//void clrscr(void);
void save();
void MainMenu();
void Registered();
void Login();
void LoginSuccessfully();

struct AccountInformation acc[20], * p=acc;

void save()

{
     if((fp=fopen("F://AccountInformation.dat","wb"))==NULL)
	 {
	  printf("Cannot open this file\n");
	  return;
	 }
	 //printf("请选择要保存的学生信息的编号:\t");
	 //scanf("%a",&a);
	 for(int i=0;i<20;i++)
	 if(fwrite(&acc[i],sizeof(struct AccountInformation),1,fp)!=1)
		 printf("File write error\n");
	 fclose(fp);
}

void MainMenu()
{
    int choice;
    printf("\t\t--------------------------------------    Login    --------------------------------------\n");
    printf("\t\t--------------------------------------  Registered --------------------------------------\n");
    printf("\t\t                      input(1)Login, input(2)Registered, input(0)Exit\n");
    printf("Choice: ");
    scanf("%d",&choice);
    if(choice!=1&&choice!=2&&choice!=0)
    {
            printf("Error,Please do one more time for Choice: ");
            scanf("%d",&choice);
    }
switch(choice)
{
    case 1: Login();system("cls");break;
    case 2: Registered();system("cls");break;
    case 0: system("cls");break;
}

}

void Registered()
{
    int choice;
    char Acc[20];
    char passW[20];
    char passW2[20];
    printf("--------------------------------------    Create Your Account    --------------------------------------\n");
    printf("--------------------------------------            Input create          --------------------------------------\n");
    printf("Input your account:\n");
    scanf("%s",&Acc);
    printf("Input your password:\n");
    scanf("%s",&passW);
    printf("Input your password second time (must equal with the first one):\n");
    scanf("%s",&passW2);
    if(strcmp(passW,passW2)!=0)
    {
            printf("Error, your password are not the same! Please try again");
            printf("Input your password:\n");
            scanf("%s",&passW);
            printf("Input your password second time (must equal with the first one):\n");
            scanf("%s",&passW2);
    }
    for(int i=0;i<20;i++)
    {
        if(acc[i].Exist==0)
        {
            acc[i].Exist=1;
            strcpy(acc[i].account,Acc);
            strcpy(acc[i].password,passW);
            break;
        }
    }
    save();

    printf("input(1)MainMenu, input(0)\n");
    printf("Choice: ");
    scanf("%d",&choice);
    if(choice!=1&&choice!=0)
    {
            printf("Error,Please do one more time for Choice: ");
            scanf("%d",&choice);
    }
switch(choice)
{
    case 1: MainMenu();system("cls");break;
    case 0: system("cls");break;
}

}

void Login()
{
    int choice;
    char Acc[20];
    char passW[20];
    printf("--------------------------------------     Login Your Account     --------------------------------------\n");
    printf("Input your account:\n");
    scanf("%s",&Acc);
    printf("Input your password:\n");
    scanf("%s",&passW);
    for(int i=0;i<20;i++)
    {
        if(strcmp(Acc,acc[i].account)==0)
        {
            if(strcmp(passW,acc[i].password)==0)
            {
                LoginSuccessfully();
                break;
            }
            else
            {
                system("cls");
                printf("\n\n");
                printf("Error, your password is not correct. Please try again.\n");
                MainMenu();
            }
        }
        if(i=19)
        {
            system("cls");
            printf("\n\n");
            printf("Error, your account is not in the database.\n");
            MainMenu();
        }
    }


}

void LoginSuccessfully()
{
    int choice;
    printf("Successfully");
    printf("Your reward: www.op.gg\n");
    printf("input(1)MainMenu, input(0)\n");
    printf("Choice: ");
    scanf("%d",&choice);
    if(choice!=1&&choice!=0)
    {
            printf("Error,Please do one more time for Choice: ");
            scanf("%d",&choice);
    }
switch(choice)
{
    case 1: MainMenu();system("cls");break;
    case 0: system("cls");break;
}
}

int main()
{
   MainMenu();
   printf("111\n");
   return 0;
}
