// Fill out your copyright notice in the Description page of Project Settings.

#include "FastNoiseUtils/Public/FNRandomModule.h"


FNRandomModule::FNRandomModule() {
	modulePool = new std::list<FN*>();
}


FNRandomModule::~FNRandomModule()
{
	delete modulePool;
}



float FNRandomModule::getNoise(double x, double y, double z)
{
	return activeModule->getNoise(x, y, z);
}

float FNRandomModule::getNoise(double x, double y)
{
	return activeModule->getNoise(x,y);
}

void FNRandomModule::addModuleToPool(FN* newModule)
{
	modulePool->push_back(newModule);
	dice();
}



// randomly sets new acitve module
void FNRandomModule::dice()
{
	// get length of pool list
	size_t poolSize = modulePool->size();

	// set random module
	int activeModuleIndex = rand() % poolSize;

	// get module from list
	int i = 0;
	for (FN* m : *modulePool) {
		if (i == activeModuleIndex) {
			activeModule = m;
			break;
		}
		i++;
	}
}


