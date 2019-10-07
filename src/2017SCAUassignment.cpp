#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//定义结构体
	struct StudentInformation
	{
	   char num[20];
	   char name[20];
	   char year[3];
	   char phonenumber[20];
	   char adress[200];
	   char email[30];
	}temp;

//查找用的字符串
       char find[200];

//排序用的字符串指针
	   char * stl;

    FILE *fp;

	int i,n,a,j;

	//声明开头函数
	void First();

	//声明保存函数
	void save();

	//声明主菜单函数
	int z=1;
	void MainMenu(int z);

    //声明1.添加信息函数
	void InputInformation(struct StudentInformation stu[]);
    struct StudentInformation stu[35], * p=stu;

	//声明2.显示信息函数
	void ShowInformation(int z);

	//声明3.删除信息函数
	void DeleteInformation();

	//声明4.查询信息函数
	void FindInformation();

	//声明5.修改信息函数
	void AlterInformation();

	//声明6.保存信息函数
    void Save();

	//声明7.排序信息函数
    void SortInformation();

	//声明5种查询信息函数
	void Number();
	void Name();
	void Phonenumber();
	void Adress();
	void No();

	//声明2种排序信息函数
	void UseNumber();
	void UseName();



int main()
{
 First();
 printf("*************************************必要的运行**************************************");
 printf("\n\n\n\n\n\n\n\n\n\n\n\n");
 MainMenu(z);
 return 0;
}


void MainMenu(int z)
{

  //Menu
	printf("\n\n\n");
	printf("                      *******************************************************************\n");
	printf("                      *******************************************************************\n");
	printf("                      ***********  !Welcome to use the communicated system! *************\n");
	printf("                      *************************|------------|****************************\n");
	printf("                      *************************| 1.添加记录 |****************************\n");
	printf("                      *************************| 2.显示记录 |****************************\n");
	printf("                      *************************| 3.删除记录 |****************************\n");
	printf("                      *************************| 4.查询记录 |****************************\n");
	printf("                      *************************| 5.修改记录 |****************************\n");
	printf("                      *************************| 6.保存记录 |****************************\n");
	printf("                      *************************| 7.排序记录 |****************************\n");
	printf("                      *************************| 0.退出程序 |****************************\n");
	printf("                      *************************|------------|****************************\n");
	printf("                      *******************************************************************\n");
	printf("                                                 选择:(0-7)                              \n");
	printf("\n\n\n");

	//Menu Choice
	printf("您的选择是:\t");scanf("%d",&n);
	for(;n>7||n<0;)
	{
		printf("Error,请输入0-7\n");
        printf("您的选择是:\t");
	    scanf("%d",&n);
	}

	switch(n)
	{
	case 0: break;
	case 1: InputInformation(p); break;
	case 2: ShowInformation(z); break;
	case 3: DeleteInformation(); break;
	case 4: FindInformation(); break;
	case 5: AlterInformation(); break;
	case 6: Save(); break;
	case 7: SortInformation();break;
	}
}





void save()

{
     if((fp=fopen("D://Information.dat","wb"))==NULL)
	 {
	  printf("Cannot open this file\n");
	  return;
	 }
	 //printf("请选择要保存的学生信息的编号:\t");
	 //scanf("%a",&a);
	 for(i=0;i<35;i++)
	 if(fwrite(&stu[i],sizeof(struct StudentInformation),1,fp)!=1)
		 printf("File write error\n");
	 fclose(fp);
}





// 1

void InputInformation(struct StudentInformation stu[])

{
	printf("请输入要登入学生信息的学生编号(从1开始):\t");
	scanf("%d",&a);
	printf("\n\n");

	printf("请输入学生的信息:\n");
    printf("--------------------------------------------------\n");
    printf("请依次输入：学生学号 姓名 年龄 联系电话 地址 邮箱 \n");
    printf("--------------------------------------------------\n");

       scanf("%s %s %s %s %s %s",stu[a].num,stu[a].name,stu[a].year,stu[a].phonenumber,stu[a].adress,stu[a].email);
       save();
      printf("请选择0(退出程序)-1(继续登入信息)-2(返回主菜单):\t");
	  scanf("%d",&n);
	     for(;n>2||n<0;)
		 {
		printf("Error,请输入0-2\n");
		 printf("请选择0(退出程序)-1(继续登入信息)-2(返回主菜单):\t");
	    scanf("%d",&n);
		 }
           switch(n)
		   {
		   case 0:break;
		   case 1:InputInformation(p);break;
		   case 2:printf("\n\n\n\n\n\n\n");MainMenu(z);break;
		   }

}




// 2

