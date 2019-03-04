% Run prediction over 5 time steps

x = (0);
x_dot = (0);
state_cov_matrix = get_state_cov_matrix(x, x_dot, R);