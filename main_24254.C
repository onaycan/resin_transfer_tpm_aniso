#include <stdlib.h>           
#include <assert.h>           
#include <stdio.h>            
// Begin local includes 
#include <odb_API.h>          
#include <odb_MaterialTypes.h>   
#include <odb_SectionTypes.h>    
 
#if !defined ODB_API_ONLY 
void SMAStsStdB_initialize(int&);   
void SMAStsStdB_finalize(int&);     
#endif 
 
static int called = 0;        
 
void umkInitialize(int& active) { 
    if (called++) return;     
    active++;                 
 
#if !defined ODB_API_ONLY 
    SMAStsStdB_initialize(active);  
#endif 
    odb_initializeAPI();   
} 
  
void umkFinalize(int& active) { 
    if (--called) return;     
    active--;                 
 
    odb_finalizeAPI();     
#if !defined ODB_API_ONLY 
    SMAStsStdB_finalize(active);    
#endif
} 
  
static int active;            
 
void ABQFinalize() {          
    if (active)               
       umkFinalize(active);   
    assert(active == 0);      
} 
// 
// Begin local includes 
// 
#include <odb_WipReporter.h>  
#include <nex_Exception.h>  
// 
int ABQmain(int argc, char** argv); 
int main(int argc, char** argv)
{  
    umkInitialize(active); 
    atexit(ABQFinalize);     
  
  
    int status = 0; 
    try { 
       status = ABQmain(argc, argv);  
    } 
    catch (const nex_Exception& nex) {
    fprintf(stderr, "%s\n", nex.UserReport().CStr()); 
    fprintf(stderr, "ODB Application exited with error(s)\n");
    } 
    catch (...) {
    fprintf(stderr, "ODB Application exited with error(s)\n");
    } 
  
    ABQFinalize(); 
  
    return status; 
} 
