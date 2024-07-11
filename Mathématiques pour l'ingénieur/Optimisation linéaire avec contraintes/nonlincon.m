% TP4 S6 2023-2024 Optimisation non linéaire avec contraintes
function [c,ceq,gc,gceq] = nonlincon(x,choixpb)
% contraintes non linéaires c(x) <= 0, ceq(x) = 0
% et leurs gradients gc(x) et gceq(x)  
switch choixpb
   case 1 
   	c = x(1)^2+x(2)^2-1;
    ceq = [];
   case 2
    c = [];
    ceq = x(1)^2+x(2)^2-1;
   case 3
    c = [100-(x(1)+5)^2-(x(2)-10)^2; 100-(x(1)-5)^2-x(2)^2];
    ceq = [];
   otherwise
      c = []; ceq = [];
end
if (nargout > 2) % calcul des gradients
    switch choixpb
        case 1 
            gc = [2*x(1); 2*x(2)];
            gceq = [];
        case 2 
            gc = [];
            gceq = [2*x(1); 2*x(2)];
        case 3 
            gc = -[2*(x(1)+5) 2*(x(2)-10); 2*(x(1)-5) 2*x(2)];
            gceq = [];
           
        otherwise
            gc = []; gceq = [];
    end
end
