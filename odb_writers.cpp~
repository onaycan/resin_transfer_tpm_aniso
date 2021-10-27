void odb_model_writer(Node _nodes[], Element _elements[],vector < layup_Node > & layup_Nodes, vector < layup_Element > & layup_Elements,
                       int _numberofnodes, int _numberofelements,char *argv[],odb_Odb& odb)
{

int numberoflayers_perelement=4;
int numberofelementrows=4;
int numberofnodes_perrow=_numberofnodes/(numberofelementrows+1);

int numberofnodes_shells=numberoflayers_perelement*numberofelementrows*numberofnodes_perrow;
int numberofelements_shells=_numberofelements*numberoflayers_perelement;
int numberof_initial_nodes_shells=numberofelements_shells*4;


layup_Nodes.resize(numberof_initial_nodes_shells);
layup_Elements.resize(numberofelements_shells);


int layup_nodecounter=1;
int layup_elementcounter=1;

for(int e=0;e<_numberofelements;e++)
{
double layer_number=0.0;
for(int s=0;s<numberoflayers_perelement;s++)
{

double shell_nodes_coord[3];
int current_conn[4];

layer_number++;
shell_nodes_coord[0]=(_nodes[_elements[e].connid[4]].X_lamb[0]-_nodes[_elements[e].connid[0]].X_lamb[0])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[0]].X_lamb[0];
shell_nodes_coord[1]=(_nodes[_elements[e].connid[4]].X_lamb[1]-_nodes[_elements[e].connid[0]].X_lamb[1])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[0]].X_lamb[1];
shell_nodes_coord[2]=(_nodes[_elements[e].connid[4]].X_lamb[2]-_nodes[_elements[e].connid[0]].X_lamb[2])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[0]].X_lamb[2];
layup_Node_constructer(layup_Nodes[layup_nodecounter-1], layup_nodecounter, shell_nodes_coord);
current_conn[0]=layup_nodecounter;
layup_nodecounter++;



shell_nodes_coord[0]=(_nodes[_elements[e].connid[5]].X_lamb[0]-_nodes[_elements[e].connid[1]].X_lamb[0])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[1]].X_lamb[0];
shell_nodes_coord[1]=(_nodes[_elements[e].connid[5]].X_lamb[1]-_nodes[_elements[e].connid[1]].X_lamb[1])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[1]].X_lamb[1];
shell_nodes_coord[2]=(_nodes[_elements[e].connid[5]].X_lamb[2]-_nodes[_elements[e].connid[1]].X_lamb[2])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[1]].X_lamb[2];
layup_Node_constructer(layup_Nodes[layup_nodecounter-1], layup_nodecounter, shell_nodes_coord);
current_conn[1]=layup_nodecounter;
layup_nodecounter++;



shell_nodes_coord[0]=(_nodes[_elements[e].connid[6]].X_lamb[0]-_nodes[_elements[e].connid[2]].X_lamb[0])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[2]].X_lamb[0];
shell_nodes_coord[1]=(_nodes[_elements[e].connid[6]].X_lamb[1]-_nodes[_elements[e].connid[2]].X_lamb[1])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[2]].X_lamb[1];
shell_nodes_coord[2]=(_nodes[_elements[e].connid[6]].X_lamb[2]-_nodes[_elements[e].connid[2]].X_lamb[2])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[2]].X_lamb[2];
layup_Node_constructer(layup_Nodes[layup_nodecounter-1], layup_nodecounter, shell_nodes_coord);
current_conn[2]=layup_nodecounter;
layup_nodecounter++;


shell_nodes_coord[0]=(_nodes[_elements[e].connid[7]].X_lamb[0]-_nodes[_elements[e].connid[3]].X_lamb[0])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[3]].X_lamb[0];
shell_nodes_coord[1]=(_nodes[_elements[e].connid[7]].X_lamb[1]-_nodes[_elements[e].connid[3]].X_lamb[1])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[3]].X_lamb[1];
shell_nodes_coord[2]=(_nodes[_elements[e].connid[7]].X_lamb[2]-_nodes[_elements[e].connid[3]].X_lamb[2])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[3]].X_lamb[2];
layup_Node_constructer(layup_Nodes[layup_nodecounter-1], layup_nodecounter, shell_nodes_coord);
current_conn[3]=layup_nodecounter;
layup_nodecounter++;





