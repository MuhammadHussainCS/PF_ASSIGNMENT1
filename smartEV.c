#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define PEAK_CHARGING_RATE 50
#define OFF_CHARGING_RATE 35

int main(){
    printf("--------------------------------------------------\n");
    printf("Smart EV Charging and Parking Management System\n");
    printf("--------------------------------------------------\n");

    char vehicle_type;
    label1:
    printf("\nEnter Vehicle Type : E = Electric Vehicle, H = Hybrid Vehicle : ");
    vehicle_type = getche();
    vehicle_type = toupper(vehicle_type);

    if(vehicle_type != 'E' && vehicle_type!= 'H') {
        printf("\nInvalid Input.Enter again[!]\n");
        goto label1;
    }

    int current_battery_percentage;
    label2:
    printf("\nEnter battery Percentage (State of Charge (SOC)) %% : ");
    scanf("%d", &current_battery_percentage);

    if(current_battery_percentage<=0 || current_battery_percentage>100) {
        printf("\nInvalid Input.Enter again[!]\n");
        goto label2;
    }

    int req_charging_level;

    label3:
    printf("\nEnter Required Charging Level As Percentage %% : ");
    scanf("%d", &req_charging_level);

    if(req_charging_level<=0 || req_charging_level > 100) {
        printf("\nInvalid Input.Enter again[!]\n");
        goto label3;
    }

    float parking_duration;
    label4:
    printf("\nEnter expected parking duration in HOURS (use \"point(.)\" ) for minutes .Ex 23.25 : ");
    scanf("%f", &parking_duration);

    if(parking_duration<0) {
        printf("\nInvalid Input.Enter again[!]\n");
        goto label4;
    }

    float time;

    label5:
    printf("\nEnter Current time in 24-hour format (use \"point(.)\" ) for minutes .Ex 23.25 : ");
    scanf("%f", &time);

    if(time<0 || time>24) {
        printf("\nInvalid Input.Enter again[!]\n");
        goto label5;
    }

    char parking_membership;
    label6:
    printf("\nDid you have the parking membership (Y/N) : ");
    parking_membership = getche();
    parking_membership = toupper(parking_membership);

    if(parking_membership != 'Y' && parking_membership != 'N') {
        printf("\nInvalid Input.Enter again[!]\n");
        goto label6;
    }

    char disabled_person;
    label7:
    printf("\nDid you have a disabled person priority (Y/N) : ");
    disabled_person = getche();
    disabled_person = toupper(disabled_person);

    if(disabled_person != 'Y' && disabled_person != 'N') {
        printf("\nInvalid Input.Enter again[!]\n");
        goto label7;
    }

    char charging_station_available;
    label8:
    printf("\nIs the charging station is currently available (Y/N) ? : ");
    charging_station_available = getche();
    charging_station_available = toupper(charging_station_available);

    if(charging_station_available != 'Y' && charging_station_available != 'N') {
        printf("\nInvalid Input.Enter again[!]\n");
        goto label8;
    }

    int emergency_priority = 0,disabled_priority = 0,simple_no_priority = 0,charging_assigned = 1;

    if(charging_station_available == 'N') {
        if(vehicle_type == 'H') {
            charging_assigned = 0;
            printf("\nCharging Unavailable,Parking Only\n");
        } else {
            charging_assigned = 0;
            printf("\nNo chargine slot Avialable\n");
        }
    } else {//charging station available == 'Y'
        if(vehicle_type == 'E') {
            if(req_charging_level<=current_battery_percentage) {
                charging_assigned = 0;
                printf("\nNo Charging Required\n");
            } else {
                if(current_battery_percentage<=15 && req_charging_level>=80) {
                    emergency_priority = 1;
                printf("\nemergency Charging Priority\n");
                } else if(disabled_person == 'Y' || (parking_membership == 'Y' && current_battery_percentage<=30)) {
                        disabled_priority = 1;
                        printf("\nPriority Charging\n");
                } else {
                        simple_no_priority = 1;
                        printf("\nAssign normal charging\n");
                    }
                }
            } else  {//vehicle_type='H'
            if(current_battery_percentage<40) {
                if(req_charging_level<=current_battery_percentage) {
                    charging_assigned = 0;
                    printf("\nNo charging required");
                } else if(current_battery_percentage<=15 && req_charging_level>=80) {
                    emergency_priority = 1;
                    printf("\nEmergency Condition Priority");
                } else if(disabled_person == 'Y' || (parking_membership == 'Y' && current_battery_percentage<=30)) {
                    disabled_priority = 1;
                    printf("\nAssign Priority Charging");
                } else {
                    simple_no_priority = 1;
                    printf("\nNormal Charging");
                }
            } else {
                printf("\nVehicle does not qualify for EV charging.");
            }
        }
    }

    double charging_bill = 0;
    float charging_discount = 0;
    int required_charging;

    if(req_charging_level <= current_battery_percentage) {
    required_charging = 0;
    } else {
    required_charging = req_charging_level - current_battery_percentage;
    }

    if(charging_assigned != 0) {
        if(time>=17 && time<=22) {//peak
        charging_bill = PEAK_CHARGING_RATE * required_charging;
        if(parking_membership == 'Y' && emergency_priority !=1) {
            charging_discount = charging_bill * 0.10;
            charging_bill = charging_bill - charging_discount;
            printf("\n10% peak membership discount applied[!]");
        }
    } else {//off
        charging_bill = OFF_CHARGING_RATE * required_charging;
        if(parking_membership == 'Y' && emergency_priority != 1) {
            charging_discount = charging_bill*0.20;
            charging_bill = charging_bill - charging_discount;
            printf("\nYou have got 20%% discount because you are a Member[!]\n");
            } 
        }
    }
    float parking_bill = 0;
    float parking_discount = 0;

    if(disabled_person == 'Y') {
        parking_bill = 0;
        parking_discount = 0;
        printf("\nYOU GOT FREE PARKING");
    } else {
        if(parking_duration <= 2) {
            parking_bill = 200;
        } else if(parking_duration > 2 && parking_duration <= 5) {
            parking_bill = 400;
        } else { // more than 5 hrs
            parking_bill = 700;
        }

        if(parking_membership == 'Y') {
            parking_discount = parking_bill * 0.20; // Fixed multiplier bug here
            parking_bill = parking_bill - parking_discount;
            printf("\n20% discount applied to parking due to membership[!]");
        }        
    }

    if(parking_duration > 8) {
        printf("\nLong-stay warning: Please relocate your vehicle after charging");
    } else {
        printf("\nStandard parking duration");
    }
    double final_amount = parking_bill + charging_bill;
    printf("\nVEHICLE TYPE = %c", vehicle_type);
    printf("\nCURRENT BATTERY PERCENTAGE = %d", current_battery_percentage);
    printf("\nREQUIRED CHARGING PERCENTAGE = %d", required_charging);
    printf("\nCHARGING COST = %.2lf", charging_bill);
    printf("\nPARKING COST = %.2f", parking_bill);
    printf("\n20%% Membership Discount = %.2lf", charging_discount);
    printf("\nPARKING DISCOUNT = %.2f", parking_discount);
    printf("\nOriginal Charging Bill = %.2lf", charging_bill + charging_discount);
    printf("\nDiscounted Charging Bill = %.2lf", charging_bill);
    printf("\nFINAL PAYABLE AMOUNT = %.2lf", final_amount);

    if(time>=17 && time<=22) {
        printf("\nPEAK TIME");
    } else {
        printf("\nOFF-PEAK TIME");
    }

    if(emergency_priority == 1) {
        printf("\nEMERGENCY PRIORITY");
    } else if(disabled_priority == 1) {
        printf("\nDISABLED PRIORITY");
    } else if(simple_no_priority == 1) {
        printf("\nSIMPLE PRIORITY(NO PRIORITY)");
    } else {
        printf("\nCHARGING IS NOT EVEN ASSINED / PARKING ONLY");
    }

    printf("\nThanks for using our services. GOOD BYE[!]\n");
    return 0;
}