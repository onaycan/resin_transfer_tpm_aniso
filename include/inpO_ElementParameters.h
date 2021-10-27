/*   -*- mode: c++ -*-   */
#ifndef inpO_ElementParameters_h
#define inpO_ElementParameters_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_ElementParameters
//
// Description:
//

// Includes

// Forward declarations
class odb_Element;
class inpO_BasicElemTypeData;

// Begin local includes
#include <mem_AllocationOperators.h>
#include <cow_String.h>

// Class definition

class inpO_ElementParameters  : public mem_AllocationOperators
{
public:

   inpO_ElementParameters(const cow_String&             etype,
                          const inpO_BasicElemTypeData& basicElemTypeData,
                          int                           offset = 0,
                          bool                          solidNumbering = false);
   inpO_ElementParameters(const odb_Element&            element,
                          const inpO_BasicElemTypeData& basicElemTypeData);
   ~inpO_ElementParameters();

   const cow_String& Type() const;

   bool IsSupported() const;
   bool IsObsolete() const;
   bool IsUserElement() const;
   bool IsSuperelement() const;

   bool IsOffsetElement() const;
   bool IsVariableNodeElement() const;
   bool IsGasketElement() const;
   bool IsCohesiveElement() const;
   bool IsConnectorElement() const;
   bool IsGeneralizedPlainStrainElement() const;
   bool IsBeamElement() const;
   bool HasExtraNodes(int currentNumNodes) const;

   bool IsZeroLabelAllowed() const;

   int MinNodesPerElement() const;
   int MaxNodesPerElement() const;

   bool IsEighteenNodeGasket() const;

   void UpdateMinNumNodesForOffsetElm(int);

private:

   void SetNodesInfo();
   void SetElementInfo();

   bool SetIsSuperelement();
   bool SetIsUserElement();
   bool SetIsZeroNodeLabelAllowed();

   void SetOffsetElemData();

   void Initialize();

   //
   cow_String  m_type;

   bool m_supported;
   bool m_obsolete;
   bool m_userElement;
   bool m_superlement;

   bool m_offsetElm;
   bool m_variableNodeElm;
   bool m_gasketElm;
   bool m_cohesiveElm;
   bool m_connectorElm;

   bool m_zeroLabelAllowed;
   bool m_solidNumbering;

   int  m_minNodesPerElement;
   int  m_maxNodesPerElement;

   int m_offset;
   int m_nodesPerPlane;
   int m_numberPlanes;
   int m_numberPlanesToDefine;
   int m_numberNodesInElmOffset;

   const inpO_BasicElemTypeData & m_basicElemTypeData;
};


//---------------------------------------------------------------------------->
inline const cow_String&
inpO_ElementParameters::Type() const
//---------------------------------------------------------------------------->
{
   return m_type;
}

//---------------------------------------------------------------------------->
inline bool
inpO_ElementParameters::IsSupported() const
//---------------------------------------------------------------------------->
{
   return m_supported;
}

//---------------------------------------------------------------------------->
inline bool
inpO_ElementParameters::IsObsolete() const
//---------------------------------------------------------------------------->
{
   return m_obsolete;
}

//---------------------------------------------------------------------------->
inline bool
inpO_ElementParameters::IsUserElement() const
//---------------------------------------------------------------------------->
{
   return m_userElement;
}

//---------------------------------------------------------------------------->
inline bool
inpO_ElementParameters::IsSuperelement() const
//---------------------------------------------------------------------------->
{
   return m_superlement;
}

//---------------------------------------------------------------------------->
inline bool
inpO_ElementParameters::IsOffsetElement() const
//---------------------------------------------------------------------------->
{
   return m_offsetElm;
}

//---------------------------------------------------------------------------->
inline bool
inpO_ElementParameters::IsVariableNodeElement() const
//---------------------------------------------------------------------------->
{
   return m_variableNodeElm;
}

//---------------------------------------------------------------------------->
inline bool
inpO_ElementParameters::IsGasketElement() const
//---------------------------------------------------------------------------->
{
   return m_gasketElm;
}

//---------------------------------------------------------------------------->
inline bool
inpO_ElementParameters::IsCohesiveElement() const
//---------------------------------------------------------------------------->
{
   return m_cohesiveElm;
}

//---------------------------------------------------------------------------->
inline bool
inpO_ElementParameters::IsConnectorElement() const
//---------------------------------------------------------------------------->
{
   return m_connectorElm;
}

//---------------------------------------------------------------------------->
inline bool
inpO_ElementParameters::IsZeroLabelAllowed() const
//---------------------------------------------------------------------------->
{
   return m_zeroLabelAllowed;
}

//---------------------------------------------------------------------------->
inline int
inpO_ElementParameters::MinNodesPerElement() const
//---------------------------------------------------------------------------->
{
   return m_minNodesPerElement;
}

//---------------------------------------------------------------------------->
inline int
inpO_ElementParameters::MaxNodesPerElement() const
//---------------------------------------------------------------------------->
{
   return m_maxNodesPerElement;
}


#endif /* inpO_ElementParameters_h */