void ShowInformation(int z)
{
  //输出信息


//打开已存在的文件准备读出信息
          if((fp=fopen("D://Information.dat","rb"))==NULL)
		  {
               printf("Cannot open this file\n");
	           exit(0);
		  }


		  printf("学生的信息:\n");
          printf("------------------------------------------------------------------------------------------------------------\n");
          printf("编号      学生学号        姓名      年龄     联系电话                   地址                     邮箱       \n");
          printf("------------------------------------------------------------------------------------------------------------\n");

      printf("!------------------------------------------------------------------------------------------------------------!\n");
      for(i=0;i<35;i++)
	  {
		  fread(&stu[i],sizeof(struct StudentInformation),1,fp);
          printf(" %d      %s     %s      %s    %s    %s  %s\n",i,stu[i].num,stu[i].name,stu[i].year,stu[i].phonenumber,stu[i].adress,stu[i].email);
	  }
      printf("!------------------------------------------------------------------------------------------------------------!\n");
          //关闭文件
          fclose(fp);

	        printf("请选择0(退出程序)-1(返回主菜单):\t");
	  scanf("%d",&n);
	     for(;n>1||n<0;)
		 {
		printf("Error,请输入0-1\n");
		 printf("请选择0(退出程序)-1(返回主菜单):\t");
	    scanf("%d",&n);
		 }
           switch(n)
		   {
		   case 0:break;
		   case 1:printf("\n\n\n\n\n\n\n");MainMenu(z);break;
		   }
}



//  3

void DeleteInformation()

{

    printf("请输入要删除的学生信息的学生编号:\t");
	scanf("%d",&a);
	printf("\n\n");

    stu[a].num[0]=0;
	stu[a].name[0]=0;
	stu[a].year[0]=0;
	stu[a].phonenumber[0]=0;
	stu[a].adress[0]=0;
	stu[a].email[0]=0;

       save();

   printf("删除成功!:\n");

   printf("\n\n");
	   printf("请选择0(退出程序)-1(继续删除)-2(返回主菜单):\t");

	   scanf("%d",&n);
	       for(;n>2||n<0;)
		   {
	     	printf("Error,请输入0-2\n");
			 printf("请选择0(退出程序)-1(继续删除)-2(返回主菜单):\t");
	        scanf("%d",&n);
		   }
	   switch(n)
		   {
		   case 0:break;
		   case 1:DeleteInformation();break;
		   case 2:printf("\n\n\n\n\n\n\n");MainMenu(z);break;
		   }

}




//  4

void FindInformation()

{
  printf("需要使用2.显示信息一次后方可使用\n");
  printf("\n\n\n");
  printf("请选择查找信息的方式1-5:\n");
  printf("1(按学号查找)-2(按姓名查找)-3(按联系电话查找)-4(按地址查找)-5(学生信息的信息编号)\t");

  scanf("%d",&n);
  	       for(;n>5||n<0;)
		   {
	     	printf("Error,请输入0-5\n");
            printf("1(按学号查找)-2(按姓名查找)-3(按联系电话查找)-4(按地址查找)-5(学生信息的信息编号)\t");
	        scanf("%d",&n);
		   }

       switch(n)
	   {
	    case 1:Number();break;
	    case 2:Name();break;
	    case 3:Phonenumber();break;
	    case 4:Adress();break;
		case 5:No();break;
	   }
}




//  5

void AlterInformation()

{


  int Alter,alter;
  printf("请选择要修改信息的学生编号:\t");
  scanf("%d",&Alter);
  printf("\n");
  printf("请选择要修改信息的编号(1.学生学号2.姓名3.年龄4.联系电话5.地址6.邮箱):\t");
  scanf("%d",&alter);

    	       for(;alter>6||alter<0;)
		   {
	     	printf("Error,请输入0-6\n");
            printf("请选择要修改信息的编号(1.学生学号2.姓名3.年龄4.联系电话5.地址6.邮箱)\t");
	        scanf("%d",&alter);
		   }

  printf("\n");

      switch(alter)
	  {
	     case 1:printf("学生学号:\t");scanf("%s",&stu[Alter].num);break;
         case 2:printf("姓名:\t");scanf("%s",&stu[Alter].name);break;
         case 3:printf("年龄:\t");scanf("%s",&stu[Alter].year);break;
	     case 4:printf("联系电话:\t");scanf("%s",&stu[Alter].phonenumber);break;
	     case 5:printf("地址:\t");scanf("%s",&stu[Alter].adress);break;
	     case 6:printf("邮箱:\t");scanf("%s",&stu[Alter].email);break;
		 default:printf("Error,please enter a right number\n");
	  }

       save();

	   printf("\n\n");
	   printf("请选择0(退出程序)-1(继续修改)-2(返回主菜单):\t");

	   scanf("%d",&n);
	       for(;n>2||n<0;)
		   {
	     	printf("Error,please try again\n");
	        scanf("%d",&n);
		   }
	   switch(n)
		   {
		   case 0:break;
		   case 1:AlterInformation();break;
		   case 2:printf("\n\n\n\n\n\n\n");MainMenu(z);break;
		   }


}


