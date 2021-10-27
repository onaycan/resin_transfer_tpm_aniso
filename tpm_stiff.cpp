void calc_K_Wlambdau_at_gauss(double _K_Wlambdau[][32],//the geometrical stiffness matrix to be passed 
         	              double B[][32], //this is necessary for the computation of the green-lagrange strain tensor and the second piola kirchoff stress tensor 
 			      double _coeff,
                              double current_lambda,
			      double CauchyInv[6],
			      double dNdX[24],
                              ofstream &_debugfile
)
{
double dlambda_du[32];

for(int i=0;i<32;i++)
dlambda_du[i]=0.0;

for(int i=0;i<24;i++) 
dlambda_du[i+i/3]=dNdX[i]*current_lambda;

double first_v[32]; 

for(int n=0;n<32;n++)
first_v[n]=0.0;

for(int i=0;i<32;i++)
for(int j=0;j<6;j++)
first_v[i]=first_v[i]+CauchyInv[j]*B[j][i];


for(int i=0;i<32;i++)
for(int j=0;j<32;j++)
_K_Wlambdau[j][i]=_K_Wlambdau[j][i]-first_v[i]*dlambda_du[j]*_coeff;





};













void calc_K_Wlambda_at_gauss(double _K_Wlambda[][32],//the geometrical stiffness matrix to be passed 
         	             double B[][32], //this is necessary for the computation of the green-lagrange strain tensor and the second piola kirchoff stress tensor 
                             double _coeff,
			     double CauchyInv[6],
			     double N_lambda[32],
			     ofstream &_debugfile
		             )
{




double first_v[32]; //left node driven 
double second_v[32]; //right node driven 



//they are all supposed to be initialized as zero 
for(int n=0;n<32;n++)
first_v[n]=0.0;

for(int n=0;n<32;n++)
second_v[n]=0.0;

for(int i=0;i<32;i++)
for(int j=0;j<6;j++)
first_v[i]=first_v[i]+CauchyInv[j]*B[j][i];



for(int n=0;n<32;n++)
second_v[n]=-0.5*N_lambda[n];


for(int i=0;i<32;i++)
for(int j=0;j<32;j++)
_K_Wlambda[i][j]=_K_Wlambda[i][j]+first_v[i]*second_v[j]*_coeff;




};
























void calc_K_M1uJ_at_gauss(double B[][32], //this is necessary for the computation of the green-lagrange strain tensor and the second piola kirchoff stress tensor 
	                  double _K_M1uJ[][32],//the geometrical stiffness matrix to be passed 
			  double N_lambda[32],
			  double CauchyInv[6],
			  double detF,
		          double Cauchy_rate[6],
                          ofstream &_debugfile)

{

double somecoeff=0.0;
for(int n=0;n<6;n++)
somecoeff=somecoeff+Cauchy_rate[n]*CauchyInv[n];

double first_v[32]; //left node driven 
double second_v[32]; //right node driven 

for(int n=0;n<32;n++)
{
first_v[n]=0.0;
second_v[n]=0.0;
}



for(int n=0;n<32;n++)
first_v[n]=0.5*detF*somecoeff*N_lambda[n]; //it was different before 

for(int i=0;i<32;i++)
for(int j=0;j<6;j++)
second_v[i]=second_v[i]+CauchyInv[j]*B[j][i];


for(int i=0;i<32;i++)
for(int j=0;j<32;j++)
_K_M1uJ[i][j]=_K_M1uJ[i][j]+first_v[i]*second_v[j];





};
































void calc_K_M1uGeo_at_gauss(double _K_M1uGeo[][32],//the geometrical stiffness matrix to be passed 
         	            double B[][32], //this is necessary for the computation of the green-lagrange strain tensor and the second piola kirchoff stress tensor 
			    double _coeff,
		            double N_lambda[32],
			    double CauchyInv[6],
			    ofstream &_debugfile
			    )
{


double first_v[32]; //left node driven 
double second_v[32]; //right node driven 
for(int n=0;n<32;n++)
first_v[n]=0.0;
for(int n=0;n<32;n++)
first_v[n]=_coeff*N_lambda[n];
for(int n=0;n<32;n++)
second_v[n]=0.0;

for(int i=0;i<32;i++)
for(int j=0;j<6;j++)
second_v[i]=second_v[i]+CauchyInv[j]*B[j][i];


for(int i=0;i<32;i++)
for(int j=0;j<32;j++)
_K_M1uGeo[i][j]=_K_M1uGeo[i][j]+first_v[i]*second_v[j];






};



