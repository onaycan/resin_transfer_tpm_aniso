void master_nodes_update(master_Node _masternodes[], int _numberofmasternodes, double _l, double _numberofloadsteps)
{
for(int n=0;n<_numberofmasternodes;n++)
{
//for(int i=0;i<3;i++)
_masternodes[n].masterX[2]=_masternodes[n].masterX[2]+0.5;
}


};


void contact_disp_update(Node _nodes[], Element _elements[], int &_numberofnodes, int &_numberofelements, csrM & _K, double fi[], ofstream &_debugfile, double _l, double numberofloadsteps, int &noclearence,
                         master_Node _masternodes[], master_Element _masterelements[], int _numberofmasternodes, int _numberofmasterelements, int c)
{
double beta_2=0.25;
double beta_1=0.5;
double penalty_coeff=pow(10.0,10.0);
double penetration_depth=-1.0;
for(int n=0;n<_numberofnodes;n++)
if(_nodes[n].nodenormals_x.size()!=0.0)//indicating that this is a contact node 
{
double current_gap[3];
double current_pa[3];
double current_pb[3];
double current_pc[3];
double current_xa[3];
double current_slave_Normal[3];
double current_slave_normal[3];
double size_current_slave_normal=0.0;
double current_slave_x[3];
double A[3][3];
double A_inv[3][3];
double B[6][24];
double B_node[6][3];
double F[9];
double F_tens[3][3];
double F_tens_inv[3][3];
double F_tens_invT[3][3];
int current_homeelement;
int current_homeconnectivity;
double current_contact_f[3];
double current_contact_K[4][4];




current_slave_Normal[0]=_nodes[n].nodeNormals_x[_nodes[n].nodeNormals_x.size()-1];
current_slave_Normal[1]=_nodes[n].nodeNormals_y[_nodes[n].nodeNormals_x.size()-1];
current_slave_Normal[2]=_nodes[n].nodeNormals_z[_nodes[n].nodeNormals_x.size()-1];

for(int i=0;i<3;i++)
_nodes[n].u_lamb[i]=_nodes[n].u_lamb[i]+_nodes[n].du_lamb[i];


current_slave_x[0]=_nodes[n].X_lamb[0]+_nodes[n].u_lamb[0];
current_slave_x[1]=_nodes[n].X_lamb[1]+_nodes[n].u_lamb[1];
current_slave_x[2]=_nodes[n].X_lamb[2]+_nodes[n].u_lamb[2];

current_homeelement=_nodes[n].contacthomeelement_id;
current_homeconnectivity=_nodes[n].contacthomeelement_connection;

double ksi=0.0;
double eta=0.0;
double zeta=0.0;
//to which connectivity is the contact node belongs 
if(current_homeconnectivity==0)
{ksi=-1.0; eta=-1.0; zeta=-1.0;}
else if(current_homeconnectivity==1)
{ksi=1.0; eta=-1.0; zeta=-1.0;}
else if(current_homeconnectivity==2)
{ksi=1.0; eta=1.0; zeta=-1.0;}
else if(current_homeconnectivity==3)
{ksi=-1.0; eta=1.0; zeta=-1.0;}
else if(current_homeconnectivity==4)
{ksi=-1.0; eta=-1.0; zeta=1.0;}
else if(current_homeconnectivity==5)
{ksi=1.0; eta=-1.0; zeta=1.0;}
else if(current_homeconnectivity==6)
{ksi=1.0; eta=1.0; zeta=1.0;}
else if(current_homeconnectivity==7)
{ksi=-1.0; eta=1.0; zeta=1.0;}


//deformation gradient at contact node 

F_at_contact_node(_nodes,_elements,ksi,eta,zeta,current_homeelement,B,F,_debugfile);
for(int i=0;i<3;i++)
_nodes[n].u_lamb[i]=_nodes[n].u_lamb[i]-_nodes[n].du_lamb[i];



for(int i=0;i<6;i++)
for(int j=0;j<3;j++)
B_node[i][j]=B[i][current_homeconnectivity*3+j];



for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
F_tens[i][j]=F[i*3+j];

inverse(F_tens,F_tens_inv);

for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
F_tens_invT[i][j]=F_tens_inv[j][i];

for(int i=0;i<3;i++)
current_slave_normal[i]=0.0;


//nanson's formula applied 
for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
current_slave_normal[i]=current_slave_normal[i]+F_tens_invT[i][j]*current_slave_Normal[j];
for(int i=0;i<3;i++)
size_current_slave_normal=size_current_slave_normal+current_slave_normal[i]*current_slave_normal[i];
size_current_slave_normal=sqrt(size_current_slave_normal);

//unit current normal 
for(int i=0;i<3;i++)
current_slave_normal[i]=current_slave_normal[i]/size_current_slave_normal;

//start of determination of the target 



_nodes[n].nodenormals_x[0]=current_slave_normal[0];
_nodes[n].nodenormals_y[0]=current_slave_normal[1];
_nodes[n].nodenormals_z[0]=current_slave_normal[2];

/*
current_pa[0]=0.0;
current_pa[1]=98.68+penetration_depth*_l/numberofloadsteps;
current_pa[2]=0.0;

current_pb[0]=0.0;
current_pb[1]=98.68+penetration_depth*_l/numberofloadsteps;
current_pb[2]=100.0;

current_pc[0]=100.0;
current_pc[1]=98.68+penetration_depth*_l/numberofloadsteps;
current_pc[2]=0.0;

A[0][0]=-current_slave_normal[0];
A[1][0]=-current_slave_normal[1];
A[2][0]=-current_slave_normal[2];

A[0][1]=current_pb[0]-current_pa[0];
A[1][1]=current_pb[1]-current_pa[1];
A[2][1]=current_pb[2]-current_pa[2];

A[0][2]=current_pc[0]-current_pa[0];
A[1][2]=current_pc[1]-current_pa[1];
A[2][2]=current_pc[2]-current_pa[2];

for(int i=0;i<3;i++)
current_xa[i]=current_slave_x[i]-current_pa[i];

inverse(A,A_inv);
double detA=det(A);

// check if the overclosure is reached or not 
for(int i=0;i<3;i++)
current_gap=current_gap+A_inv[0][i]*current_xa[i];
*/
//_debugfile<<_nodes[n].nodelabel<<'\t'<<current_gap<<endl;

double penetration_coeff=1.0;
double epsilon=pow(10.0,-6.0);
double tolerance=0.05;
int found=0;
int _nodelabel=_nodes[n].nodelabel;
//cout<<"start master_search"<<endl;
master_search(_masternodes, _masterelements, _numberofmasternodes, _numberofmasterelements,
              current_slave_normal, current_pa, current_pb, current_pc, current_slave_x, 
              A, current_gap, found, _debugfile, _nodelabel);
//cout<<"end master_search"<<endl;

//_nodes[n].activ_contactnode=0;
if(found==1)
{
noclearence++;
/*
_debugfile<<"this node is to be corrected"<<endl;
_debugfile<<_nodes[n].nodelabel<<'\t'<<current_gap[0]<<endl;
//_debugfile<<detA<<endl;
_debugfile<<ksi<<'\t'<<eta<<'\t'<<zeta<<endl;
_debugfile<<current_slave_normal[0]<<'\t'<<current_slave_normal[1]<<'\t'<<current_slave_normal[2]<<endl;
*/
_nodes[n].activ_contactnode=1;

//if(c==0)
for(int i=0;i<3;i++)
{
//_nodes[n].u_lamb[i]=_nodes[n].u_lamb[i]-_nodes[n].du_lamb[i];
_nodes[n].du_lamb[i]=current_slave_normal[i]*current_gap[0];//-current_slave_normal[i]*tolerance;//+current_slave_normal[i]*epsilon;
//_nodes[n].u_lamb[i]=_nodes[n].u_lamb[i]+_nodes[n].du_lamb[i];
//_debugfile<<'\t'<<_nodes[n].du_lamb[i]<<endl;
//if(_nodes[n].du_lamb[i]!=0.0)
//{
//_nodes[n].natural_bc[i]=1;
//_nodes[n].natural_val[i]=_nodes[n].du_lamb[i];
//_nodes[n].nonzero_natural_bc[i]=1;
//}
}
}


}
};


