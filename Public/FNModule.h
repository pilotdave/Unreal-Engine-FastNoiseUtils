// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FastNoise.h"
#include "FN.h"
#include "CoreMinimal.h"

/**
*
*/
class SANDBOXGAME_API FNModule: public FN
{
public:
	FNModule();
	~FNModule();

	float getNoise(double x, double y, double z);
	float getNoise(double x, double y);

	void setSeed(int seed);
	void setFrequency(float frequency);
	void setNoiseType(FastNoise::NoiseType noiseType);
	void setCellularDistanceFunction(FastNoise::CellularDistanceFunction cellularDistanceFunction);
	void setCellularReturnType(FastNoise::CellularReturnType cellularReturnType);
	void setFractalType(FastNoise::FractalType fractalType);
	void setInterp(FastNoise::Interp interpolation);
	void setOctaves(int octaves);
	void setLacunarity(float lacunarity);
	void setFractalGain(float fractalGain);

private:
	FastNoise * noise; //internal noise calculator
	
};
