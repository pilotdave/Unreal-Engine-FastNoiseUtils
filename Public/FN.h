
#pragma once

#include "BiomeEnum.h"
#include "CoreMinimal.h"

/* This is the interface for a FastNoise Util module */
class FN {

public:
	FN();
	virtual ~FN();
	virtual float getNoise(double x, double y, double z) = 0;
	virtual float getNoise(double x, double y) = 0;
};