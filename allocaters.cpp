void surface_allocater(Node _nodes[], Element _elements[], ifstream &surface_input_read, ifstream &surface_input_count, int &_numberofnodes, int &_numberofelements, ofstream &_debugfile)
{




char current_line[256];
int numberoffacets=0;



surface_input_count.getline(current_line,256);
int condition=0;
while(condition==0)
{
surface_input_count.getline(current_line,256);
if(current_line[1]=='S' && current_line[2]=='U' && current_line[3]=='R' && current_line[4]=='F' && current_line[5]=='A')
condition=1; 
}


surface_input_count.getline(current_line,256);

while(current_line[0]!='*')
{
surface_input_count.getline(current_line,256);
numberoffacets++;
}



surface_input_read.getline(current_line,256);
condition=0;
while(condition==0)
{
surface_input_read.getline(current_line,256);
if(current_line[1]=='S' && current_line[2]=='U' && current_line[3]=='R' && current_line[4]=='F' && current_line[5]=='A')
condition=1; 
}

for(int l=0;l<numberoffacets;l++)
{
char comma;
string surface_orient; 
int current_element_label;
int current_element_id;
int current_nodes[4];
surface_input_read>>current_element_label;
surface_input_read>>comma;
surface_input_read>>surface_orient;
char lastChar=surface_orient.at(surface_orient.length()-1);
int found=0;
int element_counter=0;
while(found==0)
{
if(_elements[element_counter].elementlabel==current_element_label)
{
found=1;
current_element_id=element_counter;
}
else
element_counter++;
};

double v_one[3];
double v_two[3];
double current_normal[3];
double size_current_nodenormal=0.0;

if(lastChar=='2')
{
for(int i=0;i<3;i++)
{
v_one[i]=_nodes[_elements[current_element_id].connid[5]].X_lamb[i]-_nodes[_elements[current_element_id].connid[4]].X_lamb[i];
v_two[i]=_nodes[_elements[current_element_id].connid[7]].X_lamb[i]-_nodes[_elements[current_element_id].connid[4]].X_lamb[i];
}
cross_product(v_one,v_two,current_normal);
for(int j=0;j<3;j++)
size_current_nodenormal=size_current_nodenormal+current_normal[j]*current_normal[j];
for(int j=0;j<3;j++)
current_normal[j]=current_normal[j]/sqrt(size_current_nodenormal);
_nodes[_elements[current_element_id].connid[4]].contacthomeelement_id=current_element_id;
_nodes[_elements[current_element_id].connid[5]].contacthomeelement_id=current_element_id;
_nodes[_elements[current_element_id].connid[6]].contacthomeelement_id=current_element_id;
_nodes[_elements[current_element_id].connid[7]].contacthomeelement_id=current_element_id;
_nodes[_elements[current_element_id].connid[4]].contacthomeelement_connection=4;
_nodes[_elements[current_element_id].connid[5]].contacthomeelement_connection=5;
_nodes[_elements[current_element_id].connid[6]].contacthomeelement_connection=6;
_nodes[_elements[current_element_id].connid[7]].contacthomeelement_connection=7;
normal_clusterer(_nodes[_elements[current_element_id].connid[4]], current_normal);
normal_clusterer(_nodes[_elements[current_element_id].connid[5]], current_normal);
normal_clusterer(_nodes[_elements[current_element_id].connid[6]], current_normal);
normal_clusterer(_nodes[_elements[current_element_id].connid[7]], current_normal);
//_debugfile<<_elements[current_element_id].connid[4]<<endl;
}

if(lastChar=='1')
{
for(int i=0;i<3;i++)
{
v_one[i]=_nodes[_elements[current_element_id].connid[1]].X_lamb[i]-_nodes[_elements[current_element_id].connid[0]].X_lamb[i];
v_two[i]=_nodes[_elements[current_element_id].connid[3]].X_lamb[i]-_nodes[_elements[current_element_id].connid[0]].X_lamb[i];
}
cross_product(v_one,v_two,current_normal);
for(int j=0;j<3;j++)
size_current_nodenormal=size_current_nodenormal+current_normal[j]*current_normal[j];
for(int j=0;j<3;j++)
current_normal[j]=current_normal[j]/sqrt(size_current_nodenormal);
_nodes[_elements[current_element_id].connid[0]].contacthomeelement_id=current_element_id;
_nodes[_elements[current_element_id].connid[1]].contacthomeelement_id=current_element_id;
_nodes[_elements[current_element_id].connid[2]].contacthomeelement_id=current_element_id;
_nodes[_elements[current_element_id].connid[3]].contacthomeelement_id=current_element_id;
_nodes[_elements[current_element_id].connid[0]].contacthomeelement_connection=0;
_nodes[_elements[current_element_id].connid[1]].contacthomeelement_connection=1;
_nodes[_elements[current_element_id].connid[2]].contacthomeelement_connection=2;
_nodes[_elements[current_element_id].connid[3]].contacthomeelement_connection=3;
normal_clusterer(_nodes[_elements[current_element_id].connid[0]], current_normal);
normal_clusterer(_nodes[_elements[current_element_id].connid[1]], current_normal);
normal_clusterer(_nodes[_elements[current_element_id].connid[2]], current_normal);
normal_clusterer(_nodes[_elements[current_element_id].connid[3]], current_normal);
}


}


for(int n=0;n<_numberofnodes;n++)
if(_nodes[n].nodeNormals_x.size()!=0)//indicating that this is a contact node 
current_normal_allocater(_nodes[n]);



};







