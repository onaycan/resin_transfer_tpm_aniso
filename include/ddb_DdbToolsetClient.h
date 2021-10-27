/* -*- mode: c++ -*- */
///////////////////////////////////////////////////////////////////////////////
//
// File Name: ddb_DdbToolsetClient.h
// 
// Description:
//
//
//

#ifndef ddb_DdbToolsetClient_h
#define ddb_DdbToolsetClient_h

//
// SECTION: System includes
//

//
// Begin Local Includes
//
#include <mem_AllocationOperatorsTiny.h>
#include <BasicConstants.h>
#include <omi_types.h>
//
// SECTION: Forward Declarations
//
class  cow_String;

//
// SECTION: Class definition
//

class ddb_DdbToolsetClient  : public mem_AllocationOperatorsTiny
{
public:
    ddb_DdbToolsetClient();
    virtual ~ddb_DdbToolsetClient();

    // Used to keep track of individual clients in a client list.
    void    SetClientId( const uint  id ) { clientId = id; }
    uint  ClientId() const { return  clientId; }

    // Methods called by ddb_DdbToolset to notify clients of database
    // activity
    virtual void  RespondToOpenOdb( const cow_String& fileName ) = 0;
    virtual void  RespondToCloseOdb( const cow_String& fileName ) = 0;
    virtual void  RespondToUpdateOdb( const cow_String& fileName ) = 0;
    virtual void  UpdateScene();
    virtual void  UpdateSceneForDatum( bool edit, const cow_String &name );
    virtual void  UpdateSceneForDeleteDatum(const cow_String& name );
    virtual void  UpdateModelForFieldOutput(const cow_String &);

    bool IsViewer() const { return isViewer; }
    
protected:
    bool isViewer;
    
private:
    uint  clientId;
};

#endif  // #ifdef ddb_DdbToolsetClient_h
