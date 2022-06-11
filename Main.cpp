#include <bits/stdc++.h>
#include "Util.h"
#include "Data.h"
#include "Eigen/eigen-3.4.0/Eigen/Dense"

using namespace std;

using Eigen::MatrixXd;

#define INPUT_SIZE 4
#define OUTPUT_SIZE 1

vector<int> LAYER_SIZES = {INPUT_SIZE, 4, 2, OUTPUT_SIZE};
#define NUMBER_OF_LAYERS LAYER_SIZES.size()

int main(int argc, char* argv[]) {
    srand(time(NULL));
    cin.tie(0);
    ios::sync_with_stdio(0);

    Data input_data;
    Util::ReadData(input_data, argv[1]);

    vector<Eigen::MatrixXd> layers(NUMBER_OF_LAYERS);
    vector<Eigen::MatrixXd> weights(NUMBER_OF_LAYERS - 1);

    // Initialize the first layer
    Eigen::MatrixXd input_layer(1, INPUT_SIZE);
    for (int i = 1; i < input_data.table[0].size(); i++)
        input_layer(0, i - 1) = input_data.table[3][i];
    layers[0] = input_layer;

    // Initialize the weights

    // Weights for the input layer
    Eigen::MatrixXd weights_input(INPUT_SIZE, LAYER_SIZES[1]);
    for (int row = 0; row < weights_input.rows(); row++)
        for (int col = 0; col < weights_input.cols(); col++)
            weights_input(row, col) = ((double)rand() / (RAND_MAX)) * 2 - 1;
    weights[0] = weights_input;

    // Weights for the hidden layers
    for (int i = 1; i < NUMBER_OF_LAYERS - 2; i++) {
        Eigen::MatrixXd weights_layer(LAYER_SIZES[i], LAYER_SIZES[i + 1]);
        for (int row = 0; row < weights_layer.rows(); row++)
            for (int col = 0; col < weights_layer.cols(); col++)
                weights_layer(row, col) = ((double)rand() / (RAND_MAX)) * 2 - 1;
        weights[i] = weights_layer;
    }

    Eigen::MatrixXd weights_last(LAYER_SIZES[NUMBER_OF_LAYERS - 2], OUTPUT_SIZE);
    for (int row = 0; row < weights_last.rows(); row++)
        for (int col = 0; col < weights_last.cols(); col++)
            weights_last(row, col) = ((double)rand() / (RAND_MAX)) * 2 - 1;
    weights[NUMBER_OF_LAYERS - 2] = weights_last;

    cout << "Input Layer: \n"
         << layers[0] << "\n\n";

    for (auto m : weights) {
        cout << m << "\n\n\n";
    }
}