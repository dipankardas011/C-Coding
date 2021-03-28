/*
 to display the calender to user
    assuming that is a non-leap year
 mon 0
 tue 1
 wed 2
 thu 3
 fri 4
 sat 5
 sun 6
*/

#include <stdio.h>
#include <stdlib.h>

static int year;
enum month_name{
    Jan=1,
    Feb,
    Mar,
    Apr,
    May,
    Jun,
    Jul,
    Aug,
    Sep,
    Oct,
    Nov,
    Dec
};

int start_day(int yy){
    int day = 1;
    for(int i=1901;i < yy;i++){
        if(day == 5){
            if((i%4 == 0 && i%100 != 0)|| (i%400 == 0))
                day = 0;
            else
                day++;
        }
        else if (day ==6){
            if((i%4 == 0 && i%100 != 0)|| (i%400 == 0))
                day = 1;
            else
                day=0;
        }
        else{
            if((i%4 == 0 && i%100 != 0)|| (i%400 == 0))
                day+=2;
            else
                day++;
        }
    }
    return day;
}

int cal_last_day(int mm){
    if(mm==1||mm==3||mm==5||mm==7||mm==8||mm==10||mm==12)
        return 31;
    else if (mm==4||mm==6||mm==9||mm==11)
        return 30;
    else if (mm==2){
        if((year%4 == 0 && year%100 != 0)||(year%400 == 0))
            return 29;
        else
            return 28;
    }
    else return -9999;
}

void print_month_name(int mm){
    switch(mm){
        case Jan: printf("January");break;
        case Feb: printf("February");break;
        case Mar: printf("March");break;
        case Apr: printf("April");break;
        case May: printf("May");break;
        case Jun: printf("June");break;
        case Jul: printf("July");break;
        case Aug: printf("August");break;
        case Sep: printf("September");break;
        case Oct: printf("October");break;
        case Nov: printf("November");break;
        case Dec: printf("December");break;
    }
}
int main(){
    
    printf("enter the year: ");
    scanf("%d",&year);
    int starting = start_day(year);
    system("cls");
    int month_no;
    printf("\n\n\n\t\t\t*********************************************************\n");
    printf("\t\t\t\t\t  CALENDER OF YEAR %d  \n\t\t\t#########################################################\n\n",year);
    int calender[4][3][6][7]={0};

    int rows_pf=0;
    month_no=0;
    while(rows_pf < 4){

        int months_pf=0;

        while(months_pf < 3){
            month_no++;

            int days=1, space=0;
            /* month */
            for(int week_no = 0; week_no < 6; week_no++){
                
                int index=0;
                while(space++<starting){
                    index++;
                }starting =0;
                
                for(; index<7; index++){

                    if(days == cal_last_day(month_no)+1){     //last day change according to the month
                        starting = index;
                        goto nextmonth;
                    }
                    calender[rows_pf][months_pf][week_no][index]=days++;
                }
            }
            nextmonth:
            months_pf++;
        }

        rows_pf++;
    }

    rows_pf=0;
    int month=1;
    while(rows_pf < 4){
        print_month_name(month);printf("\t\t\t\t\t");
        print_month_name(month+1);printf("\t\t\t\t\t");
        print_month_name(month+2);
        printf("\nMon  Tue  Wed  Thr  Fri  Sat  Sun\tMon  Tue  Wed  Thr  Fri  Sat  Sun\tMon  Tue  Wed  Thr  Fri  Sat  Sun\n");
        printf("\n");
        month+=3;
        for(int week_no=0;week_no<6;week_no++){
            
            for(int months_pf=0;months_pf<3;months_pf++){
                for(int days=0; days<7;days++){
                    if (0 == calender[rows_pf][months_pf][week_no][days])
                        printf("     ");
                    else
                        printf("%-5d",calender[rows_pf][months_pf][week_no][days]);
                }
                printf("\t");
            }
            printf("\n\n");
        }
        rows_pf++;
    }
}