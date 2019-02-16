// KalmanFilter.hpp

#ifndef KALMAN_FILTER_H
#define KALMAN_FILTER_H
#include <eigen3/Eigen/Dense>
#include <math.h>
#include <opencv4/opencv.hpp>
using namespace Eigen;
using namespace cv;

struct gaussian {
	double mu;
	double sigma;
};

class KalmanFilter {
	public:
	KalmanFilter(Vector2d x, Vector2d u, double dt, gaussian epsilon);
	~KalmanFilter();
  MatrixXd& operator=(const MatrixXd & other);

	// void KalmanFilter::multivariateGaussian(Vector2d x, int mean, Matrix2d cov);
	void init();
	MatrixXd setSigma(cv &v);
	void setMean();
	int getAverage();

	gaussian update();

	MatrixXd getVectorMatrix(Vector2d v1, Vector2d v2);
	void setVectorMatrix(Vector2d v);
	void setMatrices();

	private:

  MatrixXd A, B, C, Q, R, P, K, P0;
	double t0, t, dt; // initial t, current t, and timestep
	int n; // num state dimensions
	Vector2d cur_x, new_x; // Estimated state vectors
	Vector2d cur_u, new_u; // Estimated control vectors
	MatrixXd I; // n-size identity
	gaussian epsilon;

};
#endif