layup_Element_constructer(layup_Elements[layup_elementcounter-1], layup_elementcounter, current_conn);

//main fiber direction assignment 
double stack[3];
double main_fiber[3];
double current_angle; 
current_angle=_elements[e].lay_ang[s];
main_fiber[0]=cos(current_angle);
main_fiber[1]=sin(current_angle);
main_fiber[2]=0;
stack[0]=0.0;
stack[1]=0.0;
stack[2]=0.0;

layup_Element_fiber_assigner(layup_Elements[layup_elementcounter-1],main_fiber);
layup_elementcounter++;

}




}









for(int n1=0;n1<layup_Nodes.size();n1++)
{
int corner_node=1;
for(int n2=0;n2<layup_Nodes.size();n2++)
{
double criteria=sqrt(
(layup_Nodes[n1].layupX[0]-layup_Nodes[n2].layupX[0])*(layup_Nodes[n1].layupX[0]-layup_Nodes[n2].layupX[0])+
(layup_Nodes[n1].layupX[1]-layup_Nodes[n2].layupX[1])*(layup_Nodes[n1].layupX[1]-layup_Nodes[n2].layupX[1])+
(layup_Nodes[n1].layupX[2]-layup_Nodes[n2].layupX[2])*(layup_Nodes[n1].layupX[2]-layup_Nodes[n2].layupX[2]));
if(criteria<0.001 && n1!=n2)
{
corner_node=0;
for(int e=0;e<layup_Elements.size();e++)
for(int c=0;c<4;c++)
if(layup_Elements[e].layup_conn[c]==layup_Nodes[n2].layup_nodelabel)
{
layup_Elements[e].layup_conn[c]=layup_Nodes[n1].layup_nodelabel;
layup_Elements[e].layup_connid[c]=n1;
}
layup_Nodes.erase(layup_Nodes.begin()+n2);
}
}
if(corner_node==1)
for(int e=0;e<layup_Elements.size();e++)
for(int c=0;c<4;c++)
if(layup_Elements[e].layup_conn[c]==layup_Nodes[n1].layup_nodelabel)
layup_Elements[e].layup_connid[c]=n1;


}







  odb_Part& part1 = odb.Part("part-1",
       odb_Enum::THREE_D, odb_Enum::DEFORMABLE_BODY);

//writing the model data: nodes
  odb_SequenceInt nodeLabels;

for(int n=0;n<layup_Nodes.size();n++)
{
nodeLabels.append(layup_Nodes[n].layup_nodelabel);
}

  odb_SequenceSequenceFloat nodeCoor;
  for (int n=0; n<nodeLabels.size(); n++) {    
    odb_SequenceFloat loc;
    for (int i=0; i<3; i++)
      loc.append(layup_Nodes[n].layupX[i]);
    nodeCoor.append(loc);
  }
  part1.addNodes(nodeLabels, nodeCoor, "Nodes");

//writing the model data: elements 
  odb_SequenceInt elLabels;

for(int e=0;e<numberofelements_shells;e++)
elLabels.append(layup_Elements[e].layup_elementlabel);

  odb_SequenceSequenceInt connect;
  const int numNodePerEl = 4;
  for (int e=0; e<elLabels.size(); e++) {
    odb_SequenceInt l;
    for (int i=0; i<numNodePerEl; i++)
      l.append(layup_Elements[e].layup_conn[i]);
    connect.append(l);
  }
	
    odb_String sectionCategoryName("S4");
    odb_String sectionCategoryDescription("layup_quads");
    odb_SectionCategory& sCat =
        odb.SectionCategory(sectionCategoryName,
                            sectionCategoryDescription);


  part1.addElements(elLabels, connect, "S4",
		    "Quads",sCat);

    odb_Assembly& rootAssy = odb.rootAssembly();
    odb_Instance& instance1 =
    odb.rootAssembly().Instance("part-1-1", part1);




  // An ElementSet on an instance  
  odb_SequenceInt eLabelsA;
