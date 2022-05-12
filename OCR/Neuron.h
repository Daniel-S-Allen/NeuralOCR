#pragma once
#include <vector>
#include "Activations.h"
class Neuron
{
public:
	Neuron(int size, bool randomValues);
	Neuron(std::vector<double> biases, std::vector<double> weights);
	std::vector<double> biases;
	std::vector<double> weights;
	double value = 0;
	double calc(std::vector<double> inputs);
};

