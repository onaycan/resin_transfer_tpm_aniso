/* -*- mode: c++ -*- */
#ifndef odb_OdbRepository_h
#define odb_OdbRepository_h

// Begin local includes
#include <mem_AllocationOperators.h>
#include <odb_Odb.h>
#include <thr_GlobalSingleton.h>
#include <cow_Btree.h>
#include <cow_String.h>
#include <omu_PrimTuple.h>
// End local includes

COW_BTREE_DECL(odb_String, odb_Odb, odb_OdbMap);

// Forward declarations
class ddb_DdbContainer;
COW_COW_DECL(ddb_DdbContainer);

class odb_OdbRepositoryIT;
class rfm_File;

class odb_OdbRepository : public thr_GlobalSingleton<odb_OdbRepository>
{
    friend class thr_GlobalSingleton<odb_OdbRepository>;
    friend class odb_OdbRepositoryIT;

public:
    ~odb_OdbRepository( );

    void insert(const odb_String& name, const odb_Odb& odb);
    odb_Odb& get(const odb_String& name);
    const odb_Odb& constGet(const odb_String& name);
    odb_Odb& operator[](const odb_String& name){return get(name);};
    void remove(const odb_String& name);
    int size();
    bool isMember(const odb_String& name);

private:
    odb_OdbRepository();
    ddb_DdbContainerCOW DdbCon;
    odb_OdbMap OdbMap;

public:   // undocumented and unsupported
    ddb_DdbContainer& DdbContainer();
    odb_OdbMap& odbMap();
    bool IsFileOpen(const odb_String& path);
    bool IsOdbLocked(const odb_String& odbPath);
    bool LockOdb(const odb_String& odbPath);
    bool RemoveLock(const odb_String& odbPath);
    odb_String GetLockPhase( const odb_String& odbPath );

    void  RespondToCloseOdb(const odb_String&  path);
};

class odb_OdbRepositoryIT : public mem_AllocationOperators
{
public:
    odb_OdbRepositoryIT(odb_OdbRepository& );

    void first();
    void next();
    bool isDone();
    const odb_Odb& currentValue();
    const odb_String& currentKey();

private:
    odb_OdbMapIT _iter;
    odb_OdbRepository& _odbCon;
};

/////////////////////////////////////////////////////
//
// Functions
//

odb_Odb& Odb( const odb_String& name,
              const odb_String& analysisTitle="",
	      const odb_String& description="",
              const odb_String& path="" );

odb_Odb& openOdb( const odb_String& path,
		  bool  readOnly = false,
                bool  readInternalSets = false);



odb_Odb& openOdb( const odb_String& name,
                  const odb_String& path,
		  bool  readOnly = false,
		  bool  checkPhase = true,
                bool  readInternalSets = false );

odb_Odb& getActiveOdb();

void saveOdb(odb_Odb& o);
void closeOdb(odb_Odb& o);
void upgradeOdb(const odb_String& fileInput, const odb_String& fileOutput);

bool isUpgradeRequiredForOdb(const odb_String& fileInput);
//Undocumented and Unsupported
void upgradeRemoteOdb(const odb_String& fileInput, const odb_String& fileOutput,const odb_String& remoteConnectionName);
void _procsAfterConversion(int oldDatabaseVersion, const odb_String& fileOutput);
// 0 - up to date, 1 - needs upgrade, 2 - needs downgrade, 3 - could not determine (invalid db)
int _getOdbUpToDateStatus(const rfm_File &fileInput, int *databaseVersion = NULL);
int _getOdbUpToDateStatus(const odb_String &fileName, int *databaseVersion = NULL);
//this is just for internal use for testing purposes of odb upgrade
omu_PrimTuple* _getOdbSchema(bool includeOldVersions);
///////////////////////////////////////////////////////

#endif // odb_OdbRepository_h







