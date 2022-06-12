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

    Util::InitializeNetwork(input_data, layers, weights, LAYER_SIZES);

    cout << "Input Layer: \n"
         << layers[0] << "\n\n";

    for (auto m : weights) {
        cout << m << "\n\n\n";
    }
}