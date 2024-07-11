% TP4 S6 2023-2024 Optimisation non linéaire avec contraintes
function [J,gJ,HJ] = fobj(x,choixpb)

% calcul de la fonction objectif
switch choixpb
    case 1 
		J = -3*x(1)+0.5*x(2)^2;
    case 2 
        J = 4*x(1)^2-6*x(1)*x(2)+10*x(2)^2;
    case 3 
        J = 2*((x(1)-5)^2+(x(2)-10)^2)+1.5*((x(1)-10)^2+(x(2)-5)^2)...
            +2*(x(1)^2+(x(2)-12)^2)+3*((x(1)-12)^2+x(2)^2);
end
if (nargout > 1) % vecteur gradient 
    switch choixpb
        case 1  
            gJ(1) = -3;
            gJ(2) = x(2);
        case 2 
            gJ(1) = 8*x(1)-6*x(2);
            gJ(2) = -6*x(1)+20*x(2);
        case 3 
            gJ(1) = 17*x(1)-122;
            gJ(2) = 17*x(2)-103;
    end

    if (nargout > 2) % matrice hessienne 
        switch choixpb
            case 1 
                HJ = [0 0; 0 1];
            case 2 
                HJ = [8 -6; -6 20];
            case 3 
                HJ = [17 0; 0 17];
        end
    end
end
    
