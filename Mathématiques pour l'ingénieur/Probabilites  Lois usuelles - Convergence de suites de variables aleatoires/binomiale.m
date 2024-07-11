function x = binomiale(N, n, p)
    x = zeros(N,1);
    for i=1:N
        U = rand(1,n);     
        U = U <= p;
        x(i) = sum(U);   
    end
end