void master_search(master_Node _masternodes[], master_Element _masterelements[], int _numberofmasternodes, int _numberofmasterelements,
                   double _current_slave_normal[3], double _current_pa[3], double _current_pb[3], double _current_pc[3], double _current_slave_x[3], 
                   double _A[3][3], double _current_gap[3], int& _found, ofstream &_debugfile, int homenode)
{
_found=0;
int e=0;
while(_found==0 && e<_numberofmasterelements) 
{
double v_one[3];
double v_two[3];
double master_normal[3];
double current_xa[3];
double size_master_normal=0.0;
double dot_prod=0.0;
double A_inv[3][3];

for(int i=0;i<3;i++)
{
v_one[i]=_masternodes[_masterelements[e].master_connid[1]].masterX[i]-_masternodes[_masterelements[e].master_connid[0]].masterX[i];
v_two[i]=_masternodes[_masterelements[e].master_connid[3]].masterX[i]-_masternodes[_masterelements[e].master_connid[0]].masterX[i];
}



cross_product(v_one,v_two,master_normal);
for(int j=0;j<3;j++)
size_master_normal=size_master_normal+master_normal[j]*master_normal[j];
for(int j=0;j<3;j++)
master_normal[j]=master_normal[j]/sqrt(size_master_normal);
for(int j=0;j<3;j++)
dot_prod=dot_prod+master_normal[j]*_current_slave_normal[j];

//cout<<master_normal[0]<<endl;
//cout<<master_normal[1]<<endl;
//cout<<master_normal[2]<<endl;


if(dot_prod>0.0)
{
//first triangle 
for(int i=0;i<3;i++)
{
_current_pa[i]=_masternodes[_masterelements[e].master_connid[0]].masterX[i];
_current_pb[i]=_masternodes[_masterelements[e].master_connid[1]].masterX[i];
_current_pc[i]=_masternodes[_masterelements[e].master_connid[3]].masterX[i];
}
_A[0][0]=-_current_slave_normal[0];
_A[1][0]=-_current_slave_normal[1];
_A[2][0]=-_current_slave_normal[2];

_A[0][1]=_current_pb[0]-_current_pa[0];
_A[1][1]=_current_pb[1]-_current_pa[1];
_A[2][1]=_current_pb[2]-_current_pa[2];

_A[0][2]=_current_pc[0]-_current_pa[0];
_A[1][2]=_current_pc[1]-_current_pa[1];
_A[2][2]=_current_pc[2]-_current_pa[2];

for(int i=0;i<3;i++)
current_xa[i]=_current_slave_x[i]-_current_pa[i];

double detA=det(_A);

for(int j=0;j<3;j++)
_current_gap[j]=0.0;


if(detA!=0.0)
{
inverse(_A,A_inv);


// check if the overclosure is reached or not 
for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
_current_gap[i]=_current_gap[i]+A_inv[i][j]*current_xa[j];
/*
if(homenode==1683)
{
_debugfile<<_masterelements[e].master_elementlabel<<endl;
_debugfile<<_current_gap[0]<<'\t'<<_current_gap[1]<<'\t'<<_current_gap[2]<<endl;
}
*/
double epsilon=pow(10.0,-10.0);
int gap_condition=0;
if(_current_gap[0]<0.0)
if(fabs(_current_gap[0])>epsilon)
gap_condition=1;


if(gap_condition==1)
{
if(_current_gap[1]<=1.0 && _current_gap[1]>0.0)
if(_current_gap[2]<=1.0 && _current_gap[2]>0.0)
if((_current_gap[1]+_current_gap[2])<=1.0)
_found=1;
}
}




if(_found==0)
{
for(int i=0;i<3;i++)
{
_current_pa[i]=_masternodes[_masterelements[e].master_connid[2]].masterX[i];
_current_pb[i]=_masternodes[_masterelements[e].master_connid[1]].masterX[i];
_current_pc[i]=_masternodes[_masterelements[e].master_connid[3]].masterX[i];
}
_A[0][0]=-_current_slave_normal[0];
_A[1][0]=-_current_slave_normal[1];
_A[2][0]=-_current_slave_normal[2];

_A[0][1]=_current_pb[0]-_current_pa[0];
_A[1][1]=_current_pb[1]-_current_pa[1];
_A[2][1]=_current_pb[2]-_current_pa[2];

_A[0][2]=_current_pc[0]-_current_pa[0];
_A[1][2]=_current_pc[1]-_current_pa[1];
_A[2][2]=_current_pc[2]-_current_pa[2];

for(int i=0;i<3;i++)
current_xa[i]=_current_slave_x[i]-_current_pa[i];

detA=det(_A);

for(int j=0;j<3;j++)
_current_gap[j]=0.0;


if(detA!=0.0)
{
inverse(_A,A_inv);


// check if the overclosure is reached or not 
for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
_current_gap[i]=_current_gap[i]+A_inv[i][j]*current_xa[j];

double epsilon=pow(10.0,-10.0);
int gap_condition=0;
if(_current_gap[0]<0.0)
if(fabs(_current_gap[0])>epsilon)
gap_condition=1;

//

//if(_current_gap[0]>0.0)
//if(fabs(_current_gap[0])<epsilon)
//gap_condition=1;



if(gap_condition==1)
if(_current_gap[1]<=1.0 && _current_gap[1]>0.0)
if(_current_gap[2]<=1.0 && _current_gap[2]>0.0)
if((_current_gap[1]+_current_gap[2])<=1.0)
_found=1;
}
}



}





e++;
};











};




