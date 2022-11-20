#pragma once
#include <vector>
#include <Eigen/Dense>
using namespace std;

vector<Eigen::Vector4d> Gram_Schmidt(const unsigned int n, vector<Eigen::Vector4d>& arr);
double Dot_product(Eigen::Vector4d& a, Eigen::Vector4d& b);
