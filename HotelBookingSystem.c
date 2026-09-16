#include<stdio.h>

#define PEAK_STANDARD_RATE 5000
#define PEAK_DELUXE_RATE 8000
#define PEAK_SUITE_RATE 12000
#define OFF_STANDARD_RATE 3000
#define OFF_DELUXE_RATE 5000
#define OFF_SUITE_RATE 8000

int main(){
    printf("\n=====================================================================\n");
    printf("\t\tWELCOME TO HOTEL 5-STAR");
    printf("\n=====================================================================\n");
    

    int season,room_type,no_night;
    double discount, customer_bill,hotel_revenue = 0;
    // double rate;
        printf("\nWelcome to Our Hotel.\nIn order to accommodate you please answer the following question:\n\n");

        label2:
        printf("Select Season: (1). PEAK SEASON\t(2). OFF SEASON\t : ");
        scanf("%d", &season);

        if(season <=0 || season > 2){
            printf("\nInvalid number entered[!].Try Again\n");
            goto label2;
        }

        label3:
        printf("\nSelect Room type : (1). STANDARD\t(2). DELUXE\t(3). SUITE : ");
        scanf("%d",&room_type);

        if(room_type<=0 || room_type > 3){
            printf("\nInvalid number entered[!].Try Again");
            goto label3;
        }

        label4:
        printf("\nEnter NO OF NIGHTS you will stay : ");
        scanf("%d", &no_night);

        if(no_night<=0){
            printf("\nInvalid number entered[!].Try Again\n");
            goto label4;
        }

        if(season == 1){
            if(room_type == 1) {
                customer_bill = PEAK_STANDARD_RATE * no_night;
            } else if (room_type == 2) {
                customer_bill = PEAK_DELUXE_RATE * no_night;
            } else {
                customer_bill = PEAK_SUITE_RATE * no_night;
            }
        } else {
            if(room_type == 1) {
                customer_bill = OFF_STANDARD_RATE * no_night;
            } else if (room_type == 2) {
                customer_bill = OFF_DELUXE_RATE * no_night;
            } else {
                customer_bill = OFF_SUITE_RATE * no_night;
            }
        }

        if(no_night>7){
            discount = customer_bill  * 0.15;
            customer_bill = customer_bill - discount;
            printf("\n[+] Long-stay discount applied (15%% off: RS.%.2lf)\n", discount);
            printf("\nYour Bill for %d NO OF NIGHTS in Room type %d  is RS.%.2lf\n", no_night, room_type, customer_bill);
        } else {
            printf("\nYour Bill for %d NO OF NIGHTS in Room type %d is RS.%.2lf\n", no_night, room_type, customer_bill);
        }
        hotel_revenue = hotel_revenue + customer_bill;

    
    printf("\n=====================================================================\n");
    printf("\tHOTEL TOTAL REVENUE: RS.%.2lf\n", hotel_revenue);
    printf("=====================================================================\n");
    return 0 ;
}