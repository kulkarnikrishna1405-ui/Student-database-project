#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct stu
{
    int rollnor;
    char name[50];
    float marks;
    struct stu *next;
}SLL;

void insert_node(SLL **hptr);
void print(SLL *hptr);
void delete_node(SLL **hptr);
void sort_node(SLL *hptr);
void save_in_file(SLL *hptr);
void read_file(SLL **hptr);
void modify_node(SLL **hptr);
void delete_all_node(SLL **hptr);
void reverse_node(SLL **hptr);

void main()
{
    SLL *hptr=0;
    int op;
    SLL *p;
    while(1)
    {
        printf("\n**************************************************\n");
        printf("\n       STUDENT DATABASE MANAGEMENT SYSTEM         \n");
        printf("\n**************************************************\n");


        printf(" 1 - insert student details \n 2 - display details\n 3 - delete particular student details\n 4 - modify student details\n 5 - sort student details\n 6 - read details from file\n 7 - delete all student details\n 8 - reverse the list \n 9 - save and exit\n 10 - exit without saving\n");
        printf("\n**************************************************\n");
        printf("\nEnter your option : ");
        scanf("%d",&op);
        switch(op)
        {

            case 1: insert_node(&hptr);
            break;
            case 2: print(hptr);
            break;
            case 3:delete_node(&hptr);
            break;
            case 4:modify_node(&hptr);
            break;
            case 5: sort_node(hptr);
            break;
            case 6:read_file(&hptr);
            break;
            case 7:delete_all_node(&hptr);
            break;
            case 8 : reverse_node(&hptr);
            break;
             case 9:save_in_file(hptr);
            case 10:printf("\n Thank you for using student data base.\n");
                     exit(0);
                     break;
            default : printf("\nINVALID OPTION.\n");
            break;

        }

    }
}

void insert_node(SLL **hptr)
{
    SLL *n=malloc(sizeof(SLL));
    SLL *last=*hptr;

    printf("\nEnter the student details(name, marks) to insert  :\n");
    scanf("%s%f",n->name,&n->marks);
    n->next=NULL;

    if(n->marks<=100)
    {

    if(*hptr==0)
        *hptr=n;
    else{
        while(last->next!=NULL)
            last=last->next;
        last->next=n;

       }

    }
    else
    {
            printf("\n Entered marks is greater than 100.\n");
            free(n);
            return;
    }

}
void print(SLL *hptr)
{
    printf("\n---------------------------------------\n");
    if(hptr==0)
    {
        printf("NO STUDENT RECORDS FOUND TO DISPLAY\n");
        return;
    }
    printf("\nRoll nor       Name            marks \n");
    printf("-----------------------------------------\n");
    SLL *p=hptr;
    int c=1;
    while(p!=NULL)
    {
        p->rollnor=c;
        printf("%6d %12s %17.4f\n",p->rollnor,p->name,p->marks);
        c++;
        p=p->next;
    }
    printf("\nCount of records = %d",c-1);
     printf("\n---------------------------------------\n");
}

