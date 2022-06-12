#include <bits/stdc++.h>
#include "Util.h"
#include "Data.h"
#include "Eigen/eigen-3.4.0/Eigen/Dense"

using namespace std;

using Eigen::MatrixXd;

#define NUMBER_OF_LAYERS LAYER_SIZES.size()
vector<int> LAYER_SIZES = {4, 4, 2, 2};

int main(int argc, char* argv[]) {
    srand(time(NULL));
    cin.tie(0);
    ios::sync_with_stdio(0);

    Data input_data;
    Util::ReadData(input_data, argv[1]);

    vector<Eigen::MatrixXd> layers(NUMBER_OF_LAYERS);
    vector<Eigen::MatrixXd> weights(NUMBER_OF_LAYERS - 1);
    vector<Eigen::MatrixXd> biases(NUMBER_OF_LAYERS - 1);

    Util::InitializeNetwork(input_data, layers, weights, biases, LAYER_SIZES);

    cout << "========\n"
         << "Layers\n"
         << "========\n\n\n";

    for (auto l : layers)
        cout << l << "\n\n\n";

    cout << "========\n"
         << "Weights\n"
         << "========\n\n\n";

    for (auto m : weights)
        cout << m << "\n\n\n";

    Util::FeedForward(layers, weights, LAYER_SIZES);

    cout << "========\n"
         << "Layers\n"
         << "========\n\n\n";

    for (auto l : layers)
        cout << l << "\n\n\n";

    cout << "========\n"
         << "Weights\n"
         << "========\n\n\n";

    for (auto m : weights)
        cout << m << "\n\n\n";

    cout << "========\n"
         << "Biases\n"
         << "========\n\n\n";

    for (auto b : biases)
        cout << b << "\n\n\n";
}