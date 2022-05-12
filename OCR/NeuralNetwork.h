#pragma once
#include <vector>
#include "Layer.h"
#include "Tuple.h"
#include "Logger.h"
class NeuralNetwork
{
	NeuralNetwork(bool randomValues, std::vector<int> dimensions);
	NeuralNetwork(std::vector<std::vector<double>> weights, std::vector<std::vector<double>> biases);

	std::vector<Layer> hiddenLayers;
	void train(std::vector<double> inputs, std::vector<double> outputs);
	std::vector<double> estimate(std::vector<double> inputs);
};

