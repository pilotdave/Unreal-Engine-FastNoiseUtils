// Fill out your copyright notice in the Description page of Project Settings.

#include "FastNoiseUtils/Public/FNAdd.h"


FNAdd::FNAdd(FN* sourceModule1, FN * sourceModule2)
{
	fn_sourceModule1 = sourceModule1;
	fn_sourceModule2 = sourceModule2;
}

FNAdd::FNAdd() {

}


FNAdd::~FNAdd()
{
}


void FNAdd::setSourceModules(FN * sourceModule1, FN * sourceModule2)
{
	fn_sourceModule1 = sourceModule1;
	fn_sourceModule2 = sourceModule2;
}

float FNAdd::getNoise(double x, double y, double z)
{
	return fn_sourceModule1->getNoise(x, y, z) + fn_sourceModule2->getNoise(x, y, z);
}

float FNAdd::getNoise(double x, double y)
{
	return fn_sourceModule1->getNoise(x, y) + fn_sourceModule2->getNoise(x, y);
}