for(int e=0;e<numberofelements_shells;e++)
eLabelsA.append(layup_Elements[e].layup_elementlabel);
odb_Set& elset=instance1.ElementSet("elSetA", eLabelsA);
 







//start materials
    odb_MaterialApi materialApi;
    odb.extendApi(odb_Enum::odb_MATERIAL,materialApi);
    odb_String materialName("Elastic Material");
    odb_Material& material_1 =
        materialApi.Material(materialName);
    odb_SequenceSequenceDouble myTable;
    odb_SequenceDouble myData;
    myData.append(12000.00);//youngs modulus
    myData.append(0.3);//poissons ratio
    myTable.append(myData);
    odb_String type("ISOTROPIC");
    bool noCompression = false;
    bool noTension = false;
    bool temperatureDependency = false;
    int dependencies = 0;
    odb_String moduli("LONG_TERM");
    material_1.Elastic(myTable,
                       type,
                       noCompression,
                       noTension,
                       temperatureDependency,
                       dependencies,
                       moduli);

 odb_SectionApi sectionApi;
    odb.extendApi(odb_Enum::odb_SECTION,
                  sectionApi);
    odb_String sectionName("Homogeneous Shell Section");
    double thickness = 2.0;
    odb_HomogeneousShellSection& section_1 =
        sectionApi.HomogeneousShellSection(sectionName,thickness,materialName);


instance1.assignSection(elset,section_1);
//instance1.assignMaterialOrientation(elset,somecoord,odb_Enum::odb_AxisEnum(),45.0,odb_Enum::odb_StackDirectionEnum());

  // A NodeSet on the rootAssembly

  odb_SequenceSequenceInt nodeLabelsRA;
  odb_SequenceString namesRA;
  namesRA.append("part-1-1");
  odb_SequenceInt nodeLabelsRA_A;
  for (int n=0; n<nodeLabels.size(); n++)
  nodeLabelsRA_A.append(layup_Nodes[n].layup_nodelabel);
  nodeLabelsRA.append(nodeLabelsRA_A);
  const odb_Set& nSetRA = rootAssy.NodeSet("nodeSetRA",
					   namesRA, nodeLabelsRA);  








    odb_String stepName("step-1");
    odb_String stepDescription("first analysis step");
    odb_Step& step1 = odb.Step(stepName,
                               stepDescription,
                               odb_Enum::TIME,
			       1.0);



result_writer_shell(layup_Nodes, layup_Elements,
                  layup_Nodes.size(), layup_Elements.size());


 };






void odb_result_writer(Node _nodes[], Element _elements[],vector < layup_Node > & layup_Nodes, vector < layup_Element > & layup_Elements,
                       int _numberofnodes, int _numberofelements,char *argv[],odb_Odb& odb, double l, double numberofloadsteps)

