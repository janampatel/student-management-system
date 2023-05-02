#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct student
{
    char name[20];
    int roll_no;
    long int phone_no;
    int y,m,d;
    char email[30];
    char address[100];
    char lastschool[20];
    int current_sem;
    float sem_pr;

    struct student* prev;
    struct student* next;
};
FILE *fp = NULL;
struct student* head = NULL;

void insertstudent(){

    fp=fopen("test.txt","a+");
    
    struct student* st = (struct student*)malloc(sizeof(struct student));
    struct student* ptr,*p,*q;
    printf("Enter Name of student : ");
    scanf("\n");
    gets(st->name);
    fprintf(fp,"Name: %s\n",st->name);
   
    printf("Enter Roll number of student : ");
    scanf("%d",&st->roll_no);
    fprintf(fp,"Roll No: %d\n",st->roll_no);
    
    printf("Enter Date of birth of student\nYear : ");
    scanf("%d",&st->y);
    printf("Month : ");
    scanf("%d",&st->m);
    printf("Day : ");
    scanf("%d",&st->d);
    fprintf(fp,"DOB: %d/%d/%d\n",st->d,st->m,st->y);
    
    printf("Enter Contact number of student : ");
    scanf("%ld",&st->phone_no);
    fprintf(fp,"Contact Number: %ld\n",st->phone_no);
    
    printf("Enter address of student : ");
    scanf("\n");
    gets(st->address);
    fprintf(fp,"Address: %s\n",st->address);
    
    printf("Enter email address of student : ");
    scanf("%s",st->email);
    fprintf(fp,"Email: %s\n",st->email);
    
    printf("Enter name of last school attended: ");
    scanf("\n");
    gets(st->lastschool);
    fprintf(fp,"Name of last school: %s\n",st->lastschool);
    
    printf("Enter current semester of student : ");
    scanf("%d",&st->current_sem);
    fprintf(fp,"Current semester: %d\n",st->current_sem);
    
    printf("Enter percentage(last sem) of student : ");
    scanf("%f",&st->sem_pr);
    fprintf(fp,"Percentage(last sem): %f\n\n\n",st->sem_pr);
    
    if(head==NULL){
        head=st;
        st->prev=NULL;
        st->next=NULL;
    }
    else
    {
        ptr = head;
        while((st->roll_no > ptr->roll_no) && ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        p = ptr->prev;
        if(ptr = head)
        {
            st->next = head;
            st->prev = NULL;
            head->prev = st;
            head = st;
        }
        else if((ptr->next==NULL)&&((st->roll_no > ptr->roll_no)))
        {
            st->prev = ptr;
            st->next = NULL;
            ptr->next = st;
        }
        else
        {
            st->next = ptr;
            st->prev = p;
            p->next = st;
            ptr->prev = st;
        }
    }

     printf("STUDENT REGISTRATION HAS BEEN DONE SUCCESSFULLY!!\n\n");
}

void removestudent()
{
    struct student* ptr = head,*m=NULL,*n=NULL;
    int r;
    printf("ENTER STUDENT'S ROLL NO YOU WANT TO REMOVE : ");
    scanf("%d",&r);
    
    while(ptr->roll_no != r)
    {
        ptr=ptr->next;
    }
    
    m=ptr->prev;
    n=ptr->next;
    if(ptr==head && n!=NULL){
        head=head->next;
        head->prev=NULL;
    }
    else if(n==NULL && m!=NULL){
        m->next=NULL;
    }
    else if(n==NULL && m==NULL){
        head=NULL;
        printf("List is empty\n");

    }
    else{
    m->next = n;
    n->prev = m;
    }
    printf("DATA HAS BEEN DELETED SUCCESSFULLY!!\n\n");
}

void filter()
{
    if(head==NULL)
        {
            printf("List is empty\n");
            return;
        }
    int c,da,mo,ye;
    printf("1.by name\n2.by D.O.B\n");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
        {
        char str[20];
        struct student * q = head;
        
        printf("ENTER THE NAME OF STUDENT YOU WANT TO SEARCH : ");
        scanf("\n");
        gets(str);
        
        printf(" ===============================================================================================================================================================\n");
        printf("|ROLL NO  |    NAME   |         EMAIL            |  D.O.B   |   CONTACT   |          ADDRESS              |PREVIOUS SCHOOL |CURRENT SEM  | PERCENTAGE(LAST SEM)|\n");
        printf(" ===============================================================================================================================================================\n");
        label2:
        
        if(strcmp(str,q->name)==0)
        {
            if(q->next==NULL)
            {
                printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->roll_no,q->name,q->email,q->d,q->m,q->y,q->phone_no,q->address,q->lastschool,q->current_sem,q->sem_pr);
                printf(" ---------------------------------------------------------------------------------------------------------------------------------------------------------------");
                return;
            }
            else
            {
                printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->roll_no,q->name,q->email,q->d,q->m,q->y,q->phone_no,q->address,q->lastschool,q->current_sem,q->sem_pr);
                q=q->next;
                goto label2;
            }
        }
        
        else
        {
            if(q->next==NULL){return;}
            q=q->next;
            goto label2;
        }
        }
        
        case 2:
        {  
            printf("1 .BY MONTH\n");
            printf("2 .BY YEAR\n");
            printf("ENTER CHOICE: ");
            scanf("%d",&da);
            struct student* q = head;
            switch(da)
            {
                case 1:
                {
                printf("Enter month of birth date: ");
                scanf("%d",&mo);
                printf(" ===============================================================================================================================================================\n");
                printf("|ROLL NO  |    NAME   |         EMAIL            |  D.O.B   |   CONTACT   |          ADDRESS              |PREVIOUS SCHOOL |CURRENT SEM  | PERCENTAGE(LAST SEM)|\n");
                printf(" ===============================================================================================================================================================\n");
                label3:
                if(q->m==mo)
                {
                     if(q->next==NULL)
                    {
                        printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->roll_no,q->name,q->email,q->d,q->m,q->y,q->phone_no,q->address,q->lastschool,q->current_sem,q->sem_pr);
                        printf(" ---------------------------------------------------------------------------------------------------------------------------------------------------------------");
                        return;
                    }
                    else
                    {
                        printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->roll_no,q->name,q->email,q->d,q->m,q->y,q->phone_no,q->address,q->lastschool,q->current_sem,q->sem_pr);
                        q=q->next;
                        goto label3;
                    }
                }
                else
                {
                    if(q->next==NULL){return;}
                    q=q->next;
                    goto label3;
                }
                }
                
                case 2:
                {
                printf("Enter year of birth date : ");
                scanf("%d",&ye);
                printf(" ===============================================================================================================================================================\n");
                printf("|ROLL NO  |    NAME   |         EMAIL            |  D.O.B   |   CONTACT   |          ADDRESS              |PREVIOUS SCHOOL |CURRENT SEM  | PERCENTAGE(LAST SEM)|\n");
                printf(" ===============================================================================================================================================================\n");
                label4:
                if(q->y==ye)
                {
                     if(q->next==NULL)
                    {
                        printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->roll_no,q->name,q->email,q->d,q->m,q->y,q->phone_no,q->address,q->lastschool,q->current_sem,q->sem_pr);
                        printf(" ---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
                        return;
                    }
                    else
                    {
                        printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->roll_no,q->name,q->email,q->d,q->m,q->y,q->phone_no,q->address,q->lastschool,q->current_sem,q->sem_pr);
                        q=q->next;
                        goto label4;
                    }
                }
                else
                {
                    if(q->next==NULL){return;}
                    q=q->next;
                    goto label4;
                }
                }
            }
        }
    }
}
void displaylist()
{   
    fp=fopen("test.txt","a+");
    struct student * q = head;
    if(q==NULL){
        printf("List is empty\n");
    }
    else{
    while(q != NULL)
    {
        if(head->next==NULL){
        printf(" ===============================================================================================================================================================\n");
        printf("|ROLL NO  |    NAME   |         EMAIL            |  D.O.B   |   CONTACT   |          ADDRESS              |PREVIOUS SCHOOL |CURRENT SEM  | PERCENTAGE(LAST SEM)|\n");
        printf(" ===============================================================================================================================================================\n");
        printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->roll_no,q->name,q->email,q->d,q->m,q->y,q->phone_no,q->address,q->lastschool,q->current_sem,q->sem_pr);
        printf(" ---------------------------------------------------------------------------------------------------------------------------------------------------------------");

        fprintf(fp," ===============================================================================================================================================================\n");
        fprintf(fp,"|ROLL NO  |    NAME   |         EMAIL            |  D.O.B   |   CONTACT   |          ADDRESS              |PREVIOUS SCHOOL |CURRENT SEM  | PERCENTAGE(LAST SEM)|\n");
        fprintf(fp," ===============================================================================================================================================================\n");
        fprintf(fp,"| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->roll_no,q->name,q->email,q->d,q->m,q->y,q->phone_no,q->address,q->lastschool,q->current_sem,q->sem_pr);
        fprintf(fp," ---------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        
        }
        
        else if(q==head){
        printf(" ===============================================================================================================================================================\n");
        printf("|ROLL NO  |    NAME   |         EMAIL            |  D.O.B   |   CONTACT   |          ADDRESS              |PREVIOUS SCHOOL |CURRENT SEM  | PERCENTAGE(LAST SEM)|\n");
        printf(" ===============================================================================================================================================================\n");
        printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->roll_no,q->name,q->email,q->d,q->m,q->y,q->phone_no,q->address,q->lastschool,q->current_sem,q->sem_pr);

        fprintf(fp," ===============================================================================================================================================================\n");
        fprintf(fp,"|ROLL NO  |    NAME   |         EMAIL            |  D.O.B   |   CONTACT   |          ADDRESS              |PREVIOUS SCHOOL |CURRENT SEM  | PERCENTAGE(LAST SEM)|\n");
        fprintf(fp," ===============================================================================================================================================================\n");
        fprintf(fp,"| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->roll_no,q->name,q->email,q->d,q->m,q->y,q->phone_no,q->address,q->lastschool,q->current_sem,q->sem_pr);

        
        
        }
        
        
        else if(q->next==NULL){
        printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->roll_no,q->name,q->email,q->d,q->m,q->y,q->phone_no,q->address,q->lastschool,q->current_sem,q->sem_pr);
        printf(" --------------------------------------------------------------------------------------------------------------------------------------------------------------");        

        fprintf(fp,"| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->roll_no,q->name,q->email,q->d,q->m,q->y,q->phone_no,q->address,q->lastschool,q->current_sem,q->sem_pr);
        fprintf(fp," --------------------------------------------------------------------------------------------------------------------------------------------------------------\n");        

        }
        else{
        printf("| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->roll_no,q->name,q->email,q->d,q->m,q->y,q->phone_no,q->address,q->lastschool,q->current_sem,q->sem_pr);
        fprintf(fp,"| %-8d| %-10s| %-25s|%-2d-%-2d-%-4d| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->roll_no,q->name,q->email,q->d,q->m,q->y,q->phone_no,q->address,q->lastschool,q->current_sem,q->sem_pr);

        }
        
        q=q->next;
    }
    printf("\n\n");
    }
    fclose(fp);
}

    
void searchbyroll_no()
{
    int s;
    struct student * q = head;
    printf("ENTER THE ROLL NO OF STUDENT YOU WANT TO SEARCH : ");
    scanf("%d",&s);
    while(q->roll_no != s)
    {
        q = q->next;
    }
    
        printf(" ====================================================================================================================================================\n");
        printf("|ROLL NO   |    NAME   |         EMAIL            |   CONTACT   |          ADDRESS              |PREVIOUS SCHOOL |CURRENT SEM  | PERCENTAGE(LAST SEM)|\n");
        printf(" ====================================================================================================================================================\n");
        printf("| %-10d| %-10s| %-25s| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->roll_no,q->name,q->email,q->phone_no,q->address,q->lastschool,q->current_sem,q->sem_pr);
        printf(" ----------------------------------------------------------------------------------------------------------------------------------------------------\n");
        printf("\n\n");
}



void searchbyname(){
    char str[20];
    struct student * q = head;
    printf("ENTER THE NAME OF STUDENT YOU WANT TO SEARCH : ");
    scanf("\n");
    gets(str);
    int j=0;
    while(q!=NULL){
    int i = strcmp(q->name,str);
    

    if(i!=0){
        
        q=q->next;
    }
    
    else if(i==0){
        printf(" ===================================================================================================================================================\n");
        printf("|ROLL NO  |    NAME   |         EMAIL            |   CONTACT   |          ADDRESS              |PREVIOUS SCHOOL |CURRENT SEM  | PERCENTAGE(LAST SEM)|\n");
        printf(" ===================================================================================================================================================\n");
        printf("| %-8d| %-10s| %-25s| %-12ld| %-30s| %-15s| %-12d| %-20f|\n",q->roll_no,q->name,q->email,q->phone_no,q->address,q->lastschool,q->current_sem,q->sem_pr);
        printf(" ---------------------------------------------------------------------------------------------------------------------------------------------------\n");
            printf("\n\n");
    break;    
    }
    
    }
}    

int main()
{
    fp = fopen("test.txt","w+");
    
    
    printf("__________________________________________________________________________________________|\n");
    printf("|                                                                                         |\n");
    printf("|                                                                                         |\n");
    printf("|                        |=====================================|                          |\n");
    printf("|=======================<  WELCOME TO STUDENT DATABASE SYSTEM   >=========================|\n");
    printf("|                        |=====================================|                          |\n");
    printf("|                            BY: 21BCE197,21BCE198,21BCE199                               |\n");
    printf("|_________________________________________________________________________________________|\n\n\n");

    fprintf(fp,"__________________________________________________________________________________________|\n");
    fprintf(fp,"|                                                                                         |\n");
    fprintf(fp,"|                                                                                         |\n");
    fprintf(fp,"|                        |=====================================|                          |\n");
    fprintf(fp,"|=======================<  WELCOME TO STUDENT DATABASE SYSTEM   >=========================|\n");
    fprintf(fp,"|                        |=====================================|                          |\n");
    fprintf(fp,"|                            BY: 21BCE197,21BCE198,21BCE199                               |\n");
    fprintf(fp,"|_________________________________________________________________________________________|\n\n\n");
   fclose(fp);
    int c,s;

    label:
        
        printf("________________________________________\n");
        printf("| 1 | To add a student                  |\n");
        printf("|---|-----------------------------------|\n");
        printf("| 2 | To remove student                 |\n");
        printf("|---|-----------------------------------|\n");
        printf("| 3 | To display entire list of students|\n");
        printf("|---|-----------------------------------|\n");
        printf("| 4 | To search a specific student      |\n");
        printf("|---|-----------------------------------|\n");
        printf("| 5 | To Filter                         |\n");
        printf("|---|-----------------------------------|\n");
        printf("| 6 | To Exit                           |\n");
        printf("|___|___________________________________|\n");
        printf("\nENTER YOUR CHOICE : ");
        scanf("%d",&c);
        printf("\n\n");
        switch(c)
        {
            case 1:
                
                insertstudent();
            break;
            
            case 2:
                removestudent();
            break;
            
            case 3:
                displaylist();
            break;
            
            case 4:
            {
                printf("1.BY ROLL NO\n2.BY NAME\nENTER YOUR CHOICE : ");
                scanf("%d",&s);
                if(s==1)
                    searchbyroll_no();
                else if(s==2)
                    searchbyname();
            }
            break;
            
            case 5:
                filter();
            break;
            
            case 6:
                return 0;
            break;

        }
         
        goto label;
}