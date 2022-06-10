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
    for(int col = 0; col < matrix.cols(); col++){
        matrix(0, col) = 1/(1+exp(-(matrix(0, col))));
    }
}