{





ofstream dummy_outfile("dummy_outfile.log");
int numberoflayers_perelement=4;
int numberofelementrows=4;
int numberofnodes_perrow=_numberofnodes/(numberofelementrows+1);

int numberofnodes_shells=numberoflayers_perelement*numberofelementrows*numberofnodes_perrow;
int numberofelements_shells=_numberofelements*numberoflayers_perelement;
int numberof_initial_nodes_shells=numberofelements_shells*4;


// start of nodal velocity staff
double N[4];
double N_mat[12][12];
double N_mat_prev[12][12];
for(int i=0;i<12;i++)
for(int j=0;j<12;j++)
N_mat[i][j]=0.0;
int integ_counter=0;
for(double g2=-1.0;g2<2.0;g2=g2+2.0)
for(double g1=-1.0;g1<2.0;g1=g1+2.0)
{

double ksi=g1/sqrt(3.0);
double eta=g2/sqrt(3.0);

int shape_counter=0;
for(double sign_eta=-1.0;sign_eta<2.0;sign_eta=sign_eta+2.0)
for(double sign_ksi=-1.0;sign_ksi<2.0;sign_ksi=sign_ksi+2.0)
{
N[shape_counter]=0.25*(1+sign_ksi*ksi)*(1+sign_eta*eta);
shape_counter++;
}


for(int j=0;j<4;j++)
{
N_mat[integ_counter*3+0][j*3]=N[j];
N_mat[integ_counter*3+1][j*3+1]=N[j];
N_mat[integ_counter*3+2][j*3+2]=N[j];
}
integ_counter++;
}



for(int i=0;i<12;i++)
{
for(int j=0;j<12;j++)
{
N_mat_prev[i][j]=N_mat[i][j];
//dummy_outfile<<N_mat_prev[i][j]<<'\t';
}
//dummy_outfile<<endl;
}


//end of nodal velocity staff






int layup_elementcounter=1;

for(int e=0;e<_numberofelements;e++)
{
double layer_number=0.0;
for(int s=0;s<numberoflayers_perelement;s++)
{

double currentu[3];
double current_lambda;
double current_fluid_fraction[4];
double current_fluid_velocity[12];
double current_nodal_fluid_velocity[12];
int current_connid[4];

for(int i=0;i<4;i++)
current_connid[i]=layup_Elements[layup_elementcounter-1].layup_connid[i];


layer_number++;
currentu[0]=(_nodes[_elements[e].connid[4]].u_lamb[0]-_nodes[_elements[e].connid[0]].u_lamb[0])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[0]].u_lamb[0];
currentu[1]=(_nodes[_elements[e].connid[4]].u_lamb[1]-_nodes[_elements[e].connid[0]].u_lamb[1])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[0]].u_lamb[1];
currentu[2]=(_nodes[_elements[e].connid[4]].u_lamb[2]-_nodes[_elements[e].connid[0]].u_lamb[2])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[0]].u_lamb[2];
current_lambda=(_nodes[_elements[e].connid[4]].u_lamb[3]-_nodes[_elements[e].connid[0]].u_lamb[3])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[0]].u_lamb[3];
layup_Node_dof_assigner(layup_Nodes[current_connid[0]],currentu,current_lambda);




currentu[0]=(_nodes[_elements[e].connid[5]].u_lamb[0]-_nodes[_elements[e].connid[1]].u_lamb[0])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[1]].u_lamb[0];
currentu[1]=(_nodes[_elements[e].connid[5]].u_lamb[1]-_nodes[_elements[e].connid[1]].u_lamb[1])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[1]].u_lamb[1];
currentu[2]=(_nodes[_elements[e].connid[5]].u_lamb[2]-_nodes[_elements[e].connid[1]].u_lamb[2])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[1]].u_lamb[2];
current_lambda=(_nodes[_elements[e].connid[5]].u_lamb[3]-_nodes[_elements[e].connid[1]].u_lamb[3])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[1]].u_lamb[3];
layup_Node_dof_assigner(layup_Nodes[current_connid[1]],currentu,current_lambda);




currentu[0]=(_nodes[_elements[e].connid[6]].u_lamb[0]-_nodes[_elements[e].connid[2]].u_lamb[0])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[2]].u_lamb[0];
currentu[1]=(_nodes[_elements[e].connid[6]].u_lamb[1]-_nodes[_elements[e].connid[2]].u_lamb[1])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[2]].u_lamb[1];
currentu[2]=(_nodes[_elements[e].connid[6]].u_lamb[2]-_nodes[_elements[e].connid[2]].u_lamb[2])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[2]].u_lamb[2];
current_lambda=(_nodes[_elements[e].connid[6]].u_lamb[3]-_nodes[_elements[e].connid[2]].u_lamb[3])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[2]].u_lamb[3];
layup_Node_dof_assigner(layup_Nodes[current_connid[2]],currentu,current_lambda);


