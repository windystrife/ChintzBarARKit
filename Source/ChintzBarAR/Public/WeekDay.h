// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "WeekDay.generated.h"


/**
 * 
 */
UCLASS()
class CHINTZBARAR_API UWeekDay : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
    UFUNCTION(BlueprintCallable, Category = "DAYTIME")
    static int WeekDay(int Year, int Month, int Day);

};
 