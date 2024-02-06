#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structures for Passenger and trains
struct Passenger
{
        int aadharNumber;
        char name[50];
        int dob;
        long int phoneNumber;
        char address[50];
};

struct Train
{
        char name[50];
        int trainNumber;
        char type[50];
        char from[50];
        char to[50];
        int days;
        int noSeats;
        char seatType[50];
        int rate;
};

//Function prototypes
void addPassengerDetails(struct Passenger *passengers, int);
void addTrainDetails(struct Train *trains, int);
void viewPassengerDetails(struct Passenger *passengers, int);
int searchPassengerByAadhar(struct Passenger *passengers, int, int);
void viewTrainDetails(struct Train *trains, int);
int searchTrainByName(struct Train *trains, int, char []);
int searchTrainByLocation(struct Train *trains, int, char [], char []);
void bookTickets(struct Train *trains, struct Passenger *passengers, int, int);
void sortBookingDetails(struct Train *trains, struct Passenger *passengers, int);

int main(){
        int choice, aadhar, index ,passengersCount = 0, trainsCount = 0;
        //Dynamic memory allocation for passengers and trains
        char tname[50],from[50],to[50];
        struct Passenger *passengers = (struct Passenger *)malloc(sizeof(struct Passenger));
        struct Train *trains = (struct Train *)malloc(sizeof(struct Train));

        while(1){

                //Menu
                printf("\n\n");
                printf("Menu\n1. Add Passenger Details\n2. Add Train Details\n3. View Passenger Details\n4. Search Passenger by Aadhar\n5. View Train Details\n6. Search Train by Name\n7. Search Train by From and To\n8. Book Tickets\n9. Sort Booking Details\n10. Exit\n\nEnter your choice: ");
                scanf("%d",&choice);
                printf("\n\n");

                switch(choice){
                        //Add passenger details
                        case 1: addPassengerDetails(passengers, passengersCount);
                        passengersCount++;
                        break;

                        //Add train details
                         //Add train details
                        case 2: addTrainDetails(trains, trainsCount);
                        trainsCount++;
                        break;


                        //View Passenger Details
                        case 3: viewPassengerDetails(passengers, passengersCount);
                        break;

                        case 4:

                                printf("Enter Aadhar Number: ");
                                scanf("%d",&aadhar);
                                index = searchPassengerByAadhar(passengers, passengersCount, aadhar);
                                if(index == -1 )
                                        printf("No Passenger Found!");
                                else
                                        printf("Passenger Found at Index %d",index);
                        break;

                         case 5: viewTrainDetails(trains, trainsCount);
                         break;

                        //Search Train by Name
                        case 6:
                                printf("Enter Train Name: ");
                                scanf("%s",tname);
                                int index1 = searchTrainByName(trains, trainsCount, tname);
                                if(index1 == -1)
                                        printf("No Train Found!");
                                else
                                        printf("Train Found at Index %d",index1);
                        break;

                        case 7:

                                printf("Enter From: ");
                                scanf("%s",from);
                                printf("Enter To: ");
                                scanf("%s",to);
                                int index2 = searchTrainByLocation(trains, trainsCount, from, to);
                                if(index2 == -1)
                                        printf("No Train Found!");
                                else
                                        printf("Train Found at Index %d",index2);
                        break;

                        //Book Tickets
                        case 8: bookTickets(trains, passengers, trainsCount, passengersCount);
                        break;


                        //Exit
                        case 10: exit(0);
                        break;

                        default: printf("Invalid Option!");
                }
        }
}

