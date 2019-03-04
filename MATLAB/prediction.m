function [mu_hat, sigma_hat] = prediction(mu_prior, sigma_prior, control, R, A, B)
    % Takes the prior state gaussan and updates beliefs 
    % before new measurements
    mu_hat = (A.*mu_prior) + (B.*control);
    sigma_hat = ((A*sigma_prior)*A') + R;
end