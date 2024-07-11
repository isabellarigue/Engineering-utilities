function [x,Jval,residu,lambda,exit] = lsqlineq(C,d,Aeq,beq)
    A = [C'*C Aeq'; Aeq zeros(size(Aeq,1))];
    b = [C'*d; beq];
    res = linsolve(A, b);
    n = size(C,2);
    x = res(1:n);
    lambda = res(n + 1:n + size(Aeq,1));
    residu = C*x-d;
    Jval = 0.5*norm(residu)^2;
    exit = 1;
end
