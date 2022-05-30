#include<stdio.h>

    void MainMenu();
    void gpa();                   // Function declaration for GPA.
    void cgpa();                  // Function declaration for CGPA.
    void targeted_cgpa();           // Function declaration for Targeted CGPA.
    void Quit();                  // Function declaration for Quit the Program .

int main()
{
    MainMenu();

}

void MainMenu()
{

    int i;

    system("cls");
    printf("\n\n\n\t **** Welcome to Calculate GPA,CGPA & Targeted  ***** \n\n");
    printf("\t      Please Choose an option    \n \n");
    printf("\t\t[1] Calculate GPA .\n \t\t[2] Calculate CGPA .\n \t\t[3] Targeted CGPA. \n \t\t[4] Quit.\n\n\n\n");





    menu:
    printf("\n\t\tInput Your Choice: ");  //Input will ask
    scanf("%d",&i);                       //  Read a valid Input

switch(i)
{
case 1:

    {
        gpa();                            // For GPA
        break;
    }
case 2:
    {
        cgpa();                           // For CGPA
        break;
    }
case 3:
    {
       targeted_cgpa();                     // FOR Targeted CGPA
        break;
    }
case 4:
    {
      Quit();                             // Quit the program
    }
default:
    {
        printf("\n\t\t This is a Wrong Input...Please Input again\n");   // For wrong input it will back to the menu
        goto menu;
    }

    }
}

void gpa()         // Program execution for GPA
{

    int x;
    double grade,point;               // use double for decimal values
    int subject_code,credit;
    double sum =0;
    int Total_Credit=0;
    int a,b;
    system("cls");
    printf("\t***** GPA Calculation *****\n");

    printf("\tSubject Code\tCredit\n");
    printf("\t\____________\t______\n\n");

    printf("\t \t1111\t      2 \n");
    printf("\t \t2222\t      3 \n");
    printf("\t \t3333\t      3 \n");
    printf("\t \t4444\t      3 \n");
    printf("\t \t5555\t      4 \n");                                   //display course & credits and Grade menu
    printf("\t \t6666\t      4 \n");
    printf("\t \t7777\t      4 \n");
    printf("\t \t8888\t      4 \n");


    course:
    printf("How many courses Have you taken?\nAnswer: ");
    scanf("%d",&a);                                                     // Input for Course taken

    for(b=0;b<a;b++)
    {
        code:
        printf("\n\nInput you Subject code for Course %d : ",b+1);
        scanf("%d",&subject_code);                                      // Input for Subject code
    if(subject_code==1111)
    {
        credit =2;                                                     // for subject code 1111  credit is 2
    }
    else if(subject_code==2222||3333||4444)
    {
        credit=3;                                                     // for subject code 2222,3333 &4444 credit is 3
    }
    else if(subject_code==5555||6666||7777||8888)
    {
        credit = 4;                                                   // for subject code 5555,66666,7777,8888 credit is 4
    }

    else
    {
    printf("\nWrong Input......Input Subject code again....\n");
        goto code;                                                   // if subject code is wrong then it will restart again from the input of subject code
    }
    grade:
    printf("\nInput Your Grade for Subject Code %d : ",subject_code);
    scanf("%lf",&grade);                                             // Input for grade for each Subjects

    if(grade>4)                                                      // Grading system is 4
    {
    printf("\nWrong Input.....");
    goto grade;                                                      // as grading is 4 if input is not valid then it will ask again
    }


    Total_Credit=credit+Total_Credit;                               // Formula for total credit

    if(Total_Credit>22)
    {
    printf("\nYou can not input for more than 22 credits\n");       // Maximum credit input
    break;
    }
    x=credit*grade;                                               // grade point  * course credit
    sum=sum+x;
    }

     if(Total_Credit<8)
    {
    printf("\nYou can not input for less than 8 credits\nPlease Calculate again\n");
    Total_Credit=0;
    sum=0;
    x=0;
    goto course;
    }

    point=sum/Total_Credit; // formula of GPA

    printf("\nYour GPA is: %.2lf\n\n",point);

    system("PAUSE");
    MainMenu();

}

void cgpa()                                                           // program for CGPA
{
    int semester,i,tcredit;
    double ccgpa;                                                    // use double for decimal value
    double y;
    double sum_of_point=0;
    int Sum_of_Credit=0;
    double sem_gpa;
    system("cls");
    printf("***** Calculation of CGPA ***** \n");

    printf("\n How many Semester Have you completed?\nAnswer: ");
    scanf("%d",&semester);                                          // read the number semester have been completed
    i=0;
    while(i<semester)
    {   sem:
        printf("\nInput GPA for Semester %d: ",i+1);
        scanf("%lf",&sem_gpa);                                     // read the input for GPA for semester
    if (sem_gpa>4)
    {
        printf("\nYou can not Input more than 4 as GPA");
        goto sem;
    }
        t:
    printf("\nInput Total credit for semester %d: ",i+1);
    scanf("%d",&tcredit);

        if(tcredit<8||tcredit>22)
        {
            printf("\nYou must need to input within 8 to 22 as credit......");
            goto t;
        }
    y=sem_gpa*tcredit;

    Sum_of_Credit=Sum_of_Credit+tcredit;
    sum_of_point=sum_of_point+y;
    i++;
    }

   ccgpa=sum_of_point/Sum_of_Credit;                 // formula for calculate the CGPA

   printf("\nYour CGPA is : %lf",ccgpa);
   system("PAUSE");
   MainMenu();

}

void targeted_cgpa()                                   // program start of targeted cgpa
{

    double currentcgpa;
    int takencredit;
    double targetedcgpa;
    int sem_credit;
    double x,tgpa;

    system("cls");

    printf("***** Calculate the minimum GPA for targeted CGPA ***** \n");
    printf("\nHow many credit Have you completed?\nAnswer: ");
    scanf("%d",&takencredit);                                               // read the input for completed credit
    printf("\nInput Your Current CGPA: ");
    scanf("%lf",&currentcgpa);

    printf("\n\n How many credits have you Taken This semester? : ");
    scanf("%d",&sem_credit);
    printf("\n What is Targeted CGPA? : ");
    scanf("%lf",&targetedcgpa);

    x=((takencredit+sem_credit)*targetedcgpa) - (takencredit*currentcgpa);

    tgpa=x/sem_credit;                                                      // formula for targeted CGPA

    printf("\n\n Your Targeted GPA must need for upcoming semester is %.2lf in minimum to achieve you targeted CGPA\n\n",tgpa);
    system("PAUSE");
    MainMenu();


}
void Quit()
{
    system ("cls");
    printf("\nThank you for choosing us");
    exit(0);
}
