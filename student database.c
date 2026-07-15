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
void insert_begin(SLL **hptr);
void insert_end(SLL **hptr);
void insert_middle(SLL **hptr);
void print(SLL *hptr);
SLL *search_node(SLL *hptr);
void delete_node(SLL **hptr);
void sort_node(SLL *hptr);
void save_in_file(SLL *hptr);
void read_file(SLL **hptr);
void rotate_node(SLL **hptr);
void topper_student(SLL *hptr);
void failed_student(SLL *hptr);
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


        printf(" 1 - insert student details at begin\n 2 - insert student details at end\n 3 - display details\n 4 - insert student details at middle\n 5 - search student details\n 6 - delete particular student details\n 7 - sort student details\n 8 - save details in file\n 9 - read details from file\n 10 - rotate student details\n 11 - Topper student detail\n 12 - failed student details 13 - exit\n");
        printf("\n**************************************************\n");
        printf("\nEnter your option : ");
        scanf("%d",&op);
        switch(op)
        {
            case 1: insert_begin(&hptr);
            break;
            case 2: insert_end(&hptr);
            break;
            case 3: print(hptr);
            break;
            case 4:insert_middle(&hptr);
            break;
            case 5: p=search_node(hptr);
                    if(p)
                        printf("\nSTUDENT DETAILS FOUND.\n");
                    else
                        printf("\nSTUDENT DETAILS NOT FOUND.\n");
            break;
            case 6:delete_node(&hptr);
            break;
            case 7: sort_node(hptr);
            break;
            case 8:save_in_file(hptr);
            break;
            case 9:read_file(&hptr);
            break;
            case 10: rotate_node(&hptr);
            break;
            case 11: topper_student(hptr);
            break;
            case 12: failed_student(hptr);
            break;
            case 13:printf("\n Thank you for using student data base.\n");
                     exit(0);
            default : printf("\nINVALID OPTION.\n");
            break;

        }

    }
}
void insert_begin(SLL **hptr)
{
    SLL *n=malloc(sizeof(SLL));
    printf("\nEnter the student details(rollnor, name, marks) to insert begin :\n");
    scanf("%d%s%f",&n->rollnor,n->name,&n->marks);
    SLL *p=*hptr;
    if((n->marks)<=100){
    int flag=0;
    while(p!=NULL)
    {
        if((p->rollnor==n->rollnor)){
          flag=1;
            break;
        }
        else
            p=p->next;
    }
    if(flag){
        printf("\nEntered student details is already exist so enter new details.\n");
        free(n);
        return;
    }
    else{
    n->next=*hptr;
    *hptr=n;
    }
    }
    else{
        printf("\n Entered marks is greater than 100.\n");
        return;
    }

}
void insert_end(SLL **hptr)
{
    SLL *n=malloc(sizeof(SLL));
    SLL *last=*hptr;

    printf("\nEnter the student details(rollnor, name, marks) to insert end :\n");
    scanf("%d%s%f",&n->rollnor,n->name,&n->marks);
    n->next=NULL;
        if((n->marks)<=100){
    SLL *p=*hptr;
    int flag=0;
    while(p!=NULL)
    {
        if((p->rollnor==n->rollnor)){
          flag=1;
            break;
        }
        else
            p=p->next;
    }
    if(flag){
        printf("\nEntered student details is already exist so enter new details.\n");
        free(n);
        return;
    }
    else{
    if(*hptr==0)
        *hptr=n;
    else{
        while(last->next!=NULL)
            last=last->next;
        last->next=n;

    }
    }
        }
        else
        {
            printf("\n Entered marks is greater than 100.\n");
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
    int c=0;
    while(p!=NULL)
    {
        printf("%6d %12s %17.4f\n",p->rollnor,p->name,p->marks);
        c++;
        p=p->next;
    }
    printf("\nCount of records = %d",c);
     printf("\n---------------------------------------\n");
}
SLL *search_node(SLL *hptr)
{
      SLL *n=malloc(sizeof(SLL));
    printf("\nEnter the student details(rollnor, name, marks) to search :\n");
    scanf("%d%s%f",&n->rollnor,n->name,&n->marks);
    SLL *p=hptr;
    while(p!=NULL)
    {
        if((p->rollnor==n->rollnor) )
            return p;
        else
            p=p->next;
    }
}
void delete_node(SLL **hptr)
{
    SLL *p=*hptr,*prev=NULL;
    int num;
    if(*hptr==0)
    {
        printf("No records to be deleted \n ");
        return ;
    }
    printf("Enter the particular student roll number to delete : ");
    scanf("%d",&num);
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
    printf("\nrecord not found to delete.\n");
}
void sort_node(SLL *hptr)
{
    SLL *temp;
    if(hptr==0)
    {
        printf("No students details to be sorted \n");
        return;
    }
    SLL *last=hptr;
    int c=0;
    while(last!=NULL)
    {
        c++;
        last=last->next;
    }
    SLL *p=hptr;
    SLL *p2;
    for(int i=0;i<c-1;i++)
    {
        p2=p->next;
        for(int j=i+1;j<c;j++)
        {

        if((p->rollnor) > (p2->rollnor))
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
    printf("\n nodes are sorted successfully.\n");
}
void insert_middle(SLL **hptr)
{
      SLL *n=malloc(sizeof(SLL));
    printf("\nEnter the student details(rollnor, name, marks) to insert in the middle :\n");
    scanf("%d%s%f",&n->rollnor,n->name,&n->marks);
    SLL *last=*hptr;
    SLL *mid=*hptr;

    while(last->next!=NULL && last->next->next!=NULL)
    {
        mid=mid->next;
        last=last->next->next;
    }
    if(n->marks <= 100){
    SLL *p=*hptr;
    int flag=0;
    while(p!=NULL)
    {
        if((p->rollnor==n->rollnor) ){
          flag=1;
            break;
        }
        else
            p=p->next;
    }
    if(flag){
        printf("\nEntered student details is already exist so enter new details.\n");
        free(n);
        return;
    }
    else{

    n->next=mid->next;
    mid->next=n;
    }
    }
    else{
         printf("\n Entered marks is greater than 100.\n");
            return;
    }


}
void save_in_file(SLL *hptr)
{
    FILE *fp=fopen("Student_database.txt","a+");
     fprintf(fp,"\n---------------------------------------\n");
    if(hptr==0)
    {
        fprintf(fp,"NO STUDENT RECORDS FOUND TO DISPLAY.\n");
        return;
    }
    SLL *p=hptr;
    int c=0;
    while(p!=NULL)
    {
        fprintf(fp,"%d %s %f\n",p->rollnor,p->name,p->marks);
        c++;
        p=p->next;
    }
    fprintf(fp,"\ncount of records = %d",c);
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
        break;
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

void rotate_node(SLL **hptr)
{
     int pos ;
        if((*hptr==0) || (*hptr)->next==NULL)
     {
         printf("\nNO RECORDS TO ROTATE.\n ");
         return;
     }
     printf("\n Enter the position to rotate nodes : ");
    scanf("%d",&pos);
    int op;
    printf("\n left - 1 right - 0 : \n");
    scanf("%d",&op);

    SLL *last=*hptr;
    int c=1;
    while(last->next!=NULL)
    {
        c++;
        last=last->next;
    }
    last->next=*hptr;


    SLL *p=*hptr;
   pos=pos%c;
   if(op==1){
    for(int i = 1; i <pos; i++)
        p = p->next;
   }
   else{
    for(int i = 1; i <(c-pos); i++)
        p = p->next;
   }

   *hptr=p->next;
   p->next=NULL;
   printf("\n Rotation of node done sucessfully.\n");

}
void topper_student(SLL *hptr)
{
    SLL *p=hptr,*cur=hptr;
    float max=0;
   if(hptr == NULL)
    {
        printf("No student records found.\n");
        return;
    }

    while(p!=NULL)
    {

        if(max< p->marks)
        {
            max=p->marks;
            cur=p;
        }
        p=p->next;
    }

       printf("\n Topper student of the class \n");
    printf("%d %s %f\n",cur->rollnor,cur->name,cur->marks);
}
void failed_student(SLL *hptr)
{
    if(hptr==0)
    {
         printf("No student records found.\n");
        return;
    }
    SLL *p=hptr;

    printf("\n Student how got less than 40 marks.\n");
    while(p!=NULL)
    {
        if(p->marks <=40)
        {
            printf("%d %s %f\n",p->rollnor,p->name,p->marks);
        }
        p=p->next;
    }
}
