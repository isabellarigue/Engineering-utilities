function x = normale(N,m,v)

    y = randn(1, N);
    x = (v^(1/2)).*y + m;

end