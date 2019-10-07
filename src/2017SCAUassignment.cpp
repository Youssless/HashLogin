#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//����ṹ��
	struct StudentInformation
	{
	   char num[20];
	   char name[20];
	   char year[3];
	   char phonenumber[20];
	   char adress[200];
	   char email[30];
	}temp;

//�����õ��ַ���
       char find[200];

//�����õ��ַ���ָ��
	   char * stl;

    FILE *fp;

	int i,n,a,j;

	//������ͷ����
	void First();

	//�������溯��
	void save();

	//�������˵�����
	int z=1;
	void MainMenu(int z);

    //����1.�����Ϣ����
	void InputInformation(struct StudentInformation stu[]);
    struct StudentInformation stu[35], * p=stu;

	//����2.��ʾ��Ϣ����
	void ShowInformation(int z);

	//����3.ɾ����Ϣ����
	void DeleteInformation();

	//����4.��ѯ��Ϣ����
	void FindInformation();

	//����5.�޸���Ϣ����
	void AlterInformation();

	//����6.������Ϣ����
    void Save();

	//����7.������Ϣ����
    void SortInformation();

	//����5�ֲ�ѯ��Ϣ����
	void Number();
	void Name();
	void Phonenumber();
	void Adress();
	void No();

	//����2��������Ϣ����
	void UseNumber();
	void UseName();



