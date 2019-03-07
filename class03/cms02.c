#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void marksmodule();
void informationmodule();
void addmarks();
void showmarks();
void addstudentinfo();
void showstudentinfo();
void markscalculate(int roll);
void showallstudents();
void showallmarks();
void showresult();
void writetomarks();
void writetostudents();
void search(char *string,char *file);
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

//Global Variables
student s[100];
studentmarks m[100];

int main(){
    int ch,smsch,sisch;
    system("clear");
    search("1","students.txt");

    printf("\nSelect Module");
    printf("\n1. Student Marks System");
    printf("\n2. Student Information System");
    printf("\n3. Show Result");
    printf("\n9. Exit");
    scanf("%d",&ch);
    switch(ch){
    case 1:
        marksmodule();
        break;
    case 2:
        informationmodule();
        break;
        case 3:
        showresult();
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
        printf("\nPress \n1.Add Marks\n2.Show marks");
        printf("3.Show All Marks \n9. Go to mainmenu");
        scanf("%d",&ch);
        switch(ch){
        case 1:
            addmarks();        
        break;
        case 2:
            showmarks();
            break;
        case 3:
            showallmarks();
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
        printf("\nPress \n 1.Add Student Details\n2.Show Student Details \n3.Show All Students");
        printf("\n9.Go to MainMenu");
        scanf("%d",&ch);
        switch(ch){
              case 1:
              addstudentinfo();
              break;
              case 2:
              showstudentinfo();
              break;
              case 3:
              showallstudents();
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
    int roll;
    printf("\nEnter student RollNo , Name , Father Name");
    scanf("%d",&roll);
    s[roll-1].roll=roll;
    scanf("%s",&s[roll-1].name);
    scanf("%s",&s[roll-1].fathername);
    writetostudents();
    informationmodule();
}
void showstudentinfo(){
    system("clear");
    int roll;
    printf("Student Information");
    printf("Please enter the roll no of the student");
    scanf("%d",&roll);
    printf("\nName : %s",s[roll-1].name);
    printf("\nFather Name : %s",s[roll-1].fathername);
    informationmodule();
}
void showallstudents(){
    int i;
    system("clear");
    printf("Roll\tStudent Name\tFather Name");
    for(i=0;i<100;i++){
        if(!(s[i].roll==0)){
        printf("\n%d\t%s\t%s",s[i].roll,s[i].name,s[i].fathername);
        }
    }

}

void showallmarks(){
    int i;
    system("clear");
    printf("Roll\tSub 1\tSub2");
    for(i=0;i<100;i++){
        if(!(m[i].roll==0)){
            printf("\n%d\t%d\t%d\t%d\t%f",m[i].roll,m[i].s1,m[i].s2,m[i].total,m[i].avg);
        }
        
    }

}



void addmarks(){
    
    system("clear");
    int roll;
    printf("\nEnter student RollNo , Two subject marks ");
    scanf("%d",&roll);
    roll=roll-1;
    m[roll].roll=roll;
    scanf("%d%d",&m[roll].s1,&m[roll].s2);
    markscalculate(roll);
    writetomarks();
    printf("Done");
    marksmodule();

 return;
}
void showmarks(){
    int roll;
    system("clear");
    printf("\nenter rollno : ");
    scanf("%d",&roll);
    roll=roll-1;
    printf("\nStudent Marks");
    printf("\nRoll No : %d ",++m[roll].roll);
    printf("\nSub1 Marks  : %d ",m[roll].s1);
    printf("\nSub2 Marks : %d ",m[roll].s2);
    printf("\nTotal: %d",m[roll].total );
    printf("\nAverage: %f",m[roll].avg );
    marksmodule(roll);
}
void markscalculate(int roll){
    m[roll].total=m[roll].s1+m[roll].s2;
    m[roll].avg=(m[roll].s1+m[roll].s2)/2;
}

void showresult(){
    int i;
    printf("Roll No\tName\tFatherName\ts1\ts2\ttotal\tavg\n");
    printf("_______________________________________________");
    for(i=0;i<100;i++)
    {
        printf("\n%d\t%s\t%s\t%d\t%d\t%d\t%f",s[i].roll,s[i].name,s[i].fathername,m[i].s1,m[i].s2,m[i].total,m[i].avg);
    }
    main();
}


void writetomarks(){
    int i;
    FILE *marksfile;
    marksfile=fopen("marks.txt","w");
    for(i=0;i<100;i++){
        fprintf(marksfile,"\n%d\t%d\t%d\t%d\t%f",m[i].roll,m[i].s1,m[i].s2,m[i].total,m[i].avg);
    }
    fclose(marksfile);
    return;
}
void writetostudents(){
    int i;
    FILE *studentsfile;
    studentsfile=fopen("students.txt","w");
    for(i=0;i<100;i++){
        fprintf(studentsfile,"\n%d\t%s\t%s",s[i].roll,s[i].name,s[i].fathername);
    }
    fclose(studentsfile);
    return;
}

void search(char *string,char *file){
    char cmd[100];
    strcat(cmd,"grep ");
    strcat(cmd,string);
    strcat(cmd," ");
    strcat(cmd,file);
    system(cmd);
}