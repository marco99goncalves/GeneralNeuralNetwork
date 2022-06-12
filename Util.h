#pragma once
using namespace std;

#include "Data.h"
#include "Eigen/eigen-3.4.0/Eigen/Dense"

namespace Util {
void ReadData(Data &data, string filename);
void Sigmoid(Eigen::MatrixXd &matrix);
void InitializeNetwork(Data &input_data, vector<Eigen::MatrixXd> &layers, vector<Eigen::MatrixXd> &weights, const vector<int> &LAYER_SIZES);
};