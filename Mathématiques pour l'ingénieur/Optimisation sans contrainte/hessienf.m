% TP3 S6 2023-2024 Optimisation sans contrainte
function H = hessienf(x,choixf)
% calcule la matrice hessienne de la fonction choixf en x, x dans Rn
H = zeros(length(x));
switch choixf
    case 0
        H = [2,0;0,2];
    case 1
        H(1,1) = 12*x(1)^2+6*x(1)-1.5;
        H(2,2) = 12*x(2)^2-4; 
    case 2
        H(1,1) = exp(x(1)); H(2,2) = 2;
    case 3
        H = [2 1 0;1 2 -1;0 -1 3];
    otherwise
        disp('pb avec choixf')
end
