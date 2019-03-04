function [mu_hat, sigma_hat] = predict_over_time(timestep, mu_prior, sigma_prior, control, R, A, B)
%Run prediction over certain # of times steps
    cur_mu = mu_prior;
    cur_sigma = sigma_prior;
    for k=1:timestep
        [cur_mu, cur_sigma] = prediction(cur_mu, cur_sigma, control, R, A, B);
        disp(cur_mu)
        disp(cur_sigma)
    end
    mu_hat = cur_mu;
    sigma_hat = cur_sigma;
end
