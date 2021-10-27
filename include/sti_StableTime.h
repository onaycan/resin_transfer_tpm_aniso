#ifndef sti_StableTime_h
#define sti_StableTime_h
///////////////////////////////////////////////////////////////////////////////
//
// Abaqus/CAE stable time increment calculation interface
//
//
// Arguments:
// ---------
//
// elemType           Name of Abaqus element type (e.g. 'C3D8R').
//                    Must be a type supported by /Explicit and /CAE.
//
// numNode            Number of nodes in the mesh
//
// numElem            Number of elements
//
// nodeCoords         Array of XYZ node coordinates. Array size = numNode*3
//
// connect            Element connectivity array.  Node numbering is
//                    zero-based.  Array size = numElem*(num nodes per elem)
//
// materialType       Material type code. Refer to the material type
//                    #define statements below.
//
// materialData       Array for material data.  The length and contents
//                    of the array depend upon the selected material type:
//
//                      * For elastic materials: Refer to *ELASTIC in the
//                        Abaqus Keywords Reference Manual.  The array contains
//                        all entries for the data line(s) as described in the
//                        manual, without temperature or field variables.
//
//                      * For hyperelastic materials: Refer to *HYPERELASTIC
//                        in the Abaqus Keywords Reference Manual. The first
//                        array entry is N, followed by all entries for the
//                        data line(s) as described in the manual, without
//                        temperature.  Note that for ARRUDA-BOYCE and
//                        VAN DER WAALS, N must be set to one.
//
//                      * For hyperfoam: Refer to *HYPERFOAM in the Abaqus
//                        Keywords Reference Manual. The first array entry
//                        is N, followed by N*3 data line values, without
//                        temperature, as described in the manual.
//
//                      * For acoustic medium: The array must contain two
//                        values: bulk modulus and volumetric drag.  Refer
//                        to *ACOUSTIC MEDIUM in the Abaqus Keywords
//                        Reference Manual.
//
// density             Array of density values for each element.
//
// thick               Array of shell thicknesses or cohesive thicknesses
//                     for each element, if appropriate.  Else pass a NULL
//                     array pointer or 1.0 for each value.
//
// linBulkVis          Linear bulk viscosity scale factor.  See data line
//                     description under *SECTION CONTROLS in the Abaqus
//                     Keywords Reference Manual.
//
// beamData            Array of size 3, applicable only to beam or truss
//                     elements:
//                        * Beam or truss cross sectional area.
//                        * Alpha stiffness proportional material damping.
//                        * Beta stiffness proportional material damping.
//                          (See *DAMPING documentation in the Abaqus Keywords
//                           Reference Manual.)
//
// cohesiveData        Array of size 2, applicable only to cohesive
//                     elements:
//                        * Flag = 0 if cohesive thickness is to be
//                          calculated based on geometry; 1 if specified in
//                          the 'thick' array above.
//                        * Out-of-plane thickness
//
// stableTime          Output stable time increments for each element.
//
// elemErrors          Output error codes for each element:
//                          0 : Success
//                        100 : Section definition error
//                        200 : Material definition error
//                        300 : Unsupported element type
//                        400 : Area/volume calculation error
//                       other: Unknown error
//
// ------------
// Return Value: Returns zero on success, or one of the above error codes.
//

//
// Material types
//
#define sti_ELASTIC_ISOTROPIC 100
#define sti_ELASTIC_ORTHOTROPIC 101
#define sti_ELASTIC_LAMINA 102
#define sti_ELASTIC_ANISOTROPIC 103
#define sti_ELASTIC_TRACTION 125
#define sti_ELASTIC_COUPLED_TRACTION 126
#define sti_ELASTIC_ENGINEERING_CONSTANTS 9001
#define sti_HYPERELASTIC_POLYNOMIAL 105
#define sti_HYPERELASTIC_OGDEN 107
#define sti_HYPERELASTIC_ARRUDA_BOYCE 118
#define sti_HYPERELASTIC_VAN_DER_WAALS 119
#define sti_HYPERFOAM 109
#define sti_ACOUSTIC_MEDIUM 250


//
// Routine declaration
//
int
sti_StableTime( const char *elemType,
                int numNode,
                int numElem,
                const float *nodeCoords,
                const int *connect,
                int materialType,
                const float *materialData,
                const float *density,
                const float *thick,
                float linBulkVis,
                float beamData[3],
                const float cohesiveData[2],
                float *stableTime,
                int *elemErrors );

#endif  // ifndef sti_StableTime_h

