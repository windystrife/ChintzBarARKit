// Fill out your copyright notice in the Description page of Project Settings.

#include "ScreenShotFunction.h"
#include "Paths.h"
//~~~ Image Wrapper ~~~
#include "ImageUtils.h"
#include "IImageWrapper.h"
#include "IImageWrapperModule.h"

//~~~ Image Wrapper ~~~

#include "ModuleManager.h"
#include "FileHelper.h"
#include "Engine/Texture2D.h"
#include "FileManager.h"


#include <string>
#include <chrono>
#include <random>

#include <string>
#include "GenericPlatformFile.h"


FString UScreenShotFunction::GetPathGoldFishScreenShoot()
{
	return FPaths::ScreenShotDir();
}

FString UScreenShotFunction::GetPathNormalScreenShoot()
{
	return FPaths::BugItDir();
}

FString UScreenShotFunction::EngineVersionAgnosticUserDir()
{
	return FPaths::EngineVersionAgnosticUserDir();	
}


FString UScreenShotFunction::TakeScreenshot(FString filename)
{
	//FString filename = "/UE4_Project/Fuck.png";
	FScreenshotRequest::RequestScreenshot(filename, false, true);
	return FPaths::ScreenShotDir();
	//return FScreenshotRequest::GetFilename();

}

static EImageFormat GetJoyImageFormat(EJoyImageFormats JoyFormat)
{
	switch (JoyFormat)
	{
	case EJoyImageFormats::JPG: return EImageFormat::JPEG;
	case EJoyImageFormats::PNG: return EImageFormat::PNG;
	case EJoyImageFormats::BMP: return EImageFormat::BMP;
	case EJoyImageFormats::ICO: return EImageFormat::ICO;
	case EJoyImageFormats::EXR: return EImageFormat::EXR;
	case EJoyImageFormats::ICNS: return EImageFormat::ICNS;
	}
	return EImageFormat::JPEG;
}


UTexture2D* UScreenShotFunction::Tung_LoadTexture2D_FromFile(const FString& FullFilePath, EJoyImageFormats ImageFormat, bool& IsValid, int32& Width, int32& Height)
{


	IsValid = false;
	UTexture2D* LoadedT2D = NULL;

	IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(FName("ImageWrapper"));
	TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(GetJoyImageFormat(ImageFormat));

	//Load From File
	TArray<uint8> RawFileData;
	if (!FFileHelper::LoadFileToArray(RawFileData, *FullFilePath)) return NULL;
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

	//Create T2D!
	if (ImageWrapper.IsValid() && ImageWrapper->SetCompressed(RawFileData.GetData(), RawFileData.Num()))
	{
		const TArray<uint8>* UncompressedBGRA = NULL;
		if (ImageWrapper->GetRaw(ERGBFormat::BGRA, 8, UncompressedBGRA))
		{
			LoadedT2D = UTexture2D::CreateTransient(ImageWrapper->GetWidth(), ImageWrapper->GetHeight(), PF_B8G8R8A8);

			//Valid?
			if (!LoadedT2D) return NULL;
			//~~~~~~~~~~~~~~

			//Out!
			Width = ImageWrapper->GetWidth();
			Height = ImageWrapper->GetHeight();

			//Copy!
			void* TextureData = LoadedT2D->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_WRITE);
			FMemory::Memcpy(TextureData, UncompressedBGRA->GetData(), UncompressedBGRA->Num());
			LoadedT2D->PlatformData->Mips[0].BulkData.Unlock();

			//Update!
			LoadedT2D->UpdateResource();
		}
	}

	// Success!
	IsValid = true;
	return LoadedT2D;
}




bool UScreenShotFunction::TungFileIO_GetFiles(TArray<FString>& Files, FString RootFolderFullPath, FString Ext)
{
	if (RootFolderFullPath.Len() < 1) return false;

	FPaths::NormalizeDirectoryName(RootFolderFullPath);

	IFileManager& FileManager = IFileManager::Get();

	if (!Ext.Contains(TEXT("*")))
	{
		if (Ext == "")
		{
			Ext = "*.*";
		}
		else
		{
			Ext = (Ext.Left(1) == ".") ? "*" + Ext : "*." + Ext;
		}
	}

	FString FinalPath = RootFolderFullPath + "/" + Ext;

	FileManager.FindFiles(Files, *FinalPath, true, false);
	return true;
}


FString UScreenShotFunction::ScreenShotsDir()
{
	return FPaths::ConvertRelativePathToFull(FPaths::ScreenShotDir());
}
