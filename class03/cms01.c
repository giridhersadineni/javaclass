
#include<stdio.h>
#include<stdlib.h>
void marksmodule();
void informationmodule();
void addmarks();
void showmarks();
void addstudentinfo();
void showstudentinfo();
typedef struct student{
    int roll;
    char name[20];
    char fathername[20];
}student;

typedef struct studentmarks{
    int roll;
    int s1;
    int s2;
    int total;
    float avg;
}studentmarks;
student s;

int main(){
    int ch,smsch,sisch;
    system("clear");
    printf("\nSelect Module");
    printf("\n1. Student Marks System");
    printf("\n2. Student Information System");
    printf("\n9. Exit");
    scanf("%d",&ch);
    switch(ch){
    case 1:
        marksmodule();
        break;
    case 2:
        informationmodule();
        break;
    case 9:
        return 0;
    default:
    printf("\ninvalid Entry , Please Retry");
    main();
    }
    return 0;
}

void marksmodule(){
    int ch;
    printf("\nStudent Marks System");
        printf("\nPress \n 1.Add Marks\n2.Show marks \n9. Go to mainmenu");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            addmarks();        
        break;
        case 2:
            showmarks();
            break;
        case 9:
            main();
        break;       
        default:
        printf("\nInvalid Input");
        break;       
        }
    return;
}
void informationmodule(){
    int ch;
    printf("\nStudent information System");
        printf("\nPress \n 1.Add Student Details\n2.Show Student Details \n9.Go to MainMenu");
        scanf("%d",&ch);
        switch(ch){
              case 1:
              addstudentinfo();
              break;
              case 2:
              showstudentinfo();
              break;
              case 9:
              main();
              break;
              default:
              printf("\nInvalid Input");
              break; 
        }
    return;
}

void addstudentinfo(){
    system("clear");
    printf("\nEnter student RollNo , Name , Father Name");
    scanf("%d%s%s",&s.roll,&s.name,&s.fathername);
    informationmodule();
}
void showstudentinfo(){
    system("clear");
    printf("Student Information");
    printf("\nRoll No : %d",s.roll);
    printf("\nName : %s",s.name);
    printf("\nFather Name : %s",s.fathername);
    informationmodule();
}

void addmarks(){
 return;
}
void showmarks(){
return;
}