void delete_node(SLL **hptr)
{
    SLL *p=*hptr,*prev=NULL;
    if(*hptr==0)
    {
        printf("No records to be deleted \n ");
        return ;
    }
    int op,num;
    char s[30];
    printf("\n Enter your choice delete details based on ");
    printf("\n 1 - rollnor  2 - name\n");
    scanf("%d",&op);
    if(op==1)
    {
      printf("\n Enter the rollnor to delete : ");
      scanf("%d",&num);
    }
    else if(op==2)
    {
        printf("\nEnter the student name : ");
        scanf("%s",s);
    }
    if(op==1){
            p=*hptr;
    while(p!=NULL)
    {

        if(p->rollnor == num)
        {
        if(prev==NULL)
            *hptr=p->next;
        else
            prev->next=p->next;

            free(p);
            printf("\n particular node is deleted successfully. \n");
            return;
        }
          prev=p;
            p=p->next;
    }
    }
    else if(op==2)
    {
        SLL *f=*hptr,q;
        int c=0,r;
        while(f!=NULL)
        {
           if((strcmp(f->name,s))==0)
           {
               printf("%d %s %f\n",f->rollnor,f->name,f->marks);
               c=1;
           }
           f=f->next;
        }
        if(c)
        {
            printf("enter the roll number from the above to delete the record : ");
            scanf("%d",&r);
            int flag=0;
            p=*hptr;
            while(p!=NULL)
         {

        if(p->rollnor == r && (strcmp(p->name,s))==0)
        {
            flag=1;
        if(prev==NULL)
            *hptr=p->next;
        else
            prev->next=p->next;

            free(p);
            printf("\n particular node is deleted successfully. \n");
            return;
        }
          prev=p;
            p=p->next;
        }
        if(flag==0)
            printf("\n Invalid roll number from the above list.\n");

        }
      else
      {
        printf("\n Student name not found to delete.\n");
      }

    }
    else
        printf("\n Invalid option to delete the student details.\n");

    if(op==1 || op==2)
    printf("\nRecord not found to delete.\n");
}
void sort_node(SLL *hptr)
{
    SLL *temp=malloc(sizeof(SLL));
    if(hptr==0)
    {
        printf("No students details to be sorted \n");
        return;
    }
    int op;
    printf("\n Enter your choice sort details based on ");
    printf("\n 1 - name  2 - marks\n");
    scanf("%d",&op);
    SLL *last=hptr;
    int c=0;
    while(last!=NULL)
    {
        c++;
        last=last->next;
    }
    SLL *p=hptr;
    SLL *p2;
    if(op==2){
            p=hptr;
    for(int i=0;i<c-1;i++)
    {
        p2=p->next;
        for(int j=i+1;j<c;j++)
        {

        if((p->marks) > (p2->marks))
        {
            temp->rollnor=p->rollnor;
            strcpy(temp->name,p->name);
            temp->marks=p->marks;

            p->rollnor=p2->rollnor;
            strcpy(p->name,p2->name);
            p->marks=p2->marks;

            p2->rollnor=temp->rollnor;
            strcpy(p2->name,temp->name);
            p2->marks=temp->marks;
        }
        p2=p2->next;
        }
        p=p->next;
    }
    }
    else if(op==1)
    {
        p=hptr;
        for(int i=0;i<c-1;i++)
       {
        p2=p->next;
        for(int j=i+1;j<c;j++)
        {

        if((strcmp(p->name,p2->name))>0)
        {
            temp->rollnor=p->rollnor;
            strcpy(temp->name,p->name);
            temp->marks=p->marks;

            p->rollnor=p2->rollnor;
            strcpy(p->name,p2->name);
            p->marks=p2->marks;

            p2->rollnor=temp->rollnor;
            strcpy(p2->name,temp->name);
            p2->marks=temp->marks;
        }
        p2=p2->next;
        }
        p=p->next;
    }
    }
    else
        printf("\n Invalid option to sort list.\n");

    if(op==1 || op==2)
    printf("\n list is sorted successfully.\n");
}

void save_in_file(SLL *hptr)
{
    FILE *fp=fopen("Student_database.txt","w");
     fprintf(fp,"\n---------------------------------------\n");
    if(hptr==0)
    {
        fprintf(fp,"NO STUDENT RECORDS FOUND TO DISPLAY.\n");
        return;
    }
    SLL *p=hptr;
    int c=1;
    while(p!=NULL)
    {
        p->rollnor=c;
        fprintf(fp,"%d %s %f\n",p->rollnor,p->name,p->marks);
        c++;
        p=p->next;
    }
    fprintf(fp,"\ncount of records = %d",c-1);
     fprintf(fp,"\n---------------------------------------\n");
      fclose(fp);

    printf("Student records saved successfully.\n");

}
void read_file(SLL **hptr)
{
    SLL *n;
    FILE *fp=fopen("read_student_data.txt","r");
    if(fp==0)
    {
        printf("FILE NOT PRESENT.\n");
        return;
    }
   while(1)
   {
       n=malloc(sizeof(SLL));

       if((fscanf(fp,"%d%s%f",&n->rollnor,n->name,&n->marks))==-1)
       {
           free(n);
           break;
       }
       n->next=NULL;

       if(*hptr==NULL)
        *hptr=n;
       else
       {
           SLL *last=*hptr;
           while(last->next!=NULL)
            last=last->next;
           last->next=n;
       }
   }
   fclose(fp);
   printf("\n records loaded successfully.\n");

}

