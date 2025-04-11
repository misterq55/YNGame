// Fill out your copyright notice in the Description page of Project Settings.


#include "YNPlayerController.h"

void AYNPlayerController::BeginPlay()
{
	Super::BeginPlay();
}

bool AYNPlayerController::ProcessConsoleExec(const TCHAR* Cmd, FOutputDevice& Ar, UObject* Executor)
{
	return true;
}
