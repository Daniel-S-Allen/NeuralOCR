#pragma once
#ifndef ACTIVATION_FUNCTIONS
#define ACTIVATION_FUNCTIONS
#include <math.h>
namespace Activations {
	enum Activation {
		NONE,
		CLAMP,
		SMOOTHSTEP,
		SIGMOID
	};
	double sigmoid(double in) {
		return 1 / (1 + exp(-in));
		
	}
	double clamp(double in, double min = 0, double max = 1) {
		if (in < min)
			return min;
		if (in >= max)
			return max;
		return in;
	}
	double smoothStep(double in, double min = 0, double max = 1) {
		if (in < min)
			return min;
		if (in > max)
			return max;
		in = (in - min) / (max-min);
		return in * in * (3 - 2 * in);
	}
	double error(double actual, double ideal) {
		return pow(ideal - actual, 2) / 2;
	}
}
#endif