void contact_enforcer(Node _nodes[], Element _elements[], int &_numberofnodes, int &_numberofelements, csrM & _K, double fi[], ofstream &_debugfile, double _l, double numberofloadsteps, int &noclearence)
{
double beta_2=0.25;
double beta_1=0.5;
double penalty_coeff=pow(10.0,10.0);
double penetration_depth=-0.6;
for(int n=0;n<_numberofnodes;n++)
if(_nodes[n].nodenormals_x.size()!=0.0)//indicating that this is a contact node 
{
double current_gap=0.0;
double current_pa[3];
double current_pb[3];
double current_pc[3];
double current_xa[3];
double current_slave_Normal[3];
double current_slave_normal[3];
double size_current_slave_normal=0.0;
double current_slave_x[3];
double A[3][3];
double A_inv[3][3];
double B[6][24];
double B_node[6][3];
double F[9];
double F_tens[3][3];
double F_tens_inv[3][3];
double F_tens_invT[3][3];
int current_homeelement;
int current_homeconnectivity;
double current_contact_f[3];
double current_contact_K[4][4];


current_pa[0]=0.0;
current_pa[1]=98.68+penetration_depth*_l/numberofloadsteps;
current_pa[2]=0.0;

current_pb[0]=0.0;
current_pb[1]=98.68+penetration_depth*_l/numberofloadsteps;
current_pb[2]=100.0;

current_pc[0]=100.0;
current_pc[1]=98.68+penetration_depth*_l/numberofloadsteps;
current_pc[2]=0.0;

current_slave_Normal[0]=_nodes[n].nodeNormals_x[0];
current_slave_Normal[1]=_nodes[n].nodeNormals_y[0];
current_slave_Normal[2]=_nodes[n].nodeNormals_z[0];

current_slave_x[0]=_nodes[n].X_lamb[0]+_nodes[n].u_lamb[0];
current_slave_x[1]=_nodes[n].X_lamb[1]+_nodes[n].u_lamb[1];
current_slave_x[2]=_nodes[n].X_lamb[2]+_nodes[n].u_lamb[2];

current_homeelement=_nodes[n].contacthomeelement_id;
current_homeconnectivity=_nodes[n].contacthomeelement_connection;

double ksi=0.0;
double eta=0.0;
double zeta=0.0;
//to which connectivity is the contact node belongs 
if(current_homeconnectivity==0)
{ksi=-1.0; eta=-1.0; zeta=-1.0;}
else if(current_homeconnectivity==1)
{ksi=1.0; eta=-1.0; zeta=-1.0;}
else if(current_homeconnectivity==2)
{ksi=1.0; eta=1.0; zeta=-1.0;}
else if(current_homeconnectivity==3)
{ksi=-1.0; eta=1.0; zeta=-1.0;}
else if(current_homeconnectivity==4)
{ksi=-1.0; eta=-1.0; zeta=1.0;}
else if(current_homeconnectivity==5)
{ksi=1.0; eta=-1.0; zeta=1.0;}
else if(current_homeconnectivity==6)
{ksi=1.0; eta=1.0; zeta=1.0;}
else if(current_homeconnectivity==7)
{ksi=-1.0; eta=1.0; zeta=1.0;}



//deformation gradient at contact node 
F_at_contact_node(_nodes,_elements,ksi,eta,zeta,current_homeelement,B,F,_debugfile);


for(int i=0;i<6;i++)
for(int j=0;j<3;j++)
B_node[i][j]=B[i][current_homeconnectivity*3+j];



for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
F_tens[i][j]=F[i*3+j];

inverse(F_tens,F_tens_inv);

for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
F_tens_invT[i][j]=F_tens_inv[j][i];

for(int i=0;i<3;i++)
current_slave_normal[i]=0.0;


//nanson's formula applied 
for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
current_slave_normal[i]=current_slave_normal[i]+F_tens_invT[i][j]*current_slave_Normal[j];
for(int i=0;i<3;i++)
size_current_slave_normal=size_current_slave_normal+current_slave_normal[i]*current_slave_normal[i];
size_current_slave_normal=sqrt(size_current_slave_normal);

//unit current normal 
for(int i=0;i<3;i++)
current_slave_normal[i]=current_slave_normal[i]/size_current_slave_normal;

_nodes[n].nodenormals_x[0]=current_slave_normal[0];
_nodes[n].nodenormals_y[0]=current_slave_normal[1];
_nodes[n].nodenormals_z[0]=current_slave_normal[2];




A[0][0]=-current_slave_normal[0];
A[1][0]=-current_slave_normal[1];
A[2][0]=-current_slave_normal[2];

A[0][1]=current_pb[0]-current_pa[0];
A[1][1]=current_pb[1]-current_pa[1];
A[2][1]=current_pb[2]-current_pa[2];

A[0][2]=current_pc[0]-current_pa[0];
A[1][2]=current_pc[1]-current_pa[1];
A[2][2]=current_pc[2]-current_pa[2];

for(int i=0;i<3;i++)
current_xa[i]=current_slave_x[i]-current_pa[i];

inverse(A,A_inv);
double detA=det(A);


// check if the overclosure is reached or not 
for(int i=0;i<3;i++)
current_gap=current_gap+A_inv[0][i]*current_xa[i];

//_debugfile<<_nodes[n].nodelabel<<'\t'<<current_gap<<endl;

double penetration_coeff=1.0;
double tolerance=0.05;


if(current_gap<0.0)
{
//noclearence++;
_debugfile<<"this node is still behind the overclosure !"<<endl;
_debugfile<<_nodes[n].nodelabel<<'\t'<<current_gap<<endl;//'\t'<<detA<<endl;
//_debugfile<<'\t'<<current_slave_normal[0]<<'\t'<<current_slave_normal[1]<<'\t'<<current_slave_normal[2];
}

//if(fabs(current_gap)<0.05 || current_gap<0.0)
if(current_gap<tolerance)
{


//penetration_coeff=-1.0;

//initialize the contact force as zero 
for(int i=0;i<3;i++)
current_contact_f[i]=0.0;

//compute the contact force 
for(int l=0;l<3;l++)
for(int i=0;i<3;i++)
current_contact_f[i]=current_contact_f[i]-penetration_coeff*penalty_coeff*A_inv[0][l]*current_xa[l]*current_slave_normal[i];

//computation of the derivative of the current normal with respect to the Cauchy Green Strain tensor 
double F_dot[3][3];
double F_dotT[3][3];
double FT[3][3];
double delFinvT_delC_tens[3][3][3][3];
double nom[3][3];
double denom[3][3];
double Cauchy[3][3];
double Cauchy_inv[3][3];
double deln_delC_tens[3][3][3];
double deln_delC[3][6];
double C_contrac_Normal=0.0;



double coeff;
if(_l>0.0)
coeff=1.0*beta_2/beta_1/_l;
else if(_l==0.0)
coeff=1.0;



F_dot[0][0]=1.0*coeff*(F_tens[0][0]-1.0);
F_dot[0][1]=1.0*coeff*(F_tens[0][1]);
F_dot[0][2]=1.0*coeff*(F_tens[0][2]);
F_dot[1][0]=1.0*coeff*(F_tens[1][0]);
F_dot[1][1]=1.0*coeff*(F_tens[1][1]-1.0);
F_dot[1][2]=1.0*coeff*(F_tens[1][2]);
F_dot[2][0]=1.0*coeff*(F_tens[2][0]);
F_dot[2][1]=1.0*coeff*(F_tens[2][1]);
F_dot[2][2]=1.0*coeff*(F_tens[2][2]-1.0);


for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
{
F_dotT[i][j]=F_dot[j][i];
FT[i][j]=F_tens[j][i];
nom[i][j]=0.0;
denom[i][j]=0.0;
}


for(int i=0;i<3;i++)
for(int k=0;k<3;k++)
for(int l=0;l<3;l++)
for(int j=0;j<3;j++)
nom[i][j]=nom[i][j]-F_tens_inv[i][k]*F_dotT[k][l]*F_tens_inv[l][j];

for(int k=0;k<3;k++)
for(int i=0;i<3;i++)
for(int l=0;l<3;l++)
denom[k][l]=denom[k][l]+F_dotT[k][i]+F_tens[i][l]+FT[k][i]*F_dot[i][l];


for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
for(int k=0;k<3;k++)
for(int l=0;l<3;l++)
{
if(denom[k][l]!=0.0)
delFinvT_delC_tens[i][j][k][l]=nom[i][j]/denom[k][l];
else 
delFinvT_delC_tens[i][j][k][l]=0.0;
}


for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
Cauchy[i][j]=0.0;


for(int i=0;i<3;i++)
for(int k=0;k<3;k++)
for(int j=0;j<3;j++)
Cauchy[i][j]=Cauchy[i][j]+FT[i][k]*F_tens[k][j];

inverse(Cauchy,Cauchy_inv);

for(int i=0;i<3;i++)
for(int k=0;k<3;k++)
for(int j=0;j<3;j++)
deln_delC_tens[i][k][j]=0.0;


for(int o=0;o<3;o++)
for(int p=0;p<3;p++)
C_contrac_Normal=C_contrac_Normal+Cauchy_inv[o][p]*current_slave_Normal[o]*current_slave_Normal[p];


for(int i=0;i<3;i++)
for(int m=0;m<3;m++)
for(int k=0;k<3;k++)
for(int l=0;l<3;l++)
{
if(C_contrac_Normal!=0.0)
deln_delC_tens[i][k][l]=deln_delC_tens[i][k][l]+delFinvT_delC_tens[i][m][k][l]*current_slave_Normal[m]/C_contrac_Normal;
}

for(int o=0;o<3;o++)
for(int k=0;k<3;k++)
for(int l=0;l<3;l++)
for(int p=0;p<3;p++)
for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
{
if(C_contrac_Normal!=0.0)
deln_delC_tens[i][k][l]=deln_delC_tens[i][k][l]+Cauchy_inv[o][k]*Cauchy_inv[l][p]*current_slave_Normal[o]*current_slave_Normal[p]/C_contrac_Normal/C_contrac_Normal*F_tens_inv[i][j]*current_slave_Normal[j];
}


for(int i=0;i<3;i++)
{
deln_delC[i][0]=deln_delC_tens[i][0][0];
deln_delC[i][1]=deln_delC_tens[i][1][1];
deln_delC[i][2]=deln_delC_tens[i][2][2];
deln_delC[i][3]=deln_delC_tens[i][0][1];
deln_delC[i][4]=deln_delC_tens[i][1][2];
deln_delC[i][5]=deln_delC_tens[i][2][0];
}




for(int i=0;i<4;i++)
for(int j=0;j<4;j++)
current_contact_K[i][j]=0.0;

//compute the contact force 



for(int o=0;o<3;o++)
for(int p=0;p<3;p++)
for(int j=0;j<3;j++)
for(int l=0;l<3;l++)
for(int i=0;i<3;i++)
current_contact_K[i][j]=current_contact_K[i][j]-
penalty_coeff*A_inv[0][o]*A_inv[0][l]*deln_delC[o][p]*B_node[p][j]*current_xa[l]*current_slave_normal[i];

for(int j=0;j<3;j++)
for(int i=0;i<3;i++)
current_contact_K[i][j]=current_contact_K[i][j]-
penalty_coeff*A_inv[0][j]*current_slave_normal[i];

for(int p=0;p<3;p++)
for(int j=0;j<3;j++)
for(int l=0;l<3;l++)
for(int i=0;i<3;i++)
current_contact_K[i][j]=current_contact_K[i][j]-
penalty_coeff*A_inv[0][l]*current_xa[l]*deln_delC[i][p]*B_node[p][j];


for(int i=0;i<4;i++)
for(int j=0;j<4;j++)
current_contact_K[i][j]=penetration_coeff*current_contact_K[i][j];


//updating the contact force and stiffness 
for(int i=0;i<3;i++)
fi[n*4+i]=fi[n*4+i]-current_contact_f[i];


double current_contact_K_red[4][4];
double normal_metric[3][3];

for(int i=0;i<4;i++)
for(int j=0;j<4;j++)
current_contact_K_red[i][j]=0.0;

for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
normal_metric[i][j]=current_slave_normal[i]*current_slave_normal[j];


for(int i=0;i<3;i++)
for(int k=0;k<3;k++)
for(int l=0;l<3;l++)
for(int j=0;j<3;j++)
current_contact_K_red[i][j]=current_contact_K_red[i][j]+normal_metric[i][k]*current_contact_K[k][l]*normal_metric[l][j];




_K.Insert_Matrix_incsrM(current_contact_K_red, n*4, n*4);




}


}




};