currentu[0]=(_nodes[_elements[e].connid[7]].u_lamb[0]-_nodes[_elements[e].connid[3]].u_lamb[0])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[3]].u_lamb[0];
currentu[1]=(_nodes[_elements[e].connid[7]].u_lamb[1]-_nodes[_elements[e].connid[3]].u_lamb[1])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[3]].u_lamb[1];
currentu[2]=(_nodes[_elements[e].connid[7]].u_lamb[2]-_nodes[_elements[e].connid[3]].u_lamb[2])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[3]].u_lamb[2];
current_lambda=(_nodes[_elements[e].connid[7]].u_lamb[3]-_nodes[_elements[e].connid[3]].u_lamb[3])/numberoflayers_perelement*(layer_number-0.5)+_nodes[_elements[e].connid[3]].u_lamb[3];
layup_Node_dof_assigner(layup_Nodes[current_connid[3]],currentu,current_lambda);



for(int i=0;i<4;i++)
for(int j=0;j<3;j++)
current_fluid_velocity[i*3+j]=_elements[e].v_fluid[s*4+i][j];

for(int i=0;i<4;i++)
current_fluid_fraction[i]=1.0-_elements[e].ns[s*4+i];


layup_Element_dof_assigner(layup_Elements[layup_elementcounter-1], current_fluid_velocity, current_fluid_fraction);


layup_elementcounter++;

}




}





odb_Assembly& rootAssy = odb.rootAssembly();

odb_Instance& instance1 = 
        rootAssy.instances()["part-1-1"];

    odb_Step& step1 = odb.steps()["step-1"];

    int incrementNumber = l+1;
    float analysisTime = (l+1)/numberofloadsteps;

    odb_String frameDescription("results frame for time");
    frameDescription.append(analysisTime);
    odb_Frame frame1 = step1.Frame(incrementNumber,
                                   analysisTime,
                                   frameDescription);


  odb_SequenceInt nodeLabels;
	for(int n=0;n<layup_Nodes.size();n++)
  	nodeLabels.append(layup_Nodes[n].layup_nodelabel);
  

  odb_SequenceInt eLabelsA;
	for(int e=0;e<layup_Elements.size();e++)
	eLabelsA.append(layup_Elements[e].layup_elementlabel);


// Field data:
    // Create a step and a frame.


    // Write nodal displacements.
    odb_String fieldName("U");
    odb_String fieldDescription("Displacements");
    odb_FieldOutput& uField =
        frame1.FieldOutput(fieldName,
                           fieldDescription,
			   odb_Enum::VECTOR);

    odb_SequenceSequenceFloat dispData;

    // create some displacement values
  for (int n=0; n<layup_Nodes.size(); n++)
{
       odb_SequenceFloat current_dispData;
	current_dispData.append(layup_Nodes[n].layupu[0]);
	current_dispData.append(layup_Nodes[n].layupu[1]);
	current_dispData.append(layup_Nodes[n].layupu[2]);

	

	dispData.append(current_dispData);
}   
    uField.addData(odb_Enum::NODAL,
                   instance1,
                   nodeLabels,
                   dispData);

    // Make this the default deformed field for visualization.

    step1.setDefaultDeformedField(uField);






    // Write nodal pore pressure 
    odb_String porepres("Pore-Pressure");
    odb_String porepresDescription("Porepressure");
    odb_FieldOutput& porepresField =
        frame1.FieldOutput(porepres,
                           porepresDescription,
			   odb_Enum::SCALAR);

    odb_SequenceSequenceFloat porepresData;

    // create some displacement values
  for (int n=0; n<layup_Nodes.size(); n++)
{
        odb_SequenceFloat current_porepresData;
	current_porepresData.append(layup_Nodes[n].layup_lambda);
	porepresData.append(current_porepresData);
}   
    porepresField.addData(odb_Enum::NODAL,
                         instance1,
                         nodeLabels,
                         porepresData);


