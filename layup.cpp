
void layup_Node_constructer(layup_Node& current_Node, int _currentnodelabel, double _current_coord[3])
{
current_Node.layup_nodelabel=_currentnodelabel;
current_Node.layupX=new double[3];
current_Node.layupu=new double[3];
current_Node.nodal_vf=new double[3];
current_Node.nodal_vf_flag=0;
for(int i=0;i<3;i++)
{
current_Node.layupX[i]=_current_coord[i];
current_Node.nodal_vf[i]=0.0;
}
};


void layup_Element_constructer(layup_Element& current_Element, int _currentelementlabel, int _current_conn[4])
{
current_Element.layup_elementlabel=_currentelementlabel;
current_Element.layup_conn=new int[4];
current_Element.layup_connid=new int[4];
current_Element.layup_fiber=new double[3];
current_Element.layup_fv=new double[12];
current_Element.layup_nf=new double[4];
for(int i=0;i<4;i++)
{
current_Element.layup_conn[i]=_current_conn[i];
current_Element.layup_connid[i]=_current_conn[i]-1;
}
};


void layup_Element_fiber_assigner(layup_Element& current_Element, double _current_fiber[3])
{
for(int i=0;i<3;i++)
current_Element.layup_fiber[i]=_current_fiber[i];
};

void layup_Node_dof_assigner(layup_Node& current_Node, double _current_u[3], double _current_lambda)
{
for(int i=0;i<3;i++)
current_Node.layupu[i]=_current_u[i];

current_Node.layup_lambda=_current_lambda;

};


void layup_Element_dof_assigner(layup_Element& current_Element, double _current_fluid_velocity[12], double _current_nf[4])
{
for(int i=0;i<12;i++)
current_Element.layup_fv[i]=_current_fluid_velocity[i];

for(int i=0;i<4;i++)
current_Element.layup_nf[i]=_current_nf[i];

};


void layup_Node_vel_assigner(layup_Node& current_Node, double _current_v[3])
{
//if(current_Node.nodal_vf_flag==0)
for(int i=0;i<3;i++)
current_Node.nodal_vf[i]=current_Node.nodal_vf[i]+_current_v[i];

current_Node.nodal_vf_flag++;

};