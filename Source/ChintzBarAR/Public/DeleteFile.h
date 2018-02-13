// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DeleteFile.generated.h"

/**
 * 
 */
UCLASS()
class CHINTZBARAR_API UDeleteFile : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "Custom")
		static void deleteFile(FString AbsoluteFilePath);
	
	
};