// 6

void Save()

{
  save();
  printf("保存成功\n!");
  printf("自动返回主菜单!\n");
  printf("\n\n\n\n\n\n");
  MainMenu(z);

}




// 7

void SortInformation()

{
  printf("请选择0(返回主菜单)-1(确定学号排序)-2(确定名字排序)\t");

  scanf("%d",&n);
  	       for(;n>2||n<0;)
		   {
	     	printf("Error,请输入0-2\n");
            printf("请选择0(返回主菜单)-1(确定学号排序)-2(确定名字排序)\t");
	        scanf("%d",&n);
		   }


       switch(n)
	   {
	     case 0:MainMenu(z);break;
	     case 1:UseNumber();break;
		 case 2:UseName();break;
	   }

  printf("排序成功，自动返回主菜单!\n\n\n\n\n\n\n\n");
  MainMenu(z);

}






//5种查询信息函数

void Number()

{

  if((fp=fopen("D://Information.dat","rb"))==NULL)
		  {
               printf("Cannot open this file\n");
	           exit(0);
		  }


  printf("请输入你想要查找的学号:\t");
  scanf("%s",find);


	  for(i=0;i<35;i++)
	  {

	      if(strcmp(find,stu[i+1].num)==0)
		  {
			printf("%d\n",i);
			fread(&stu[i],sizeof(struct StudentInformation),1,fp);
			printf("学生的信息:\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
            printf("学生学号        姓名      年龄     联系电话                   地址                     邮箱     \n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			printf("%s    %s      %s  %s    %s  %s\n",stu[i+1].num,stu[i+1].name,stu[i+1].year,stu[i+1].phonenumber,stu[i+1].adress,stu[i+1].email);
		  }

	  }

      fclose(fp);

	  printf("\n\n");
	   printf("请选择0(退出程序)-1(返回主菜单):\t");

	   scanf("%d",&n);
	       for(;n>1||n<0;)
		   {
	     	printf("Error,please try again\n");
	        scanf("%d",&n);
		   }
	   switch(n)
		   {
		   case 0:break;
		   case 1:printf("\n\n\n\n\n\n\n");MainMenu(z);break;
		   }
}


void Name()

{
   if((fp=fopen("D://Information.dat","rb"))==NULL)
		  {
               printf("Cannot open this file\n");
	           exit(0);
		  }


  printf("请输入你想要查找的名字:\t");
  scanf("%s",find);
      for(i=0;i<35;i++)
	  {

	      if(strcmp(find,stu[i+1].name)==0)
		  {
			printf("%d\n",i);
			fread(&stu[i],sizeof(struct StudentInformation),1,fp);
			printf("学生的信息:\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
            printf("学生学号        姓名      年龄     联系电话                   地址                     邮箱     \n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			printf("%s    %s      %s  %s    %s  %s\n",stu[i+1].num,stu[i+1].name,stu[i+1].year,stu[i+1].phonenumber,stu[i+1].adress,stu[i+1].email);
		  }

	  }

      fclose(fp);

	  printf("\n\n");
	   printf("请选择0(退出程序)-1(返回主菜单):\t");

	   scanf("%d",&n);
	       for(;n>1||n<0;)
		   {
	     	printf("Error,please try again\n");
	        scanf("%d",&n);
		   }
	   switch(n)
		   {
		   case 0:break;
		   case 1:printf("\n\n\n\n\n\n\n");MainMenu(z);break;
		   }
}




void Phonenumber()

{
    if((fp=fopen("D://Information.dat","rb"))==NULL)
		  {
               printf("Cannot open this file\n");
	           exit(0);
		  }


  printf("请输入你想要查找的联系电话:\t");
  scanf("%s",find);
      for(i=0;i<35;i++)
	  {

	      if(strcmp(find,stu[i+1].phonenumber)==0)
		  {
			printf("%d\n",i);
			fread(&stu[i],sizeof(struct StudentInformation),1,fp);
			printf("学生的信息:\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
            printf("学生学号        姓名      年龄     联系电话                   地址                     邮箱     \n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			printf("%s    %s      %s  %s    %s  %s\n",stu[i+1].num,stu[i+1].name,stu[i+1].year,stu[i+1].phonenumber,stu[i+1].adress,stu[i+1].email);
		  }

	  }

      fclose(fp);

	  printf("\n\n");
	   printf("请选择0(退出程序)-1(返回主菜单):\t");

	   scanf("%d",&n);
	       for(;n>1||n<0;)
		   {
	     	printf("Error,please try again\n");
	        scanf("%d",&n);
		   }
	   switch(n)
		   {
		   case 0:break;
		   case 1:printf("\n\n\n\n\n\n\n");MainMenu(z);break;
		   }
}


void Adress()

{
     if((fp=fopen("D://Information.dat","rb"))==NULL)
		  {
               printf("Cannot open this file\n");
	           exit(0);
		  }


  printf("请输入你想要查找的地址:\t");
  scanf("%s",find);
      for(i=0;i<35;i++)
	  {

	      if(strcmp(find,stu[i+1].adress)==0)
		  {
			printf("%d\n",i);
			fread(&stu[i],sizeof(struct StudentInformation),1,fp);
			printf("学生的信息:\n");
            printf("------------------------------------------------------------------------------------------------\n");
            printf("学生学号        姓名      年龄     联系电话                   地址                     邮箱     \n");
            printf("------------------------------------------------------------------------------------------------\n");
			printf("%d       %s    %s      %s  %s    %s  %s\n",i,stu[i+1].num,stu[i+1].name,stu[i+1].year,stu[i+1].phonenumber,stu[i+1].adress,stu[i+1].email);
		  }

	  }

      fclose(fp);

	  printf("\n\n");
	   printf("请选择0(退出程序)-1(返回主菜单):\t");

	   scanf("%d",&n);
	       for(;n>1||n<0;)
		   {
	     	printf("Error,please try again\n");
	        scanf("%d",&n);
		   }
	   switch(n)
		   {
		   case 0:break;
		   case 1:printf("\n\n\n\n\n\n\n");MainMenu(z);break;
		   }
}



void No()

{
  if((fp=fopen("D://Information.dat","rb"))==NULL)
		  {
               printf("Cannot open this file\n");
	           exit(0);
		  }


  printf("请输入你想要查找的学生信息的信息编号:\n");
  scanf("%d",&i);


			fread(&stu[i],sizeof(struct StudentInformation),1,fp);
			printf("学生的信息:\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
            printf("学生学号        姓名      年龄     联系电话                   地址                     邮箱     \n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			printf("%s    %s      %s  %s      %s  %s\n",stu[i].num,stu[i].name,stu[i].year,stu[i].phonenumber,stu[i].adress,stu[i].email);


      fclose(fp);

	  printf("\n\n");
	   printf("请选择0(退出程序)-1(返回主菜单):\n");

	   scanf("%d",&n);
	       for(;n>1||n<0;)
		   {
	     	printf("Error,please try again\n");
	        scanf("%d",&n);
		   }
	   switch(n)
		   {
		   case 0:break;
		   case 1:printf("\n\n\n\n\n\n\n");MainMenu(z);break;
		   }
}



//2种排序信息函数

	void UseNumber()

	{
	  //char student[20];
      for(i=1;i<34;i++)
		  for(j=i+1;j<35;j++)
		  {

		        if(strcmp(stu[i].num,stu[j].num)>0)
				{

					  if(stu[j].num!='\0')
					  {
						temp=stu[i];
				        stu[i]=stu[j];
				        stu[j]=temp;
					  }

				}


		  }

      save();
	}






	void UseName()

	{
          for(i=1;i<34;i++)
		  for(j=i+1;j<35;j++)
		  {

		        if(strcmp(stu[i].name,stu[j].name)>0)
				{

					  if(stu[j].name!='\0')
					  {
						temp=stu[i];
				        stu[i]=stu[j];
				        stu[j]=temp;
					  }

				}


		  }

      save();
	}


	void First()

	{
	if((fp=fopen("D://Information.dat","rb"))==NULL)
		  {
               printf("Cannot open this file\n");
	           exit(0);
		  }


		  printf("学生的信息:\n");
          printf("------------------------------------------------------------------------------------------------------------\n");
          printf("编号      学生学号        姓名      年龄     联系电话                   地址                     邮箱       \n");
          printf("------------------------------------------------------------------------------------------------------------\n");

      printf("!------------------------------------------------------------------------------------------------------------!\n");
      for(i=0;i<35;i++)
	  {
		  fread(&stu[i],sizeof(struct StudentInformation),1,fp);
          printf(" %d      %s     %s      %s    %s    %s  %s\n",i,stu[i].num,stu[i].name,stu[i].year,stu[i].phonenumber,stu[i].adress,stu[i].email);
	  }
      printf("!------------------------------------------------------------------------------------------------------------!\n");
          //关闭文件
          fclose(fp);
	}