//write fiber directions 
   odb_String fiberdirection("Fiberdirection");
   odb_String fdDescription("Fiberdirection");
    odb_FieldOutput& fdField =
        frame1.FieldOutput(fiberdirection,
                           fdDescription,
			   odb_Enum::VECTOR);

    odb_SequenceSequenceFloat fdData;

    // create some displacement values
  for (int e=0; e<layup_Elements.size(); e++)
	for(int i=0;i<4;i++)
{
        odb_SequenceFloat current_fdData;
	current_fdData.append(layup_Elements[e].layup_fiber[0]);
	current_fdData.append(layup_Elements[e].layup_fiber[1]);
	current_fdData.append(layup_Elements[e].layup_fiber[2]);	
        fdData.append(current_fdData);
}   
    fdField.addData(odb_Enum::INTEGRATION_POINT,
                    instance1,
                    eLabelsA,
                    fdData);




//write integration fluid fraction
   odb_String fluidfraction("Fluid-Fraction");
   odb_String ffDescription("Fluidfraction");
    odb_FieldOutput& ffField =
        frame1.FieldOutput(fluidfraction,
                           ffDescription,
			   odb_Enum::SCALAR);

    odb_SequenceSequenceFloat ffData;

    // create some displacement values
  for (int e=0; e<layup_Elements.size(); e++)
	for(int i=0;i<4;i++)
{
        odb_SequenceFloat current_ffData;
	current_ffData.append(layup_Elements[e].layup_nf[i]);
	ffData.append(current_ffData);
}   
    ffField.addData(odb_Enum::INTEGRATION_POINT,
                         instance1,
                         eLabelsA,
                         ffData);


//write integration fluid velocity
   odb_String fluidvelocity("velocity");
   odb_String fvDescription("velocity");
    odb_FieldOutput& fvField =
        frame1.FieldOutput(fluidvelocity,
                           fvDescription,
			   odb_Enum::VECTOR);

    odb_SequenceSequenceFloat fvData;

    // create some displacement values
  for (int e=0; e<layup_Elements.size(); e++)
	for(int i=0;i<4;i++)
{
        odb_SequenceFloat current_fvData;
	current_fvData.append(layup_Elements[e].layup_fv[i*3+0]);
	current_fvData.append(layup_Elements[e].layup_fv[i*3+1]);
	current_fvData.append(layup_Elements[e].layup_fv[i*3+2]);	
        fvData.append(current_fvData);
}   
    fvField.addData(odb_Enum::INTEGRATION_POINT,
                    instance1,
                    eLabelsA,
                    fvData);




};









void odb_model_writer_solid(Node _nodes[], Element _elements[],
                       int _numberofnodes, int _numberofelements,char *argv[],odb_Odb& odb)
{







  odb_Part& part1 = odb.Part("part-1",
       odb_Enum::THREE_D, odb_Enum::DEFORMABLE_BODY);

//writing the model data: nodes
  odb_SequenceInt nodeLabels;

for(int n=0;n<_numberofnodes;n++)
{
nodeLabels.append(_nodes[n].nodelabel);
}

  odb_SequenceSequenceFloat nodeCoor;
  for (int n=0; n<nodeLabels.size(); n++) {    
    odb_SequenceFloat loc;
    for (int i=0; i<3; i++)
      loc.append(_nodes[n].X_lamb[i]);
    nodeCoor.append(loc);
  }
  part1.addNodes(nodeLabels, nodeCoor, "Nodes");

//writing the model data: elements 
  odb_SequenceInt elLabels;

for(int e=0;e<_numberofelements;e++)
elLabels.append(_elements[e].elementlabel);

  odb_SequenceSequenceInt connect;
  const int numNodePerEl = 8;
  for (int e=0; e<elLabels.size(); e++) {
    odb_SequenceInt l;
    for (int i=0; i<numNodePerEl; i++)
      l.append(_elements[e].conname[i]);
    connect.append(l);
  }
	
    odb_String sectionCategoryName("C3D8");
    odb_String sectionCategoryDescription("my_hexahedras");
    odb_SectionCategory& sCat =
        odb.SectionCategory(sectionCategoryName,
                            sectionCategoryDescription);


  part1.addElements(elLabels, connect, "C3D8",
		    "Hexahedras",sCat);

    odb_Assembly& rootAssy = odb.rootAssembly();
    odb_Instance& instance1 =
    odb.rootAssembly().Instance("part-1-1", part1);

  // An ElementSet on an instance  
  odb_SequenceInt eLabelsA;
for(int e=0;e<_numberofelements;e++)
eLabelsA.append(_elements[e].elementlabel);
  instance1.ElementSet("elSetA", eLabelsA);
  
  // A NodeSet on the rootAssembly

  odb_SequenceSequenceInt nodeLabelsRA;
  odb_SequenceString namesRA;
  namesRA.append("part-1-1");
  odb_SequenceInt nodeLabelsRA_A;
  for (int n=0; n<nodeLabels.size(); n++)
  nodeLabelsRA_A.append(_nodes[n].nodelabel);
  nodeLabelsRA.append(nodeLabelsRA_A);
  const odb_Set& nSetRA = rootAssy.NodeSet("nodeSetRA",
					   namesRA, nodeLabelsRA);  


    odb_String stepName("step-1");
    odb_String stepDescription("first analysis step");
    odb_Step& step1 = odb.Step(stepName,
                               stepDescription,
                               odb_Enum::TIME,
			       1.0);

 };






