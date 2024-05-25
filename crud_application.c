#include<stdio.h>
#include<string.h>
void addstudent();
void editstudent();
void deletestudent();
//void searchstudent();
void displaylistofstudents();

int numberOfstudentsAdded;
struct student
{
    int rollnumber;
    char name[22];


};
struct student s[100];
int main()
{

    int ch;
    numberOfstudentsAdded=0;
    while(1)
    {
    printf("1. Add student :\n");
    printf("2. Edit student :\n");
    printf("3. Delete student :\n");
    printf("4. Search student :\n");
    printf("5. Display list of students :\n");
    printf("6. exit\n");
    printf("Enter your choice :");
    scanf("%d",&ch);
     fflush(stdin);
    if(ch<1 || ch>6)
    {
        printf("Invalid choice\n :");
        continue;       
    }
    if(ch==1) addstudent();
    if(ch==2) editstudent();
    if(ch==3) deletestudent();
    //if(ch==4) searchstudent();
    if(ch==5) displaylistofstudents();
    if(ch==6) break;
  }
    return 0;
}

void addstudent()
{
    int vrollnumber;
    char vName[22];
    int e;
    char m;
    printf("Enter roll number :");
    scanf("%d",&vrollnumber);
    fflush(stdin);
    if(vrollnumber<=0)
    {
        printf("Invalid roll number :");
        return ;
    }
    e=0;
    while(e<numberOfstudentsAdded)
    {
        if(vrollnumber==s[e].rollnumber)
        {
            printf("That roll number assigned to %s student :\n",s[e].name);
            return ;
        }
        e++;

    }
    printf("Enter name :");
    fgets(vName,22,stdin);
    vName[strlen(vName)-1]='\0';
    fflush(stdin);
    printf("Save Y/N :");
    m=getchar();
    if(m!='y'&&m!='Y')
    {
        printf("Student not added :\n");
        return ;
    }
    s[numberOfstudentsAdded].rollnumber=vrollnumber;
    strcpy(s[numberOfstudentsAdded].name,vName);
    numberOfstudentsAdded++;
    fflush(stdin);
    printf("Student added successfully \n");
    printf("Press enter to continue :\n");
    getchar();
    fflush(stdin);


}
void editstudent()
{
    int found,e;
    char m;
    int vrollnumber;
    char vName[22];
    printf("Student (edit module)\n");
    printf("Enter roll number to edit :");
    scanf("%d",&vrollnumber);
    fflush(stdin);
    if(vrollnumber<=0)
    {
        printf("Invalid roll number ");
        return ;
    }
    found=0;
    e=0;
    while(e<numberOfstudentsAdded)
    {
        if(vrollnumber==s[e].rollnumber)
        {
            found=1;
            break;
        }
        e++;
    }
    if(found==0)
    {
        printf("Invalid roll number try again........");
        return ;
    }
    printf("Name %s\n",s[e].name);
    printf("Edit Y/N :\n");
    m=getchar();
    fflush(stdin);
    if(m!='y'&&m!='Y')
    {
        printf("Student not edited.... ");
        return ;
    }
    printf("Enter new name \n");
    fgets(vName,22,stdin);
    fflush(stdin);
    vName[strlen(vName)-1]='\0';
    printf("Want to update information regarding name of student Y/N :\n ");
    m=getchar();
    fflush(stdin);
    if(m!='y'&&m!='Y')
    {
        printf("Information not updated");
        return ;
    }
    printf("Previous name : %s\n",s[e].name);
    strcpy(s[e].name,vName);
    printf("Updated name : %s\n",s[e].name);
    printf("Press enter to continue...... ");
    getchar();
    fflush(stdin);



}
void deletestudent ()
{
    int vrollnumber,ep;
    char m;
    char vname[22];
    int found,e;
    printf("Student (delete module) ");
    printf("Enter roll number: ");
    scanf("%d",&vrollnumber);
    fflush(stdin);
    if(vrollnumber<=0)

    {
        printf("Invalid roll number ");
        return ;

    }
    e=0;
    found=0;
    while(e<numberOfstudentsAdded)
    {
        if(vrollnumber==s[e].rollnumber)
        {
            found=1;
            break;
        }
        e++;
    }
    printf("Name : %s\n ",s[e].name);
    printf("Want to delete Y/N:\n");
    m=getchar();
    fflush(stdin);
    if(m!='y'&&m!='Y')
    {
        printf("Invalid action\n");
        return ;
    }
    ep=numberOfstudentsAdded-2;
    while(e<=ep)
    {
        s[e].rollnumber=s[e+1].rollnumber;
        strcpy(s[e].name,s[e+1].name);
        e++;
    }
    numberOfstudentsAdded--;
    printf("Student deleted press enter to continue  ");
    getchar();
    fflush(stdin);



    

}
//void searchstudent()
//{//

//}
void displaylistofstudents()
{
    int f;
    printf("Students (display module)\n");
    f=0;
    while(f<numberOfstudentsAdded)
    {
        printf("Name : %s \n Rollnumber : %d\n",s[f].name,s[f].rollnumber);
        f++;
    }
    printf("Press enter to continue....");
    getchar();
    fflush(stdin);


}