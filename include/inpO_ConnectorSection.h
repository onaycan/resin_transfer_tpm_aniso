/* -*- mode: c++ -*- */
#ifndef inpO_ConnectorSection_h
#define inpO_ConnectorSection_h

////////////////////////////////////////////////////////////////////////
//
//  Name: inpO_ConnectorSection
//
//  Description: Write connector section data to ODB using ODB API 
//

// Forward declaration
class inpO_ConnectorSectionVisitor;

//
// Begin local includes
#include <mem_AllocationOperators.h>
//

#include <odb_String.h>
#include <odb_Types.h>
#include <cow_Map.h>


class inpO_ConnectorSection  : public mem_AllocationOperators
{
    friend class inpO_ConnectorSectionVisitor;
public:
    inpO_ConnectorSection() {}
    inpO_ConnectorSection( const cow_String& _elsetName,
                           const cow_String& _behaviorName,
                           const cow_String& _assembledType,
                           const cow_String& _rotationalType,
                           const cow_String& _translationalType );

   void SetMaterialFlowFactor(double);
   void SetMassPerLength(double);
   void SetContactAngle(double);

private:
    odb_String elsetName;
    odb_String behaviorName;
    odb_String oriName1;
    odb_String origName2;
    odb_String assembledType;
    odb_String rotationalType;
    odb_String translationalType;

   double m_materialFlowFactor;
   bool   m_massPerLengthFlag;
   double  m_massPerLength;
   bool   m_contactAngleFlag;
   double  m_contactAngle;
    
};

COW_MAP_ITER_DECL(cow_String, inpO_ConnectorSection, inpO_ConnectorSectionMap);

//---------------------------------------------------------------------------->
inline void
inpO_ConnectorSection::SetMaterialFlowFactor(double val)
//---------------------------------------------------------------------------->
{
   m_materialFlowFactor = val;
}


//---------------------------------------------------------------------------->
inline void
inpO_ConnectorSection::SetMassPerLength(double val)
//---------------------------------------------------------------------------->
{
   m_massPerLengthFlag = true;
   m_massPerLength = val;
}


//---------------------------------------------------------------------------->
inline void
inpO_ConnectorSection::SetContactAngle(double val)
//---------------------------------------------------------------------------->
{
   m_contactAngleFlag = true;
   m_contactAngle = val;
}


#endif // inpO_ConnectorSection_h