void Pore_Elasticity_at_Gauss(double D_pore[][6],  
	    	              double F[], //deformation gradient 
			      ofstream &_debugfile,
			      double lambda)
{
double Ftens[3][3];
double FtensT[3][3];
double Cauchy[3][3]; //Cauchy-Green Strain Tensor 
double CauchyInv[3][3]; //Cauchy-Green Strain Tensor 
double C[3][3][3][3]; //bulk constitutive tensor 

Ftens[0][0]=F[0];
Ftens[0][1]=F[3];
Ftens[0][2]=F[6];
Ftens[1][0]=F[1];
Ftens[1][1]=F[4];
Ftens[1][2]=F[7];
Ftens[2][0]=F[2];
Ftens[2][1]=F[5];
Ftens[2][2]=F[8];

transpose(Ftens,FtensT); 
matrix_product(FtensT,Ftens,Cauchy); 
inverse(Cauchy,CauchyInv);




//effect of fluid pore pressure
for(int I=0;I<3;I++)
for(int J=0;J<3;J++)
for(int K=0;K<3;K++)
for(int L=0;L<3;L++)
C[I][J][K][L]=lambda*(CauchyInv[I][K]*CauchyInv[J][L]+CauchyInv[I][L]*CauchyInv[J][K]);




D_pore[0][0]=C[0][0][0][0];
D_pore[0][1]=C[0][0][1][1];
D_pore[0][2]=C[0][0][2][2];
D_pore[0][3]=C[0][0][0][1];
D_pore[0][4]=C[0][0][1][2];
D_pore[0][5]=C[0][0][2][0];
 
D_pore[1][0]=C[1][1][0][0];
D_pore[1][1]=C[1][1][1][1];
D_pore[1][2]=C[1][1][2][2];
D_pore[1][3]=C[1][1][0][1];
D_pore[1][4]=C[1][1][1][2];
D_pore[1][5]=C[1][1][2][0];

D_pore[2][0]=C[2][2][0][0];
D_pore[2][1]=C[2][2][1][1];
D_pore[2][2]=C[2][2][2][2];
D_pore[2][3]=C[2][2][0][1];
D_pore[2][4]=C[2][2][1][2];
D_pore[2][5]=C[2][2][2][0];

D_pore[3][0]=C[0][1][0][0];
D_pore[3][1]=C[0][1][1][1];
D_pore[3][2]=C[0][1][2][2];
D_pore[3][3]=C[0][1][0][1];
D_pore[3][4]=C[0][1][1][2];
D_pore[3][5]=C[0][1][2][0];

D_pore[4][0]=C[1][2][0][0];
D_pore[4][1]=C[1][2][1][1];
D_pore[4][2]=C[1][2][2][2];
D_pore[4][3]=C[1][2][0][1];
D_pore[4][4]=C[1][2][1][2];
D_pore[4][5]=C[1][2][2][0];

D_pore[5][0]=C[2][0][0][0];
D_pore[5][1]=C[2][0][1][1];
D_pore[5][2]=C[2][0][2][2];
D_pore[5][3]=C[2][0][0][1];
D_pore[5][4]=C[2][0][1][2];
D_pore[5][5]=C[2][0][2][0];



};






void calc_K_M1uMat_at_gauss(double _K_M1uMat[][32],//the geometrical stiffness matrix to be passed 
      	                    double B[][32], //this is necessary for the computation of the green-lagrange strain tensor and the second piola kirchoff stress tensor 
                            double F[],
			    double Cauchy_rate[6],
			    double N_lambda[32],
			    double detF,
                            ofstream &_debugfile
			    )
{

double D_pore[6][6];


//computing the pore elasticity
Pore_Elasticity_at_Gauss(D_pore, F, _debugfile,1.0);

for(int i=0;i<6;i++)
for(int j=0;j<6;j++)
D_pore[i][j]=-0.5*D_pore[i][j];



double first_v[32]; //left node driven 
double second_v[6]; //right node driven 
double third_v[32]; //right node driven 

for(int n=0;n<32;n++)
first_v[n]=0.0;


for(int n=0;n<32;n++)
first_v[n]=1.0*detF*N_lambda[n];

for(int n=0;n<6;n++)
second_v[n]=0.0;
for(int n=0;n<32;n++)
third_v[n]=0.0;

for(int i=0;i<6;i++)
for(int j=0;j<6;j++)
second_v[i]=second_v[i]+Cauchy_rate[j]*D_pore[i][j];

for(int i=0;i<32;i++)
for(int j=0;j<6;j++)
third_v[i]=third_v[i]+second_v[j]*B[j][i];

for(int i=0;i<32;i++)
for(int j=0;j<32;j++)
_K_M1uMat[i][j]=_K_M1uMat[i][j]+first_v[i]*third_v[j];




};