void normal_clusterer(Node &node, double current_normal[3])
{
int significantly_different=0;
if(node.nodeNormals_x.size()!=0)
for(int i=0;i<node.nodeNormals_x.size();i++)
{
double that_nodenormal[3];
double current_dot=0.0;
that_nodenormal[0]=node.nodeNormals_x[i];
that_nodenormal[1]=node.nodeNormals_y[i];
that_nodenormal[2]=node.nodeNormals_z[i];
for(int j=0;j<3;j++)
current_dot=current_dot+that_nodenormal[j]*current_normal[j];
if(asin(current_dot)*180.0/3.1415926>15.0)
significantly_different=1;
}

if(significantly_different==0)
{
node.nodeNormals_x.push_back(current_normal[0]);
node.nodeNormals_y.push_back(current_normal[1]);
node.nodeNormals_z.push_back(current_normal[2]);
}

};


void current_normal_allocater(Node &node)
{
int significantly_different=0;
if(node.nodeNormals_x.size()!=0)
for(int i=0;i<node.nodeNormals_x.size();i++)
{
node.nodenormals_x.push_back(node.nodeNormals_x[i]);
node.nodenormals_y.push_back(node.nodeNormals_y[i]);
node.nodenormals_z.push_back(node.nodeNormals_z[i]);
}

};








