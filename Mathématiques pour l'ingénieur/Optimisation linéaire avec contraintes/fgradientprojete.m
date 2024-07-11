function [x,fval,cvge,iter] = fgradientprojete(choixf,x0,rho,tolerance,itermax)
    % n: dimension de la matrice
    % A: matrice tridiagonale [sous-diagonale, diagonale, sur-diagonale]
    % b: vecteur du côté droit du système
    % itermax: nombre maximum d'itérations
    % tolerance: tolérance pour la convergence

    % Initialisation
    x = x0;
    iter = 0;
    cvge = 0;
    
    while ((~cvge)&&(iter<itermax))
        [~, gradJ] = fobj(x, choixf);
        xsuiv = projete(x - rho * gradJ, choixf);

        if(choixf < 3)
          %afficher le segment tracé des points
          plot([x(1),xsuiv(1)],[x(2),xsuiv(2)],'k-*') %tracera un segment noir entre les points x et xsuiv et placera des * sur ces deux points
        end
        ecart = norm (xsuiv-x);
        cvge = (ecart < tolerance);
        iter = iter+1;
        x = xsuiv;
    end

    fval = fobj(x,choixf);
end