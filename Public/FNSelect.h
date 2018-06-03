// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FNModule.h"
#include "FastNoise.h"

/**
 * 
 */
class SANDBOXGAME_API FNSelect: public FNModule
{
public:
	FNSelect();
	~FNSelect();

	float getNoise(double x, double y, double z);
	void SetBounds(double lowerBound, double upperBound);
	void SetEdgeFalloff(double edgeFalloff);
	void SetControlModule(FNModule* ctrlModule);
	void SetSourceModules(FNModule* module1, FNModule* module2);

	private:
		FNModule* controlModule;
		FNModule* noiseModule1;
		FNModule* noiseModule2;

		double m_lowerBound = -1;
		double m_upperBound = 1;
		double m_edgeFalloff = 0;

		// helper functions
		double SCurve3(double a);
		double LinearInterp(double n0, double n1, double a);

	
};
