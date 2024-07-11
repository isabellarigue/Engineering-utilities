function y = projete(x,choixpb)
  switch choixpb
    case 1
      if (x(1)>=0 && x(2)>=0 && (x(1)^2 + x(2)^2<=1))
        y = x;
      else
        if (x(1)>0 && x(2)>0)
          y = x/norm(x);
        else
           if (x(1)<=0 && x(2)>= 0)
              y(2) = min(1,x(2));
              y(1) = 0;
           else
              y(1) = 0; y(2) = 0;
           end
        end
      end
  case 2
    if (x(1) == 0 && x(2) == 0)
      y = x;
    else
      y(1) = x(1)/norm(x);
      y(2) = x(2)/norm(x);
    end
  end
end
