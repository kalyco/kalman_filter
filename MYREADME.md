
### Summary
The Kalman filter produces an estimate of the state of the system as the mean of the system's predicted state  and of the new measurement using a weighted average  


## Book Notes: Terms to know

### Weights
The purpose of the weights is that values with better (i.e., smaller) estimated uncertainty are "trusted" more.  

The weights are calculated from the covariance  

### Covariance
A measure of the estimated uncertainty of the prediction of the system's state.  

The relative certainty of the measurements and current state estimate is an important consideration, and it is common to discuss the response of the filter in terms of the Kalman filter's gain.

### Kalman Gain

The Kalman gain is the relative weight given to the measurements and current state estimate, and can be "tuned" to achieve particular performance.

With a high gain, the filter places more weight on the most recent measurements, and thus follows them more responsively. 

With a low gain, the filter follows the model predictions more closely.

At the extremes, a high gain close to one will result in a more jumpy estimated trajectory, while low gain close to zero will smooth out noise but decrease the responsiveness.

## Practice

When performing the actual calculations for the filter, the state estimate and covariances are coded into matrices to handle the multiple dimensions involved in a single set of calculations.
This allows for a representation of linear relationships between different state variables (such as position, velocity, and acceleration) in any of the transition models or covariances.