void section_allocater(Element _elements[], ifstream &solid_section_input_read, ifstream &solid_section_input_count, int &_numberofelements)
{




char current_line[256];
double* layer_angles;
double* layer_thickness;
int numberoflayers=0;



solid_section_input_count.getline(current_line,256);
int condition=0;
while(condition==0)
{
solid_section_input_count.getline(current_line,256);
if(current_line[1]=='S' && current_line[2]=='O' && current_line[3]=='L' && current_line[4]=='I' && current_line[5]=='D')
condition=1; 
}


solid_section_input_count.getline(current_line,256);

while(current_line[0]!='*')
{
solid_section_input_count.getline(current_line,256);
numberoflayers++;
}

//cout<<"number of layers: "<<numberoflayers<<endl;

layer_angles=new double[numberoflayers];
layer_thickness=new double[numberoflayers];


solid_section_input_read.getline(current_line,256);
condition=0;
while(condition==0)
{
solid_section_input_read.getline(current_line,256);
if(current_line[1]=='S' && current_line[2]=='O' && current_line[3]=='L' && current_line[4]=='I' && current_line[5]=='D')
condition=1; 
}
//solid_section_input_read.getline(current_line,256);

for(int l=0;l<numberoflayers;l++)
{
char comma;
string material_name; 
double dummy;
solid_section_input_read>>layer_thickness[l];
solid_section_input_read>>comma;
solid_section_input_read>>dummy;
solid_section_input_read>>comma;
solid_section_input_read>>material_name;
solid_section_input_read>>layer_angles[l];
//cout<<layer_thickness[l]<<endl;
//cout<<layer_angles[l]<<endl;
}



for(int e=0;e<_numberofelements;e++)
{
_elements[e].lay_thick=new double[numberoflayers];
_elements[e].lay_ang=new double[numberoflayers];
for(int l=0;l<numberoflayers;l++)
{
_elements[e].lay_thick[l]=layer_thickness[l];
_elements[e].lay_ang[l]=layer_angles[l]*3.14159/180.0;
}
_elements[e].numberoflayers=numberoflayers;
}

double* ns;
double** v_fluid;
double** v_fs;

for(int e=0;e<_numberofelements;e++)
{
_elements[e].ns=new double[4*_elements[e].numberoflayers];
_elements[e].v_fluid=new double*[4*_elements[e].numberoflayers];
_elements[e].v_fs=new double*[4*_elements[e].numberoflayers];
for(int i=0;i<4*_elements[e].numberoflayers;i++)
{
_elements[e].v_fluid[i]=new double[3];
_elements[e].v_fs[i]=new double[3];
}
}

}






void node_allocater(Node _nodes[], ifstream &_nodes_infile, int &_numberofnodes)
{

//Start allocating 
for(int n=0;n<_numberofnodes;n++)
{
_nodes[n].X_lamb=new double[4];
_nodes[n].u_lamb=new double[4];
_nodes[n].du_lamb=new double[4];
_nodes[n].natural_bc=new int[4];
_nodes[n].natural_val=new double[4];
_nodes[n].nonzero_natural_bc=new int[4];
_nodes[n].neumann_bc=new int[4];
_nodes[n].neumann_val=new double[4];
}
//End Allocating 


char current_line[256];
_nodes_infile.getline(current_line,256);
int condition=0;
while(condition==0)
{
_nodes_infile.getline(current_line,256);
if(current_line[1]=='N' && current_line[2]=='O' && current_line[3]=='D' && current_line[4]=='E')
condition=1; 
}

for(int n=0;n<_numberofnodes;n++)
{
char comma;
_nodes_infile>>_nodes[n].nodelabel; 
_nodes_infile>>comma;
for(int i=0;i<2;i++)
{
_nodes_infile>>_nodes[n].X_lamb[i]; 
_nodes_infile>>comma;
}
_nodes_infile>>_nodes[n].X_lamb[2];
_nodes[n].X_lamb[3]=0.0; 
for(int i=0;i<4;i++)
{
_nodes[n].u_lamb[i]=0.0;
_nodes[n].du_lamb[i]=0.0;
_nodes[n].natural_bc[i]=0;
_nodes[n].natural_val[i]=0.0;
_nodes[n].nonzero_natural_bc[i]=0;
_nodes[n].neumann_bc[i]=0;
_nodes[n].neumann_val[i]=0.0;
}
_nodes[n].nS=0.8; //solid volume fraction in the reference coordinate system 
_nodes[n].ns=0.0; // '' in the current coordinate system 
_nodes[n].inpermeability=0.08;
_nodes[n].layup=0.0;
_nodes[n].neighbour_nodes.push_back(n);
_nodes[n].activ_contactnode=0;
}

/*
for(int n=0;n<_numberofnodes;n++)
{
cout<<_nodes[n].nodelabel<<'\t';
cout<<_nodes[n].X[0]<<'\t';
cout<<_nodes[n].X[1]<<'\t';
cout<<_nodes[n].X[2]<<endl;
}
*/
}

