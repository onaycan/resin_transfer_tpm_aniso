#!/bin/csh -f
echo Deleting the old data...
rm TPM_CAN_RTM_BIG.cpp TPM_CAN_RTM_BIG.exe TPM_CAN_RTM_BIG.o
echo Combining the cpp-s...
cat tpm_main.cpp csr_Matrix.cpp allocaters.cpp contact.cpp master_surface.cpp gauss.cpp tpm_stiff.cpp tpm_internal.cpp global_functions.cpp linear_algebra.cpp readers.cpp writers.cpp odb_writers.cpp layup.cpp>>TPM_CAN_RTM_BIG.cpp

if ( $#argv > 0 ) then
    set source = "$argv[1]"
else
    set source = "TPM_CAN_RTM_BIG"
endif

#echo Setting the library path...

#LD_LIBRARY_PATH=$LD_LIBRARY_PATH:"/net/netapp/home/can/tpm_can_rtm/tpm/lib"

#setenv LD_LIBRARY_PATH ./lib 

echo Compiling and Linking...

abq6111 make job=TPM_CAN_RTM_BIG.cpp

#icpc -c -cxxlib -Kc++eh -fPIC -Krtti -Kc++ -pc64 -restrict -DABQ_LINUX -DABQ_LNX86_64 -DFOR_TRAIL -DHAS_BOOL -DASSERT_ENABLED -D_BSD_TYPES -D_BSD_SOURCE -D_GNU_SOURCE -D_POSIX_SOURCE -D_XOPEN_SOURCE_EXTENDED -D_XOPEN_SOURCE -DHAVE_OPENGL -DHKS_OPEN_GL -DTYPENAME=typename -DGL_GLEXT_PROTOTYPES -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64-we1011 -we120 -we117 -we556 -we144 -we268 -we1224 -we167 -we880 -O0 -I./include ./$source.C

#icpc -c -cxxlib -Kc++eh -fPIC -Krtti -Kc++ -pc64 -restrict -DABQ_LINUX -DABQ_LNX86_64 -DFOR_TRAIL -DHAS_BOOL -DASSERT_ENABLED -D_BSD_TYPES -D_BSD_SOURCE -D_GNU_SOURCE -D_POSIX_SOURCE -D_XOPEN_SOURCE_EXTENDED -D_XOPEN_SOURCE -DHAVE_OPENGL -DHKS_OPEN_GL -DTYPENAME=typename -DGL_GLEXT_PROTOTYPES -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -we101 -we120 -we117 -we556 -we144 -we268 -we1224 -we167 -we880 -O0 -I./include ./$source.cpp


#echo Linking... 

#icpc -cxxlib -fPIC -Wl,-Bdynamic -i-dynamic -o ./$source.exe ./$source.o  -L./lib  -lABQDDB_Odb -lABQSMAOdbApi -lABQSMAOdbCore -lABQSMAOdbCoreGeom -lABQSMAOdbAttrEO -lABQSMAAbuBasicUtils -lABQSMABasShared -lABQSMABasCoreUtils -lABQCAE_StableTime -lABQSMABasMem -lABQSMAAbuGeom -lABQSMARomDiagEx -lABQSMASspUmaCore -lABQSMASimInterface -lABQSMAMtxCoreModule -lpthread

#icpc -cxxlib -fPIC -Wl,-Bdynamic -i-dynamic -o ./$source.exe ./$source.o  -L./lib  -lABQDDB_Odb -lABQSMAOdbApi -lABQSMAOdbCore -lABQSMAOdbCoreGeom -lABQSMAOdbAttrEO -lABQSMAAbuBasicUtils -lABQSMABasShared -lABQSMABasCoreUtils -lABQCAE_StableTime -lABQSMABasMem -lABQSMAAbuGeom -lABQSMARomDiagEx -lABQSMASspUmaCore -lABQSMASimInterface -lABQSMAMtxCoreModule -lpthread

