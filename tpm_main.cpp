#include "headers.h"
#include <odb_API.h>
#include <vector>
#include <ctime>
//Mkl libraries
#include "mkl.h" 
#include "mkl_lapack.h" 
#include "mkl_blas.h" 
#include "mkl_service.h"
#include "mkl_spblas.h"
#include "mkl_pardiso.h"
#include "mkl_dss.h"

using namespace std;

int ABQmain(int argc,char *argv[])
{


//values to be changed as input 
double numberofloadsteps=20.0;
double ltwocurrentfi=10000.0;
double ltwoinitialfi=10000.0;

ifstream nodes_infile(argv[1]);
ifstream nodes_infile_alloc(argv[1]);
int numberofnodes;
Node *nodes; 

ifstream elements_infile(argv[1]);
ifstream elements_infile_alloc(argv[1]);
int numberofelements;
Element* elements;

ifstream solid_section_input_count(argv[1]);
ifstream solid_section_input_read(argv[1]);

ifstream surface_input_read(argv[1]);
ifstream surface_input_count(argv[1]);



//files of boundary conditions 
ifstream natural_bc("natural_bc.inp");
ifstream neumann_bc("neumann_bc.inp");
ifstream inpermeability_bc("inpermeability_bc.inp");
//debugfile 
ofstream debugfile("debugfile.deb");


//Global declerations, thought initially as dense matrices 
int **eft;
int** Kloc;
double* force;
double* force_constant;
double* df;
double* incremental_force;
double *u;
double* du;
double* du_prev;
double *fi;

//counting 
node_counter(nodes_infile,numberofnodes);
element_counter(elements_infile,numberofelements);


//allocation and initialization of the parameters 
nodes=new Node[numberofnodes];
elements=new Element[numberofelements];
cout<<"Allocating Nodes..."<<endl;
node_allocater(nodes,nodes_infile_alloc,numberofnodes);
cout<<"Allocating Elements..."<<endl;
element_allocater(nodes, elements, elements_infile_alloc, numberofnodes, numberofelements);
cout<<"Allocating Solid Sections..."<<endl;
section_allocater(elements, solid_section_input_read, solid_section_input_count, numberofelements);
cout<<"Allocating Surfaces..."<<endl;
surface_allocater(nodes,elements,surface_input_read,surface_input_count,numberofnodes,numberofelements,debugfile);

//allocation of the global vectors 
Kloc=new int*[4*numberofnodes];
eft=new int*[32];
force=new double[4*numberofnodes];
df=new double[4*numberofnodes];
u=new double[4*numberofnodes];
du=new double[4*numberofnodes];
du_prev=new double[4*numberofnodes];
fi=new double[4*numberofnodes];
incremental_force=new double[4*numberofnodes];
for(int i=0;i<32;i++)
eft[i]=new int[numberofelements];

for(int i=0;i<4*numberofnodes;i++)
{

Kloc[i]=new int[4*numberofnodes];
for(int j=0;j<4*numberofnodes;j++)
Kloc[i][j]=0;
force[i]=0.0;
df[i]=0.0;
incremental_force[i]=0.0;
du_prev[i]=0.0;
u[i]=0.0;
du[i]=0.0;
fi[i]=0.0;
}


cout<<"Start: Applying natural boundary conditions..."<<endl;
apply_natural_bc(nodes,natural_bc,numberofnodes,u,debugfile);
cout<<"End: Applying natural boundary conditions..."<<endl;
cout<<"Start: Applying neumann boundary conditions..."<<endl;
apply_neumann_bc(force,nodes,neumann_bc,numberofnodes);
cout<<"End: Applying neumann boundary conditions..."<<endl;
//cout<<"Applying imperbeability boundary conditions (not necessary)..."<<endl;
//apply_inpermeability_bc(nodes, inpermeability_bc, numberofnodes);
//set_layup_integration(nodes, elements, numberofnodes, numberofelements);
cout<<"Start: Constructing element freedom table..."<<endl;
eftable(elements,eft,debugfile,numberofelements);
cout<<"End: Constructing element freedom table..."<<endl;



// reading teh master surface:
ifstream master_nodes_infile("torus_master.inp");
ifstream master_nodes_infile_alloc("torus_master.inp");
ifstream master_elements_infile("torus_master.inp");
ifstream master_elements_infile_alloc("torus_master.inp");
int numberofmasternodes;
master_Node* masternodes;
int numberofmasterelements;
master_Element* masterelements;

node_counter(master_nodes_infile,numberofmasternodes);
element_counter(master_elements_infile,numberofmasterelements);


masternodes=new master_Node[numberofmasternodes];
masterelements=new master_Element[numberofmasterelements];

cout<<"Allocating Master Nodes..."<<endl;
master_node_allocater(masternodes,master_nodes_infile_alloc,numberofmasternodes, debugfile);
cout<<"Allocating Master Elements..."<<endl;
master_element_allocater(masternodes, masterelements, master_elements_infile_alloc, numberofmasternodes, numberofmasterelements, debugfile);









// Generating the odb 
/*
std::string odb_name;
odb_name.assign(argv[1]);

odb_name.erase(odb_name.end()-4,odb_name.end());
odb_name.push_back('_');
odb_name.push_back('r');
odb_name.push_back('e');
odb_name.push_back('s');
odb_name.push_back('.');
odb_name.push_back('o');
odb_name.push_back('d');
odb_name.push_back('b');


char* odb_name_inchar=new char[odb_name.length()];

    odb_String name("shellModel");
    odb_String analysisTitle("ODB created with C++ ODB API");
    odb_String description("example illustrating C++ ODB API");
    for(int i=0;i<odb_name.length();i++)
    odb_name_inchar[i]=odb_name[i];

    odb_String path(odb_name_inchar);
    
    odb_Odb &myodb = Odb(name,
                       analysisTitle,
                       description,
                       path);
*/


std::string odb_name_solid;
odb_name_solid.assign(argv[1]);

odb_name_solid.erase(odb_name_solid.end()-4,odb_name_solid.end());
odb_name_solid.push_back('_');
odb_name_solid.push_back('s');
odb_name_solid.push_back('o');
odb_name_solid.push_back('l');
odb_name_solid.push_back('.');
odb_name_solid.push_back('o');
odb_name_solid.push_back('d');
odb_name_solid.push_back('b');


char* odb_name_inchar_solid=new char[odb_name_solid.length()];

    odb_String name_solid("solidModel");
    odb_String analysisTitle_solid("ODB created with C++ ODB API");
    odb_String description_solid("example illustrating C++ ODB API");
    for(int i=0;i<odb_name_solid.length();i++)
    odb_name_inchar_solid[i]=odb_name_solid[i];

    odb_String path_solid(odb_name_inchar_solid);
    
    odb_Odb &myodb_solid = Odb(name_solid,
                       analysisTitle_solid,
                       description_solid,
                       path_solid);





vector < layup_Node > layup_Nodes; 
vector < layup_Element > layup_Elements;




cout<<"Start: Writing the Model Data"<<endl;
//odb_model_writer(nodes,elements,layup_Nodes,layup_Elements,numberofnodes,numberofelements,argv,myodb);
odb_model_writer_solid(nodes, elements,numberofnodes,numberofelements,argv,myodb_solid);
cout<<"End: Writing the Model Data"<<endl;



//cout<<layup_Nodes.size()<<endl;
//cout<<layup_Elements.size()<<endl;





unsigned begin;
unsigned end;
double elapsed_secs;



cout<<'\t'<<"Start: Allocation Global Stifness Matrix..."<<endl;
begin=clock();
csrM K; 
//K.CreateOfHollow(4*numberofnodes);
K_allocater(nodes,K,Kloc,eft,numberofnodes,numberofelements);
end=clock();
cout<<'\t'<<"End Allocation time of Global Stiffness Matrix:"<<(end-begin)<<endl;


for(double l=0;l<numberofloadsteps;l++)
{

double sometime=l+1; //steady state inposition 

//double sometime=0.0;
int numberofinneriterations=0;
ltwocurrentfi=100000.0;
ltwoinitialfi=100000.0;
double errormeasure;
initialize(nodes,numberofloadsteps,debugfile,numberofnodes,du,u,incremental_force,force,sometime);

cout<<'\t'<<"frame "<<l<<endl;
debugfile<<'\t'<<"frame "<<l<<endl;

int domore=1;

//contact displacement update has to be here 
//if(sometime>1.0)
//contact_disp_update(nodes,elements,numberofnodes,numberofelements,K,fi,debugfile,sometime,numberofloadsteps);
int noclearence=1;
cout<<'\t'<<'\t'<<"Start: Contact iterations"<<endl; 
//while(noclearence!=0)

master_nodes_update(masternodes, numberofmasternodes, l, numberofloadsteps);
for(int c=0;c<5;c++)
{
noclearence=0;
contact_disp_update(nodes,elements,numberofnodes,numberofelements,K,fi,debugfile,sometime,numberofloadsteps,noclearence,
                    masternodes,masterelements,numberofmasternodes,numberofmasterelements,c);
cout<<'\t'<<'\t'<<"contact iteration # overclosure nodes:"<<noclearence<<endl; 
}
cout<<'\t'<<'\t'<<"End: Contact iterations"<<endl; 
Nodes_disp_update(nodes,numberofnodes);




//incremental_force_initial(nodes,elements,fi,numberofloadsteps,sometime,debugfile,numberofnodes,numberofelements,incremental_force);
do
{

Nodes_disp_downdate(nodes,numberofnodes);

K_global(nodes,elements,numberofelements,debugfile,sometime);


//cout<<"Start Assembly..."<<endl;
//begin=clock();
csrK_assembly(elements,K,eft,numberofnodes,numberofelements);
//end=clock();
//cout<<"Assembly time:"<<(end-begin)<<endl;








Nodes_disp_update(nodes,numberofnodes);
//contact_enforcer(nodes,elements,numberofnodes,numberofelements,K,fi,debugfile,sometime,numberofloadsteps, noclearence);
cout<<'\t'<<"Start: Updating internal forces"<<endl;
update_fi(nodes,elements,fi,numberofloadsteps,sometime,debugfile,numberofnodes,numberofelements,incremental_force);
cout<<'\t'<<"End: Updating internal forces"<<endl;
//odb_result_writer_solid(nodes,elements,numberofnodes,numberofelements,argv,myodb_solid,l,numberofloadsteps);
//myodb_solid.save();
//myodb_solid.close();
//cout<<"close it"<<endl;



//cout<<"Start First reduction..."<<endl;
//begin=clock();
cout<<'\t'<<"Start: Reducing the global stiffness"<<endl;
csrKglobal_reducer(nodes,K,fi,debugfile,numberofnodes);
//end=clock();
//cout<<"First reduction time:"<<end-begin<<endl;



//if(numberofinneriterations==0 && l==0)
//csrfullincrementalforcevector(nodes,incremental_force,du,K,debugfile,numberofnodes,fi);



//if(numberofinneriterations==0.0)
//du_copy(du,du_prev,debugfile,numberofnodes);


//cout<<"Start second Reduction..."<<endl;
//begin=clock();
csrKglobal_ff_reducer(nodes,K,fi,debugfile,numberofnodes);
cout<<'\t'<<"End: Reducing the global stiffness"<<endl;
//end=clock();
//cout<<"Second reduction time:"<<end-begin<<endl;


cout<<'\t'<<"Start Solving..."<<endl;
begin=clock();

Pardiso_UnsymSolver(K,du,fi,4*numberofnodes,'Y');
end=clock();
cout<<'\t'<<"Solver time:"<<end-begin<<endl;

if(numberofinneriterations==0.0)
du_copy(du,du_prev,debugfile,numberofnodes);

Nodes_neumann_update(nodes, du, 4*numberofnodes); 

Nodes_disp_update(nodes,numberofnodes);


if(numberofinneriterations>0.0)
errormeasure=error_indu(du,du_prev,debugfile,numberofnodes);
else 
errormeasure=1.0;

debugfile<<'\t'<<"iteration"<<numberofinneriterations<<'\t'<<errormeasure<<endl; 
cout<<'\t'<<"iteration"<<numberofinneriterations<<'\t'<<errormeasure<<endl; 
if(errormeasure<0.01 && numberofinneriterations>=3.0)
domore=0;
if(errormeasure>0.01 && numberofinneriterations>=15.0)
domore=0;
numberofinneriterations++;
K.SetZero();
//set_fi_zero(fi,numberofnodes);
/*
if(l==6)
{
odb_result_writer_solid(nodes,elements,numberofnodes,numberofelements,argv,myodb_solid,l,numberofloadsteps);
myodb_solid.save();
myodb_solid.close();
}
*/
}
while(domore==1);

if(l==numberofloadsteps-1)
Nodes_disp_update(nodes,numberofnodes);


//odb_result_writer(nodes,elements,layup_Nodes,layup_Elements,numberofnodes,numberofelements,argv,myodb,l,numberofloadsteps);
odb_result_writer_solid(nodes,elements,numberofnodes,numberofelements,argv,myodb_solid,l,numberofloadsteps);


numberofinneriterations=0;
}


//result_writer(nodes,elements,numberofnodes,numberofelements);
//odb_result_writer(nodes,elements,numberofnodes,numberofelements,argv,myodb);

//myodb.save();
//myodb.close();
myodb_solid.save();
myodb_solid.close();

delete[] force;
delete[] df;
delete[] incremental_force;
delete[] u;
delete[] du;
delete[] du_prev;
delete[] fi;






//cout<<"The file name you have given: "<<argv[1]<<endl;
return 0;
};
