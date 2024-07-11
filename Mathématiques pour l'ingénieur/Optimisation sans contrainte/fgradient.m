function [x,fval,cvge,iter] = fgradient(choixf,x0,rho,tolerance,itermax)
    % choixf: fonction choisi
    % x0: point initial
    % rho: un réel fixé (indépendant de k), fait partie de la methode
    % itermax: nombre maximum d'itérations
    % tolerance: tolérance pour la convergence

    % Initialisation
    x = x0;
    xsuiv = x0;
    iter = 0;
    cvge = 0;



    while ((~cvge)&&(iter<itermax))
        gradient = gradf(x, choixf);
        for i=1:length(x0)
            xsuiv(i) = x(i)- rho * gradient(i);
        end

        if(choixf < 3)
          %afficher le segment tracé des points
          plot([x(1),xsuiv(1)],[x(2),xsuiv(2)],'k-*') %tracera un segment noir entre les points x et xsuiv et placera des * sur ces deux points
        end
        ecart = norm (xsuiv-x);
        cvge = (ecart < tolerance);
        iter = iter+1;
        x = xsuiv;
    end

    fval = f(x,choixf);
end