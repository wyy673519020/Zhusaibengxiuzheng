function z = PSO_cha( Swarm )
addr_td1=['ZSB_A5.csv'];
addr_td2=['ZSB_A7.csv'];
u3=csvread(addr_td1);
n=size(u3, 1);
for i=1:n
u(i,:)=[u3(i,:),Swarm]
end
u2=csvread(addr_td2);
sim_time=1;
collect=0.5;
for  j = 1 : n
W_average= simrun( u(j,:),sim_time,collect);
W_average1(j,:) = W_average;
cha(j,:)= W_average1(j,:)-u2(j,:);
cha(j,:)=abs(cha(j,:));end
z=sum(cha(1:end,:))
end
