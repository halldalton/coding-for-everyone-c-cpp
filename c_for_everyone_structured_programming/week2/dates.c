/*
  Dates
*/

#include <stdio.h>
#include <ctype.h>

typedef enum month {jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec} month;
typedef struct date {month m; int d;} date;


date next_date(date dt)
{
    month next_month;
    int next_day, mod;

    switch(dt.m) // determine how many dates in month + 1
    {
        case jan: mod = 32; break;
        case feb: mod = 29; break;
        case mar: mod = 32; break;
        case apr: mod = 31; break;
        case may: mod = 32; break;
        case jun: mod = 31; break;
        case jul: mod = 32; break;
        case aug: mod = 32; break;
        case sep: mod = 31; break;
        case oct: mod = 32; break;
        case nov: mod = 31; break;
        case dec: mod = 32; break;
        default: mod = 1; break; // Shouldn't be needed
    }

    next_day = (dt.d + 1) % mod; // calculate next date, modulo by max days in month

    if (next_day == 0) // Reached end of month, increment date to 1, and increment month
    {
        next_day = 1;
        next_month = (dt.m + 1) % 12;
    }
    else
    {
        next_month = dt.m;
    }

    return (date){next_month, next_day};
}


void print_date(date dt)
{
    switch(dt.m)
    {
        case jan: printf("January %d", dt.d); break;
        case feb: printf("February %d", dt.d); break;
        case mar: printf("March %d", dt.d); break;
        case apr: printf("April %d", dt.d); break;
        case may: printf("May %d", dt.d); break;
        case jun: printf("June %d", dt.d); break;
        case jul: printf("July %d", dt.d); break;
        case aug: printf("August %d", dt.d); break;
        case sep: printf("September %d", dt.d); break;
        case oct: printf("October %d", dt.d); break;
        case nov: printf("November %d", dt.d); break;
        case dec: printf("December %d", dt.d); break;
        default: printf("Invalid Date"); break; // Shouldn't be needed
    }
}


void print_today_and_next(date dt)
{
    printf("Today is: ");
    print_date(dt);
    printf(", and tomorrow is: ");
    print_date(next_date(dt));
}


int main(void)
{
    int i;
    date dt1 = {jan, 1}, dt2 = {feb, 28}, dt3 = {mar, 14}, dt4 = {oct, 31}, dt5 = {dec, 31};
    date dates[] = {dt1, dt2, dt3, dt4, dt5};
    printf("\n");

    for (i = 0; i < 5; i++)
    {
        print_today_and_next(dates[i]);
        printf("\n\n");
    }

    return 0;
}