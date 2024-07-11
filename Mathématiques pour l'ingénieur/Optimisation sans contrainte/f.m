% TP3 S6 2023-2024 Optimisation sans contrainte
function y = f(x,choixf)
% calcule la valeur de la fonction choixf en x, x dans Rn

switch choixf
    case 0
        y = (x(1)-1)^2+x(2)^2;% min en (1,0)
    case 1
        y = (x(1)-0.5)^2*(x(1)+1)^2+(x(2)+1)^2*(x(2)-1)^2;
        % min global (qui vaut 0) en (-1,1),(0.5,1),(-1,-1),(0.5,-1)
        % et max local (qui vaut 1.3164) en (-0.25,0)
        % points selles aux 4 autres points stationnaires :
        % (-1,0), (-0.25,1), (-0.25,-1), (0.5,0)
    case 2
        y = exp(x(1))-x(1)+x(2)^2+x(2);
        % min global strict en (0,-0.5), qui vaut 1.75
    case 3
        y = x(1)^2+x(1)*x(2)+x(2)^2-x(2)*x(3)+1.5*x(3)^2-9*x(1)-x(2)-7*x(3);
        % min global strict en (5,-1,2), qui vaut -29
    otherwise
        disp('pb avec choixf')
end
