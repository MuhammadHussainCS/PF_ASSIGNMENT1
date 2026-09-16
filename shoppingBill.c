#include<stdio.h>
int main(){
    printf("==================================================\n");
    printf("           E-SHOP SMART BILLING SYSTEM         \n");
    printf("==================================================\n");
    printf("  Welcome! We are thrilled to have you shop with us.\n");
    printf("  Let's calculate your order total in a few easy steps.\n");
    printf("--------------------------------------------------\n\n");

    int quantity;
    double price;
    float discount_percentage;
    float tax_percentage;

    label1:
    printf("\nEnter the quantity of products purchased : ");
    scanf("%d", &quantity);
    if(quantity<=0) {
        printf("\nInvalid Number Of Products Entered[!]\n");
        goto label1;
    }

    label2:
    printf("\nEnter the price per item : ");
    scanf("%lf", &price);
    if(price<=0) {
        printf("\nInvalid Price Entered[!]\n");
        goto label2;
    }

    label3:
    printf("\nEnter the discount percentage (%%) : ");
    scanf("%f", &discount_percentage);
    if(discount_percentage<=0 || discount_percentage>=20) {
        printf("\nInvalid Discount Percentage Entered[!]\n");
        goto label3;
    }

    label4:
    printf("\nEnter the Tax percentage (%%) : ");
    scanf("%f", &tax_percentage);
    if(tax_percentage<=0 || tax_percentage>=15) {
        printf("\nInvalid Tax Percentage Entered[!]\n");
        goto label4;
    }

    double sub_total = quantity * price;
    double discounted_amount = sub_total - (sub_total * discount_percentage) / 100.0;
    double final_bill = discounted_amount + (discounted_amount * tax_percentage)/100;

    printf("--------------------------------------------\n");
    printf("\n\tGENERATING BILL....");
    printf("\n--------------------------------------------\n");

    printf("\nYour subtotal is:\t\tRs.%.2lf", sub_total);
    printf("\nYour Discounted Amount is:\tRs.%.2lf", discounted_amount);
    printf("\n------------------------------------------------");
    printf("\nYour Final Bill is:\tRs.%.2lf", final_bill);
    
    printf("\n--------------------------------------------------\n");
    printf("         Thank you for shopping with us!      \n");
    printf("==================================================\n");
    printf("  Your transaction has been successfully processed.\n");
    printf("  Have a wonderful day! Goodbye!                  \n");
    printf("==================================================\n");

    return 0;
}