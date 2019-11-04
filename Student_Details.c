#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct details
{
    int semester;
    float pointer;
    long long int contact_number;
    char name[30],address[200],id[10];
    struct details *next;
}*start=NULL;
void add_student()
{
    struct details *newnode, *temp;
    int i;
    newnode=(struct details *)malloc(sizeof(struct details));
    fflush(stdin);
    printf("\nEnter the id of the student:");
    gets(newnode->id);
    fflush(stdin);
    printf("\nEnter the Name of the student:");
    gets(newnode->name);
    fflush(stdin);
    printf("\nEnter the Semester of the student:");
    scanf("%d",&newnode->semester);
    fflush(stdin);
    printf("\nEnter the average pointer of the student:");
    scanf("%f",&newnode->pointer);
    fflush(stdin);
    printf("\nEnter the contact number of the student:");
    scanf("%10lld",&newnode->contact_number);
    fflush(stdin);
    printf("\nEnter the address of the student:");
    gets(newnode->address);
    newnode->next=NULL;
    if(start==NULL)
    {
        start=newnode;
    }
    else
    {
        temp=start;
        while(temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void display()
{
    struct details *temp;
    int i;
    if(start==NULL)
    {
        printf("No records found");
    }
    else
    {
        temp=start;
        printf("\nID \t \t NAME \t \t   SEMESTER \t \t average POINTER \t \t CONTACT NUMEBER \t ADDRESS\n");
        printf("__________________________________________________________________________________________________________________________________________________\n");
        while(temp !=NULL)
        {
            printf("%s",temp->id);
            printf(" \t");
            printf("%s",temp->name);
            printf(" \t");
            printf("   %d \t \t \t",temp->semester);
            printf("   %.02f \t \t",temp->pointer);
            printf("\t     %lld",temp->contact_number);
            printf("\t \t  ");
            puts(temp->address);
            temp=temp->next;
        }
    }
}
void delete_student()
{
    struct details *temp,*temp1;
    char id[20];
    if(start==NULL)
    {
        printf("RECORDS DONOT EXIT");
    }
    else
    {
        printf("Enter student ID:");
        gets(id);
        if(strcmpi(start->id,id)==0)
        {
            temp=start->next;
            free(start);
            start=temp;
        }
        else
        {
            temp=start;
            while (temp != NULL && (strcmpi(temp->id,id)!=0))
            {
                temp1=temp;
                temp=temp->next;
            }
            if(temp==NULL)
            {
                printf("\nNO RECORDS FOUND FOR ENTERD ID.");
                return;
            }
            else
            {
                temp1->next=temp->next;
                free(temp);
            }
        }   
    }
}
void search_student()
{
    struct details *temp;
    char id[10];
    int i;
    if(start==NULL)
    {
        printf("\nRECODRS DO NOT EXSIST");
        return;
    }
    else
    {
        printf("\nEnter the id to be searched");
        gets(id);
        temp=start;
        while(temp !=NULL && (strcmpi(id,temp->id) !=0))
        {
            temp=temp->next;
        }
        if(temp ==NULL)
        {
            printf("\nNO RECORDS FOUND FOR ENTERED ID.");
            return;
        }
        else
        {   
            printf("\nID \t \t NAME \t \t   SEMESTER \t \t average POINTER \t \t CONTACT NUMEBER \t ADDRESS\n");
            printf("__________________________________________________________________________________________________________________________________________________\n");
            printf("%s",temp->id);
            printf(" \t");
            printf("%s",temp->name);
            printf(" \t");
            printf("   %d \t \t \t",temp->semester);
            printf("   %.02f \t \t",temp->pointer);
            printf("\t     %lld",temp->contact_number);
            printf("\t \t  ");
            puts(temp->address);
        }
    }
}
void modify_student()
{
    struct details *temp;
    char id[20];
    int i,n;
    if(start==NULL)
    {
        printf("\nRECORDS DONOT EXSIST");
        return;
    }
    else
    {
        printf("\nEnter the id to be modified");
        gets(id);
        temp=start;
        while(temp !=NULL && (strcmpi(id,temp->id) !=0))
        {
            temp=temp->next;
        }
        if(temp ==NULL)
        {
            printf("\nNO RECORDS FOUND FOR ENTERED ID.");
            return;
        }
        else
        {
            printf("\nEnter 1 to change name.");
            printf("\nEnter 2 to change semester.");
            printf("\nEnter 3 to change pointer.");
            printf("\nEnter 4 to change phone number.");
            printf("\nEnter 5 to change address.");
            printf("\nEnter your choice");
            scanf("%d",&n);
            switch (n)
            {
            case 1:
                printf("Enter new name:");
                gets(temp->name);
                break;
            case 2:
                printf("Enter updated semester:");
                scanf("%d",&temp->semester);
                break;
            case 3:
                printf("Enter new pointer:");
                scanf("%f",&temp->pointer);
                break;    
            case 4:
                printf("Enter updated phone number:");
                scanf("%10lld",&temp->contact_number);
                break;
            case 5:
                printf("Enter new address:");
                gets(temp->address);
                break;    
            default:printf("INVALID INPUT");
                break;
            }
        }  
    }
}
void export()
{
    struct details *temp;
    FILE *fp;
    if(start==NULL)
    {
        printf("\nNO RECORDS EXSIST");
        return;
    }
    else
    {
        fp=fopen("record.txt","w+");
        temp=start;
        fprintf(fp,"\nID \t \t NAME \t \t   SEMESTER \t \t average POINTER \t \t CONTACT NUMEBER \t ADDRESS\n");
        fprintf(fp,"__________________________________________________________________________________________________________________________________________________\n");
        while(temp !=NULL)
        {
            fprintf(fp,"%s",temp->id);
            fprintf(fp," \t");
            fprintf(fp,"%s",temp->name);
            fprintf(fp," \t");
            fprintf(fp,"   %d \t \t \t",temp->semester);
            fprintf(fp,"   %.02f  \t \t",temp->pointer);
            fprintf(fp,"\t     %lld",temp->contact_number);
            fprintf(fp,"\t \t  ");
            fputs(temp->address,fp);
            frpintf(fp,"\n");
            temp=temp->next;
        }
    }
}    
void menu()
{
    int ch;
    do
    {
        printf("\nEnter 1 to Add new student details");
        printf("\nEnter 2 to Show the list");
        printf("\nEnter 3 to Delete student details");
        printf("\nEnter 4 to Search student details");
        printf("\nEnter 5 to Modify student details");
        printf("\nEnter 6 to Export details to file");
        printf("\nEnter 7 to Exit");
        printf("\nEnter your choice");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            add_student();
            break;
        case 2:
            display();
            break;
        case 3:
            fflush(stdin);
            delete_student();
            break;
        case 4:
            fflush(stdin);
            search_student();
            break;
        case 5:
            fflush(stdin);
            modify_student();
            break;
        case 6:
            fflush(stdin);
            export();
            break;
        case 7:
            printf("THANK YOU :)");
            break;
        default: printf("INALID INPUT");
            break;
        }
    } while (ch != 7); 
}
int main()
{
    menu();
}