/*
void calc_K_M1uN_at_gauss(Node _nodes[],
	                  Element _elements[],
	                  double _ksi, double _eta, double _zeta,
         	          double B[][32], //this is necessary for the computation of the green-lagrange strain tensor and the second piola kirchoff stress tensor 
	                  double D[][6], //this is necessary for the computation of the second piola kirchoff stress tensor 
                          double F[],
	                  double S[],
	                  double _K_M1uN[][32],//the geometrical stiffness matrix to be passed 
	                  double& detj,
                          int _currentelement,
                          ofstream &_debugfile,
	    	          double _t,
			  double _coeff)
{


double beta_2=0.25;
double beta_1=0.5;
double Ftens[3][3];
double FtensT[3][3];
double FtensInv[3][3];
double Cauchytens[3][3];
double CauchytensInv[3][3];
double Cauchy_rate[6];
double CauchyInv[6];
double dNdX[24]; 
double detF;



//can: startof:=these values are for the geometric stiffnes similar part and its convergence 
double dNdksi[24]; 
double inversejacob[24][24]; 
double jacob[3][3]; 
//can: endof:=these values are for the geometric stiffnes similar part and its convergence 


Ftens[0][0]=F[0];
Ftens[0][1]=F[3];
Ftens[0][2]=F[6];
Ftens[1][0]=F[1];
Ftens[1][1]=F[4];
Ftens[1][2]=F[7];
Ftens[2][0]=F[2];
Ftens[2][1]=F[5];
Ftens[2][2]=F[8];



transpose(Ftens,FtensT); 
matrix_product(FtensT,Ftens,Cauchytens); 
inverse(Cauchytens,CauchytensInv);
detF=det(Ftens);


CauchyInv[0]=CauchytensInv[0][0];
CauchyInv[1]=CauchytensInv[1][1];
CauchyInv[2]=CauchytensInv[2][2];
CauchyInv[3]=CauchytensInv[0][1];
CauchyInv[4]=CauchytensInv[1][2];
CauchyInv[5]=CauchytensInv[2][0];



Cauchy_rate[0]=1.0*_coeff*(Cauchytens[0][0]-1.0);
Cauchy_rate[1]=1.0*_coeff*(Cauchytens[1][1]-1.0);
Cauchy_rate[2]=1.0*_coeff*(Cauchytens[2][2]-1.0);
Cauchy_rate[3]=2.0*_coeff*Cauchytens[0][1];
Cauchy_rate[4]=2.0*_coeff*Cauchytens[1][2];
Cauchy_rate[5]=2.0*_coeff*Cauchytens[2][0];

double somecoeff=0.0;
for(int n=0;n<6;n++)
somecoeff=somecoeff+Cauchy_rate[n]*CauchyInv[n]*detF;






//computation of the third part 
dNdksi[0]=-0.125*(1.0-_eta)*(1.0-_zeta);
dNdksi[1]=-0.125*(1.0-_ksi)*(1.0-_zeta);
dNdksi[2]=-0.125*(1.0-_ksi)*(1.0-_eta);


dNdksi[3]=0.125*(1.0-_eta)*(1.0-_zeta);
dNdksi[4]=-0.125*(1.0+_ksi)*(1.0-_zeta);
dNdksi[5]=-0.125*(1.0+_ksi)*(1.0-_eta);


dNdksi[6]=0.125*(1.0+_eta)*(1.0-_zeta);
dNdksi[7]=0.125*(1.0+_ksi)*(1.0-_zeta);
dNdksi[8]=-0.125*(1.0+_ksi)*(1.0+_eta);

dNdksi[9]=-0.125*(1.0+_eta)*(1.0-_zeta);
dNdksi[10]=0.125*(1.0-_ksi)*(1.0-_zeta);
dNdksi[11]=-0.125*(1.0-_ksi)*(1.0+_eta);

dNdksi[12]=-0.125*(1.0-_eta)*(1.0+_zeta);
dNdksi[13]=-0.125*(1.0-_ksi)*(1.0+_zeta);
dNdksi[14]=0.125*(1.0-_ksi)*(1.0-_eta);

dNdksi[15]=0.125*(1.0-_eta)*(1.0+_zeta);
dNdksi[16]=-0.125*(1.0+_ksi)*(1.0+_zeta);
dNdksi[17]=0.125*(1.0+_ksi)*(1.0-_eta);

dNdksi[18]=0.125*(1.0+_eta)*(1.0+_zeta);
dNdksi[19]=0.125*(1.0+_ksi)*(1.0+_zeta);
dNdksi[20]=0.125*(1.0+_ksi)*(1.0+_eta);

dNdksi[21]=-0.125*(1.0+_eta)*(1.0+_zeta);
dNdksi[22]=0.125*(1.0-_ksi)*(1.0+_zeta);
dNdksi[23]=0.125*(1.0-_ksi)*(1.0+_eta);




for(int i=0;i<24;i++)
{
for(int j=0;j<24;j++)
inversejacob[i][j]=0.0; 
dNdX[i]=0.0; 
}


for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
jacob[i][j]=0.0;


for(int i=0;i<3;i++) // row label 
for(int j=0;j<8;j++) 
{
jacob[i][0]=jacob[i][0]+dNdksi[j*3+i]*(_nodes[_elements[_currentelement].connid[j]].X_lamb[0]+_nodes[_elements[_currentelement].connid[j]].u_lamb[0]);
jacob[i][1]=jacob[i][1]+dNdksi[j*3+i]*(_nodes[_elements[_currentelement].connid[j]].X_lamb[1]+_nodes[_elements[_currentelement].connid[j]].u_lamb[1]);
jacob[i][2]=jacob[i][2]+dNdksi[j*3+i]*(_nodes[_elements[_currentelement].connid[j]].X_lamb[2]+_nodes[_elements[_currentelement].connid[j]].u_lamb[2]);
}

detj=jacob[0][0]*(jacob[1][1]*jacob[2][2]-jacob[2][1]*jacob[1][2])-
     jacob[0][1]*(jacob[1][0]*jacob[2][2]-jacob[2][0]*jacob[1][2])+
     jacob[0][2]*(jacob[1][0]*jacob[2][1]-jacob[2][0]*jacob[1][1]);


inversejacob[0][0]=inversejacob[3][3]=inversejacob[6][6]=inversejacob[9][9]=inversejacob[12][12]=inversejacob[15][15]=inversejacob[18][18]=inversejacob[21][21]=(jacob[1][1]*jacob[2][2]-jacob[2][1]*jacob[1][2])/detj;
inversejacob[0][1]=inversejacob[3][4]=inversejacob[6][7]=inversejacob[9][10]=inversejacob[12][13]=inversejacob[15][16]=inversejacob[18][19]=inversejacob[21][22]=(jacob[0][2]*jacob[2][1]-jacob[2][2]*jacob[0][1])/detj;
inversejacob[0][2]=inversejacob[3][5]=inversejacob[6][8]=inversejacob[9][11]=inversejacob[12][14]=inversejacob[15][17]=inversejacob[18][20]=inversejacob[21][23]=(jacob[0][1]*jacob[1][2]-jacob[1][1]*jacob[0][2])/detj; 

inversejacob[1][0]=inversejacob[4][3]=inversejacob[7][6]=inversejacob[10][9]=inversejacob[13][12]=inversejacob[16][15]=inversejacob[19][18]=inversejacob[22][21]=(jacob[1][2]*jacob[2][0]-jacob[2][2]*jacob[1][0])/detj;
inversejacob[1][1]=inversejacob[4][4]=inversejacob[7][7]=inversejacob[10][10]=inversejacob[13][13]=inversejacob[16][16]=inversejacob[19][19]=inversejacob[22][22]=(jacob[0][0]*jacob[2][2]-jacob[2][0]*jacob[0][2])/detj;
inversejacob[1][2]=inversejacob[4][5]=inversejacob[7][8]=inversejacob[10][11]=inversejacob[13][14]=inversejacob[16][17]=inversejacob[19][20]=inversejacob[22][23]=(jacob[0][2]*jacob[1][0]-jacob[1][2]*jacob[0][0])/detj;

inversejacob[2][0]=inversejacob[5][3]=inversejacob[8][6]=inversejacob[11][9]=inversejacob[14][12]=inversejacob[17][15]=inversejacob[20][18]=inversejacob[23][21]=(jacob[1][0]*jacob[2][1]-jacob[2][0]*jacob[1][1])/detj;
inversejacob[2][1]=inversejacob[5][4]=inversejacob[8][7]=inversejacob[11][10]=inversejacob[14][13]=inversejacob[17][16]=inversejacob[20][19]=inversejacob[23][22]=(jacob[0][1]*jacob[2][0]-jacob[2][1]*jacob[0][0])/detj;
inversejacob[2][2]=inversejacob[5][5]=inversejacob[8][8]=inversejacob[11][11]=inversejacob[14][14]=inversejacob[17][17]=inversejacob[20][20]=inversejacob[23][23]=(jacob[0][0]*jacob[1][1]-jacob[1][0]*jacob[0][1])/detj;


for(int i=0;i<24;i++)
for(int j=0;j<24;j++)
dNdX[i]=dNdX[i]+inversejacob[i][j]*dNdksi[j];


for(int i=0;i<32;i++)
for(int j=0;j<32;j++)
{
if(i%4==3 && j%4==0)
{
_K_M1uN[i][j+0]=_K_M1uN[i][j+0]+somecoeff*dNdX[i-i/3];
_K_M1uN[i][j+1]=_K_M1uN[i][j+1]+somecoeff*dNdX[i-i/3+1];
_K_M1uN[i][j+2]=_K_M1uN[i][j+2]+somecoeff*dNdX[i-i/3+2];
}
}


};

*/


