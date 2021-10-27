/*   -*- mode: c++ -*-   */
#ifndef inpO_BasicElemTypeData_h
#define inpO_BasicElemTypeData_h

///////////////////////////////////////////////////////////////////////////////
//
// Class: inpO_BasicElemTypeData
//
// Description:
//

// Includes

// Forward declarations

// Begin local includes
#include <mem_AllocationOperators.h>
#include <cow_String.h>
#include <inp_elements.h>
#include <inp_ElementVisitor.h>
#include <cow_MapString2Int.h>


// Class definition

class inpO_BasicElemTypeData  : public mem_AllocationOperators
{
public:

   inpO_BasicElemTypeData();
   ~inpO_BasicElemTypeData();

   bool IsSupported(const cow_String& etype) const;
   bool IsObsolete(const cow_String& etype) const;

   int MinNodesPerElement(const cow_String& etype) const;
   int MaxNodesPerElement(const cow_String& etype) const;

   void UpdateUserElemType(const cow_String& userElemType, int numNodes);
   bool HasUserElemTypeBeenDefined(const cow_String& userElemType) const;
   int  NumNodesInUserElemType(const cow_String& userElemType) const;

private:

   void SetValidElementInfo();
   void SetObsoleteElementInfo();

   cow_MapString2Int        m_userElemTypeNodeInfoMap;
   inp_ValidElementInfoMap  m_validElements, m_obsoleteElements;
};


//---------------------------------------------------------------------------->
inline bool
inpO_BasicElemTypeData::HasUserElemTypeBeenDefined(const cow_String& userElemType) const
//---------------------------------------------------------------------------->
{
   return m_userElemTypeNodeInfoMap.IsMember(userElemType);
}

//---------------------------------------------------------------------------->
inline int
inpO_BasicElemTypeData::NumNodesInUserElemType(const cow_String& userElemType) const
//---------------------------------------------------------------------------->
{
   // Un = n is a positive integer less than 10000
   return (m_userElemTypeNodeInfoMap.IsMember(userElemType)) ? 
           m_userElemTypeNodeInfoMap.ConstGet(userElemType) : 0;
}


#endif /* inpO_BasicElemTypeData_h */
