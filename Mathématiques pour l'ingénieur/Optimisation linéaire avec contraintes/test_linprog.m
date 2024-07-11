% TP4 S6 2023-2024 Optimisation linéaire avec contraintes
clear;
disp('Résolution de problèmes linéaires');
disp('1- exemple de la ferme');
disp('2- problème de livraison');
choixpb = input('pb n° : ');
switch choixpb
    case 1 
        f = -[155 160 150];
        %A = [270 150 110];
        A = [16 13 17 ;270 150 110];
        b = [180; 1600];
        Aeq = [1 1 1]; beq = 12;
        lb = [0; 0; 0]; ub = [];
    case 2
        s = [200; 500];
        r = [22; 38; 8; 44; 28];
        f = [10 5 8 1 15 8 12 11 20 9];
        M = 2;
        N = 5;
        
        A = [ones(1,N) zeros(1,N); zeros(1,N) ones(1,N)];
        b = s;
        Aeq = [eye(5) eye(5)]; beq = r;
        lb = zeros(10,1); ub = [];
              
end

% appel de linprog et affichage des résultats
[x,fval,exitflag,output,lambda] = linprog(f,A,b,Aeq,beq,lb,ub);

if exitflag == 1
    % affichage des résultats : iter, x, fval, contraintes
    disp('nombre d''iterations :'); disp(output.iterations);
    disp('x : '); disp(x);
    disp('f(x min) :'); disp(fval);
    disp('contraintes Ax <= b :'); disp(lambda.ineqlin);
    disp('contraintes lb <= x :'); disp(lambda.lower);
end