void odb_result_writer_solid(Node _nodes[], Element _elements[],
                       int _numberofnodes, int _numberofelements,char *argv[],odb_Odb& odb, double l, double numberofloadsteps)

{

odb_Assembly& rootAssy = odb.rootAssembly();

odb_Instance& instance1 = 
        rootAssy.instances()["part-1-1"];

    odb_Step& step1 = odb.steps()["step-1"];

    int incrementNumber = l+1;
    float analysisTime = (l+1)/numberofloadsteps;

    odb_String frameDescription("results frame for time");
    frameDescription.append(analysisTime);
    odb_Frame frame1 = step1.Frame(incrementNumber,
                                   analysisTime,
                                   frameDescription);


  odb_SequenceInt nodeLabels;
	for(int n=0;n<_numberofnodes;n++)
  	nodeLabels.append(_nodes[n].nodelabel);
  

  odb_SequenceInt eLabelsA;
	for(int e=0;e<_numberofelements;e++)
	eLabelsA.append(_elements[e].elementlabel);



// Field data:
    // Create a step and a frame.


    // Write nodal displacements.
    odb_String fieldName("U");
    odb_String fieldDescription("Displacements");
    odb_FieldOutput& uField =
        frame1.FieldOutput(fieldName,
                           fieldDescription,
			   odb_Enum::VECTOR);

    odb_SequenceSequenceFloat dispData;

    // create some displacement values
  for (int n=0; n<_numberofnodes; n++)
{
       odb_SequenceFloat current_dispData;
	current_dispData.append(_nodes[n].u_lamb[0]);
	current_dispData.append(_nodes[n].u_lamb[1]);
	current_dispData.append(_nodes[n].u_lamb[2]);
	dispData.append(current_dispData);
}   
    uField.addData(odb_Enum::NODAL,
                   instance1,
                   nodeLabels,
                   dispData);

    // Make this the default deformed field for visualization.

    step1.setDefaultDeformedField(uField);



    // Write nodal normals.
    odb_String normalfieldName("normal");
    odb_String normalfieldDescription("nodenormal");
    odb_FieldOutput& normalField =
        frame1.FieldOutput(normalfieldName,
                           normalfieldDescription,
			   odb_Enum::VECTOR);

    odb_SequenceSequenceFloat normalData;

    // create some displacement values
  for (int n=0; n<_numberofnodes; n++)
{
       odb_SequenceFloat current_normalData;
	if(_nodes[n].nodenormals_x.size()!=0)
	{
        current_normalData.append(_nodes[n].nodenormals_x[0]);
	current_normalData.append(_nodes[n].nodenormals_y[0]);
	current_normalData.append(_nodes[n].nodenormals_z[0]);
	}
	else
	{
        current_normalData.append(0.0);
	current_normalData.append(0.0);
	current_normalData.append(0.0);
	}
normalData.append(current_normalData);
}   
    normalField.addData(odb_Enum::NODAL,
                        instance1,
                        nodeLabels,
                        normalData);

//odb.save();
//odb.close();

};



