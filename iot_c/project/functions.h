#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h> 
#include <ctype.h>  
#include <stdlib.h> 

#define MAX_ROWS 26
#define MAX_SEATS 156
#define MAX_NAME_LEN 50
#define MAX_INPUT_LEN 50

typedef struct
{
    char first_name[MAX_NAME_LEN];
    char last_name[MAX_NAME_LEN];
    int row;
    int seat;
} Seats;


int loadReservations(const char *filename, Seats seats[], int *count);
int saveReservation(const char *filename, const Seats *seats);

int getValidRow();  
char getValidSeat();  
void getValidName(char *name, int maxLength);  
int isSeatAvailable(const Seats seats[], int count, int row, char seat);

int addReservation(Seats seats[], int *count, const char *filename);
int removeReservation(Seats seats[], int *count, const char *filename);

void printSeatMap(const Seats seats[], int count);  
void printPassengerList(const Seats seats[], int count);

void sortReservations(Seats seats[], int count);

int findReservation(const Seats seats[], int count, int row, char seat);  
void toLowerCase(char *str);



#endif // FUNCTIONS_H