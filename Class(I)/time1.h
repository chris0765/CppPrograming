#ifndef TIME1_H
#define TIME1_H

class Time{
private:
    int hour;
    int minute;
    int second;
public:
    void setTime(int, int, int);
    void printTime12();
    void printTime24();
};

#endif