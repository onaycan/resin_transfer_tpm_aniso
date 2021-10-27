/* -*- mode: c++ -*- */
#ifndef inpO_ConnectorTangentialBehavior_h
#define inpO_ConnectorTangentialBehavior_h

////////////////////////////////////////////////////////////////////////
//
//  Name: inpO_ConnectorTangentialBehavior
//
//  Description: placeholder for tangential behavior data
//  ODB API does not support a default value constructor

// Forward declaration
//
// Begin local includes
#include <mem_AllocationOperators.h>
//
#include <cow_CountedHld.h>

#include <kbeO_TangentialBehavior.h>

class inpO_ConnectorTangentialBehavior  : public mem_AllocationOperators
{
public:
    inpO_ConnectorTangentialBehavior( odb_String formulation,
                                      bool slipRateDependency,
                                      bool pressureDependency,
                                      bool temperatureDependency,
                                      int dependencies,
                                      odb_String exponentialDecayDefinition,
                                      odb_Union shearStressLimit,
                                      odb_String maximumElasticSlip,
                                      double fraction,
                                      odb_Union absoluteDistance,
                                      const odb_SequenceSequenceDouble& table );
    odb_String _formulation;
    bool _slipRateDependency;
    bool _pressureDependency;
    bool _temperatureDependency;
    int _dependencies;
    odb_String _exponentialDecayDefinition;
    odb_Union _shearStressLimit;
    odb_String _maximumElasticSlip;
    double _fraction;
    odb_Union _absoluteDistance;
    odb_SequenceSequenceDouble _table;
};

COW_COUNTEDHLD_DECL(inpO_ConnectorTangentialBehavior, inpO_ConnectorTangentialBehaviorHld)

#endif // inpO_ConnectorTangentialBehavior_h

