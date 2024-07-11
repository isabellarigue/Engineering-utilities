function x = bernoul(N, p)

x = zeros(1,N);   
for i = 1:N
    u = rand(1);     
    if u <= p
        x(i) = 1;
    end
end

end