void calc_K_M2uJ_at_gauss(double _K_M2uJ[][32],
                          Node _nodes[],
	                  Element _elements[],
                          int _currentelement,
	                  double _ksi, double _eta, double _zeta,
         	          double B[][32],
                          double _coeff,
			  double CauchyInv[6],
			  double dNdX[24],
			  double alfa,
			  double beta,
			  double current_nS,
			  double current_nf,
			  double M_vec[3],
			  double detF,
		          double N[8],
			  ofstream &_debugfile, int integration_counter
			 )
{


double dlambda_dX[3];
double Lambda_var[6][32];
double current_ns;

double dlambda_dX_f[3];
double dlambda_dX_pf[3];
double M_met[3][3];



for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
M_met[i][j]=M_vec[i]*M_vec[j];



current_ns=current_nS/detF;
/*
if(_zeta<0.0 && _eta<0.0 && _ksi<0.0)
_elements[_currentelement].ns[0]=current_ns;
if(_zeta<0.0 && _eta<0.0 && _ksi>0.0)
_elements[_currentelement].ns[1]=current_ns;
if(_zeta<0.0 && _eta>0.0 && _ksi>0.0)
_elements[_currentelement].ns[2]=current_ns;
if(_zeta<0.0 && _eta>0.0 && _ksi<0.0)
_elements[_currentelement].ns[3]=current_ns;
if(_zeta>0.0 && _eta<0.0 && _ksi<0.0)
_elements[_currentelement].ns[4]=current_ns;
if(_zeta>0.0 && _eta<0.0 && _ksi>0.0)
_elements[_currentelement].ns[5]=current_ns;
if(_zeta>0.0 && _eta>0.0 && _ksi>0.0)
_elements[_currentelement].ns[6]=current_ns;
if(_zeta>0.0 && _eta>0.0 && _ksi<0.0)
_elements[_currentelement].ns[7]=current_ns;
*/
_elements[_currentelement].ns[integration_counter]=current_ns;





double some_deriv=0.0;
some_deriv=current_nf*current_nf+2.0*current_nf*current_nS/detF;


double somecoeff=0.0;
somecoeff=(0.5*detF)*some_deriv;




for(int i=0;i<3;i++)
{
dlambda_dX[i]=0.0;
dlambda_dX_f[i]=0.0;
dlambda_dX_pf[i]=0.0;
}


for(int i=0;i<24;i++) 
dlambda_dX[i%3]=dlambda_dX[i%3]+dNdX[i]*_nodes[_elements[_currentelement].connid[i/3]].u_lamb[3];

for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
dlambda_dX_f[i]=dlambda_dX_f[i]+M_met[i][j]*dlambda_dX[j];

for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
dlambda_dX_pf[i]=dlambda_dX_pf[i]+(cronecker(i,j)-M_met[i][j])*dlambda_dX[j];


double seepage[3];
for(int i=0;i<3;i++)
seepage[i]=-1.0/beta*current_nf*dlambda_dX_pf[i]-1.0/alfa*current_nf*dlambda_dX_f[i];

double v_solid[3];
for(int i=0;i<3;i++)
v_solid[i]=0.0;

for(int s=0;s<8;s++)
for(int i=0;i<3;i++)
v_solid[i]=v_solid[i]+_coeff*N[s]*_nodes[_elements[_currentelement].connid[s]].u_lamb[i];

/*
if(_zeta<0.0 && _eta<0.0 && _ksi<0.0)
for(int i=0;i<3;i++)
{
_elements[_currentelement].v_fluid[0*3+i]=seepage[i]+v_solid[i];
_elements[_currentelement].v_fs[0*3+i]=seepage[i];
}
if(_zeta<0.0 && _eta<0.0 && _ksi>0.0)
for(int i=0;i<3;i++)
{
_elements[_currentelement].v_fluid[1*3+i]=seepage[i]+v_solid[i];
_elements[_currentelement].v_fs[1*3+i]=seepage[i];
}
if(_zeta<0.0 && _eta>0.0 && _ksi>0.0)
for(int i=0;i<3;i++)
{
_elements[_currentelement].v_fluid[2*3+i]=seepage[i]+v_solid[i];
_elements[_currentelement].v_fs[2*3+i]=seepage[i];
}
if(_zeta<0.0 && _eta>0.0 && _ksi<0.0)
for(int i=0;i<3;i++)
{
_elements[_currentelement].v_fluid[3*3+i]=seepage[i]+v_solid[i];
_elements[_currentelement].v_fs[3*3+i]=seepage[i];
}
if(_zeta>0.0 && _eta<0.0 && _ksi<0.0)
for(int i=0;i<3;i++)
{
_elements[_currentelement].v_fluid[4*3+i]=seepage[i]+v_solid[i];
_elements[_currentelement].v_fs[4*3+i]=seepage[i];
}
if(_zeta>0.0 && _eta<0.0 && _ksi>0.0)
for(int i=0;i<3;i++)
{
_elements[_currentelement].v_fluid[5*3+i]=seepage[i]+v_solid[i];
_elements[_currentelement].v_fs[5*3+i]=seepage[i];
}
if(_zeta>0.0 && _eta>0.0 && _ksi>0.0)
for(int i=0;i<3;i++)
{
_elements[_currentelement].v_fluid[6*3+i]=seepage[i]+v_solid[i];
_elements[_currentelement].v_fs[6*3+i]=seepage[i];
}
if(_zeta>0.0 && _eta>0.0 && _ksi<0.0)
for(int i=0;i<3;i++)
{
_elements[_currentelement].v_fluid[7*3+i]=seepage[i]+v_solid[i];
_elements[_currentelement].v_fs[7*3+i]=seepage[i];
}
*/ 
for(int i=0;i<3;i++)
{
_elements[_currentelement].v_fluid[integration_counter][i]=seepage[i]+v_solid[i];
_elements[_currentelement].v_fs[integration_counter][i]=seepage[i];
}


for(int i=0;i<6;i++)
for(int j=0;j<32;j++)
Lambda_var[i][j]=0.0;


for(int i=0;i<8;i++)
{
//the first three columns are set to be zero 
Lambda_var[0][i*4+3]=(1.0*dNdX[i*3+0]*dlambda_dX_f[0])/alfa;
Lambda_var[1][i*4+3]=(1.0*dNdX[i*3+1]*dlambda_dX_f[1])/alfa;
Lambda_var[2][i*4+3]=(1.0*dNdX[i*3+2]*dlambda_dX_f[2])/alfa;
Lambda_var[3][i*4+3]=(0.5*dNdX[i*3+0]*dlambda_dX_f[1]+0.5*dNdX[i*3+1]*dlambda_dX_f[0])/alfa;
Lambda_var[4][i*4+3]=(0.5*dNdX[i*3+1]*dlambda_dX_f[2]+0.5*dNdX[i*3+2]*dlambda_dX_f[1])/alfa;
Lambda_var[5][i*4+3]=(0.5*dNdX[i*3+2]*dlambda_dX_f[0]+0.5*dNdX[i*3+0]*dlambda_dX_f[2])/alfa;

Lambda_var[0][i*4+3]=Lambda_var[0][i*4+3]+(1.0*dNdX[i*3+0]*dlambda_dX_pf[0])/beta;
Lambda_var[1][i*4+3]=Lambda_var[1][i*4+3]+(1.0*dNdX[i*3+1]*dlambda_dX_pf[1])/beta;
Lambda_var[2][i*4+3]=Lambda_var[2][i*4+3]+(1.0*dNdX[i*3+2]*dlambda_dX_pf[2])/beta;
Lambda_var[3][i*4+3]=Lambda_var[3][i*4+3]+(0.5*dNdX[i*3+0]*dlambda_dX_pf[1]+0.5*dNdX[i*3+1]*dlambda_dX_pf[0])/beta;
Lambda_var[4][i*4+3]=Lambda_var[4][i*4+3]+(0.5*dNdX[i*3+1]*dlambda_dX_pf[2]+0.5*dNdX[i*3+2]*dlambda_dX_pf[1])/beta;
Lambda_var[5][i*4+3]=Lambda_var[5][i*4+3]+(0.5*dNdX[i*3+2]*dlambda_dX_pf[0]+0.5*dNdX[i*3+0]*dlambda_dX_pf[2])/beta;
} 






double first_v[32]; //left node driven 
double second_v[32]; //right node driven 

for(int n=0;n<32;n++)
first_v[n]=0.0;

for(int i=0;i<32;i++)
for(int j=0;j<6;j++)
first_v[i]=first_v[i]+somecoeff*CauchyInv[j]*Lambda_var[j][i];

for(int n=0;n<32;n++)
second_v[n]=0.0;


for(int i=0;i<32;i++)
for(int j=0;j<6;j++)
second_v[i]=second_v[i]+CauchyInv[j]*B[j][i];

for(int i=0;i<32;i++)
for(int j=0;j<32;j++)
_K_M2uJ[i][j]=_K_M2uJ[i][j]+first_v[i]*second_v[j];



};



