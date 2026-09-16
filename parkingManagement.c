#include<stdio.h>
#include<ctype.h>
#include<conio.h>
int main(){
    const int car_space = 1, bike_space = 1, van_space = 2;
    const int max_ZoneA = 20, max_ZoneB = 40, max_ZoneC = 15;
    int exp_vehicles, accepted = 0, rejected = 0, no_of_cars = 0, no_of_vans = 0, no_of_bikes = 0;
    int total_space = 75;
    int remaining_ZoneA_parking = 20, remaining_ZoneB_parking = 40, remaining_ZoneC_parking = 15;


    printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=");
    printf("\n\t\tWELCOME TO PARKING SYSTEM\n");
    printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n\n");
    
    label1:
    printf("Enter the expected vehicles today ? : ");
    scanf("%d", &exp_vehicles);
    
    if(exp_vehicles<0 || exp_vehicles>total_space) {
        printf("\n\nInvalid Number of Vehicles Enterd[!].Try Again[!}\n\n");
        goto label1;
    }


    printf("\nIn order to allow you to park your vehicle , kindly answer the following question....");

    char vehicle_type;
    label2:
    printf("\n\nPlease enter the vehicle type:\tC for CAR\tB for Bike\tV for VAN :  ");
        vehicle_type = getche();
        vehicle_type = toupper(vehicle_type);

        if(vehicle_type != 'C' && vehicle_type != 'B' && vehicle_type != 'V') {
            printf("\nInvalid category. Please enter the right vehicle type[!]\n");
            goto label2;
        }

        char category;
        label3:
        printf("\nEnter the Category:\tF for Faculty\tS for Student\tG for Guest : ");
        category = getche();
        category = toupper(category);

        if(category != 'F' && category != 'S' && category != 'G') {
            printf("\nInvalid category. Please enter the right vehicle type[!]\n");
            goto label3;
        }

        char parking_permit;
        label4:
        printf("\nDo you have valid Permit for Parking (Y/N): ");
        parking_permit = getche();
        parking_permit = toupper(parking_permit);

        if(parking_permit != 'Y' && parking_permit != 'N') {
            printf("\nInvalid Character entered.Please enter one of given options[!]\n");
            goto label4;
        }

        char emergency;
        label5:
        printf("\nIs your vehicle is an emergency vehicle[!] (Y/N) : \n");
        emergency = getche();
        emergency = toupper(emergency);

        if(emergency != 'Y' && emergency != 'N') {
            printf("\nInvalid Character entered.Please enter one of given options[!]\n");
            goto label5;
        }

        if(emergency == 'Y') {
            if(category == 'F') {
                if(vehicle_type == 'V') {
                    if(remaining_ZoneA_parking>=van_space) {
                        no_of_vans += 1;
                        accepted += 1;
                        remaining_ZoneA_parking -= van_space;
                        printf("\nZone A assigned to Vehicle due to emergency irrespective of Parking Permit. Remaining capacity: %d spaces.\n\n",remaining_ZoneA_parking);
                    } else {
                        rejected += 1;
                        printf("\nZone A is full.We are really sorry we know you have emergency vehicle but we can not do anything\n");
                    }
                } else if(vehicle_type == 'C') {
                    if(remaining_ZoneA_parking>=car_space) {
                        no_of_cars += 1;
                        accepted += 1;
                        remaining_ZoneA_parking -= car_space;
                        printf("\nZone A assigned to Vehicle due to emergency irrespective of Parking Permit. Remaining capacity: %d spaces.\n\n",remaining_ZoneA_parking);
                    } else {
                        rejected += 1;
                        printf("\nZone A is full.We are really sorry we know you have emergency vehicle but we can not do anything\n");
                    }
                } else {
                    if(remaining_ZoneA_parking>=bike_space) {
                        no_of_bikes += 1;
                        remaining_ZoneA_parking -= bike_space;
                        accepted += 1;
                        printf("\nZone A assigned to Vehicle due to emergency irrespective of Parking Permit. Remaining capacity: %d spaces.\n\n",remaining_ZoneA_parking);
                    } else {
                        rejected += 1;
                        printf("\nZone A is full.We are really sorry we know you have emergency vehicle but we can not do anything\n");
                    }
                }
            } else if(category == 'S') {
                if(vehicle_type == 'V') {
                    if(remaining_ZoneB_parking>=van_space) {
                        no_of_vans += 1;
                        remaining_ZoneB_parking -= van_space; 
                        accepted += 1;
                        printf("\nZone B assigned to Vehicle due to emergency irrespective of Parking Permit. Remaining capacity: %d spaces.\n\n",remaining_ZoneB_parking);
                    } else if(remaining_ZoneC_parking>=van_space) {
                        no_of_vans += 1;
                        remaining_ZoneC_parking -= van_space;
                        accepted += 1;
                        printf("\nZone C assigned to Vehicle due to emergency irrespective of Parking Permit. Remaining capacity: %d spaces.\n\n",remaining_ZoneC_parking);
                    } else {
                        rejected += 1;
                        printf("\nZone B and C is full.We are really sorry we know you have emergency vehicle but we can not do anything\n");
                    }
                } else if(vehicle_type == 'C') {
                    if(remaining_ZoneB_parking>=car_space) {
                        no_of_cars += 1;
                        remaining_ZoneB_parking -= car_space;
                        accepted += 1;
                        printf("\nZone B assigned to Vehicle due to emergency irrespective of Parking Permit. Remaining capacity: %d spaces.\n\n",remaining_ZoneB_parking);
                    } else {
                        rejected += 1;
                        printf("\nZone B is full.We are really sorry we know you have emergency vehicle but we can not do anything\n");
                    }
                } else {
                    if(remaining_ZoneB_parking>=bike_space) {
                        accepted += 1;
                        remaining_ZoneB_parking -= bike_space;
                        no_of_bikes += 1;
                        printf("\nZone B assigned to Vehicle  due to emergency irrespective of Parking Permit. Remaining capacity: %d spaces.\n\n",remaining_ZoneB_parking);
                    } else {
                        rejected += 1;
                        printf("\nZone B is full.We are really sorry we know you have emergency vehicle but we can not do anything\n");
                    }
                } 
            } else {//for guest
                if(vehicle_type == 'V') {
                    if(remaining_ZoneC_parking>=van_space) {
                        accepted += 1;
                        no_of_vans += 1;
                        remaining_ZoneC_parking -= van_space;
                        printf("\nZone C assigned to Vehicle due to emergency irrespective of Parking Permit. Remaining capacity: %d spaces.\n\n",remaining_ZoneC_parking);
                    } else {
                        rejected += 1;
                        printf("Zone C is full.We are really sorry we know you have emergency vehicle but we can not do anything\n");
                    }
                } else if(vehicle_type == 'C') {
                    if(remaining_ZoneC_parking>=car_space) {
                        accepted += 1;
                        no_of_cars += 1;
                        remaining_ZoneC_parking -= car_space;
                        printf("\nZone C assigned to Vehicle due to emergency irrespective of Parking Permit. Remaining capacity: %d spaces.\n\n",remaining_ZoneC_parking);
                    } else {
                        rejected += 1;
                        printf("Zone C is full.We are really sorry we know you have emergency vehicle but we can not do anything\n");
                    }
                } else {//guest bike
                    if(remaining_ZoneC_parking>=bike_space) {
                        accepted += 1;
                        no_of_bikes += 1;
                        remaining_ZoneC_parking -= bike_space;
                        printf("\nZone C assigned to Vehicle due to emergency irrespective of Parking Permit. Remaining capacity: %d spaces.\n\n",remaining_ZoneC_parking);
                    } else {
                        rejected += 1;
                        printf("Zone C is full.We are really sorry we know you have emergency vehicle but we can not do anything\n");
                    }
                } 
            }
        } else {//emergency == 'N'
            if(category == 'F') {
                if(parking_permit == 'Y') {
                    if(vehicle_type == 'V') {
                        if(remaining_ZoneA_parking>=van_space) {
                            accepted += 1;
                            no_of_vans += 1;
                            remaining_ZoneA_parking -= van_space;
                            printf("\nZone A assigned to Vehicle.Have A Good Day Sir. Remaining capacity: %d spaces.\n\n",remaining_ZoneA_parking);
                        } else {
                            rejected += 1;
                            printf("Zone A is full.We are really sorry\n");
                        }
                    } else if(vehicle_type == 'C') {
                        if(remaining_ZoneA_parking>=car_space) {
                            accepted += 1;
                            no_of_cars += 1;
                            remaining_ZoneA_parking -= car_space;
                            printf("\nZone A assigned to Vehicle.Have A Good Day Sir. Remaining capacity: %d spaces.\n\n",remaining_ZoneA_parking);
                        } else {
                            rejected += 1;
                            printf("Zone A is full.We are really sorry\n");
                        }
                    } else {//Faculty Bike
                        if(remaining_ZoneA_parking>=bike_space) {
                            accepted += 1;
                            no_of_bikes += 1;
                            remaining_ZoneA_parking -= bike_space;
                            printf("\nZone A assigned to Vehicle.Have A Good Day Sir. Remaining capacity: %d spaces.\n\n",remaining_ZoneA_parking);
                        } else {
                            rejected += 1;
                            printf("Zone A is full.We are really sorry\n");
                        }
                    }
                } else {
                    rejected += 1;
                    printf("\nRejected: Faculty member does not have a valid parking permit.\n");
                }
            } else if(category == 'S') {
                if(parking_permit == 'Y') {
                    if(vehicle_type == 'V') {
                        if(remaining_ZoneB_parking>=van_space) {
                            accepted += 1;
                            no_of_vans += 1;
                            remaining_ZoneB_parking -= van_space;
                            printf("\nZone B assigned to Vehicle .Have A Good Day Sir. Remaining capacity: %d spaces.\n\n",remaining_ZoneB_parking);
                        } else if (remaining_ZoneC_parking>=van_space) {
                            accepted += 1;
                            no_of_vans += 1;
                            remaining_ZoneC_parking -= van_space;
                            printf("\nZone C assigned to Vehicle.Have A Good Day Sir. Remaining capacity: %d spaces.\n\n",remaining_ZoneC_parking);
                        } else {
                            rejected += 1;
                            printf("Zone B and C are full.We are really sorry\n");
                        }
                    } else if(vehicle_type == 'C') {
                        if(remaining_ZoneB_parking>=car_space) {
                            accepted += 1;
                            no_of_cars += 1;
                            remaining_ZoneB_parking -= car_space;
                            printf("\nZone B assigned to Vehicle.Have A Good Day Sir. Remaining capacity: %d spaces.\n\n",remaining_ZoneB_parking);
                        } else {
                            rejected += 1;
                            printf("Zone B is full.We are really sorry\n");
                        }
                    } else {//student bikes
                        if(remaining_ZoneB_parking>=bike_space) {
                            accepted += 1;
                            no_of_bikes += 1;
                            remaining_ZoneB_parking -= bike_space;
                            printf("\nZone B assigned to Vehicle .Have A Good Day Sir. Remaining capacity: %d spaces.\n\n",remaining_ZoneB_parking);
                        } else {
                            rejected += 1;
                            printf("Zone B is full.We are really sorry\n");
                        }
                    }  
                } else {
                    rejected += 1;
                    printf("\nRejected: Student does not have a valid parking permit.\n");
                }
            } else {//category == 'G'
                if(parking_permit == 'Y') {
                    if(vehicle_type == 'V') {
                        if(remaining_ZoneC_parking>=van_space) {
                            accepted += 1;
                            no_of_vans += 1;
                            remaining_ZoneC_parking -= van_space;
                            printf("\nZone C assigned to Vehicle .Have A Good Day Sir. Remaining capacity: %d spaces.\n\n",remaining_ZoneC_parking);
                        } else {
                            rejected += 1;
                            printf("Zone C is full.We are really sorry\n");
                        }
                    } else if(vehicle_type == 'C') {
                        if(remaining_ZoneC_parking>=car_space) {
                            accepted += 1;
                            no_of_cars += 1;
                            remaining_ZoneC_parking -= car_space;
                            printf("\nZone C assigned to Vehicle.Have A Good Day Sir. Remaining capacity: %d spaces.\n\n",remaining_ZoneC_parking);
                        } else {
                            rejected += 1;
                            printf("Zone C is full.We are really sorry\n");
                        }
                    } else {//guest Bike
                        if(remaining_ZoneC_parking>=bike_space) {
                            accepted += 1;
                            no_of_bikes += 1;
                            remaining_ZoneC_parking -= bike_space;
                            printf("\nZone C assigned to Vehicle .Have A Good Day Sir. Remaining capacity: %d spaces.\n\n",remaining_ZoneC_parking);
                        } else {
                            rejected += 1;
                            printf("Zone C is full.We are really sorry\n");
                        }
                    }       
                } else {
                    rejected += 1;
                    printf("\nRejected: Guest does not have a valid parking permit.\n");
                }
            }
            
        }

    

    int occupied_ZoneA_spaces = max_ZoneA - remaining_ZoneA_parking;
    int occupied_ZoneB_spaces = max_ZoneB - remaining_ZoneB_parking;
    int occupied_ZoneC_spaces = max_ZoneC - remaining_ZoneC_parking;

    printf("\n\n+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=");
    printf("\n\t\tPARKING SYSTEM SUMMARY REPORT\n");
    printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n\n");

    printf("Total Vehicles Processed : %d\n", exp_vehicles);
    printf("Total Accepted Vehicles  : %d\n", accepted);
    printf("Total Rejected Vehicles  : %d\n", rejected);
    printf("-----------------------------------------------------------------------\n");
    
    printf("Successfully Parked Vehicle Breakdown:\n");
    printf(" - Cars  : %d\n", no_of_cars);
    printf(" - Bikes : %d\n", no_of_bikes);
    printf(" - Vans  : %d\n", no_of_vans);
    printf("-----------------------------------------------------------------------\n");
    
    printf("Zone Final Occupancy and Remaining Capacity:\n");
    printf(" - Zone A (Faculty)  : Occupied Spaces = %d | Remaining Capacity = %d\n", occupied_ZoneA_spaces, remaining_ZoneA_parking);
    printf(" - Zone B (Students) : Occupied Spaces = %d | Remaining Capacity = %d\n", occupied_ZoneB_spaces, remaining_ZoneB_parking);
    printf(" - Zone C (Visitors) : Occupied Spaces = %d | Remaining Capacity = %d\n", occupied_ZoneC_spaces, remaining_ZoneC_parking);
    printf("-----------------------------------------------------------------------\n");

    if (occupied_ZoneA_spaces >= occupied_ZoneB_spaces && occupied_ZoneA_spaces >= occupied_ZoneC_spaces) {
        printf("Zone with Highest Occupancy : Zone A (Faculty) with %d spaces\n", occupied_ZoneA_spaces);
    } else if (occupied_ZoneB_spaces >= occupied_ZoneA_spaces && occupied_ZoneB_spaces >= occupied_ZoneC_spaces) {
        printf("Zone with Highest Occupancy : Zone B (Students) with %d spaces\n", occupied_ZoneB_spaces);
    } else {
        printf("Zone with Highest Occupancy : Zone C (Visitors) with %d spaces\n", occupied_ZoneC_spaces);
    }

    int total_occupied = occupied_ZoneA_spaces + occupied_ZoneB_spaces + occupied_ZoneC_spaces;
    if (total_occupied >= 75) {
        printf("Campus Status                 : The entire campus parking facility is FULL!\n");
    } else {
        printf("Campus Status                 : The entire campus parking facility is NOT full.\n");
    }
    printf("+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n");
    return 0;
}