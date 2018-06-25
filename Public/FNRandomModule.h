// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <list>
#include "FN.h"
#include "FastNoise.h"

/**
 * 
 */
class SANDBOXGAME_API FNRandomModule: public FN
{
public:
	FNRandomModule();
	~FNRandomModule();

	float getNoise(double x, double y, double z);
	float getNoise(double x, double y);

	void addModuleToPool(FN* newModule);
	void dice();


private:
	FN * activeModule;
	std::list<FN*>* modulePool = {};
	int seed = 1793;

	
};
