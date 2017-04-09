#include <iostream>
#include "tools.h"

using Eigen::VectorXd;
using Eigen::MatrixXd;
using std::vector;

Tools::Tools() {}

Tools::~Tools() {}

VectorXd Tools::CalculateRMSE(const vector<VectorXd> &estimations,
                              const vector<VectorXd> &ground_truth) {
  VectorXd rmse(4);
  rmse << 0, 0, 0, 0;
  if ((estimations.size() == 0) || (estimations.size() != ground_truth.size())){
    std::cout << "Please check estimations and ground_truth size" << std::endl;
    return rmse;
  }

  for (int i=0; i<estimations.size(); i++){
    VectorXd diff = estimations[i] - ground_truth[i];
    diff = diff.array() * diff.array();
    rmse += diff;
  }
  rmse /= estimations.size();
  rmse = rmse.array().sqrt();

  return rmse;
}
