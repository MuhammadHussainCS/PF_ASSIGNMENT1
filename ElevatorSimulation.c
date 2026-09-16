#include<stdio.h>
int main(){
printf("---------------------------------------------------");
printf("\n\tElevator Simulation System\n");
printf("---------------------------------------------------");

int current_floor = 0,total_requests;
int floor_request;

label1:
printf("\nEnter floor number you want elevator to come : ");
scanf("%d", &floor_request);
if(floor_request<0) {
    printf("\nInvalid Input[!!!].Enter again");
    goto label1;
}

    if(current_floor < floor_request) {
        printf("\nMoving UP");
    } else if (current_floor > floor_request) {
        printf("\nMoving Down");
    } else {
        printf("\nDoors Opening");
    }
    current_floor = floor_request;
    return 0;
}
