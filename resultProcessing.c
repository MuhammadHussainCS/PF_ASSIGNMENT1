#include<stdio.h>
int main(){
int total_students, i = 0;
float maths,phy,eng,pf,icp,avg,sum;
    printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=");
    printf("\n\t\tWELCOME TO RESULT GENEARTOR\n");
    printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=");


    printf("\n\nEnter the details for Student");
    label1:
    printf("\nEnter the marks of Mathematics  : ");
    scanf("%f", &maths);

if(maths<0 || maths>100) {
    printf("\nInvalid Marks Entered[!].Try Again Harder[!]\n");
    goto label1;
}

    label2:
    printf("\nEnter the marks of Physics  : ");
    scanf("%f", &phy);

if(phy<0 || phy>100) {
    printf("\nInvalid Marks Entered[!].Try Again Harder[!]\n");
    goto label2;
}

label3:
    printf("\nEnter the marks of Functional English  : ");
    scanf("%f", &eng);

if(eng<0 || eng>100) {
    printf("\nInvalid Marks Entered[!].Try Again Harder[!]\n");
    goto label3;
}

label4:
    printf("\nEnter the marks of Programming Fundamentals  : ");
    scanf("%f", &pf);

if(pf<0 || pf>100) {
    printf("\nInvalid Marks Entered[!].Try Again Harder[!]\n");
    goto label4;
}

label5:
    printf("\nEnter the marks of Ideology And Constitution Of Pakitan  : ");
    scanf("%f", &icp);

if(icp<0 || icp>100) {
    printf("\nInvalid Marks Entered[!].Try Again Harder[!]\n");
    goto label5;
}

sum = maths + phy + eng + pf + icp;
avg = sum / 5;
printf("\n\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
printf("\t\tGenerating Result....\n");
printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
printf("\nSubject 1 Marks\t: %.2f", maths);
printf("\nSubject 2 Marks\t: %.2f", phy);
printf("\nSubject 3 Marks\t: %.2f", eng);
printf("\nSubject 4 Marks\t: %.2f", pf);
printf("\nSubject 5 Marks\t: %.2f", icp);

int all_sub_pass = 1;
if(maths<33 || phy<33 || eng<33 || pf<33 || icp<33) {
all_sub_pass = 0;
}

if(all_sub_pass == 0) {
printf("\n\nFail Due to subject Deficiency");
} else if(avg>=80) {
printf("\nCongratulations\tDISTINCTION\tAVERAGE = %.2f",avg);
} else if(avg>=60) {
printf("\nGood Work Keep it up\tPASS\tAVERAGE = %.2f", avg);
} else {
printf("\nVery Much Dissapointed.Not expected from your side\tFAIL due to average less than 60. Your AVERAGE IS %.2f", avg);
}

return 0;
}