int main()
{
 First();
 printf("*************************************��Ҫ������**************************************");
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
	printf("                      *************************| 1.��Ӽ�¼ |****************************\n");
	printf("                      *************************| 2.��ʾ��¼ |****************************\n");
	printf("                      *************************| 3.ɾ����¼ |****************************\n");
	printf("                      *************************| 4.��ѯ��¼ |****************************\n");
	printf("                      *************************| 5.�޸ļ�¼ |****************************\n");
	printf("                      *************************| 6.�����¼ |****************************\n");
	printf("                      *************************| 7.�����¼ |****************************\n");
	printf("                      *************************| 0.�˳����� |****************************\n");
	printf("                      *************************|------------|****************************\n");
	printf("                      *******************************************************************\n");
	printf("                                                 ѡ��:(0-7)                              \n");
	printf("\n\n\n");

	//Menu Choice
	printf("����ѡ����:\t");scanf("%d",&n);
	for(;n>7||n<0;)
	{
		printf("Error,������0-7\n");
        printf("����ѡ����:\t");
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
	 //printf("��ѡ��Ҫ�����ѧ����Ϣ�ı��:\t");
	 //scanf("%a",&a);
	 for(i=0;i<35;i++)
	 if(fwrite(&stu[i],sizeof(struct StudentInformation),1,fp)!=1)
		 printf("File write error\n");
	 fclose(fp);
}





// 1

void InputInformation(struct StudentInformation stu[])

{
	printf("������Ҫ����ѧ����Ϣ��ѧ�����(��1��ʼ):\t");
	scanf("%d",&a);
	printf("\n\n");

	printf("������ѧ������Ϣ:\n");
    printf("--------------------------------------------------\n");
    printf("���������룺ѧ��ѧ�� ���� ���� ��ϵ�绰 ��ַ ���� \n");
    printf("--------------------------------------------------\n");

       scanf("%s %s %s %s %s %s",stu[a].num,stu[a].name,stu[a].year,stu[a].phonenumber,stu[a].adress,stu[a].email);
       save();
      printf("��ѡ��0(�˳�����)-1(����������Ϣ)-2(�������˵�):\t");
	  scanf("%d",&n);
	     for(;n>2||n<0;)
		 {
		printf("Error,������0-2\n");
		 printf("��ѡ��0(�˳�����)-1(����������Ϣ)-2(�������˵�):\t");
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
  //�����Ϣ


//���Ѵ��ڵ��ļ�׼��������Ϣ
          if((fp=fopen("D://Information.dat","rb"))==NULL)
		  {
               printf("Cannot open this file\n");
	           exit(0);
		  }


		  printf("ѧ������Ϣ:\n");
          printf("------------------------------------------------------------------------------------------------------------\n");
          printf("���      ѧ��ѧ��        ����      ����     ��ϵ�绰                   ��ַ                     ����       \n");
          printf("------------------------------------------------------------------------------------------------------------\n");

      printf("!------------------------------------------------------------------------------------------------------------!\n");
      for(i=0;i<35;i++)
	  {
		  fread(&stu[i],sizeof(struct StudentInformation),1,fp);
          printf(" %d      %s     %s      %s    %s    %s  %s\n",i,stu[i].num,stu[i].name,stu[i].year,stu[i].phonenumber,stu[i].adress,stu[i].email);
	  }
      printf("!------------------------------------------------------------------------------------------------------------!\n");
          //�ر��ļ�
          fclose(fp);

	        printf("��ѡ��0(�˳�����)-1(�������˵�):\t");
	  scanf("%d",&n);
	     for(;n>1||n<0;)
		 {
		printf("Error,������0-1\n");
		 printf("��ѡ��0(�˳�����)-1(�������˵�):\t");
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

    printf("������Ҫɾ����ѧ����Ϣ��ѧ�����:\t");
	scanf("%d",&a);
	printf("\n\n");

    stu[a].num[0]=0;
	stu[a].name[0]=0;
	stu[a].year[0]=0;
	stu[a].phonenumber[0]=0;
	stu[a].adress[0]=0;
	stu[a].email[0]=0;

       save();

   printf("ɾ���ɹ�!:\n");

   printf("\n\n");
	   printf("��ѡ��0(�˳�����)-1(����ɾ��)-2(�������˵�):\t");

	   scanf("%d",&n);
	       for(;n>2||n<0;)
		   {
	     	printf("Error,������0-2\n");
			 printf("��ѡ��0(�˳�����)-1(����ɾ��)-2(�������˵�):\t");
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
  printf("��Ҫʹ��2.��ʾ��Ϣһ�κ󷽿�ʹ��\n");
  printf("\n\n\n");
  printf("��ѡ�������Ϣ�ķ�ʽ1-5:\n");
  printf("1(��ѧ�Ų���)-2(����������)-3(����ϵ�绰����)-4(����ַ����)-5(ѧ����Ϣ����Ϣ���)\t");

  scanf("%d",&n);
  	       for(;n>5||n<0;)
		   {
	     	printf("Error,������0-5\n");
            printf("1(��ѧ�Ų���)-2(����������)-3(����ϵ�绰����)-4(����ַ����)-5(ѧ����Ϣ����Ϣ���)\t");
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
  printf("��ѡ��Ҫ�޸���Ϣ��ѧ�����:\t");
  scanf("%d",&Alter);
  printf("\n");
  printf("��ѡ��Ҫ�޸���Ϣ�ı��(1.ѧ��ѧ��2.����3.����4.��ϵ�绰5.��ַ6.����):\t");
  scanf("%d",&alter);

    	       for(;alter>6||alter<0;)
		   {
	     	printf("Error,������0-6\n");
            printf("��ѡ��Ҫ�޸���Ϣ�ı��(1.ѧ��ѧ��2.����3.����4.��ϵ�绰5.��ַ6.����)\t");
	        scanf("%d",&alter);
		   }

  printf("\n");

      switch(alter)
	  {
	     case 1:printf("ѧ��ѧ��:\t");scanf("%s",&stu[Alter].num);break;
         case 2:printf("����:\t");scanf("%s",&stu[Alter].name);break;
         case 3:printf("����:\t");scanf("%s",&stu[Alter].year);break;
	     case 4:printf("��ϵ�绰:\t");scanf("%s",&stu[Alter].phonenumber);break;
	     case 5:printf("��ַ:\t");scanf("%s",&stu[Alter].adress);break;
	     case 6:printf("����:\t");scanf("%s",&stu[Alter].email);break;
		 default:printf("Error,please enter a right number\n");
	  }

       save();

	   printf("\n\n");
	   printf("��ѡ��0(�˳�����)-1(�����޸�)-2(�������˵�):\t");

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
  printf("����ɹ�\n!");
  printf("�Զ��������˵�!\n");
  printf("\n\n\n\n\n\n");
  MainMenu(z);

}




// 7

void SortInformation()

{
  printf("��ѡ��0(�������˵�)-1(ȷ��ѧ������)-2(ȷ����������)\t");

  scanf("%d",&n);
  	       for(;n>2||n<0;)
		   {
	     	printf("Error,������0-2\n");
            printf("��ѡ��0(�������˵�)-1(ȷ��ѧ������)-2(ȷ����������)\t");
	        scanf("%d",&n);
		   }


       switch(n)
	   {
	     case 0:MainMenu(z);break;
	     case 1:UseNumber();break;
		 case 2:UseName();break;
	   }

  printf("����ɹ����Զ��������˵�!\n\n\n\n\n\n\n\n");
  MainMenu(z);

}






//5�ֲ�ѯ��Ϣ����

void Number()

{

  if((fp=fopen("D://Information.dat","rb"))==NULL)
		  {
               printf("Cannot open this file\n");
	           exit(0);
		  }


  printf("����������Ҫ���ҵ�ѧ��:\t");
  scanf("%s",find);


	  for(i=0;i<35;i++)
	  {

	      if(strcmp(find,stu[i+1].num)==0)
		  {
			printf("%d\n",i);
			fread(&stu[i],sizeof(struct StudentInformation),1,fp);
			printf("ѧ������Ϣ:\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
            printf("ѧ��ѧ��        ����      ����     ��ϵ�绰                   ��ַ                     ����     \n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			printf("%s    %s      %s  %s    %s  %s\n",stu[i+1].num,stu[i+1].name,stu[i+1].year,stu[i+1].phonenumber,stu[i+1].adress,stu[i+1].email);
		  }

	  }

      fclose(fp);

	  printf("\n\n");
	   printf("��ѡ��0(�˳�����)-1(�������˵�):\t");

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


  printf("����������Ҫ���ҵ�����:\t");
  scanf("%s",find);
      for(i=0;i<35;i++)
	  {

	      if(strcmp(find,stu[i+1].name)==0)
		  {
			printf("%d\n",i);
			fread(&stu[i],sizeof(struct StudentInformation),1,fp);
			printf("ѧ������Ϣ:\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
            printf("ѧ��ѧ��        ����      ����     ��ϵ�绰                   ��ַ                     ����     \n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			printf("%s    %s      %s  %s    %s  %s\n",stu[i+1].num,stu[i+1].name,stu[i+1].year,stu[i+1].phonenumber,stu[i+1].adress,stu[i+1].email);
		  }

	  }

      fclose(fp);

	  printf("\n\n");
	   printf("��ѡ��0(�˳�����)-1(�������˵�):\t");

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


  printf("����������Ҫ���ҵ���ϵ�绰:\t");
  scanf("%s",find);
      for(i=0;i<35;i++)
	  {

	      if(strcmp(find,stu[i+1].phonenumber)==0)
		  {
			printf("%d\n",i);
			fread(&stu[i],sizeof(struct StudentInformation),1,fp);
			printf("ѧ������Ϣ:\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
            printf("ѧ��ѧ��        ����      ����     ��ϵ�绰                   ��ַ                     ����     \n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			printf("%s    %s      %s  %s    %s  %s\n",stu[i+1].num,stu[i+1].name,stu[i+1].year,stu[i+1].phonenumber,stu[i+1].adress,stu[i+1].email);
		  }

	  }

      fclose(fp);

	  printf("\n\n");
	   printf("��ѡ��0(�˳�����)-1(�������˵�):\t");

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


  printf("����������Ҫ���ҵĵ�ַ:\t");
  scanf("%s",find);
      for(i=0;i<35;i++)
	  {

	      if(strcmp(find,stu[i+1].adress)==0)
		  {
			printf("%d\n",i);
			fread(&stu[i],sizeof(struct StudentInformation),1,fp);
			printf("ѧ������Ϣ:\n");
            printf("------------------------------------------------------------------------------------------------\n");
            printf("ѧ��ѧ��        ����      ����     ��ϵ�绰                   ��ַ                     ����     \n");
            printf("------------------------------------------------------------------------------------------------\n");
			printf("%d       %s    %s      %s  %s    %s  %s\n",i,stu[i+1].num,stu[i+1].name,stu[i+1].year,stu[i+1].phonenumber,stu[i+1].adress,stu[i+1].email);
		  }

	  }

      fclose(fp);

	  printf("\n\n");
	   printf("��ѡ��0(�˳�����)-1(�������˵�):\t");

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


  printf("����������Ҫ���ҵ�ѧ����Ϣ����Ϣ���:\n");
  scanf("%d",&i);


			fread(&stu[i],sizeof(struct StudentInformation),1,fp);
			printf("ѧ������Ϣ:\n");
            printf("----------------------------------------------------------------------------------------------------------\n");
            printf("ѧ��ѧ��        ����      ����     ��ϵ�绰                   ��ַ                     ����     \n");
            printf("----------------------------------------------------------------------------------------------------------\n");
			printf("%s    %s      %s  %s      %s  %s\n",stu[i].num,stu[i].name,stu[i].year,stu[i].phonenumber,stu[i].adress,stu[i].email);


      fclose(fp);

	  printf("\n\n");
	   printf("��ѡ��0(�˳�����)-1(�������˵�):\n");

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



//2��������Ϣ����

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


		  printf("ѧ������Ϣ:\n");
          printf("------------------------------------------------------------------------------------------------------------\n");
          printf("���      ѧ��ѧ��        ����      ����     ��ϵ�绰                   ��ַ                     ����       \n");
          printf("------------------------------------------------------------------------------------------------------------\n");

      printf("!------------------------------------------------------------------------------------------------------------!\n");
      for(i=0;i<35;i++)
	  {
		  fread(&stu[i],sizeof(struct StudentInformation),1,fp);
          printf(" %d      %s     %s      %s    %s    %s  %s\n",i,stu[i].num,stu[i].name,stu[i].year,stu[i].phonenumber,stu[i].adress,stu[i].email);
	  }
      printf("!------------------------------------------------------------------------------------------------------------!\n");
          //�ر��ļ�
          fclose(fp);
	}
