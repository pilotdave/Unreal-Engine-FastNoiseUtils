// Fill out your copyright notice in the Description page of Project Settings.

#include "FastNoiseUtils/Public/FNModule.h"


FNModule::FNModule()
{
	noise = new FastNoise();
}


FNModule::~FNModule()
{
	delete noise;
}

float FNModule::getNoise(double x, double y, double z)
{
	return noise->GetNoise(x,y,z);
}


float FNModule::getNoise(double x, double y) {
	return noise->GetNoise(x, y);
}




void FNModule::setSeed(int seed)
{
	noise->SetSeed(seed);

}

void FNModule::setFrequency(float frequency)
{
	noise->SetFrequency(frequency);

}

void FNModule::setNoiseType(FastNoise::NoiseType noiseType)
{
	noise->SetNoiseType(noiseType);

}

void FNModule::setCellularDistanceFunction(FastNoise::CellularDistanceFunction cellularDistanceFunction)
{
	noise->SetCellularDistanceFunction(cellularDistanceFunction);

}

void FNModule::setCellularReturnType(FastNoise::CellularReturnType cellularReturnType)
{
	noise->SetCellularReturnType(cellularReturnType);

}

void FNModule::setFractalType(FastNoise::FractalType fractalType)
{
	noise->SetFractalType(fractalType);

}

void FNModule::setInterp(FastNoise::Interp interpolation)
{
	noise->SetInterp(interpolation);

}

void FNModule::setOctaves(int octaves)
{
	noise->SetFractalOctaves(octaves);

}

void FNModule::setLacunarity(float lacunarity)
{
	noise->SetFractalLacunarity(lacunarity);

}

void FNModule::setFractalGain(float fractalGain)
{
	noise->SetFractalGain(fractalGain);

}


