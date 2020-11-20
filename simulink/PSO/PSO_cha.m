function err = PSO_cha( Swarm, u3, u2 )
    
    n=size(u3, 1);
    err = 0;
    
    for  j = 1 : n
        
        W_average= runZSB( u3(j,1),u3(j,2),u3(j,3),u3(j,4),Swarm(1),Swarm(2),Swarm(3),Swarm(4),Swarm(5) );
        err = err + abs( W_average - u2(j) );
    end
    
    disp( err );
  
end
