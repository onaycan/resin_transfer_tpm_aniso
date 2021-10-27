/*   -*- mode: c++ -*-   */
#ifndef inp_Element_h
#define inp_Element_h

///////////////////////////////////////////////////////////////////////////////
//
// File Name: inp_Element.h
//
// Description:
//

// Includes

// Forward declarations

// Begin local includes
#include <mem_AllocationOperators.h>

#include <inpM_InstanceMap.h>
#include <cow_Map.h>
#include <cow_String.h>
#include <omi_IntTable.h>

// Class definition

class inp_Element  : public mem_AllocationOperators
{
  public:
    inp_Element();
    inp_Element(cow_String elementType, 
		const cow_ListInt& topology,
		int nodesDefined = 0,
		int nodeOffset = 0 , 
		int solidElementNumbering = 0);
    inp_Element(cow_String elementType, 
		int numNodesPerElement,
		int* topology,
		int nodesDefined = 0,
		int nodeOffset = 0 , 
		int solidElementNumbering = 0);
   ~inp_Element();

    inp_Element(const inp_Element&);
    inp_Element& operator=(const inp_Element&);

    int numNodesPerElement() const { return m_numNodesPerElement; }
    cow_String type() const { return m_type; }
    const int* topology() const { return m_topology; }
    int solidElementNumbering() const { return m_solidElementNumbering; }
    int numNodesDefined() const { return m_numNodesDefined; }
    int nodeOffset() const { return m_nodeOffset; }

  private:

    cow_String m_type;
    int* m_topology;
    int m_numNodesPerElement;
    int m_solidElementNumbering;  // for gasket elements
    int m_numNodesDefined;        // for gasket elements
    int m_nodeOffset;             // for gasket elements
};

OMI_INTTABLE_DECL(inp_Element, inp_MapInt2Element);
INPM_INSTANCE_MAP_DECL(inp_MapInt2Element, inp_ElementMap);

#endif /* inp_Element_h */
