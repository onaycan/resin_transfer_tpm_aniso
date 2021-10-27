
void master_node_allocater(master_Node _masternodes[], ifstream &_masternodes_infile, int &_numberofmasternodes, ofstream& _debugfile)
{

//Start allocating 
for(int n=0;n<_numberofmasternodes;n++)
{
_masternodes[n].masterX=new double[3];
_masternodes[n].masteru=new double[3];
}
//End Allocating 


char current_line[256];
_masternodes_infile.getline(current_line,256);
int condition=0;
while(condition==0)
{
_masternodes_infile.getline(current_line,256);
if(current_line[1]=='N' && current_line[2]=='O' && current_line[3]=='D' && current_line[4]=='E')
condition=1; 
}

for(int n=0;n<_numberofmasternodes;n++)
{
char comma;
_masternodes_infile>>_masternodes[n].master_nodelabel; 
_masternodes_infile>>comma;
for(int i=0;i<2;i++)
{
_masternodes_infile>>_masternodes[n].masterX[i]; 
_masternodes_infile>>comma;
}
_masternodes_infile>>_masternodes[n].masterX[2];
for(int i=0;i<3;i++)
{
_masternodes[n].masteru[i]=0.0;
}
}

/*
for(int n=0;n<_numberofmasternodes;n++)
{
_debugfile<<_masternodes[n].master_nodelabel<<'\t';
_debugfile<<_masternodes[n].masterX[0]<<'\t';
_debugfile<<_masternodes[n].masterX[1]<<'\t';
_debugfile<<_masternodes[n].masterX[2]<<endl;
}
*/
};

void master_element_allocater(master_Node _masternodes[], master_Element _masterelements[], ifstream &_masterelements_infile, int &_numberofmasternodes, int &_numberofmasterelements, ofstream& _debugfile)
{

//Start allocating 
for(int e=0;e<_numberofmasterelements;e++)
{
_masterelements[e].master_conname=new int[4];
_masterelements[e].master_connid=new int[4];
}
//End Allocating 


char current_line[256];
_masterelements_infile.getline(current_line,256);
int condition=0;
while(condition==0)
{
_masterelements_infile.getline(current_line,256);
//cout<<current_line<<endl;
if(current_line[1]=='E' && current_line[2]=='L' && current_line[3]=='E' && current_line[4]=='M' 
&& current_line[5]=='E' && current_line[6]=='N' && current_line[7]=='T')
condition=1; 
}

for(int e=0;e<_numberofmasterelements;e++)
{
char comma;
_masterelements_infile>>_masterelements[e].master_elementlabel; 
_masterelements_infile>>comma;
for(int i=0;i<3;i++)
{
_masterelements_infile>>_masterelements[e].master_conname[i]; 
_masterelements_infile>>comma;
}
_masterelements_infile>>_masterelements[e].master_conname[3]; 

//assignment of the connectivity id 
for(int n=0;n<_numberofmasternodes;n++)
for(int i=0;i<4;i++)
if(_masternodes[n].master_nodelabel==_masterelements[e].master_conname[i])
_masterelements[e].master_connid[i]=n;




}

/*
for(int e=0;e<_numberofmasterelements;e++)
{
_debugfile<<_masterelements[e].master_elementlabel<<'\t';
for(int i=0;i<3;i++)
_debugfile<<_masterelements[e].master_conname[i]<<'\t';
_debugfile<<_masterelements[e].master_conname[3]<<endl;
}
*/
};

