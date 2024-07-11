% TP3 S6 2023-2024 Optimisation sans contrainte
function g = gradf(x,choixf)
% calcule le gradient de la fonction choixf en x, x dans Rn

g = zeros(size(x));
switch choixf
    case 0
        g(1)=2*(x(1)-1); 
        g(2)=2*x(2);
    case 1
        g(1)=4*(x(1)-0.5)*(x(1)+1)*(x(1)+0.25);
        g(2)=4*x(2)*(x(2)+1)*(x(2)-1);
    case 2
        g(1)=exp(x(1))-1;
        g(2)=2*x(2)+1;
    case 3
        g(1)=2*x(1)+x(2)-9;
        g(2)=x(1)+2*x(2)-x(3)-1;
        g(3)=-x(2)+3*x(3)-7;
    otherwise
        disp('pb avec choixf')
end
