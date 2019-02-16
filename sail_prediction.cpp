using namespace std;
#include <vector> 

struct mean_and_var {
	vector<int>mean;
	int covariance;
};

struct outcome_probability {
	int outcome;
	int probability;	
};

vector<int> err (2, 0); // err has same dimensionality as state vector

int main() {
	vector<int> x (2, 1); // 2 params, position and velocity
	return 0;
}

// --------------------- MATRIX GETTERS --------------------//
// vector<int> get_A(vector<int>prev_mean) {
// 	vector<vector<int> > a(prev_mean, prev_mean);
// 	return a;
// }

int expected_value(outcome_probability vals[], int size) {
	int exp_val = 0;
	for(int i=0; i<size; i++) {
		exp_val += (vals[i].probability) * (vals[i].outcome);
	};
	return exp_val;
}

vector<int> multivariate_normal_dist() {

}


// --------------------- /MATRIX GETTERS -------------------//
// --------------------------------------------------------//

// ------------------------ KALMAN GAIN --------------------//
// --------------------------------------------------------//


// --------------------- /KALMAN GAIN ----------------------//
// --------------------------------------------------------//



// ---------------------- PREDICTION -----------------------//
// --------------------------------------------------------//
vector<int> predict_mean(vector<int>x_prev, vector<int>control) {
	// vector<int>a = x_prev * x_prev; TODO: make sure i'm A correctly ([][]?).
	// μ ̄t = Atμt−1 + Bt * ut
	vector<int> new_mean;
	return new_mean;
}

int predict_covariance(int prev_cov, int err_in_est, int err_in_meas) {
	return 0;
	// Σ ̄t = AtΣt−1 * ATt + R_t
}

mean_and_var predict(vector<int>prev_mean, int prev_cov, vector<int>control) {
	vector<int>pred_mean = predict_mean(prev_mean, control);
	int pred_cov = predict_covariance(prev_cov);
}

// ---------------------- \PREDICTION -----------------------//
// --------------------------------------------------------//


// ------------------------ UPDATE ------------------------//
// --------------------------------------------------------//

// int kalman_gain(int pred_cov, ) {

// }

// ------------------------ \UPDATE ------------------------//
// --------------------------------------------------------//

mean_and_var kalman_filter(vector<int>prev_mean, int prev_cov, vector<int>control, vector<int>obs) {
	mean_and_var predictions = predict(prev_mean, prev_cov, control);

	// step 4: calc Kalman gain (specifies the degree to which new measurement is incorporated into new state estimate)

	// int upd_cov = update_cov; step 5: update cov given measurement
	// return mean_and_var({upd_mean, upd_cov}; return it all
}
