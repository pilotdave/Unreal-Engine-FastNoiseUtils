// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FN.h"
#include "CoreMinimal.h"

/**
*
*/
class SANDBOXGAME_API FNExponent: public FN
{
public:
	FNExponent(FN* sourceModule, float exponent);
	~FNExponent();
	void setExponent(float exponent);
	void setSourceModule(FN* sourceModule);
	float getNoise(double x, double y, double z);
	float getNoise(double x, double y);

private:
	float fn_exponent;
	FN* fn_sourceModule;
};
