/* -*- mode: c++ -*- */
///////////////////////////////////////////////////////////////////////////////
//
// File Name: odb_DdbToolsetClient.h
// 
// Description:
//

#ifndef odb_DdbToolsetClient_h
#define odb_DdbToolsetClient_h

//
// SECTION: System includes
//

//
// Begin Local Includes
//
#include <ddb_DdbToolsetClient.h>

//
// SECTION: Forward Declarations
//

//
// SECTION: Class definition
//

class odb_DdbToolsetClient : public  ddb_DdbToolsetClient
{
public:
    odb_DdbToolsetClient();
    virtual ~odb_DdbToolsetClient();

    // Inherited methods
    virtual void  RespondToOpenOdb( const cow_String  &fileName );
    virtual void  RespondToCloseOdb( const cow_String  &fileName );
    virtual void  RespondToUpdateOdb( const cow_String  &fileName );

private:
};

#endif  // #ifdef odb_DdbToolsetClient_h
