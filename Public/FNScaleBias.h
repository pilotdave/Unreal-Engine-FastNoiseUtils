// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FNModule.h"
#include "CoreMinimal.h"

/**
*
*/
class SANDBOXGAME_API FNScaleBias: public FNModule
{
public:
	FNScaleBias(FNModule* sourceModule, float scale, float bias);
	~FNScaleBias();
	void setBias(float bias);
	void setScale(float scale);
	void setSourceModule(FNModule* sourceModule);
	float getNoise(double x, double y, double z);

private:
	float fn_scale;
	float fn_bias;
	FNModule* fn_sourceModule;
};