//to be corrected 



void calc_K_M2uMat_at_gauss(double _K_M2uMat[][32],
                            Node _nodes[],
	                    Element _elements[],
                            int _currentelement,
         	            double B[][32],
                            double F[],
                            double detF,
                            double current_nf,
                            double dNdX[24],
                            double beta,
                            double alfa,
                            double M_vec[3],
                            ofstream &_debugfile
                            )
{



double D_pore[6][6];
double dlambda_dX[3];
double Lambda_var[6][32];
double dlambda_dX_f[3];
double dlambda_dX_pf[3];
double M_met[3][3];




for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
M_met[i][j]=M_vec[i]*M_vec[j];



//computing the pore elasticity
Pore_Elasticity_at_Gauss(D_pore, F, _debugfile,1.0);

for(int i=0;i<6;i++)
for(int j=0;j<6;j++)
D_pore[i][j]=-0.5*D_pore[i][j];




for(int i=0;i<3;i++)
{
dlambda_dX_f[i]=0.0;
dlambda_dX[i]=0.0;
dlambda_dX_pf[i]=0.0;
}



for(int i=0;i<24;i++) 
dlambda_dX[i%3]=dlambda_dX[i%3]+dNdX[i]*_nodes[_elements[_currentelement].connid[i/3]].u_lamb[3];

for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
dlambda_dX_f[i]=dlambda_dX_f[i]+M_met[i][j]*dlambda_dX[j];

for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
dlambda_dX_pf[i]=dlambda_dX_pf[i]+(cronecker(i,j)-M_met[i][j])*dlambda_dX[j];


for(int i=0;i<6;i++)
for(int j=0;j<32;j++)
Lambda_var[i][j]=0.0;


for(int i=0;i<8;i++)
{
//the first three columns are set to be zero 
Lambda_var[0][i*4+3]=(1.0*dNdX[i*3+0]*dlambda_dX_f[0])/alfa;
Lambda_var[1][i*4+3]=(1.0*dNdX[i*3+1]*dlambda_dX_f[1])/alfa;
Lambda_var[2][i*4+3]=(1.0*dNdX[i*3+2]*dlambda_dX_f[2])/alfa;
Lambda_var[3][i*4+3]=(0.5*dNdX[i*3+0]*dlambda_dX_f[1]+0.5*dNdX[i*3+1]*dlambda_dX_f[0])/alfa;
Lambda_var[4][i*4+3]=(0.5*dNdX[i*3+1]*dlambda_dX_f[2]+0.5*dNdX[i*3+2]*dlambda_dX_f[1])/alfa;
Lambda_var[5][i*4+3]=(0.5*dNdX[i*3+2]*dlambda_dX_f[0]+0.5*dNdX[i*3+0]*dlambda_dX_f[2])/alfa;

Lambda_var[0][i*4+3]=Lambda_var[0][i*4+3]+(1.0*dNdX[i*3+0]*dlambda_dX_pf[0])/beta;
Lambda_var[1][i*4+3]=Lambda_var[1][i*4+3]+(1.0*dNdX[i*3+1]*dlambda_dX_pf[1])/beta;
Lambda_var[2][i*4+3]=Lambda_var[2][i*4+3]+(1.0*dNdX[i*3+2]*dlambda_dX_pf[2])/beta;
Lambda_var[3][i*4+3]=Lambda_var[3][i*4+3]+(0.5*dNdX[i*3+0]*dlambda_dX_pf[1]+0.5*dNdX[i*3+1]*dlambda_dX_pf[0])/beta;
Lambda_var[4][i*4+3]=Lambda_var[4][i*4+3]+(0.5*dNdX[i*3+1]*dlambda_dX_pf[2]+0.5*dNdX[i*3+2]*dlambda_dX_pf[1])/beta;
Lambda_var[5][i*4+3]=Lambda_var[5][i*4+3]+(0.5*dNdX[i*3+2]*dlambda_dX_pf[0]+0.5*dNdX[i*3+0]*dlambda_dX_pf[2])/beta;
} 


double first_v[32][6]; //left node driven 
double second_v[6][32]; //right node driven 

//they are all supposed to be initialized as zero 
for(int n=0;n<32;n++)
for(int j=0;j<6;j++)
first_v[n][j]=0.0;



for(int i=0;i<32;i++)
for(int j=0;j<6;j++)
first_v[i][j]=1.0*current_nf*current_nf*detF*Lambda_var[j][i];



for(int n=0;n<32;n++)
for(int j=0;j<6;j++)
second_v[j][n]=0.0;


for(int j=0;j<6;j++)
for(int k=0;k<6;k++)
for(int i=0;i<32;i++)
second_v[j][i]=second_v[j][i]+D_pore[j][k]*B[k][i];


for(int i=0;i<32;i++)
for(int k=0;k<6;k++)
for(int j=0;j<32;j++)
_K_M2uMat[i][j]=_K_M2uMat[i][j]+first_v[i][k]*second_v[k][j];



};


