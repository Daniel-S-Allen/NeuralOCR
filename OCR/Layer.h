#pragma once
#include <vector>
#include "Neuron.h"
class Layer
{
private:
	std::vector<double> inputs;
	std::vector<double> outputs;
public:
	Layer(int dimensions, int lastDimensions, bool randomValues);
	std::vector<Neuron> neurons;
	std::vector<double> get();
	void pass(std::vector<double> inputs);
};