//Adding passenger details
void addPassengerDetails(struct Passenger *passengers, int passengersCount){
        passengers = (struct Passenger *)realloc(passengers, (passengersCount+1) * sizeof(struct Passenger));
        printf("Enter Aadhar Number: ");
        scanf("%d",&passengers[passengersCount].aadharNumber);
        printf("Enter Name: ");
        scanf("%s",passengers[passengersCount].name);
        printf("Enter Date of Birth (YYYYMMDD): ");
        scanf("%d",&passengers[passengersCount].dob);
        printf("Enter Phone Number: ");
        scanf("%ld",&passengers[passengersCount].phoneNumber);
        printf("Enter Address: ");
        scanf("%s",passengers[passengersCount].address);
        printf("Passenger Added Successfully!");
}
//Adding train details
void addTrainDetails(struct Train *trains, int trainsCount){
        trains = (struct Train *)realloc(trains, (trainsCount+1) * sizeof(struct Train));
        printf("Enter Train Name: ");
        scanf("%s",trains[trainsCount].name);
        printf("Enter Train Number: ");
        scanf("%d",&trains[trainsCount].trainNumber);
        printf("Enter Type of Train: ");
        scanf("%s",trains[trainsCount].type);
        printf("Enter From: ");
        scanf("%s",trains[trainsCount].from);
        printf("Enter To: ");
        scanf("%s",trains[trainsCount].to);
        printf("Enter Days: ");
        scanf("%d",&trains[trainsCount].days);
        printf("Enter Number Seats: ");
        scanf("%d",&trains[trainsCount].noSeats);
        printf("Enter Seat Type: ");
        scanf("%s",trains[trainsCount].seatType);
        printf("Enter Rate: ");
        scanf("%d",&trains[trainsCount].rate);
        printf("Train Added Successfully!");
}

//View Passenger Details
void viewPassengerDetails(struct Passenger *passengers, int passengersCount){
        printf("Aadhar\tName\tDOB\tPhone\tAddress\n");
        for(int i=0; i<passengersCount; i++){
                printf("%d\t%s\t%d\t%ld\t%s\n", passengers[i].aadharNumber, passengers[i].name,
                passengers[i].dob, passengers[i].phoneNumber, passengers[i].address);
        }
}

//Search Passenger by Aadhar (binary search)
int searchPassengerByAadhar(struct Passenger *passengers, int passengersCount, int aadhar){
        int low, mid, high;
        low = 0;
        high = passengersCount-1;

        while(low<=high){
                mid = (low+high)/2;
                if(aadhar == passengers[mid].aadharNumber){
                        return mid;
                }
                else if(aadhar < passengers[mid].aadharNumber)
                        high = mid -1;
                else
                        low = mid + 1;
        }
        return -1;
}

//View Train Details
void viewTrainDetails(struct Train *trains, int trainsCount){
        printf("Name\tNumber\tType\tFrom\tTo\tDays\tSeats\tType\tRate\n");
        for(int i=0; i<trainsCount; i++){
                printf("%s\t%d\t%s\t%s\t%s\t%d\t%d\t%s\t%d\n", trains[i].name, trains[i].trainNumber,
                trains[i].type, trains[i].from, trains[i].to, trains[i].days,
                trains[i].noSeats, trains[i].seatType, trains[i].rate);
        }
}
int searchTrainByName(struct Train *trains, int trainsCount, char tname[]){
        for(int i=0; i<trainsCount; i++){
                if(strcmp(tname,trains[i].name) == 0)
                {

                       return i;
                }
        }
        return -1;
}
int searchTrainByLocation(struct Train *trains, int trainsCount, char from[], char to[]){
        for(int i=0; i<trainsCount; i++){
                if(strcmp(from,trains[i].from)==0 && strcmp(to,trains[i].to)==0)
                {
                     printf("Train name is %s",trains[i].name);
                     return i;

                }

        }
        return -1;
}
void bookTickets(struct Train *trains, struct Passenger *passengers, int trainsCount, int passengersCount){
        int noTicket;
        char seatType[50];
        int indexTrain, indexPassenger;

        printf("Enter Train Number: ");
        scanf("%d",&indexTrain);
        printf("Enter Number of Tickets: ");
        scanf("%d",&noTicket);
        printf("Enter Seat Type: ");
        scanf("%s",seatType);

        if(strcmp(trains[indexTrain].seatType,seatType)==0 && trains[indexTrain].noSeats >= noTicket){
                for(int i=0; i<noTicket; i++){
                        printf("Enter Passenger Aadhar: ");
                        scanf("%d",&indexPassenger);
                        int result = searchPassengerByAadhar(passengers,passengersCount,indexPassenger);
                        if(result==-1){
                                printf("Invalid Aadhar Number!");
                                i--;
                        }
                        else{
                                trains[indexTrain].noSeats = trains[indexTrain].noSeats - noTicket;
                                printf("Ticket Booked Successfully!");
                        }
                }
        }
        else{
                printf("Cannot Book Ticket!");
        }
}