void F_at_contact_node(Node _nodes[],
	               Element _elements[],
	               double _ksi, double _eta, double _zeta,
                       int _currentelement,
	               double B[][24], //Strain displacement matrix 
		       double F[], //deformation gradient 
                       ofstream &_debugfile
		       )
{
double jacob[3][3];
double detj; 
double shapederivative[9][24];
double modifiedinversejacob_B[6][9];
double modifiedinversejacob_F[9][9];
double Finterpolator[9][24];
double Gradu[9];
double GraduT_tensor[3][3];
double BLin[6][24];
double BNLin[6][24];


for(int i=0;i<9;i++)
F[i]=0.0;

for(int i=0;i<6;i++)
for(int j=0;j<24;j++)
{
//With BLin it is not necessarily meant the Linear Strain displacement matrix 
//It represents only the previous multiplication of the Nonlinear strain displacement matrix 
BLin[i][j]=0.0; 
BNLin[i][j]=0.0; 
}


for(int i=0;i<6;i++)
for(int j=0;j<32;j++)
B[i][j]=0.0;

for(int i=0;i<9;i++)
for(int j=0;j<24;j++)
{
shapederivative[i][j]=0.0;
Finterpolator[i][j]=0.0;
Gradu[i]=0.0;
}
for(int i=0;i<6;i++)
for(int j=0;j<9;j++)
modifiedinversejacob_B[i][j]=0.0;


for(int i=0;i<9;i++)
for(int j=0;j<9;j++)
modifiedinversejacob_F[i][j]=0.0;


shapederivative[0][0]=shapederivative[3][1]=shapederivative[6][2]=-0.125*(1.0-_eta)*(1.0-_zeta);
shapederivative[1][0]=shapederivative[4][1]=shapederivative[7][2]=-0.125*(1.0-_ksi)*(1.0-_zeta);
shapederivative[2][0]=shapederivative[5][1]=shapederivative[8][2]=-0.125*(1.0-_ksi)*(1.0-_eta);
//2 three columns 
shapederivative[0][3]=shapederivative[3][4]=shapederivative[6][5]=0.125*(1.0-_eta)*(1.0-_zeta);
shapederivative[1][3]=shapederivative[4][4]=shapederivative[7][5]=-0.125*(1.0+_ksi)*(1.0-_zeta);
shapederivative[2][3]=shapederivative[5][4]=shapederivative[8][5]=-0.125*(1.0+_ksi)*(1.0-_eta);
//3 three columns 
shapederivative[0][6]=shapederivative[3][7]=shapederivative[6][8]=0.125*(1.0+_eta)*(1.0-_zeta);
shapederivative[1][6]=shapederivative[4][7]=shapederivative[7][8]=0.125*(1.0+_ksi)*(1.0-_zeta);
shapederivative[2][6]=shapederivative[5][7]=shapederivative[8][8]=-0.125*(1.0+_ksi)*(1.0+_eta);
//4 three columns 
shapederivative[0][9]=shapederivative[3][10]=shapederivative[6][11]=-0.125*(1.0+_eta)*(1.0-_zeta);
shapederivative[1][9]=shapederivative[4][10]=shapederivative[7][11]=0.125*(1.0-_ksi)*(1.0-_zeta);
shapederivative[2][9]=shapederivative[5][10]=shapederivative[8][11]=-0.125*(1.0-_ksi)*(1.0+_eta);
//5 three columns 
shapederivative[0][12]=shapederivative[3][13]=shapederivative[6][14]=-0.125*(1.0-_eta)*(1.0+_zeta);
shapederivative[1][12]=shapederivative[4][13]=shapederivative[7][14]=-0.125*(1.0-_ksi)*(1.0+_zeta);
shapederivative[2][12]=shapederivative[5][13]=shapederivative[8][14]=0.125*(1.0-_ksi)*(1.0-_eta);
//6 three columns 
shapederivative[0][15]=shapederivative[3][16]=shapederivative[6][17]=0.125*(1.0-_eta)*(1.0+_zeta);
shapederivative[1][15]=shapederivative[4][16]=shapederivative[7][17]=-0.125*(1.0+_ksi)*(1.0+_zeta);
shapederivative[2][15]=shapederivative[5][16]=shapederivative[8][17]=0.125*(1.0+_ksi)*(1.0-_eta);
//7 three columns 
shapederivative[0][18]=shapederivative[3][19]=shapederivative[6][20]=0.125*(1.0+_eta)*(1.0+_zeta);
shapederivative[1][18]=shapederivative[4][19]=shapederivative[7][20]=0.125*(1.0+_ksi)*(1.0+_zeta);
shapederivative[2][18]=shapederivative[5][19]=shapederivative[8][20]=0.125*(1.0+_ksi)*(1.0+_eta);
//8 three columns 
shapederivative[0][21]=shapederivative[3][22]=shapederivative[6][23]=-0.125*(1.0+_eta)*(1.0+_zeta);
shapederivative[1][21]=shapederivative[4][22]=shapederivative[7][23]=0.125*(1.0-_ksi)*(1.0+_zeta);
shapederivative[2][21]=shapederivative[5][22]=shapederivative[8][23]=0.125*(1.0-_ksi)*(1.0+_eta);

for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
jacob[i][j]=0.0; 

//CAUTION! MOST PROBABLY THE TOTAL DEFORMATION AND THUS THE CURRENT COORDINATES HAVE TO BE USED HERE ! 
for(int i=0;i<3;i++)
for(int j=0;j<8;j++)
{
jacob[0][i]=jacob[0][i]+shapederivative[i][j*3]*_nodes[_elements[_currentelement].connid[j]].X_lamb[0];
jacob[1][i]=jacob[1][i]+shapederivative[i][j*3]*_nodes[_elements[_currentelement].connid[j]].X_lamb[1];
jacob[2][i]=jacob[2][i]+shapederivative[i][j*3]*_nodes[_elements[_currentelement].connid[j]].X_lamb[2];
}

detj=det(jacob);



modifiedinversejacob_B[0][0]=modifiedinversejacob_B[3][3]=modifiedinversejacob_B[5][6]=(jacob[1][1]*jacob[2][2]-jacob[2][1]*jacob[1][2])/detj;
modifiedinversejacob_B[0][1]=modifiedinversejacob_B[3][4]=modifiedinversejacob_B[5][7]=(jacob[1][2]*jacob[2][0]-jacob[2][2]*jacob[1][0])/detj;
modifiedinversejacob_B[0][2]=modifiedinversejacob_B[3][5]=modifiedinversejacob_B[5][8]=(jacob[1][0]*jacob[2][1]-jacob[2][0]*jacob[1][1])/detj;

modifiedinversejacob_B[1][3]=modifiedinversejacob_B[3][0]=modifiedinversejacob_B[4][6]=(jacob[0][2]*jacob[2][1]-jacob[2][2]*jacob[0][1])/detj;
modifiedinversejacob_B[1][4]=modifiedinversejacob_B[3][1]=modifiedinversejacob_B[4][7]=(jacob[0][0]*jacob[2][2]-jacob[2][0]*jacob[0][2])/detj;
modifiedinversejacob_B[1][5]=modifiedinversejacob_B[3][2]=modifiedinversejacob_B[4][8]=(jacob[0][1]*jacob[2][0]-jacob[2][1]*jacob[0][0])/detj;

modifiedinversejacob_B[2][6]=modifiedinversejacob_B[4][3]=modifiedinversejacob_B[5][0]=(jacob[0][1]*jacob[1][2]-jacob[1][1]*jacob[0][2])/detj;
modifiedinversejacob_B[2][7]=modifiedinversejacob_B[4][4]=modifiedinversejacob_B[5][1]=(jacob[0][2]*jacob[1][0]-jacob[1][2]*jacob[0][0])/detj;
modifiedinversejacob_B[2][8]=modifiedinversejacob_B[4][5]=modifiedinversejacob_B[5][2]=(jacob[0][0]*jacob[1][1]-jacob[1][0]*jacob[0][1])/detj;


modifiedinversejacob_F[0][0]=modifiedinversejacob_F[3][3]=modifiedinversejacob_F[6][6]=(jacob[1][1]*jacob[2][2]-jacob[2][1]*jacob[1][2])/detj;
modifiedinversejacob_F[0][1]=modifiedinversejacob_F[3][4]=modifiedinversejacob_F[6][7]=(jacob[1][2]*jacob[2][0]-jacob[2][2]*jacob[1][0])/detj;
modifiedinversejacob_F[0][2]=modifiedinversejacob_F[3][5]=modifiedinversejacob_F[6][8]=(jacob[1][0]*jacob[2][1]-jacob[2][0]*jacob[1][1])/detj;

modifiedinversejacob_F[1][0]=modifiedinversejacob_F[4][3]=modifiedinversejacob_F[7][6]=(jacob[0][2]*jacob[2][1]-jacob[2][2]*jacob[0][1])/detj;
modifiedinversejacob_F[1][1]=modifiedinversejacob_F[4][4]=modifiedinversejacob_F[7][7]=(jacob[0][0]*jacob[2][2]-jacob[2][0]*jacob[0][2])/detj;
modifiedinversejacob_F[1][2]=modifiedinversejacob_F[4][5]=modifiedinversejacob_F[7][8]=(jacob[0][1]*jacob[2][0]-jacob[2][1]*jacob[0][0])/detj;


modifiedinversejacob_F[2][0]=modifiedinversejacob_F[5][3]=modifiedinversejacob_F[8][6]=(jacob[0][1]*jacob[1][2]-jacob[1][1]*jacob[0][2])/detj;
modifiedinversejacob_F[2][1]=modifiedinversejacob_F[5][4]=modifiedinversejacob_F[8][7]=(jacob[0][2]*jacob[1][0]-jacob[1][2]*jacob[0][0])/detj;
modifiedinversejacob_F[2][2]=modifiedinversejacob_F[5][5]=modifiedinversejacob_F[8][8]=(jacob[0][0]*jacob[1][1]-jacob[1][0]*jacob[0][1])/detj;



for(int i=0;i<9;i++)
for(int k=0;k<24;k++)
for(int j=0;j<9;j++)
Finterpolator[i][k]=Finterpolator[i][k]+modifiedinversejacob_F[i][j]*shapederivative[j][k];





for(int i=0;i<9;i++)
for(int k=0;k<24;k++)
Gradu[i]=Gradu[i]+Finterpolator[i][k]*_nodes[_elements[_currentelement].connid[k/3]].u_lamb[k%3];



for(int i=0;i<9;i++)
{
F[i]=Gradu[i];
if(i==0 || i==4 || i==8)
F[i]=F[i]+1.0;  
}

for(int i=0;i<3;i++)
for(int j=0;j<3;j++)
GraduT_tensor[j][i]=F[i*3+j];


for(int i=0;i<6;i++)
for(int k=0;k<24;k++)
for(int j=0;j<9;j++)
BLin[i][k]=BLin[i][k]+modifiedinversejacob_B[i][j]*shapederivative[j][k];






for(int i=0;i<6;i++)
for(int k=0;k<24;k++)
for(int j=0;j<24;j++)
BNLin[i][k]=BNLin[i][k]+BLin[i][j]*GraduT_tensor[j%3][k%3]*cronecker(k/3,j/3);



//instead of deformation gradient, the zero deformation gradient is taken here 


//for(int i=0;i<6;i++)
//for(int k=0;k<24;k++)
//B[i][k+k/3]=BNLin[i][k];

for(int i=0;i<6;i++)
for(int k=0;k<24;k++)
B[i][k]=BNLin[i][k];


};



