// Kalman_Filter.cpp 
#include "KalmanFilter.h"
#include <math.h>
#include <opencv4/opencv.hpp>
using namespace Eigen;
using namespace cv;

// Constructor
KalmanFilter::KalmanFilter(Vector2d x, Vector2d u, double dt, gaussian epsilon):
	dt(dt), cur_u(u), epsilon(epsilon), I(x.size(), x.size()), t0(0), t(0)
{
	// Set mean to initial state dimensions.
	// Get intiial covariance of both values.
 	// Vector2d cur_x(Vector2d (x[0], x[1]), setSigma(x[0], x[1]));
	init();
}

void KalmanFilter::init() {
	this->n = cur_x.size();
	setMatrices();
}

void KalmanFilter::setMean(Mat &v) {
	Map<Eigen::Matrix<float,Dynamic,Dynamic,Eigen::RowMajor> > 
	mappedMat((float *)v.data(),1,v.size()) ;
	_mu=mappedMat;
}

void setSigma(cv::Mat &v)
{
    Map<Eigen::Matrix<float,Dynamic,Dynamic,Eigen::RowMajor> > 
    mappedMat((float *)v.data,v.rows,v.cols) ;
    _Sigma=mappedMat;
    _dim=v.rows;
    _det=_Sigma.determinant();
    _scale=1.f/(pow(2*PI*_dim*_det,0.5));
    _invsigma=_Sigma.inverse();
}

void KalmanFilter::setMatrices() {
		this->A = MatrixXd(n, n);
		this->B = MatrixXd(n, cur_u.size());
		// this->R = getSigma();
		this->A << 1, dt, 0, 1; // TODO: calculate these properly
		this->B << 0, 0, 0, 0;
		this->I.setIdentity();
}

// MatrixXd KalmanFilter::setSigma(double x, double y) {
// 	MatrixXd m;
// 	return m;
// }

// void KalmanFilter::multivariateGaussian(Vector2d x, int mean, Matrix2d cov) {
// }

MatrixXd KalmanFilter::getVectorMatrix(Vector2d v1, Vector2d v2) {
	MatrixXd m(v1.size(), v2.size());
	return m;
}

//
//gaussian KalmanFilter::update() {
//	gaussian prediction;
//	mu_prior = this->A * this->prev_state;
//	sigma_prior = ((this->A) * (this->sigma_prior * this->A)) + this->R;
//	return prediction;
//}



// int getMean(Array vals) {
// 	int total = 0;
// 	for (int i=0; i<=vals.length(); i++) total += vals[i];
// 	return total / vals.length();
// }

// int getVariance(int mean, Array vals) {
// 	int total = 0;
// 	for(int i=0; i<=vals.length(); i++) {
// 		total += (mean - vals[i]);
// 	}
// 	return (total / vals.length()) ^ 2;
// }

// int getCovariance(Array x_vals, int x_mean, Array y_vals, int y_mean) {
// 	if (x_vals.length() != y_vals.length()) return 0;
// 	int total = 0;
//  	for(int i; i<=x_vals.length(); i++) {
// 		 total += (x_mean - x_vals[i]) * (y_mean - y_vals[i]); 
// 	}
// 	return total / x_vals.length();
// }

MatrixXd getCovarianceMatrix(int x_variance, int y_variance) {
	MatrixXd c(2, 2);
	c(0,0) = x_variance;
	c(0,1) = x_variance * y_variance;
	c(1,0) = y_variance;
	c(1,1) = y_variance * x_variance;
	return c;
}
