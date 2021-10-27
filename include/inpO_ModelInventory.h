/*   -*- mode: c++ -*-   */
#ifndef inpO_ModelInventory_h
#define inpO_ModelInventory_h

///////////////////////////////////////////////////////////////////////////////
//
// Name: inpO_ModelInventory
//
// Description: model parameters
//

// Includes

// Forward declarations

// Begin local includes
#include <mem_AllocationOperators.h>
#include <inpO_MessageContainer.h>

#include <cow_MapString2String.h>
#include <cow_ListString.h>
#include <odb_Enum.h>

// Class definition

class inpO_PartInventory  : public mem_AllocationOperators
{
   friend class inpO_ModelInventory;
   friend class inpO_ModelInventoryVisitor;

public:

   inpO_PartInventory();
   ~inpO_PartInventory();

   odb_Enum::odb_DimensionEnum Dimension() const; // element theory
   odb_Enum::odb_DimensionEnum CoordDimension() const; // number of coordinates defined
   odb_Enum::odb_PartTypeEnum  Type() const;

   bool  HasMesh() const;
   bool  IsImported() const;
   void  SetDeformable();
   bool  HasDeformableElms() const;

   bool  IsActive() const;
   void  Deactivate();

protected:

   odb_Enum::odb_DimensionEnum  m_dimension;
   odb_Enum::odb_DimensionEnum  m_coordDimension;
   odb_Enum::odb_PartTypeEnum   m_type;

   bool  m_hasMesh;
   bool  m_imported;
   bool  m_hasDeformableElms; // no m_type default enum
   bool  m_active;
};
COW_MAP_ITER_DECL(cow_String, inpO_PartInventory, inpO_PartInventoryMap);


//---------------------------------------------------------------------------->
inline odb_Enum::odb_DimensionEnum
inpO_PartInventory::Dimension() const
//---------------------------------------------------------------------------->
{
   return m_dimension;
}

//---------------------------------------------------------------------------->
inline odb_Enum::odb_DimensionEnum
inpO_PartInventory::CoordDimension() const
//---------------------------------------------------------------------------->
{
   return m_coordDimension;
}

//---------------------------------------------------------------------------->
inline odb_Enum::odb_PartTypeEnum
inpO_PartInventory::Type() const
//---------------------------------------------------------------------------->
{
   return m_type;
}

//---------------------------------------------------------------------------->
inline bool
inpO_PartInventory::HasMesh() const
//---------------------------------------------------------------------------->
{
   return m_hasMesh;
}

//---------------------------------------------------------------------------->
inline bool
inpO_PartInventory::IsImported() const
//---------------------------------------------------------------------------->
{
   return m_imported;
}

//---------------------------------------------------------------------------->
inline void
inpO_PartInventory::SetDeformable()
//---------------------------------------------------------------------------->
{
   m_hasDeformableElms = true;
}

//---------------------------------------------------------------------------->
inline bool
inpO_PartInventory::HasDeformableElms() const
//---------------------------------------------------------------------------->
{
   return m_hasDeformableElms;
}

//---------------------------------------------------------------------------->
inline bool
inpO_PartInventory::IsActive() const
//---------------------------------------------------------------------------->
{
   return m_active;
}

//---------------------------------------------------------------------------->
inline void
inpO_PartInventory::Deactivate()
//---------------------------------------------------------------------------->
{
   m_active = false;
}



class inpO_InstanceInventory : public inpO_PartInventory
{
   friend class inpO_ModelInventory;
   friend class inpO_ModelInventoryVisitor;

public:

   inpO_InstanceInventory();
   ~inpO_InstanceInventory();

   const cow_String& PartName() const;

protected:

   cow_String  m_partName;
};
COW_MAP_ITER_DECL(cow_String, inpO_InstanceInventory, inpO_InstanceInventoryMap);

//---------------------------------------------------------------------------->
inline const cow_String&
inpO_InstanceInventory::PartName() const
//---------------------------------------------------------------------------->
{
   return m_partName;
}



class inpO_ModelInventory: public inpO_MessageContainer
{
   friend class inpO_ModelInventoryVisitor;

public:

   inpO_ModelInventory();
   ~inpO_ModelInventory();

   const cow_String& AssemblyName() const;
   const cow_String& AnalysisTitle() const;
   const cow_String& Description() const;

   odb_Enum::odb_AnalysisCodeEnum AnalysisCode() const;
   odb_Enum::odb_DimensionEnum Dimension() const;
   odb_Enum::odb_DimensionEnum CoordDimension() const;

   const cow_MapString2String& ConstGetInstancePartMap() const;

