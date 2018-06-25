// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FN.h"
#include "CoreMinimal.h"

/**
*
*/
class SANDBOXGAME_API FNAdd: public FN
{
public:
	FNAdd(FN* sourceModule1, FN* sourceModule2);
	FNAdd();
	~FNAdd();
	
	void setSourceModules(FN* sourceModule1, FN* sourceModule2);
	float getNoise(double x, double y, double z);
	float getNoise(double x, double y);

private:
	FN* fn_sourceModule1;
	FN* fn_sourceModule2;
};
