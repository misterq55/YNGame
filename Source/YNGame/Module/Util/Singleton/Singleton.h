// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

template<typename T>
class TYNSingleton
{
protected:
  TYNSingleton() {}
public:
  TYNSingleton(const TYNSingleton& c) = delete;
  void operator=(const TYNSingleton& c) = delete;

  static T& GetInstance()
  {
    static T instance;
    return instance;
  }
};
