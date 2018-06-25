// Fill out your copyright notice in the Description page of Project Settings.

#include "FastNoiseUtils/Public/FNExponent.h"


FNExponent::FNExponent(FN* sourceModule, float exponent) {
	fn_sourceModule = sourceModule;
	fn_exponent = exponent;
}


FNExponent::~FNExponent()
{
}

void FNExponent::setExponent(float exponent)
{
	fn_exponent = exponent;
}


void FNExponent::setSourceModule(FN* sourceModule)
{
	fn_sourceModule = sourceModule;
}

float FNExponent::getNoise(double x, double y, double z)
{
	return pow(fn_sourceModule->getNoise(x, y, z), fn_exponent);
}

float FNExponent::getNoise(double x, double y)
{
	return pow(fn_sourceModule->getNoise(x, y), fn_exponent);
}