   const inpO_PartInventoryMap& ConstGetPartInventory() const;
   inpO_PartInventoryMap&       GetPartInventory();

   const inpO_InstanceInventoryMap& ConstGetInstanceInventory() const;
   inpO_InstanceInventoryMap& GetInstanceInventory();

   int GetNumRefNodes() const;
   void IncrementNumRefNodes();

   void CheckModel();
   void Print(aio_ostream&) const;

   cow_ListString InstanceNamesOfPart(const cow_String& partName) const;

private:

   void UpdateComponentType(inpO_PartInventory&, odb_Enum::odb_PartTypeEnum);

   cow_String DimensionEnum2String(odb_Enum::odb_DimensionEnum dimension) const;
   cow_String PartTypeEnum2String(odb_Enum::odb_PartTypeEnum type) const;
   cow_String AnalysisCodeEnum2String(odb_Enum::odb_AnalysisCodeEnum analysis) const;
   cow_String Bool2String(bool flag) const;

   static odb_Enum::odb_DimensionEnum 
   CheckComponentDimension(odb_Enum::odb_DimensionEnum targetDimension,
                           odb_Enum::odb_DimensionEnum dimension);

   // data //
   odb_Enum::odb_AnalysisCodeEnum m_analysisType;
   odb_Enum::odb_DimensionEnum    m_dimension;
   odb_Enum::odb_DimensionEnum    m_coordDimension;

   cow_String  m_assemblyName;
   cow_String  m_analysisTitle;
   cow_String  m_description;

   int m_numRefNodes;

   cow_MapString2String m_instancePartNames;
   cow_ListString m_partNames;  // to check the same part name occurences

   inpO_PartInventoryMap     m_partInventoryMap;
   inpO_InstanceInventoryMap m_instanceInventoryMap;
};


//---------------------------------------------------------------------------->
inline const cow_String&
inpO_ModelInventory::AssemblyName() const
//---------------------------------------------------------------------------->
{
   return m_assemblyName;
}

//---------------------------------------------------------------------------->
inline const cow_String&
inpO_ModelInventory::AnalysisTitle() const
//---------------------------------------------------------------------------->
{
   return m_analysisTitle;
}

//---------------------------------------------------------------------------->
inline const cow_String&
inpO_ModelInventory::Description() const
//---------------------------------------------------------------------------->
{
   return m_description;
}

//---------------------------------------------------------------------------->
inline odb_Enum::odb_AnalysisCodeEnum
inpO_ModelInventory::AnalysisCode() const
//---------------------------------------------------------------------------->
{
   return m_analysisType;
}

//---------------------------------------------------------------------------->
inline odb_Enum::odb_DimensionEnum
inpO_ModelInventory::Dimension() const
//---------------------------------------------------------------------------->
{
   return m_dimension;
}

//---------------------------------------------------------------------------->
inline odb_Enum::odb_DimensionEnum
inpO_ModelInventory::CoordDimension() const
//---------------------------------------------------------------------------->
{
   return m_coordDimension;
}

//---------------------------------------------------------------------------->
inline const cow_MapString2String&
inpO_ModelInventory::ConstGetInstancePartMap() const
//---------------------------------------------------------------------------->
{
   return m_instancePartNames;
}

//---------------------------------------------------------------------------->
inline const inpO_PartInventoryMap&
inpO_ModelInventory::ConstGetPartInventory() const
//---------------------------------------------------------------------------->
{
   return m_partInventoryMap;
}

//---------------------------------------------------------------------------->
inline inpO_PartInventoryMap&
inpO_ModelInventory::GetPartInventory()
//---------------------------------------------------------------------------->
{
   return m_partInventoryMap;
}

//---------------------------------------------------------------------------->
inline const inpO_InstanceInventoryMap&
inpO_ModelInventory::ConstGetInstanceInventory() const
//---------------------------------------------------------------------------->
{
   return m_instanceInventoryMap;
}

//---------------------------------------------------------------------------->
inline inpO_InstanceInventoryMap&
inpO_ModelInventory::GetInstanceInventory()
//---------------------------------------------------------------------------->
{
   return m_instanceInventoryMap;
}

//---------------------------------------------------------------------------->
inline int
inpO_ModelInventory::GetNumRefNodes() const
//---------------------------------------------------------------------------->
{
   return m_numRefNodes;
}

//---------------------------------------------------------------------------->
inline void
inpO_ModelInventory::IncrementNumRefNodes()
//---------------------------------------------------------------------------->
{
   ++m_numRefNodes;
}


#endif /* inpO_ModelInventory_h */
