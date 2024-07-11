% TP6 S6 2023-2024 Moindres carrés avec contraintes linéaires
clf;

disp('1- Problème initial');
disp('2- Problème Interpolation-appoximation d''un nuage de points');
choixpb = input('Choix n° : ');    

switch choixpb
    case 1
        % Definition du problème
        C = [1 0 0; 1 1 1; 1 2 4; 1 3 9; 1 4 16; 1 5 25];
        d = [65.5 ; -142; 82.5; -12; 25; -45];
        Aeq = [4 0 1; 3 1 0];
        beq = [7; 7];

        % Choix de la méthode de résolution
        disp('1- Fonction lsqlineq');
        disp('2- Fonction lsqlin de Matlab');
        choixmet = input('Choix de la méthode de résolution n° : ');

        switch choixmet
            case 1 %fonction lsqlineq
                [x,Jval,residu,lambda,exit] = lsqlineq(C,d,Aeq,beq);
            case 2 %fonction lsqlin
                [x,resnorm,residu,exit,output,lambda] = lsqlin(C, d,'', '', Aeq, beq);
                lambda = lambda.eqlin;
        end

        % affichage des résultats
        disp('x = '); disp(x);
        disp('lambda = '); disp(lambda);

    case 2 
        %Definition du problème
        xi = [-2 -1 0 1 2];
        yi = [6 4 5 3 1];
        p1 = [-3 2];
        p2 = [3 5];
        
        C = [xi'.^3 xi'.^2 xi' ones(size(xi'))];
        d = yi';
        Aeq = [p1(1)^3 p1(1)^2 p1(1) 1; p2(1)^3 p2(1)^2 p2(1) 1];
        beq = [p1(2); p2(2)];


        [x,Jval,residu,lambda,exit] = lsqlineq(C, d, Aeq, beq);
        
        % Polynome obtenu
        fprintf("f(x) = %f*x^3 + %f*x^2 + %f*x + %f\n\n", x(1),x(2),x(3),x(4));

        X = -3:0.1:3;
        Y = [X'.^3 X'.^2 X' ones(size(X'))]*x;
        
        %Graphes 
        hold on;
        plot(xi, yi, 'c*');
        plot(X, Y);
        plot([p1(1) p2(1)], [p1(2) p2(2)], 'ob');
        xlim([-3 3]);
        legend('Points d''approximation', 'Courbe polynome', 'Points d''interpolation');
        title('Approximation-interpolation d''un nuage de points');
        xlabel("Axe X");
        ylabel("Axe Y");
end
      




