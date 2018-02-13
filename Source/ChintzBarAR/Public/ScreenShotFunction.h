// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ScreenShotFunction.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EJoyImageFormats : uint8
{
	JPG		UMETA(DisplayName = "JPG        "),
	PNG		UMETA(DisplayName = "PNG        "),
	BMP		UMETA(DisplayName = "BMP        "),
	ICO		UMETA(DisplayName = "ICO        "),
	EXR		UMETA(DisplayName = "EXR        "),
	ICNS	UMETA(DisplayName = "ICNS        ")
};


UCLASS()
class CHINTZBARAR_API UScreenShotFunction : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	UFUNCTION(BlueprintPure, Category = "Take Screenshot|Load Texture From File", meta = (Keywords = "image png jpg jpeg bmp bitmap ico icon exr icns"))
		static UTexture2D* Tung_LoadTexture2D_FromFile(const FString& FullFilePath, EJoyImageFormats ImageFormat, bool& IsValid, int32& Width, int32& Height);

		UFUNCTION(BlueprintPure, Category = "Take Screenshot|File IO")
		static bool TungFileIO_GetFiles(TArray<FString>& Files, FString RootFolderFullPath, FString Ext);

		UFUNCTION(BlueprintPure, Category = "Take Screenshot|Paths")
		static FString ScreenShotsDir();

		UFUNCTION(BlueprintCallable, Category = "Take Screenshot|One Shot")
		FString TakeScreenshot(FString filename);

		UFUNCTION(BlueprintPure, Category = "Custom")
		static FString GetPathGoldFishScreenShoot();

		UFUNCTION(BlueprintPure, Category = "Custom")
		static FString GetPathNormalScreenShoot();

		UFUNCTION(BlueprintPure, Category = "Custom")
		static FString EngineVersionAgnosticUserDir();
	
	
};
