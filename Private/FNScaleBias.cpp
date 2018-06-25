// Fill out your copyright notice in the Description page of Project Settings.

#include "FastNoiseUtils/Public/FNScaleBias.h"


FNScaleBias::FNScaleBias(FN* sourceModule, float scale, float bias) {
	setScale(scale);
	setBias(bias);
	fn_sourceModule = sourceModule;
}


FNScaleBias::~FNScaleBias()
{
}

void FNScaleBias::setBias(float bias)
{
	fn_bias = bias;
}

void FNScaleBias::setScale(float scale)
{
	fn_scale = scale;
}

void FNScaleBias::setSourceModule(FN* sourceModule)
{
	fn_sourceModule = sourceModule;
}

float FNScaleBias::getNoise(double x, double y, double z)
{
	return (fn_sourceModule->getNoise(x, y, z) * fn_scale) + fn_bias;
}

float FNScaleBias::getNoise(double x, double y)
{
	return (fn_sourceModule->getNoise(x, y) * fn_scale) + fn_bias;
}


