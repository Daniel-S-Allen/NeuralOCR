#include "Layer.h"
Layer::Layer(int dimensions, int lastDimensions, bool randomValues = false) {
	neurons.clear();
	for (int i = 0; i < dimensions; i++) {
		neurons.push_back(Neuron(lastDimensions, randomValues));
	}
}

std::vector<double> Layer::get()
{
	return outputs;
}

void Layer::pass(std::vector<double> inputs) {
	this->inputs = inputs;
	this->outputs.clear();
	for (int i = 0; i < neurons.size(); i++){
		Neuron n = neurons[i];
		double value = n.calc(inputs);
		outputs.push_back(value);
	}
}