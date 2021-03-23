#include <iostream>
#include <iomanip>

using namespace std;

#define Sunday 0
#define Monday 1
#define Tuesday 2
#define Wednesday 3
#define Thursday 4
#define Friday 5
#define Saterday 6

void GiveInstructions(void);
int GetYearFromUser(void);
void PrintCalendar(int year);
void PrintCalendarMonth(int month, int year);
void IndentFirstLine(int weekday);
int MonthDays(int month, int year);
int FirstDayOfMonth(int month, int year);
string MonthName(int month);
bool IsLeapYear(int year);

int main()
{
    int year;
    GiveInstructions();
    year = GetYearFromUser();
    PrintCalendar(year);
}

void GiveInstructions(void)
{
    cout<<"This program displays a calendar for a full year\n";
    cout<<"The year must not be before 1900\n";
}

int GetYearFromUser(void)
{
    int year;
    while(true)
    {
        cout<<"Which year? ";
        cin>>year;
        if(year>=1900) return year;
        cout<<"The year must be at least 1900.\n";
    }
}

void PrintCalendar(int year)
{
    int month;
    for(month = 1; month <= 12; month++)
    {
        PrintCalendarMonth(month, year);
        cout<<endl;
    }
}

void PrintCalendarMonth(int month, int year)
{
    int weekday, nDays, day;
    cout<<MonthName(month)<<" "<<year<<endl;
    cout<<" SU MO Tu We Th Fr Sa\n";
    nDays = MonthDays(month, year);
    weekday = FirstDayOfMonth(month, year);
    IndentFirstLine(weekday);
    for(day = 1; day <= nDays; day++)
    {
        cout<<setw(3)<<day;
        if(weekday == Saterday) cout<<endl;
        weekday = (weekday + 1) % 7;
    }
    if(weekday != Sunday) cout<<endl;
}

void IndentFirstLine(int weekday)
{
    int i;
    for(i = 0; i < weekday; i++)
    {
        cout<<setw(3)<<".";
    }
}

int MonthDays(int month, int year)
{
    switch(month)
    {
        case 2:
            if(IsLeapYear(year)) return 29;
            return 28;
        case 4: case 6: case 9: case 11:
            return 30;
        default:
            return 31;
    }
}

int FirstDayOfMonth(int month, int year)
{
    int i, j, cnt = 0;
    for(i = 1900; i<year; i++)
        for(j = 1; j <= 12; j++)
            cnt += MonthDays(j, i);
    
    for(i = 1; i < month; i++)
        cnt += MonthDays(i, year);
    
    return (cnt+1)%7;
}

string MonthName(int month)
{
    switch (month)
    {
        case 1: return "January";
        case 2: return "February";
        case 3: return "March";
        case 4: return "April";
        case 5: return "May";
        case 6: return "June";
        case 7: return "July";
        case 8: return "August";
        case 9: return "September";
        case 10: return "October";
        case 11: return "November";
        case 12: return "December";
        default: return "Illegal month";
    }
}

bool IsLeapYear(int year)
{
    return (((year%4==0)&&(year%100!=0))||(year%400==0));
}