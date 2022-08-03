%% Project C++: Finite Element Method
% Realize by Alberto Cuadra Lara
% Last update: 14/04/2018
% Description:
% -delta(u) = f(x,y)    (x,y) in Omega
% u(x,y) = 0            (x,y) in deltaOmega
% Exact solution: u(x,y) = (x^2-1)(y^2-1)(x^2+y^2-1/4)
% Nx = number of elements in x 
% Ny = number of elements in y
clear all; close all; clc;
global color
% Colores
red = [0.85,0.33,0.1];blue=[0,0.45,0.74];green=[0.47,0.67,0.19];
purple = [0.49,0.18,0.56];yellow = [0.93,0.69,0.13];orange=[0.702,0.349,0];
color=[red;blue;green;purple;yellow;orange];
clear red blue green purple yellow orange;
% Path figures
filename = strcat('figure-');
fpath = strcat('/mnt/sda2/Google Drive/M2i/C++/Proyecto/Latex/Figures/');
% fpath = strcat('D:\Google Drive\M2i\C++\Proyecto\Latex\Figures\');
% ------------------------------------------------------------------------
%% FEM 2D 
A = load('matriz_A.txt');
b = load('vector_b.txt');
u = load('output.txt');
triangulos = load('mesh/mesh_tnode.dat');
nodos = load('mesh/mesh_node.dat');
nodosbnd = load('mesh/mesh_bnd_node.dat');
%% EXACT SOLUTION
x = nodos(:,1);
y = nodos(:,2);
u_exact = (x.^2-1).*(y.^2-1).*(x.^2+y.^2-1/4);

fig = figure;
% set(fig,'innerposition',[100,50,1100,800],...
%     'outerposition',[100 50 1100 800]);
set(axes,'LineWidth',1.4,'FontSize',14,'BoxStyle','full','Layer','top')
box on; hold on;
trisurf(triangulos,nodos(:,1),nodos(:,2),u);

ylabel('$y$','FontSize',18,'interpreter','latex');
xlabel('$x$','FontSize',18,'interpreter','latex');

c = colorbar;
% Change width colorbar
x1=get(gca,'position');
x2=get(c,'Position');
x2(3)=0.045;
set(c,'Position',x2)
set(gca,'position',x1)
% ------------------------
c.Label.Interpreter = 'latex';
c.Label.String = '$u(x,y)$';
c.LineWidth = 1.4;
c.Label.FontSize = 18;	
% c.Limits = [round(min(min(u_exact)),1) round(max(max(u_exact)),1)];
caxis manual
caxis ([0, max(u)])
set(c,'YTick',[0 0.02 0.04 0.06 0.08 0.1 0.12 0.14 0.16 0.18 0.2])

colormap ('jet');
% saveas(fig,strcat(fpath,filename,'1'),'epsc');
%% APPROXIMATE SOLUTION
fig = figure;
% set(fig,'innerposition',[150,150,1200,1000],...
%     'outerposition',[150 150 1200 1000]);
set(axes,'LineWidth',1.4,'FontSize',14,'BoxStyle','full','Layer','top')
box on;hold on; axis tight
trisurf(triangulos,nodos(:,1),nodos(:,2),u);
view(2);
ylabel('$y$','FontSize',18,'interpreter','latex');
xlabel('$x$','FontSize',18,'interpreter','latex');
c = colorbar;
% Change width colorbar
x1=get(gca,'position');
x2=get(c,'Position');
x2(3)=0.045;
set(c,'Position',x2)
set(gca,'position',x1)
% ------------------------
c.Label.Interpreter = 'latex';
c.Label.String = '$u_h(x,y)$';
c.LineWidth = 1.4;
c.Label.FontSize = 18;	
% c.Limits = [round(min(min(u_exact)),1) round(max(max(u_exact)),1)];
caxis manual
caxis ([0, max(u)])
set(c,'YTick',[0 0.02 0.04 0.06 0.08 0.1 0.12 0.14 0.16 0.18 0.2])
colormap ('jet');
% saveas(fig,strcat(fpath,filename,'2'),'epsc');
%% ERROR 
error = norm(u_exact-u,2)/norm(u_exact,2);
error_ab = norm(u_exact(:,1)-u(:,end),2);
fprintf('Error relativo = %.3e \n',error)
fprintf('Error absoluto = %.3e \n',error_ab)
%% Mesh of the problem
% Boundary nodes - option 1
ind0 = nodosbnd; % We are searching the indexes with Dirichlet bc
% Nodos contorno - opcion 2
% ind0 = find(u<=1e-4); % We are searching the indexes with Dirichlet bc
% -------------------------------
fig = figure;
set(axes,'LineWidth',1.4,'FontSize',16,'BoxStyle','full')
hold on;
trisurf(triangulos,nodos(:,1),nodos(:,2),-ones(990,1));
plot(nodos(ind0,1),nodos(ind0,2),'o','LineWidth',1,'MarkerSize',5,...
    'MarkerEdgeColor','black','MarkerFaceColor',[1 0 0]);
green = [0.42 1 0.42];
colormap(green)

% hold off
% dt = delaunayTriangulation(nodos(:,1),nodos(:,2));
% triplot(triangulos,nodos(:,1),nodos(:,2));
% hold on
vxlabels = arrayfun(@(n) {sprintf('P%d', n)}, nodosbnd);
Hpl = text(nodos(nodosbnd,1), nodos(nodosbnd,2), vxlabels, 'HorizontalAlignment',...
   'left', 'BackgroundColor', 'none','FontSize',14);
% ic = incenter(dt);
% numtri = size(dt,1);
% trilabels = arrayfun(@(n2) {sprintf('T%d', n2)}, (1:numtri)');
% Htl = text(ic(:,1), ic(:,2), trilabels, 'FontWeight', 'bold', ...
%    'HorizontalAlignment', 'center', 'Color', 'blue');