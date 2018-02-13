// Fill out your copyright notice in the Description page of Project Settings.

#include "WeekDay.h"

int UWeekDay::WeekDay(int Year, int Month, int Day)
{
    if (Month < 3)
    {
        Month = Month + 12;
        Year = Year - 1;
    }
    return ((abs(Day + Month * 2 + (Month + 1) * 3 / 5 + Year + Year / 4)) % 7) + 1;
    
}






