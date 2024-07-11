%Évaluation d’une proportion
N = 10000;
p = 0.51;

x = bernoul(N,p);

p_bar = cumsum(x)./(1:N);

%% 
% graphes
v = 1000:1000:N;
p_bar = p_bar(v);
err = 1.96*sqrt( (p_bar).*(1-p_bar)./v ); 
errorbar(v, p_bar, err, '*')
title('Evaluation d''une proportion');

%% Exercice 3

p_bar = cumsum(x)./(1:N);
% graphes
v = 100:100:N;
p_bar = p_bar(v);
In_max = p_bar(100) + 1.96*sqrt( (p_bar(100)).*(1-p_bar(100))/v(100) ); 
In_min = p_bar(100) - 1.96*sqrt( (p_bar(100)).*(1-p_bar(100))/v(100) ); 
sum = 0;
err = 1.96*sqrt( (p_bar).*(1-p_bar)./v ); 

for i=1:length(v)
    if (p_bar(i) >= In_min && p_bar(i) <= In_max)
        sum = sum + 1;
    end
end
disp('Nombre de fois que p appartient a In: '); disp(sum);
errorbar(v, p_bar, err, '*')
title('Evaluation d''une proportion');