void element_allocater(Node _nodes[], Element _elements[], ifstream &_elements_infile, int &_numberofnodes, int &_numberofelements)
{

//Start allocating 
for(int e=0;e<_numberofelements;e++)
{
_elements[e].conname=new int[8];
_elements[e].connid=new int[8];
_elements[e].elementnodes=new Node[8];
}
//End Allocating 


char current_line[256];
_elements_infile.getline(current_line,256);
int condition=0;
while(condition==0)
{
_elements_infile.getline(current_line,256);
//cout<<current_line<<endl;
if(current_line[1]=='E' && current_line[2]=='L' && current_line[3]=='E' && current_line[4]=='M' 
&& current_line[5]=='E' && current_line[6]=='N' && current_line[7]=='T')
condition=1; 
}

for(int e=0;e<_numberofelements;e++)
{
char comma;
_elements_infile>>_elements[e].elementlabel; 
_elements_infile>>comma;
for(int i=0;i<7;i++)
{
_elements_infile>>_elements[e].conname[i]; 
_elements_infile>>comma;
}
_elements_infile>>_elements[e].conname[7]; 

//assignment of the connectivity id 
for(int n=0;n<_numberofnodes;n++)
for(int i=0;i<8;i++)
if(_nodes[n].nodelabel==_elements[e].conname[i])
_elements[e].connid[i]=n;

for(int i=0;i<6;i++)
_elements[e].preS[i]=0.0;

_elements[e].preS[0]=-10.0;
_elements[e].preS[1]=-10.0;
_elements[e].preS[2]=-10.0;

for(int i=0;i<8;i++)
for(int j=0;j<8;j++)
_nodes[_elements[e].connid[i]].Push_Neighbour_In(_elements[e].connid[j]);



}

/*
for(int e=0;e<_numberofelements;e++)
{
cout<<_elements[e].elementlabel<<'\t';
for(int i=0;i<7;i++)
cout<<_elements[e].conname[i]<<'\t';
cout<<_elements[e].conname[8]<<endl;
}
*/
}


void Node::Push_Neighbour_In(int _n)
{
int already_inside=0;
for(int i=0;i<neighbour_nodes.size();i++)
if(_n==neighbour_nodes[i])
already_inside=1;

if(already_inside==0)
neighbour_nodes.push_back(_n);


};



void K_allocater(Node _nodes[], csrM & _K, int** _Kloc,  int** _eft, int _numberofnodes, int _numberofelements)
{
//Allocation through nodes into csr 
/*
for(int n=0;n<_numberofnodes;n++)
for(int s=0;s<_nodes[n].neighbour_nodes.size();s++)
for(int i=0;i<4;i++)
for(int j=0;j<4;j++)
{
_K.Push_Value_incsrM(0.0,n*4+i,_nodes[n].neighbour_nodes[s]*4+j);
double percent_finished=(double(n)+1)*100.0/double(_numberofnodes);
cout<<"%"<<percent_finished<<" compressed sparse row stiffness is allocated              "<<'\r';
}
*/

//Allocation through elements into csr 
/*
for(int e=0;e<_numberofelements;e++)
for(int m=0;m<32;m++)
for(int n=0;n<32;n++)
{
_K.Push_Value_incsrM(0.0,_eft[m][e],_eft[n][e]);
double percent_finished=(double(e)+1)*100.0/double(_numberofelements);
cout<<"%"<<percent_finished<<" compressed sparse row stiffness is allocated"<<'\r'; 
}
*/



for(int e=0;e<_numberofelements;e++)

for(int m=0;m<32;m++)
for(int n=0;n<32;n++)
_Kloc[_eft[m][e]][_eft[n][e]]=1; 

int counter=0;
for(int i=0;i<4*_numberofnodes;i++)
{
int newrow=1;
for(int j=0;j<4*_numberofnodes;j++)
if(_Kloc[i][j]==1)
{
_K.vM.push_back(0.0);
_K.jM.push_back(j);
if(newrow==1)
_K.iM.push_back(counter);
counter++;
newrow=0;
}
double percent_finished=(double(i)+1)*100.0/double(_numberofnodes*4);
cout<<"%"<<percent_finished<<" compressed sparse row stiffness is allocated"<<'\r'; 
}


_K.iM.push_back(_K.vM.size());
cout<<_K.vM.size()<<endl;

};