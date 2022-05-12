#include "NeuralNetwork.h"
#include <functional>


NeuralNetwork::NeuralNetwork(bool randomValues, std::vector<int> dimensions)
{
	hiddenLayers.clear();
	if (dimensions.size() == 0) {
		Logger::log("Dimension size was 0", Logger::LOGGING_LEVEL::LOG_ERROR);
		throw std::exception("Illegal arguments");
		return;
	}
	hiddenLayers.push_back(Layer(dimensions[0], dimensions[0], randomValues));
	for (int i = 1; i < dimensions.size(); i++) {
		hiddenLayers.push_back(Layer(dimensions[i], dimensions[i-1], randomValues));
	}
}

NeuralNetwork::NeuralNetwork(std::vector<std::vector<double>> weights, std::vector<std::vector<double>> biases)
{

}

void NeuralNetwork::train(std::vector<double> inputs, std::vector<double> outputs)
{
	Logger::log("Training neural network", Logger::LOGGING_LEVEL::LOG_INFORMATION);
	if (inputs.size() != outputs.size()) {
		Logger::log("Array size mismatch", Logger::LOGGING_LEVEL::LOG_ERROR);
		throw std::exception("Array mismatch");
		return;
	}
	double error = 0;
	std::vector<double> estimates = estimate(inputs);
	for (int i = 0; i < estimates.size(); i++) {
		error += Activations::error(estimates[i], outputs[i]);
	}
}
std::vector<double> NeuralNetwork::estimate(std::vector<double> inputs)
{
	std::vector<double> output;
	if (hiddenLayers.size() > 0) {
		hiddenLayers[0].pass(inputs);
		for (size_t i = 1; i < hiddenLayers.size(); i++) {
			hiddenLayers[i].pass(hiddenLayers[i - 1].get());
		}
		return hiddenLayers[hiddenLayers.size() - 1].get();
	}
	return output;
}