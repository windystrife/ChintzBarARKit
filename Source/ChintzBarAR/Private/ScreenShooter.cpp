// Fill out your copyright notice in the Description page of Project Settings.
#include "ScreenShooter.h"
#include "HighResScreenshot.h"
#include "Engine/GameViewportClient.h"
#include "UnrealClient.h"



void UScreenShooter::doScreenShot()
{
	FString filename = "/private/var/mobile/Media/DCIM/Image.png";
    FScreenshotRequest::RequestScreenshot(filename, false, true);
}


/* #include "ScreenShooter.h"
#include "HighResScreenshot.h"
#include "Engine/GameViewportClient.h"

 
 #if PLATFORM_IOS
 #include "IOSAppDelegate.h"
 #import <Foundation/Foundation.h>
 #endif
 
 #if PLATFORM_IOS
 
 @interface Screenshooter()
 @end
 
 @implementation Screenshooter
 
 + (Screenshooter*)GetDelegate
 {
     static Screenshooter* Singleton = [[Screenshooter alloc] init];
     return Singleton;
 }
 
 -(void)saveShot
 {
     NSArray *paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
     NSString *documentsDirectory = [paths objectAtIndex:0];
     
     NSString *filePath = [documentsDirectory stringByAppendingPathComponent:@"/<YourProjectName>/Saved/Screenshots/IOS/Image.png"];
     
     UIImage *image = [UIImage imageWithContentsOfFile:filePath];
     UIImageWriteToSavedPhotosAlbum(image, nil, nil, nil);
 }
 
 +(void)saveScreenshotNative
 {
     [[ScreenshotEncoder GetDelegate] performSelectorOnMainThread:@selector(saveShot) withObject:nil waitUntilDone : NO];
 }
 
 @end
 #endif
   
 bool AScreenshooter::IsScreenshotDone(FString savePath)
 {
     return FPaths::FileExists(*savePath);
 }
 
 FString AScreenshooter::RequestNewScreenshot()
 {
     FString filename = "Image.png";
     FScreenshotRequest::RequestScreenshot(filename, false, false);
     return FScreenshotRequest::GetFilename();
 }
   
 void AScreenshooter::SaveNativeScreenshot()
 {
 #if PLATFORM_IOS
     [Screenshooter saveScreenshotNative];
 #endif
 } */