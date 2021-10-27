#ifndef odb_WriteLocation_h
#define odb_WriteLocation_h

// Begin local includes
#include <mem_AllocationOperators.h>
#include <odb_Enum.h>
#include <odb_Instance.h>
#include <odb_SectionPoint.h>

#include <typ_typeTag.h>
// End local includes

class odb_WriteLocation : public mem_AllocationOperators
{
public:    // undocumented and unsupported
    odb_WriteLocation();
    odb_WriteLocation(const odb_Enum::odb_ResultPositionEnum position,
                      const odb_String& instanceName,
                      const odb_SectionPoint& sectionPoint);

    // member access
    odb_Enum::odb_ResultPositionEnum position() const {return m_position;}
    odb_String instance() const {return m_instanceName;}
    odb_SectionPoint sectionPoint() const {return m_sectionPoint;}

    //
    bool operator==(const odb_WriteLocation& rhs) const;
    bool operator!=(const odb_WriteLocation& rhs) const;


private:
    odb_Enum::odb_ResultPositionEnum     m_position;
    odb_String                 m_instanceName;  
    odb_SectionPoint           m_sectionPoint;     

};


#endif // odb_WriteLocation_h