void reverse_node(SLL **hptr)
{
    if(*hptr==0)
    {
        printf("\n NO records found to reverse.\n");
        return;
    }
    SLL *cur=*hptr;
    SLL *prev=NULL;
    SLL *temp;


    while( cur !=NULL)
    {
        temp=cur->next;
        cur->next=prev;
        prev=cur;
        cur=temp;
    }
        *hptr=prev;
        printf("\n list is reversed.\n");
}
void delete_all_node(SLL **hptr)
{
    if(*hptr==0)
    {
        printf("\n NO Student details to be deleted.\n");
        return;
    }
    SLL *p=*hptr,*q;
    while(p!=NULL)
    {
        q=p;

        p=p->next;
        free(q);
    }
    *hptr=NULL;
    printf("\n All records were deleted successfully.\n");
}
void modify_node(SLL **hptr)
{

    if(*hptr==0)
    {
        printf("\n NO Student details to be deleted.\n");
        return;
    }
    int op;
    printf("\nEnter your choice to modify the details based on ");
    printf("\n 1 - rollnor  2 - name  3 - marks \n");
    scanf("%d",&op);

    if(op==1)
    {
        int num,c=0;
        printf("\nEnter the rollnor to search for modification :");
        scanf("%d",&num);

         SLL *p=*hptr;
        SLL *q=*hptr;
        while(p!=NULL)
        {
            if(p->rollnor==num)
            {
                printf("%d %s %f\n",p->rollnor,p->name,p->marks);
                q=p;
                c++;
                break;
            }
            p=p->next;
        }
        if(c==0){
           printf("\n Roll number not found you can not do modification.\n");
            return;
        }
        else{
                printf("\n Roll number found you can do modification.\n");
                SLL *n=malloc(sizeof(SLL));

               printf("\nEnter the new student details(name,marks) to modify : \n");
               scanf("%s%f",n->name,&n->marks);
               if(n->marks<=100){
               q->marks=n->marks;
               strcpy(q->name,n->name);
              free(n);
               }
               else
               {
                  printf("\n Entered marks is greater than 100.\n");
                     free(n);
                     return;
               }
        }
    }
    else if(op==2)
    {
        char s[20];
        int c=0;
        printf("\nEnter the student name to search for modification : ");
        scanf("%s",s);
        SLL *p=*hptr;
        while(p!=NULL)
        {
            if((strcmp(p->name,s))==0)
            {
                printf("%d %s %f\n",p->rollnor,p->name,p->marks);
                c++;
            }
            p=p->next;
        }
       if(c==0){
           printf("\n Student name not found you can not do modification.\n");
            return;
        }
        else
        {
            int num;
             int flag=0;
            printf("\nEnter the rollnor of above found student details to modify : ");
            scanf("%d",&num);
            SLL *f=*hptr;
            while(f!=NULL)
            {
                if(f->rollnor==num && strcmp(f->name,s)==0)
                {
                    flag=1;
                    break;
                }
                f=f->next;
            }
            if(flag==0)
            {
                printf("\nInvalid roll number from above list.\n");
                return;
            }

            char ch[20];
            printf("\n Enter the new name  : ");
            scanf("%s",ch);
            float f1;
            printf("\n Enter the new marks : ");
            scanf("%f",&f1);
           if(f1<=100){
            SLL *q=*hptr;
            while(q!=NULL)
            {
                if(q->rollnor==num && strcmp(q->name,s)==0)
                {

                    strcpy(q->name,ch);
                    q->marks=f1;
                    break;
                }
                q=q->next;
            }
           }
           else{
            printf("\n Entered marks is greater than 100.\n");
            return;
           }
        }

    }
    else if(op==3)
    {
        float m;
        int c=0;
        printf("\nEnter the marks to search for modification : ");
        scanf("%f",&m);
        SLL *p=*hptr;
        if(m<=100){
        while(p!=NULL)
        {
            if(p->marks==m)
            {
                printf("%d %s %f\n",p->rollnor,p->name,p->marks);
                c++;
            }
            p=p->next;
        }

         if(c==0){
           printf("\n Student marks not found you can not do modification.\n");
            return;
        }
        else{
             int num,flag=0;
            printf("\nEnter the rollnor of above found student details to modify : ");
            scanf("%d",&num);
            SLL *f=*hptr;
             while(f!=NULL)
            {
                if(f->rollnor==num && f->marks==m)
                {
                    flag=1;
                    break;
                }
                f=f->next;
            }
            if(flag==0)
            {
                printf("\nInvalid roll number from above list.\n");
                return;
            }
            float f1;
            printf("\n Enter the new marks : ");
            scanf("%f",&f1);
            char ch[20];
            printf("\n Enter the new name : ");
            scanf("%s",ch);
            SLL *q=*hptr;
            if(f1<=100){
            while(q!=NULL)
            {
                if(q->rollnor==num && q->marks==m)
                {
                    strcpy(q->name,ch);
                    q->marks=f1;

                    break;
                }
                q=q->next;
            }

            }
            else{
                     printf("\n Entered marks is greater than 100.\n");
                        return;
            }
        }
    }
    else{
         printf("\n Entered marks is greater than 100.\n");

            return;
    }
   }

    else
        printf("\nInvalid option to modify student details.\n");


  if(op==1 || op==2 || op==3)
    printf("\nStudent details are successfully modified.\n");

}
