// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FN.h"
#include "FastNoise.h"

/**
 * 
 */
class SANDBOXGAME_API FNSelect: public FN
{
public:
	FNSelect();
	~FNSelect();

	float getNoise(double x, double y, double z);
	float getNoise(double x, double y);
	void SetBounds(double lowerBound, double upperBound);
	void SetEdgeFalloff(double edgeFalloff);
	void SetControlModule(FN* ctrlModule);
	void SetSourceModules(FN* module1, FN* module2);

	private:
		FN * controlModule;
		FN* noiseModule1;
		FN* noiseModule2;

		double m_lowerBound = -1;
		double m_upperBound = 1;
		double m_edgeFalloff = 0;

		// helper functions
		double SCurve3(double a);
		double LinearInterp(double n0, double n1, double a);

	
};
