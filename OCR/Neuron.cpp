#include "Neuron.h"

Neuron::Neuron(int size, bool randomValues)
{
    this->biases.clear();
    this->weights.clear();
    for (int i = 0; i < size; i++) {
        double bias = 0;
        if (randomValues) {
            bias = rand();
        }
        double weight = 0;
        if (randomValues) {
            weight = rand();
        }
        biases.push_back(bias);
        weights.push_back(weight);
    }
}

Neuron::Neuron(std::vector<double> biases, std::vector<double> weights)
{
    this->biases = biases;
    this->weights = weights;
}

double Neuron::calc(std::vector<double> inputs)
{
    double val = 0;
    for (int i = 0; i < inputs.size(); i++) {
        val += inputs[i] * weights[i] + biases[i];
    }
    this->value = Activations::sigmoid(val);
    return this->value;
}
