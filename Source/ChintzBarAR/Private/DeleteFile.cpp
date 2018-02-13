// Fill out your copyright notice in the Description page of Project Settings.

#include "DeleteFile.h"
#include "PlatformFilemanager.h"
#include "FileManager.h"

void UDeleteFile::deleteFile(FString AbsoluteFilePath)
{
	//IFileManager::Delete

	if (!FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*AbsoluteFilePath))
	{
		UE_LOG(LogTemp, Warning, TEXT("Could Not Find File"));//UE_LOG(...., "Could Not Find File");
		return;
	}
}


