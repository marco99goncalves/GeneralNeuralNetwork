#include "Util.h"

void Util::ReadData(Data &data, string filename) {
    fstream file(filename, ios::in);
    string line, word;
    if (file.is_open()) {
        while (getline(file, line)) {
            vector<double> row;
            stringstream str(line);
            while (getline(str, word, ','))
                row.push_back(stod(word));
            data.table.push_back(row);
        }
    }

    file.close();
}

void Util::Sigmoid(Eigen::MatrixXd &matrix) {
    for (int col = 0; col < matrix.cols(); col++) {
        matrix(0, col) = 1 / (1 + exp(-(matrix(0, col))));
    }
}

/**
 * Initializes the network with random weights and the first test case in the inputs.
**/
void Util::InitializeNetwork(Data &input_data, vector<Eigen::MatrixXd> &layers, vector<Eigen::MatrixXd> &weights, const vector<int> &LAYER_SIZES) {
    // Initialize the first layer
    int NUMBER_OF_LAYERS = LAYER_SIZES.size();
    int INPUT_SIZE = LAYER_SIZES[0];
    int OUTPUT_SIZE = LAYER_SIZES[NUMBER_OF_LAYERS - 1];

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
}