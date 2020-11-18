%% ��ջ���
clear
clc
warning( 'off' );
tic;
%% ��������
w = 0.6;      % �������� 
c1 = 2;       % ���ٳ���
c2 = 2;       % ���ٳ���
Dim = 5;            % ά��
SwarmSize = 10;    % ����Ⱥ��ģ
ObjFun = @PSO_cha;  % ���Ż��������
MaxIter = 2;      % ����������  
MinFit = 0;       % ��С��Ӧֵ 
Vmax=0.5;
Vmin=-0.5;
Ub = [43 70 41 315.3773 167];
Lb = [43 70 41 315.3773 167];
%% ����Ⱥ��ʼ��
Range = ones(SwarmSize,1)*(Ub-Lb);
Swarm = rand(SwarmSize,Dim).*Range + ones(SwarmSize,1)*Lb;   % ��ʼ������Ⱥ
VStep = rand(SwarmSize,Dim)*(Vmax-Vmin)+Vmin;                 % ��ʼ���ٶ�
fSwarm = zeros(SwarmSize,1);
for i=1:SwarmSize
    fSwarm(i,:) = feval(ObjFun,Swarm(i,:));                         % ����Ⱥ����Ӧֵ
end
%% ���弫ֵ��Ⱥ�弫ֵ
[bestf bestindex]=min(fSwarm);
zbest=Swarm(bestindex,:);   % ȫ�����
gbest=Swarm;                % �������
fgbest=fSwarm;              % ���������Ӧֵ
fzbest=bestf;               % ȫ�������Ӧֵ
%% ����Ѱ��
iter = 0;
y_fitness = zeros(1,MaxIter);   % Ԥ�Ȳ���4���վ���
l1 = zeros(1,MaxIter);         
l2 = zeros(1,MaxIter);
l3 = zeros(1,MaxIter);
l4 = zeros(1,MaxIter);
l5 = zeros(1,MaxIter);
while( (iter < MaxIter) && (fzbest > MinFit) )
for j=1:SwarmSize
% �ٶȸ���
VStep(j,:) = w*VStep(j,:) + c1*rand*(gbest(j,:) - Swarm(j,:)) + c2*rand*(zbest - Swarm(j,:));
if VStep(j,:)>Vmax, VStep(j,:)=Vmax; end
if VStep(j,:)<Vmin, VStep(j,:)=Vmin; end
% λ�ø���
Swarm(j,:)=Swarm(j,:)+VStep(j,:);
for k=1:Dim
if Swarm(j,k)>Ub(k), Swarm(j,k)=Ub(k); end
if Swarm(j,k)<Lb(k), Swarm(j,k)=Lb(k); end
end
% ��Ӧֵ
fSwarm(j,:) = feval(ObjFun,Swarm(j,:));
% �������Ÿ���     
if fSwarm(j) < fgbest(j)
gbest(j,:) = Swarm(j,:);
fgbest(j) = fSwarm(j);
end
% Ⱥ�����Ÿ���
if fSwarm(j) < fzbest
zbest = Swarm(j,:);
fzbest = fSwarm(j);
end
end 
iter = iter+1;                      % ������������
y_fitness(1,iter) = fzbest;         % Ϊ��ͼ��׼��
l1(1,iter)=zbest(1);
l2(1,iter)=zbest(2);
l3(1,iter)=zbest(3);
l4(1,iter)=zbest(4);
l5(1,iter)=zbest(5);
end

toc;
