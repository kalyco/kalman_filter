function state_cov_matrix = get_state_cov_matrix(x, x_dot, R)
%Get prior sigma for update step
   state_cov_matrix = get_cov(x, x_dot) + R;
end
