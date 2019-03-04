function sigma_cur = get_sigma_sq(s)
% calculate sigma
    s_m = mean(s);
    n = size(s);
    sum = 0;
    for k=1:n
        sum = sum + (s(k)- s_m);
    end
    sigma_cur = (total/n)^2;
end
