// Fill out your copyright notice in the Description page of Project Settings.

 #pragma once
 
 #if PLATFORM_IOS
 #import <UIKit/UIKit.h>
 
 @interface ScreenshotEncoder : UIViewController <UINavigationControllerDelegate>
 @end
 #endif
 
#include "GameFramework/Actor.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ScreenShooter.generated.h"
/**
 * 
 */
UCLASS()
class CHINTZBARAR_API UScreenShooter : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable, Category = "Custom", meta = (Keywords = "Fuck"))
	static void doScreenShot();

	/*UFUNCTION(BlueprintCallable, Category = "Screenshooter")
    bool IsScreenshotDone(FString savePath);
     
     UFUNCTION(BlueprintCallable, Category = "Screenshooter")
     FString RequestNewScreenshot();
     
     UFUNCTION(BlueprintCallable, Category = "Screenshooter")
     void DeleteCurrentImage();
     
     UFUNCTION(BlueprintCallable, Category = "Screenshooter")
     void SaveNativeScreenshot(); */
		
};


 
