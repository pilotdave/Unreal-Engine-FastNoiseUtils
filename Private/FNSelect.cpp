// Fill out your copyright notice in the Description page of Project Settings.

#include "FastNoiseUtils/Public/FNSelect.h"

FNSelect::FNSelect()
{
}

FNSelect::~FNSelect()
{
}


void FNSelect::SetBounds(double lowerBound, double upperBound) {
	m_lowerBound = lowerBound;
	m_upperBound = upperBound;

	// Make sure that the edge falloff curves do not overlap.
	SetEdgeFalloff(m_edgeFalloff);
}


void FNSelect::SetEdgeFalloff(double edgeFalloff){
	// Make sure that the edge falloff curves do not overlap.
	double boundSize = m_upperBound - m_lowerBound;
	m_edgeFalloff = (edgeFalloff > boundSize / 2) ? boundSize / 2 : edgeFalloff;
}

void FNSelect::SetControlModule(FNModule * ctrlModule)
{
	controlModule = ctrlModule;
}

void FNSelect::SetSourceModules(FNModule* module1, FNModule* module2)
{
	noiseModule1 = module1;
	noiseModule2 = module2;
}




float FNSelect::getNoise(double x, double y, double z)
{
	double alpha;
	if (m_edgeFalloff > 0.0) {
		if (controlModule->getNoise(x,y,z) < (m_lowerBound - m_edgeFalloff)) {
			// The output value from the control module is below the selector
			// threshold; return the output value from the first source module.
			return noiseModule1->getNoise(x,y,z);
		}
		else if (controlModule->getNoise(x, y, z) < (m_lowerBound + m_edgeFalloff)) {
			// The output value from the control module is near the lower end of the
			// selector threshold and within the smooth curve. Interpolate between
			// the output values from the first and second source modules.
			double lowerCurve = (m_lowerBound - m_edgeFalloff);
			double upperCurve = (m_lowerBound + m_edgeFalloff);
			alpha = SCurve3((controlModule->getNoise(x, y, z) - lowerCurve) / (upperCurve - lowerCurve));
			return LinearInterp(noiseModule1->getNoise(x,y,z), noiseModule2->getNoise(x,y,z), alpha);

		}
		else if (controlModule->getNoise(x, y, z) < (m_upperBound - m_edgeFalloff)) {
			// The output value from the control module is within the selector
			// threshold; return the output value from the second source module.
			return noiseModule2->getNoise(x, y, z);

		}
		else if (controlModule->getNoise(x, y, z) < (m_upperBound + m_edgeFalloff)) {
			// The output value from the control module is near the upper end of the
			// selector threshold and within the smooth curve. Interpolate between
			// the output values from the first and second source modules.
			double lowerCurve = (m_upperBound - m_edgeFalloff);
			double upperCurve = (m_upperBound + m_edgeFalloff);
			alpha = SCurve3(
				(controlModule->getNoise(x, y, z) - lowerCurve) / (upperCurve - lowerCurve));
			return LinearInterp(noiseModule2->getNoise(x, y, z), noiseModule1->getNoise(x, y, z), alpha);

		}
		else {
			// Output value from the control module is above the selector threshold;
			// return the output value from the first source module.
			return noiseModule1->getNoise(x, y, z);
		}
	}
	else {
		if (controlModule->getNoise(x, y, z) < m_lowerBound || controlModule->getNoise(x, y, z) > m_upperBound) {
			return noiseModule1->getNoise(x, y, z);
		}
		else {
			return noiseModule2->getNoise(x, y, z);
		}
	}
}


// util functions (copied from libnoise "interp.h")
double inline FNSelect::SCurve3(double a)
{
	return (a * a * (3.0 - 2.0 * a));
}

double inline FNSelect::LinearInterp(double n0, double n1, double a)
{
	return ((1.0 - a) * n0) + (a * n1);
}