void calc_K_M2lambda_at_gauss(double _K_M2lambda[][32],
			      Node _nodes[],
	                      Element _elements[],
                              int _currentelement,
			      double M_vec[3],
			      double beta,
			      double alfa,
			      double current_nS,
			      double current_nf,
			      double dNdX[24],
			      double detF,
			      double CauchyInv[6],
			      ofstream &_debugfile
		              )

{


double dlambda_dX[3];
double Lambda_var[6][32][32];


double dlambda_dX_f[3];
double dlambda_dX_pf[3];
double M_met[3][3];



for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
M_met[i][j]=M_vec[i]*M_vec[j];




double dlambda_dX_fi[3];
double dlambda_dX_pfi[3];
for(int i=0;i<3;i++)
{
dlambda_dX_f[i]=0.0;
dlambda_dX[i]=0.0;
dlambda_dX_pf[i]=0.0;
dlambda_dX_fi[i]=0.0;
dlambda_dX_pfi[i]=0.0;
}



for(int i=0;i<24;i++) 
dlambda_dX[i%3]=dlambda_dX[i%3]+dNdX[i]*_nodes[_elements[_currentelement].connid[i/3]].u_lamb[3];



for(int i=0;i<6;i++)
for(int j=0;j<32;j++)
for(int k=0;k<32;k++)
Lambda_var[i][j][k]=0.0;



for(int i=0;i<8;i++)
for(int j=0;j<8;j++)
{

double current_convert[3];
current_convert[0]=dNdX[j*3+0];
current_convert[1]=dNdX[j*3+1];
current_convert[2]=dNdX[j*3+2];

double current_convert_i[3];
current_convert_i[0]=dNdX[i*3+0];
current_convert_i[1]=dNdX[i*3+1];
current_convert_i[2]=dNdX[i*3+2];



for(int k=0;k<3;k++)
for(int l=0;l<3;l++)
dlambda_dX_f[k]=dlambda_dX_f[k]+M_met[k][l]*current_convert[l];

for(int k=0;k<3;k++)
for(int l=0;l<3;l++)
dlambda_dX_pf[k]=dlambda_dX_pf[k]+(cronecker(k,l)-M_met[k][l])*current_convert[l];


for(int k=0;k<3;k++)
for(int l=0;l<3;l++)
dlambda_dX_fi[k]=dlambda_dX_fi[k]+M_met[k][l]*current_convert_i[l];

for(int k=0;k<3;k++)
for(int l=0;l<3;l++)
dlambda_dX_pfi[k]=dlambda_dX_pfi[k]+(cronecker(k,l)-M_met[k][l])*current_convert_i[l];




Lambda_var[0][i*4+3][j*4+3]=Lambda_var[0][i*4+3][j*4+3]+0.5*(1.0*dNdX[i*3+0]*dlambda_dX_f[0])/alfa;
Lambda_var[1][i*4+3][j*4+3]=Lambda_var[0][i*4+3][j*4+3]+0.5*(1.0*dNdX[i*3+1]*dlambda_dX_f[1])/alfa;
Lambda_var[2][i*4+3][j*4+3]=Lambda_var[0][i*4+3][j*4+3]+0.5*(1.0*dNdX[i*3+2]*dlambda_dX_f[2])/alfa;
Lambda_var[3][i*4+3][j*4+3]=Lambda_var[0][i*4+3][j*4+3]+0.5*(0.5*dNdX[i*3+0]*dlambda_dX_f[1]+0.5*dNdX[i*3+1]*dlambda_dX_f[0])/alfa;
Lambda_var[4][i*4+3][j*4+3]=Lambda_var[0][i*4+3][j*4+3]+0.5*(0.5*dNdX[i*3+1]*dlambda_dX_f[2]+0.5*dNdX[i*3+2]*dlambda_dX_f[1])/alfa;
Lambda_var[5][i*4+3][j*4+3]=Lambda_var[0][i*4+3][j*4+3]+0.5*(0.5*dNdX[i*3+2]*dlambda_dX_f[0]+0.5*dNdX[i*3+0]*dlambda_dX_f[2])/alfa;

Lambda_var[0][i*4+3][j*4+3]=Lambda_var[0][i*4+3][j*4+3]+0.5*(1.0*dNdX[i*3+0]*dlambda_dX_pf[0])/beta;
Lambda_var[1][i*4+3][j*4+3]=Lambda_var[1][i*4+3][j*4+3]+0.5*(1.0*dNdX[i*3+1]*dlambda_dX_pf[1])/beta;
Lambda_var[2][i*4+3][j*4+3]=Lambda_var[2][i*4+3][j*4+3]+0.5*(1.0*dNdX[i*3+2]*dlambda_dX_pf[2])/beta;
Lambda_var[3][i*4+3][j*4+3]=Lambda_var[3][i*4+3][j*4+3]+0.5*(0.5*dNdX[i*3+0]*dlambda_dX_pf[1]+0.5*dNdX[i*3+1]*dlambda_dX_pf[0])/beta;
Lambda_var[4][i*4+3][j*4+3]=Lambda_var[4][i*4+3][j*4+3]+0.5*(0.5*dNdX[i*3+1]*dlambda_dX_pf[2]+0.5*dNdX[i*3+2]*dlambda_dX_pf[1])/beta;
Lambda_var[5][i*4+3][j*4+3]=Lambda_var[5][i*4+3][j*4+3]+0.5*(0.5*dNdX[i*3+2]*dlambda_dX_pf[0]+0.5*dNdX[i*3+0]*dlambda_dX_pf[2])/beta;


Lambda_var[0][i*4+3][j*4+3]=Lambda_var[0][i*4+3][j*4+3]+0.5*(1.0*dNdX[j*3+0]*dlambda_dX_fi[0])/alfa;
Lambda_var[1][i*4+3][j*4+3]=Lambda_var[1][i*4+3][j*4+3]+0.5*(1.0*dNdX[j*3+1]*dlambda_dX_fi[1])/alfa;
Lambda_var[2][i*4+3][j*4+3]=Lambda_var[2][i*4+3][j*4+3]+0.5*(1.0*dNdX[j*3+2]*dlambda_dX_fi[2])/alfa;
Lambda_var[3][i*4+3][j*4+3]=Lambda_var[3][i*4+3][j*4+3]+0.5*(0.5*dNdX[j*3+0]*dlambda_dX_fi[1]+0.5*dNdX[j*3+1]*dlambda_dX_fi[0])/alfa;
Lambda_var[4][i*4+3][j*4+3]=Lambda_var[4][i*4+3][j*4+3]+0.5*(0.5*dNdX[j*3+1]*dlambda_dX_fi[2]+0.5*dNdX[j*3+2]*dlambda_dX_fi[1])/alfa;
Lambda_var[5][i*4+3][j*4+3]=Lambda_var[5][i*4+3][j*4+3]+0.5*(0.5*dNdX[j*3+2]*dlambda_dX_fi[0]+0.5*dNdX[j*3+0]*dlambda_dX_fi[2])/alfa;

Lambda_var[0][i*4+3][j*4+3]=Lambda_var[0][i*4+3][j*4+3]+0.5*(1.0*dNdX[j*3+0]*dlambda_dX_pfi[0])/beta;
Lambda_var[1][i*4+3][j*4+3]=Lambda_var[1][i*4+3][j*4+3]+0.5*(1.0*dNdX[j*3+1]*dlambda_dX_pfi[1])/beta;
Lambda_var[2][i*4+3][j*4+3]=Lambda_var[2][i*4+3][j*4+3]+0.5*(1.0*dNdX[j*3+2]*dlambda_dX_pfi[2])/beta;
Lambda_var[3][i*4+3][j*4+3]=Lambda_var[3][i*4+3][j*4+3]+0.5*(0.5*dNdX[j*3+0]*dlambda_dX_pfi[1]+0.5*dNdX[j*3+1]*dlambda_dX_pfi[0])/beta;
Lambda_var[4][i*4+3][j*4+3]=Lambda_var[4][i*4+3][j*4+3]+0.5*(0.5*dNdX[j*3+1]*dlambda_dX_pfi[2]+0.5*dNdX[j*3+2]*dlambda_dX_pfi[1])/beta;
Lambda_var[5][i*4+3][j*4+3]=Lambda_var[5][i*4+3][j*4+3]+0.5*(0.5*dNdX[j*3+2]*dlambda_dX_pfi[0]+0.5*dNdX[j*3+0]*dlambda_dX_pfi[2])/beta;





for(int k=0;k<3;k++)
{
dlambda_dX_f[k]=0.0;
dlambda_dX_fi[k]=0.0;
dlambda_dX_pf[k]=0.0;
dlambda_dX_pfi[k]=0.0;
}


} 



for(int i=0;i<32;i++)
for(int k=0;k<6;k++)
for(int j=0;j<32;j++)
_K_M2lambda[j][i]=_K_M2lambda[j][i]+1.0*current_nf*current_nf*detF*Lambda_var[k][i][j]*CauchyInv[k];

};