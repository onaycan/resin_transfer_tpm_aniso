
/*   -*- mode: c++ -*-   */
#ifndef inp_keywords_h
#define inp_keywords_h

///////////////////////////////////////////////////////////////////////////////
//
// File Name: inp_keywords.h
//
// Description:  Define IDs and sub-options for all ABAQUS keywords.

// NOTE: When adding a new keyword choose any non-conflicting key number.

// Includes

// Forward declarations

// Begin local includes

// Keyword enums - set value to key number used in batch pre

enum inp_KeywordEnm
{
    inp_UNDEFINED_KEYWORD = 0,
    inp_ACOUSTIC_FLOW_VELOCITY=1143,
    inp_ACOUSTIC_MEDIUM = 1034,
    inp_ACOUSTIC_WAVE_FORMULATION = 313,
    inp_ADAPTIVE_MESH = 190,
    inp_ADAPTIVE_MESH_CONSTRAINT = 192,
    inp_ADAPTIVE_MESH_CONTROLS = 191,
    inp_ADJUST = 193,
    inp_AMPLITUDE = 131,
    inp_ANISOTROPIC_HYPERELASTIC = 1028,
    inp_ANNEAL = 123,
    inp_ANNEAL_TEMPERATURE = 1139,
    inp_AQUA = 201,
    inp_ASSEMBLY = 10000,
    inp_ASYMMETRIC_AXISYMMETRIC = 78,
    inp_AXIAL = 54,
    inp_BASELINE_CORRECTION = 138,
    inp_BASE_MOTION = 155,
    inp_BEAM_ADDED_INERTIA = 1141,
    inp_BEAM_FLUID_INERTIA = 1142,
    inp_BEAM_GENERAL_SECTION = 49,
    inp_BEAM_SECTION = 41,
    inp_BEAM_SECTION_GENERATE = 1431,
    inp_BIAXIAL = 5003,
    inp_BIAXIAL_TEST_DATA = 1043,
    inp_BLOCKAGE = 245,
    inp_BOND = 291,
    inp_BOUNDARY = 251,
    inp_BRITTLE_CRACKING = 1078,
    inp_BRITTLE_FAILURE = 1094,
    inp_BRITTLE_SHEAR = 1079,
    inp_BUCKLE = 113,
    inp_BUCKLING_ENVELOPE = 371,
    inp_BUCKLING_LENGTH = 372,
    inp_BUCKLING_REDUCTION_FACTORS = 373,
    inp_BULK_VISCOSITY = 288,
    inp_C_ADDED_MASS = 1411,
    inp_CAPACITY = 212,
    inp_CAP_CREEP = 1085,
    inp_CAP_HARDENING = 1064,
    inp_CAP_PLASTICITY = 1063,
    inp_CAST_IRON_COMPRESSION_HARDENING = 1089,
    inp_CAST_IRON_PLASTICITY = 1087,
    inp_CAST_IRON_TENSION_HARDENING = 1088,
    inp_CAVITY_DEFINITION = 289,
    inp_CECHARGE = 1404,
    inp_CECURRENT = 1408,
    inp_CENTROID = 90,
    inp_CFD = 2001,
    inp_CFILM = 1428,
    inp_CFLUX = 145,
    inp_CFLOW = 153,
    inp_CHANGE_FRICTION = 156,
    inp_CLAY_HARDENING = 1068,
    inp_CLAY_PLASTICITY = 1040,
    inp_CLEARANCE = 36,
    inp_CLOAD = 141,
    inp_COHESIVE_BEHAVIOR = 318,
    inp_COHESIVE_SECTION = 314,
    inp_COMBINED_TEST_DATA = 1049,
    inp_COMPLEX_FREQUENCY = 140,
    inp_CONCRETE = 1022,
    inp_CONCRETE_COMPRESSION_DAMAGE = 1119,
    inp_CONCRETE_COMPRESSION_HARDENING = 1117,
    inp_CONCRETE_DAMAGED_PLASTICITY = 1115,
    inp_CONCRETE_TENSION_DAMAGE = 1118,
    inp_CONCRETE_TENSION_STIFFENING = 1116,
    inp_CONDUCTION_EQUATION_SOLVER = 2002,
    inp_CONDUCTIVITY = 1001,
    inp_CONFLICTS = 10007,
    inp_CONNECTOR_BEHAVIOR = 285,
    inp_CONNECTOR_CONSTITUTIVE_REFERENCE = 1105,
    inp_CONNECTOR_CONTACT_FORCE = 1106,
    inp_CONNECTOR_DAMAGE_EVOLUTION = 1109,
    inp_CONNECTOR_DAMAGE_INITIATION = 1129,
    inp_CONNECTOR_DAMPING = 1099,
    inp_CONNECTOR_DERIVED_COMPONENT = 1126,
    inp_CONNECTOR_ELASTICITY = 1100,
    inp_CONNECTOR_FAILURE = 1101,
    inp_CONNECTOR_FRICTION = 1102,
    inp_CONNECTOR_HARDENING = 1108,
    inp_CONNECTOR_LOAD = 1427,
    inp_CONNECTOR_LOCK = 1104,
    inp_CONNECTOR_MOTION = 256,
    inp_CONNECTOR_POTENTIAL = 1127,
    inp_CONNECTOR_PLASTICITY = 1107,
    inp_CONNECTOR_SECTION = 304,
    inp_CONNECTOR_STOP = 1103,
    inp_CONNECTOR_UNIAXIAL_BEHAVIOR = 1130,
    inp_CONSTRAINT_CONTROLS = 385,
    inp_CONTACT = 387,
    inp_CONTACT_CLEARANCE = 401,
    inp_CONTACT_CLEARANCE_ASSIGNMENT = 402,
    inp_CONTACT_CONTROLS = 118,
    inp_CONTACT_CONTROLS_ASSIGNMENT = 388,
    inp_CONTACT_DAMPING = 305,
    inp_CONTACT_EXCLUSIONS = 389,
    inp_CONTACT_FILE = 180,
    inp_CONTACT_FORMULATION = 390,
    inp_CONTACT_INCLUSIONS = 391,
    inp_CONTACT_INITIALIZATION_ASSIGNMENT = 409,
    inp_CONTACT_INITIALIZATION_DATA = 410,
    inp_CONTACT_INTERFERENCE = 159,
    inp_CONTACT_OUTPUT = 1610,
    inp_CONTACT_PAIR = 286,
    inp_CONTACT_PERMEABILITY = 641,
    inp_CONTACT_PRINT = 179,
    inp_CONTACT_PROPERTY_ASSIGNMENT = 392,
    inp_CONTACT_RESPONSE = 3006,
    inp_CONTACT_STABILIZATION = 411,
    inp_CONTOUR_INTEGRAL = 281,
    inp_CONTROLS = 121,
    inp_CONWEP_CHARGE_PROPERTY = 321,
    inp_CORRELATION = 157,
    inp_COSIMULATION = 406,
    inp_COSIMULATION_CONTROLS = 408,
    inp_COSIMULATION_REGION = 405,
    inp_COUPLING = 258,
    inp_COUPLED_TEMPERATURE_DISPLACEMENT = 114,
    inp_COUPLED_THERMAL_ELECTRICAL = 117,
    inp_CRADIATE = 1429,
    inp_CREEP = 1002,
    inp_CREEP_STRAIN_RATE_CONTROL = 122,
    inp_CRUSHABLE_FOAM = 1110,
    inp_CRUSHABLE_FOAM_HARDENING = 1111,
    inp_CYCLED_PLASTIC = 1039,
    inp_CYCLIC = 128,
    inp_CYCLIC_HARDENING = 1082,
    inp_CYCLIC_SYMMETRY_MODEL = 379,
    inp_D_ADDED_MASS = 1410,
    inp_DAMAGE_EVOLUTION = 1123,
    inp_DAMAGE_INITIATION = 1122,
    inp_DAMAGE_STABILIZATION = 1124,
    inp_DAMPING = 1003,
    inp_DAMPING_CONTROLS = 492,
    inp_DASHPOT = 45,
    inp_DEBOND = 150,
    inp_DECHARGE = 1405,
    inp_DECURRENT = 1409,
    inp_DEFORMATION_PLASTICITY = 1033,
    inp_D_EM_POTENTIAL = 1441,
    inp_DENSITY = 1004,
    inp_DEPVAR = 1013,
    inp_DESIGN_PARAMETER = 3000,
    inp_DESIGN_RESPONSE = 3003,
    inp_DESIGN_SHAPE_VARIATION = 3002,
    inp_DESIGN_VALUE = 3011,
    inp_DESIGN_VARIATION = 3001,
    inp_DETONATION_POINT = 1058,
    inp_DFLOW = 151,
    inp_DFLUX = 146,
    inp_DIAGNOSTICS = 1612,
    inp_DIELECTRIC = 1048,
    inp_DIFFUSIVITY = 1052,
    inp_DIRECT_CYCLIC = 106,
    inp_DISCRETE_SECTION = 1150,
    inp_DISCRETE_INTERACTION = 1151,
    inp_DISCRETE_INTERACTION_PROPERTY = 1152,
    inp_DISPLAY_BODY = 11000,
    inp_DISTRIBUTING = 260,
    inp_DISTRIBUTING_COUPLING = 302,
    inp_DISTRIBUTION = 403,
    inp_DISTRIBUTION_TABLE = 407,
    inp_DLOAD = 142,
    inp_DRAG_CHAIN = 60,
    inp_DRUCKER_PRAGER = 1041,
    inp_DRUCKER_PRAGER_CREEP = 1084,
    inp_DRUCKER_PRAGER_HARDENING = 1075,
    inp_DSA_CONTROLS = 3010,
    inp_DSECHARGE = 1423,
    inp_DSECURRENT = 1424,
    inp_DSFLOW = 1421,
    inp_DSFLUX = 1418,
    inp_DSLOAD = 1417,
    inp_DYNAMIC = 104,
    inp_DYNAMIC_TEMPERATURE_DISPLACEMENT = 197,
    inp_ELASTIC = 1005,
    inp_ELCOPY = 14,
    inp_ELECTRICAL_CONDUCTIVITY = 1076,
    inp_ELECTROMAGNETIC = 119,
    inp_ELEMENT = 7,
    inp_ELEMENT_MATRIX_OUTPUT = 174,
    inp_ELEMENT_OUTPUT = 1606,
    inp_ELEMENT_RECOVERY_MATRIX = 208,
    inp_ELEMENT_RESPONSE = 3004,
    inp_ELFILE = 166,
    inp_ELGEN = 8,
    inp_ELPRINT = 162,
    inp_ELSET = 9,
    inp_EMBEDDED_ELEMENT = 257,
    inp_EMISSIVITY = 73,
    inp_END_ASSEMBLY = 10001,
    inp_END_INSTANCE = 10002,
    inp_END_LOAD_CASE = 266,
    inp_END_PART = 10003,
    inp_END_STEP = 102,
    inp_ENERGY_FILE = 165,
    inp_ENERGY_OUTPUT = 1608,
    inp_ENERGY_PRINT = 161,
    inp_ENRICHMENT=319,
    inp_ENRICHMENT_ACTIVATION=320,
    inp_EOF = 1,
    inp_EOS = 1057,
    inp_EOS_COMPACTION = 1121,
    inp_EOS_SHEAR = 1095,
    inp_EPJOINT = 83,
    inp_EQUATION = 253,
    //    inp_EULERIAN_COUPING = 246,
    inp_EULERIAN_BOUNDARY = 1500,
    inp_EULERIAN_INFLATOR_MIXTURE = 247,
    inp_EULERIAN_INFLATOR_PROPERTY = 248,
    inp_EULERIAN_MESH_MOTION = 1501,
    inp_EULERIAN_SECTION = 249,
    inp_EXPANSION = 1006,
    inp_EXTREME_ELEMENT_VALUE = 375,
    inp_EXTREME_NODE_VALUE = 376,
    inp_EXTREME_VALUE = 374,
    inp_FABRIC = 1027,
    inp_FAIL_STRAIN = 1066,
    inp_FAILSTRESS = 1065,
    inp_FAILURE = 1059,
    inp_FAILURE_RATIOS = 1023,
    inp_FASTENER = 378,
    inp_FASTENER_FAILURE = 384,
    inp_FASTENER_PROPERTY = 395,
    inp_FIELD = 144,
    inp_FILE_FORMAT = 169,
    inp_FILE_OUTPUT = 172,
    inp_FILM = 147,
    inp_FILM_PROPERTY = 139,
    inp_FILTER = 1700,
    inp_FIXED_MASS_SCALING = 1415,
    inp_FLOW = 152,
    inp_FLUID_BEHAVIOR = 211,
    inp_FLUID_BOUNDARY = 501,
    inp_FLUID_BULK_MODULUS = 97,
    inp_FLUID_CAVITY = 210,
    inp_FLUID_DENSITY = 96,
    inp_FLUID_EXCHANGE = 214,
    inp_FLUID_EXCHANGE_ACTIVATION = 216,
    inp_FLUID_EXCHANGE_INTERACTION = 217,
    inp_FLUID_EXCHANGE_PROPERTY = 215,
    inp_FLUID_EXPANSION = 95,
    inp_FLUID_FLUX = 1407,
    inp_FLUID_INFLATOR = 240,
    inp_FLUID_INFLATOR_ACTIVATION = 243,
    inp_FLUID_INFLATOR_INTERACTION = 244,
    inp_FLUID_INFLATOR_MIXTURE = 242,
    inp_FLUID_INFLATOR_PROPERTY = 241,
    inp_FLUID_LEAKOFF = 1071,
    inp_FLUID_LINK = 98,
    inp_FLUID_PROPERTY = 94,
    inp_FOAM = 1036,
    inp_FOAM_HARDENING = 1067,
    inp_FOUNDATION = 43,
    inp_FRACTURE_CRITERION = 1406,
    inp_FRAME_SECTION = 296,
    inp_FREQUENCY = 110,
    inp_FRICTION = 47,
    inp_GAP = 61,
    inp_GAP_CONDUCTANCE = 64,
    inp_GAP_ELECTRICAL_CONDUCTANCE = 88,
    inp_GAP_HEAT_GENERATION = 84,
    inp_GAP_FLOW = 1061,
    inp_GAP_RADIATION = 65,
    inp_GAS_SPECIFIC_HEAT = 1160,
    inp_GASKET_BEHAVIOR = 295,
    inp_GASKET_CONTACT_AREA = 1091,
    inp_GASKET_ELASTICITY = 1086,
    inp_GASKET_SECTION = 294,
    inp_GASKET_THICKNESS_BEHAVIOR = 1090,
    inp_GEL = 1056,
    inp_GEOSTATIC = 111,
    inp_GLOBAL_DAMPING = 493,
    inp_HEADING = 2,
    inp_HEAT_CAP = 303,
    inp_HEAT_GENERATION = 1032,
    inp_HEAT_TRANSFER = 107,
    inp_HOURGLASS_STIFFNESS = 81,
    inp_HYPERELASTIC = 1026,
    inp_HYPERFOAM = 1050,
    inp_HYPOELASTIC = 1038,
    inp_HYSTERESIS = 1098,
    inp_IMPEDANCE = 198,
    inp_IMPEDANCE_PROPERTY = 137,
    inp_IMPERFECTION = 37,
    inp_IMPORT = 16,
    inp_IMPORT_CONTROLS = 24,
    inp_IMPORT_ELSET = 17,
    inp_IMPORT_NSET = 18,
    inp_INCIDENT_WAVE = 307,
    inp_INCIDENT_WAVE_PROPERTY = 308,
    inp_INCIDENT_WAVE_INTERACTION = 315,
    inp_INCIDENT_WAVE_INTERACTION_PROPERTY = 316,
    inp_INCIDENT_WAVE_REFLECTION = 309,
    inp_INCIDENT_WAVE_FLUID_PROPERTY = 310,
    inp_INCLUDE = 292,
    inp_INCREMENTATION_OUTPUT = 1613,
    inp_INELASTIC_HEAT_FRACTION = 1031,
    inp_INERTIA_RELIEF = 1430,
    inp_INITIAL_CONDITIONS = 21,
    inp_INSTANCE = 10004,
    inp_INTEGRATED_OUTPUT = 1616,
    inp_INTEGRATED_OUTPUT_SECTION = 262,
    inp_INTERFACE = 79,
    inp_ITS = 66,
    inp_JOINT = 82,
    inp_JOINTED_MATERIAL = 1062,
    inp_JOINT_ELASTICITY = 74,
    inp_JOINT_PLASTICITY = 75,
    inp_JOULE_HEAT_FRACTION = 1081,
    inp_KAPPA = 1054,
    inp_KINEMATIC = 259,
    inp_KINEMATIC_COUPLING = 255,
    inp_LATENT_HEAT = 1007,
    inp_LICENSE = 3007,
    inp_LOAD_CASE = 265,
    inp_LOADING_DATA = 5001,
    inp_LOW_DENSITY_FOAM = 1046,
    inp_MAGNETIC_PERMEABILITY = 1144,
    inp_MAP_SOLUTION = 25,
    inp_MASS = 70,
    inp_MASS_ADJUST = 1444,
    inp_MASS_DIFFUSION = 120,
    inp_MASS_FLOW_RATE = 1403,
    inp_MATERIAL = 1000,
    inp_MATRIX = 77,
    inp_MATRIX_ASSEMBLE = 1433,
    inp_MATRIX_GENERATE = 1435,
    inp_MATRIX_INPUT = 1434,
    inp_MATRIX_OUTPUT = 1436,
    inp_MEDIA_TRANSPORT = 219,
    inp_MEMBRANE_SECTION = 99,
    inp_MODAL_DAMPING = 282,
    inp_MODAL_DYNAMIC = 105,
    inp_MODAL_FILE = 168,
    inp_MODAL_OUTPUT = 1609,
    inp_MODAL_PRINT = 164,
    inp_MODEL = 10006,
    inp_MODEL_CHANGE = 154,
    inp_MOHR_COULOMB = 1092,
    inp_MOHR_COULOMB_HARDENING = 1093,
    inp_MOISTURE_SWELLING = 1060,
    inp_MOLECULAR_WEIGHT = 213,
    inp_MOMENTUM_EQUATION_SOLVER = 2003,
    inp_MONITOR = 173,
    inp_MOTION = 129,
    inp_MPC = 252,
    inp_MULLINS_EFFECT = 1120,
    inp_M1 = 55,
    inp_M2 = 56,
    inp_NCOPY = 13,
    inp_NFILL = 3,
    inp_NGEN = 5,
    inp_NMAP = 12,
    inp_NO_COMPRESSION = 1019,
    inp_NODAL_ENERGYRATE = 34,
    inp_NODAL_THICKNESS = 35,
    inp_NODE = 4,
    inp_NODE_FILE = 167,
    inp_NODE_OUTPUT = 1607,
    inp_NODE_PRINT = 163,
    inp_NODE_RESPONSE = 3005,
    inp_NONSTRUCTURAL_MASS = 263,
    inp_NORMAL = 31,
    inp_NO_TENSION = 1018,
    inp_NSET = 6,
    inp_ORIENTATION = 136,
    inp_ORNL = 1017,
    inp_OUTPUT = 1604,
    inp_PARAMETER = 11100,
    inp_PARAMETER_DEPENDENCE = 11101,
    inp_PARAMETER_SHAPE_VARIATION = 38,
    inp_PART = 10005,
    inp_PERIODIC = 127,
    inp_PERIODIC_MEDIA = 134,
    inp_PERMEABILITY = 1015,
    inp_PHYSICAL_CONSTANTS = 15,
    inp_PIEZOELECTRIC = 1047,
    inp_PIPE_SOIL_INTERACTION = 306,
    inp_PIPE_SOIL_STIFFNESS = 1138,
    inp_PLANAR_TEST_DATA = 1051,
    inp_PLASTIC = 1010,
    inp_PLASTIC_AXIAL = 297,
    inp_PLASTIC_M1 = 298,
    inp_PLASTIC_M2 = 299,
    inp_PLASTIC_TORQUE = 300,
    inp_POROUS_BULK_MODULI = 1030,
    inp_POROUS_ELASTIC = 1037,
    inp_POROUS_FAILURE_CRITERIA = 1074,
    inp_POROUS_METAL_PLASTICITY = 1072,
    inp_POST_OUTPUT = 271,
    inp_POTENTIAL = 1009,
    inp_PRETENSION_SECTION = 293,
    inp_PREPRINT = 133,
    inp_PRESSURE_EQUATION_SOLVER = 2004,
    inp_PRESSURE_PENETRATION = 1416,
    inp_PRESSURE_STRESS = 1412,
    inp_PRESTRESS_HOLD = 158,
    inp_PRINT = 170,
    inp_PSD_DEFINITION = 135,
    inp_RADIATE = 148,
    inp_RADIATION_FILE = 1602,
    inp_RADIATION_OUTPUT = 1611,
    inp_RADIATION_PRINT = 1601,
    inp_RADIATION_SYMMETRY = 125,
    inp_RADIATION_VIEWFACTOR = 124,
    inp_RANDOM_RESPONSE = 116,
    inp_RATE_DEPENDENT = 1014,
    inp_RATIOS = 1008,
    inp_REACTION_RATE = 1158,
    inp_REBAR = 51,
    inp_REBAR_LAYER = 312,
    inp_REFLECTION = 126,
    inp_RELEASE = 254,
    inp_REMESH_TRIGGER = 381,
    inp_RESPONSE_SPECTRUM = 109,
    inp_RESTART = 11,
    inp_RETAINED_EIGENMODES = 236,
    inp_RETAINED_NODAL_DOFS = 222,
    inp_RIGID_BODY = 89,
    inp_RIGID_SURFACE = 52,
    inp_ROTARY_INERTIA = 80,
    inp_SECTION_CONTROLS = 301,
    inp_SECTION_FILE = 186,
    inp_SECTION_ORIGIN = 1432,
    inp_SECTION_POINTS = 59,
    inp_SECTION_PRINT = 185,
    inp_SELECT_CYCLIC_SYMMETRY_MODES = 382,
    inp_SELECT_EIGENMODES = 377,
    inp_SFILM = 1419,
    inp_SFLOW = 1422,
    inp_SHEAR = 5004,
    inp_SHEAR_CENTER = 91,
    inp_SHEAR_FAILURE = 1096,
    inp_SHEAR_RETENTION = 1025,
    inp_SHEAR_TEST_DATA = 1044,
    inp_SHELL_GENERAL_SECTION = 48,
    inp_SHELL_SECTION = 46,
    inp_SHELL_TO_SOLID_COUPLING = 386,
    inp_SIMPEDANCE = 199,
    inp_SIMPLE_SHEAR_TEST_DATA = 1055,
    inp_SLIDE_LINE = 53,
    inp_SLOAD = 160,
    inp_SOILS = 112,
    inp_SOLID_SECTION = 44,
    inp_SOLUBILITY = 1053,
    inp_SOLUTION_TECHNIQUE = 283,
    inp_SOLVER_CONTROLS = 1440,
    inp_SORPTION = 1035,
    inp_SPATIAL_DISTRIBUTION = 393,
    inp_SPECIFIC_HEAT = 1011,
    inp_SPECTRUM = 132,
    inp_SPOT_WELD = 398,
    inp_SPOT_WELD_INTERACTION = 397,
    inp_SPOT_WELD_PROPERTY = 399,
    inp_SPRING = 68,
    inp_SRADIATE = 1420,
    inp_STATIC = 103,
    inp_STEADY_STATE_CRITERIA = 1426,
    inp_STEADY_STATE_DETECTION = 1425,
    inp_STEADY_STATE_DYNAMICS = 115,
    inp_STEADY_STATE_TRANSPORT = 130,
    inp_STEP = 101,
    inp_SUBCYCLING = 1442,
    inp_SUBMODEL = 261,
    inp_SUBSTRUCTURECOPY = 227,
    inp_SUBSTRUCTUREDELETE = 226,
    inp_SUBSTRUCTUREDIRECTORY = 234,
    inp_SUBSTRUCTUREGENERATE = 200,
    inp_SUBSTRUCTURELOADCASE = 228,
    inp_SUBSTRUCTUREMATRIXOUTPUT = 233,
    inp_SUBSTRUCTUREPATH = 171,
    inp_SUBSTRUCTUREPROPERTY = 235,
    inp_SURFACE = 383,
    inp_SURFACE_BEHAVIOR = 63,
    inp_SURFACE_FLAW = 33,
    inp_SURFACE_INTERACTION = 50,
    inp_SURFACE_OUTPUT = 1614,
    inp_SURFACE_PERMEABILITY = 250,
    inp_SURFACE_PROPERTY = 71,
    inp_SURFACE_PROPERTY_ASSIGNMENT = 394,
    inp_SURFACE_SECTION = 311,
    inp_SURFACE_SMOOTHING = 396,
    inp_SWELLING = 1012,
    inp_SYMMETRIC_MODEL_GENERATION = 20,
    inp_SYMMETRIC_RESULTS_TRANSFER = 22,
    inp_SYSTEM = 10,
    inp_TEMPERATURE = 143,
    inp_TENSILE_FAILURE = 1097,
    inp_TENSION_CUTOFF = 1125,
    inp_TENSION_STIFFENING = 1024,
    inp_THERMAL_EXPANSION = 58,
    inp_TIE = 380,
    inp_TIME_POINTS = 400,
    inp_TORQUE = 57,
    inp_TORQUE_PRINT = 284,
    inp_TRACER_PARTICLE = 39,
    inp_TRANSFORM = 32,
    inp_TRANSPORT_EQUATION_SOLVER = 2005,
    inp_TRANSPORT_VELOCITY = 1413,
    inp_TRANSVERSE_SHEAR_STIFFNESS = 42,
    inp_TRIAXIAL_TEST_DATA = 1077,
    inp_TRS = 1020,
    inp_TURBULENCE_MODEL = 2006,
    inp_UNDEX_CHARGE_PROPERTY = 317,
    inp_UEL_PROPERTY = 76,
    inp_UNIAXIAL = 5000,
    inp_UNIAXIAL_TEST_DATA = 1042,
    inp_UNLOADING_DATA = 5002,
    inp_USER_DEFINED_FIELD = 1080,
    inp_USER_ELEMENT = 72,
    inp_USER_MATERIAL = 1029,
    inp_USER_OUTPUT_VARIABLES = 1069,
    inp_VARIABLE_MASS_SCALING = 1414,
    inp_VIEWFACTOR_OUTPUT = 1603,
    inp_VISCO = 108,
    inp_VISCOELASTIC = 1021,
    inp_VISCOSITY = 1113,
    inp_VISCOUS = 1140,
    inp_VOID_NUCLEATION = 1073,
    inp_VOLUMETRIC_TEST_DATA = 1045,
    inp_WAVE = 202,
    inp_WIND = 204
};

struct inp_RawKeywordInfo
{
    const char *keyword;
    inp_KeywordEnm id;
    inp_KeywordEnm const* suboptions;
};

static const inp_KeywordEnm amplitudeSuboptions[] = { 
    inp_BASELINE_CORRECTION, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm beamGeneralSectionSuboptions[] = { 
    inp_AXIAL, inp_BEAM_ADDED_INERTIA, inp_BEAM_FLUID_INERTIA, inp_CENTROID,
    inp_DAMPING, inp_M1, inp_M2, inp_SECTION_POINTS, inp_SHEAR_CENTER,
    inp_THERMAL_EXPANSION, inp_TORQUE, inp_TRANSVERSE_SHEAR_STIFFNESS,
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm beamSectionSuboptions[] = {
    inp_BEAM_ADDED_INERTIA, inp_BEAM_FLUID_INERTIA, inp_DESIGN_VARIATION,
    inp_TRANSVERSE_SHEAR_STIFFNESS,  inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm beamSectionGenerateSuboptions[] = { 
    inp_SECTION_ORIGIN, inp_SECTION_POINTS, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm anisotropichyperelasticSuboptions[] = { 
    inp_MULLINS_EFFECT, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm assemblySuboptions[] = { 
    inp_ADJUST,
    inp_CONNECTOR_SECTION, inp_COUPLING, inp_DASHPOT,
    inp_DISPLAY_BODY, inp_DISTRIBUTING, inp_DISTRIBUTING_COUPLING, 
    inp_DISTRIBUTION, 
    inp_ELSET,
    inp_EMBEDDED_ELEMENT, inp_END_INSTANCE, inp_ENRICHMENT, inp_EQUATION, 
    inp_FASTENER, inp_FASTENER_FAILURE, inp_FASTENER_PROPERTY, 
    inp_FLUID_CAVITY, inp_FLUID_INFLATOR, 
    inp_FOUNDATION, inp_GAP, inp_HEAT_CAP, inp_INCLUDE, inp_INSTANCE, inp_INTERFACE,
    inp_KINEMATIC, inp_KINEMATIC_COUPLING, inp_LICENSE, inp_MASS, inp_MASS_ADJUST, inp_MPC, 
    inp_NONSTRUCTURAL_MASS, inp_NORMAL, 
    inp_NSET, inp_ORIENTATION, inp_INTEGRATED_OUTPUT_SECTION, 
    inp_PRETENSION_SECTION, inp_RIGID_BODY, 
    inp_ROTARY_INERTIA, inp_SHELL_TO_SOLID_COUPLING, inp_SLIDE_LINE, 
    inp_SPOT_WELD, inp_SPOT_WELD_INTERACTION, 
    inp_SPOT_WELD_PROPERTY, inp_SPRING, inp_SUBMODEL, inp_SURFACE,
    inp_TIE, inp_TRANSFORM, inp_UEL_PROPERTY, inp_NODE,
    inp_ELEMENT, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm biaxialSuboptions[] = { 
    inp_LOADING_DATA, inp_UNDEFINED_KEYWORD
};


static const inp_KeywordEnm brittleCrackingSuboptions[] = { 
    inp_BRITTLE_FAILURE, inp_BRITTLE_SHEAR, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm capPlasticitySuboptions[] = { 
    inp_CAP_CREEP, inp_CAP_HARDENING, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm castIronPlasticitySuboptions[] = { 
    inp_CAST_IRON_COMPRESSION_HARDENING, inp_CAST_IRON_TENSION_HARDENING,
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm cfdSuboptions[] = { 
    inp_MOMENTUM_EQUATION_SOLVER, inp_PRESSURE_EQUATION_SOLVER, 
    inp_TRANSPORT_EQUATION_SOLVER, inp_TURBULENCE_MODEL, inp_UNDEFINED_KEYWORD
}; 

static const inp_KeywordEnm changeFrictionSuboptions[] = { 
    inp_FRICTION, inp_UNDEFINED_KEYWORD
}; 

static const inp_KeywordEnm clayPlasticitySuboptions[] = { 
    inp_CLAY_HARDENING, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm cloadSuboptions[] = {
    inp_DESIGN_VARIATION, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm cohesiveSectionSuboptions[] = {
    inp_TRANSVERSE_SHEAR_STIFFNESS,  inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm concreteSuboptions[] = { 
    inp_FAILURE_RATIOS, inp_SHEAR_RETENTION, inp_TENSION_STIFFENING,
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm concreteDamagedPlasticitySuboptions[] = { 
    inp_CONCRETE_COMPRESSION_DAMAGE, inp_CONCRETE_COMPRESSION_HARDENING, 
    inp_CONCRETE_TENSION_DAMAGE, inp_CONCRETE_TENSION_STIFFENING,
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm connectorBehaviorSuboptions[] = { 
    inp_CONNECTOR_CONSTITUTIVE_REFERENCE, inp_CONNECTOR_DAMAGE_INITIATION, 
    inp_CONNECTOR_DAMPING, inp_CONNECTOR_DERIVED_COMPONENT, inp_CONNECTOR_ELASTICITY, 
    inp_CONNECTOR_FAILURE, inp_CONNECTOR_FRICTION, inp_CONNECTOR_LOCK, 
    inp_CONNECTOR_PLASTICITY, inp_CONNECTOR_STOP, inp_CONNECTOR_UNIAXIAL_BEHAVIOR, 
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm connectorDamageInitiationSuboptions[] = {
    inp_CONNECTOR_POTENTIAL, inp_CONNECTOR_DAMAGE_EVOLUTION, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm connectorDamageEvolutionSuboptions[] = {
    inp_CONNECTOR_POTENTIAL, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm connectorLockSuboptions[] = {
    inp_CONNECTOR_POTENTIAL, inp_UNDEFINED_KEYWORD
}; 

static const inp_KeywordEnm connectorPlasticitySuboptions[] = {
    inp_CONNECTOR_HARDENING, inp_CONNECTOR_POTENTIAL, 
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm connectorFrictionSuboptions[] = {
    inp_CONNECTOR_CONTACT_FORCE, inp_FRICTION, inp_CONNECTOR_POTENTIAL,
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm connectorStopSuboptions[] = {
    inp_CONNECTOR_POTENTIAL, inp_UNDEFINED_KEYWORD
}; 

static const inp_KeywordEnm connectorUniaxialBehaviorSuboptions[] = {
    inp_LOADING_DATA, inp_UNDEFINED_KEYWORD
}; 

static const inp_KeywordEnm contactSuboptions[] = {
    inp_CONTACT_CLEARANCE_ASSIGNMENT,
    inp_CONTACT_CONTROLS_ASSIGNMENT, inp_CONTACT_EXCLUSIONS,
    inp_CONTACT_FORMULATION, inp_CONTACT_INCLUSIONS,
    inp_CONTACT_INITIALIZATION_ASSIGNMENT,
    inp_CONTACT_PROPERTY_ASSIGNMENT, inp_CONTACT_STABILIZATION,
    inp_SURFACE_PROPERTY_ASSIGNMENT, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm cosimulationSuboptions[] = { 
    inp_COSIMULATION_REGION, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm couplingSuboptions[] = {
    inp_KINEMATIC, inp_DISTRIBUTING, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm creepSuboptions[] = {
    inp_ORNL, inp_POTENTIAL, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm crushableFoamSuboptions[] = { 
    inp_CRUSHABLE_FOAM_HARDENING, inp_RATE_DEPENDENT, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm damageInitiationSuboptions[] = {
    inp_DAMAGE_EVOLUTION, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm damageEvolutionSuboptions[] = {
    inp_DAMAGE_STABILIZATION, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm debondSuboptions[] = { 
    inp_FRACTURE_CRITERION, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm densitySuboptions[] = { 
    inp_DESIGN_VARIATION, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm diffusivitySuboptions[] = { 
    inp_KAPPA, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm directCyclicSuboptions[] = { 
    inp_TIME_POINTS, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm discreteInteractionPropertySuboptions[] = { 
    inp_COHESIVE_BEHAVIOR, 
    inp_CONNECTOR_CONSTITUTIVE_REFERENCE, inp_CONNECTOR_DAMAGE_INITIATION, 
    inp_CONNECTOR_DAMPING, inp_CONNECTOR_DERIVED_COMPONENT, inp_CONNECTOR_ELASTICITY, 
    inp_CONNECTOR_FAILURE, inp_CONNECTOR_FRICTION, inp_CONNECTOR_LOCK, 
    inp_CONNECTOR_PLASTICITY, inp_CONNECTOR_STOP, inp_CONNECTOR_UNIAXIAL_BEHAVIOR,
    inp_CONTACT_DAMPING, 
    inp_DAMAGE_INITIATION,
    inp_FRICTION, inp_SURFACE_BEHAVIOR,
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm druckerPragerSuboptions[] = { 
    inp_DRUCKER_PRAGER_HARDENING, inp_DRUCKER_PRAGER_CREEP, inp_RATE_DEPENDENT,
    inp_TRIAXIAL_TEST_DATA,  inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm elasticSuboptions[] = { 
    inp_DESIGN_VARIATION, inp_NO_COMPRESSION, inp_NO_TENSION, inp_FAIL_STRAIN,
    inp_FAILSTRESS, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm eosSuboptions[] = { 
    inp_EOS_SHEAR, inp_DETONATION_POINT, inp_REACTION_RATE, inp_TENSILE_FAILURE,
    inp_EOS_COMPACTION, inp_GAS_SPECIFIC_HEAT, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm eosShearSuboptions[] = { 
    inp_TRS, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm epjointSuboptions[] = { 
    inp_JOINT_ELASTICITY, inp_JOINT_PLASTICITY, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm eulerianInflatorPropertySuboptions[] = { 
    inp_EULERIAN_INFLATOR_MIXTURE, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm extremeValueSuboptions[] = { 
    inp_EXTREME_ELEMENT_VALUE, inp_EXTREME_NODE_VALUE, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm fabricSuboptions[] = { inp_SHEAR_TEST_DATA,
    inp_BIAXIAL_TEST_DATA,  inp_UNIAXIAL_TEST_DATA, inp_UNIAXIAL,
    inp_BIAXIAL, inp_SHEAR, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm fastenerPropertySuboptions[] = {
    inp_FASTENER_FAILURE, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm fileOutputSuboptions[] = { 
    inp_ELFILE, inp_ENERGY_FILE, inp_NODE_FILE, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm fluidBehaviorSuboptions[] = { 
    inp_FLUID_BULK_MODULUS, inp_CAPACITY, inp_FLUID_DENSITY,
    inp_FLUID_EXPANSION, inp_MOLECULAR_WEIGHT,
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm fluidInflatorPropertySuboptions[] = { 
    inp_FLUID_INFLATOR_MIXTURE, inp_EULERIAN_INFLATOR_MIXTURE,
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm fluidPropertySuboptions[] = { 
    inp_FLUID_BULK_MODULUS,  inp_FLUID_DENSITY, inp_FLUID_EXPANSION,
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm foamSuboptions[] = { 
    inp_FOAM_HARDENING, inp_RATE_DEPENDENT, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm frameSectionSuboptions[] = { 
    inp_BUCKLING_ENVELOPE, inp_BUCKLING_LENGTH, inp_BUCKLING_REDUCTION_FACTORS,
    inp_PLASTIC_AXIAL, inp_PLASTIC_M1, inp_PLASTIC_M2, inp_PLASTIC_TORQUE,
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm frictionSuboptions[] = {
    inp_DESIGN_VARIATION, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm gapSuboptions[] = { 
    inp_CONTACT_DAMPING, inp_CONTACT_PERMEABILITY,  inp_GAP_CONDUCTANCE, 
    inp_GAP_HEAT_GENERATION, inp_GAP_RADIATION, inp_FRICTION, inp_SURFACE_BEHAVIOR,
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm gasketBehaviorSuboptions[] = { 
    inp_CREEP, inp_DEPVAR, inp_EXPANSION, inp_GASKET_CONTACT_AREA,
    inp_GASKET_ELASTICITY, inp_GASKET_THICKNESS_BEHAVIOR,
    inp_USER_OUTPUT_VARIABLES, inp_VISCOELASTIC, inp_UNDEFINED_KEYWORD
};


static const inp_KeywordEnm hyperelasticSuboptions[] = { 
    inp_BIAXIAL_TEST_DATA, inp_DESIGN_VARIATION, inp_HYSTERESIS, inp_MULLINS_EFFECT, 
    inp_PLANAR_TEST_DATA, inp_UNIAXIAL_TEST_DATA, inp_VOLUMETRIC_TEST_DATA,
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm hyperfoamSuboptions[] = { 
    inp_BIAXIAL_TEST_DATA, inp_DESIGN_VARIATION, inp_MULLINS_EFFECT, inp_PLANAR_TEST_DATA,
    inp_SIMPLE_SHEAR_TEST_DATA, inp_UNIAXIAL_TEST_DATA,
    inp_VOLUMETRIC_TEST_DATA, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm importSuboptions[] = { 
    inp_IMPORT_CONTROLS, inp_IMPORT_ELSET, inp_IMPORT_NSET,
    inp_UNDEFINED_KEYWORD
};
static const inp_KeywordEnm incidentWaveSuboptions[] = { 
   inp_INCIDENT_WAVE_REFLECTION, inp_UNDEFINED_KEYWORD
};
static const inp_KeywordEnm incidentWaveInteractionPropertySuboptions[] = { 
   inp_UNDEX_CHARGE_PROPERTY, inp_CONWEP_CHARGE_PROPERTY, inp_UNDEFINED_KEYWORD
};
static const inp_KeywordEnm incidentWaveInteractionSuboptions[] = { 
   inp_INCIDENT_WAVE_REFLECTION, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm incidentWavePropertySuboptions[] = { 
   inp_INCIDENT_WAVE_FLUID_PROPERTY, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm instanceSuboptions[] = { 
    inp_ADJUST,
    inp_BEAM_GENERAL_SECTION, inp_BEAM_SECTION, inp_CENTROID,
    inp_COHESIVE_SECTION, 
    inp_CONNECTOR_SECTION, inp_COUPLING, inp_DAMPING,
    inp_DASHPOT, inp_DESIGN_SHAPE_VARIATION,
    inp_DISCRETE_SECTION, inp_DISTRIBUTING,
    inp_DISTRIBUTING_COUPLING, inp_DISTRIBUTION, inp_DRAG_CHAIN, inp_ELCOPY, inp_ELEMENT,
    inp_ELGEN, inp_ELSET, inp_EMBEDDED_ELEMENT,  inp_ENRICHMENT,inp_EPJOINT, 
    inp_EQUATION, inp_EULERIAN_INFLATOR_PROPERTY, inp_EULERIAN_SECTION, 
    inp_FASTENER, inp_FASTENER_FAILURE, inp_FASTENER_PROPERTY,
    inp_FLUID_BEHAVIOR, inp_FLUID_CAVITY, 
    inp_FLUID_INFLATOR, inp_FLUID_INFLATOR_PROPERTY,
    inp_FLUID_PROPERTY, inp_FLUID_LINK, inp_FOUNDATION, inp_FRAME_SECTION,
    inp_GAP, inp_GASKET_SECTION, inp_HEAT_CAP, inp_IMPORT, inp_INCLUDE, inp_INTERFACE,
    inp_ITS, inp_JOINT, inp_KINEMATIC, inp_KINEMATIC_COUPLING, inp_LICENSE, inp_MASS,
    inp_MPC, inp_NCOPY, inp_NFILL, inp_NGEN, inp_NMAP, inp_NODAL_ENERGYRATE, 
    inp_NODAL_THICKNESS,
    inp_NODE, inp_NONSTRUCTURAL_MASS, inp_NSET, inp_NORMAL, inp_MEMBRANE_SECTION,
    inp_ORIENTATION, 
    inp_INTEGRATED_OUTPUT_SECTION, inp_PARAMETER_SHAPE_VARIATION, inp_PIPE_SOIL_INTERACTION,
    inp_PRETENSION_SECTION, inp_REBAR, inp_REBAR_LAYER, 
    inp_RELEASE, inp_RIGID_BODY, inp_RIGID_SURFACE, inp_ROTARY_INERTIA,
    inp_SOLID_SECTION, inp_SHELL_GENERAL_SECTION, inp_SHELL_SECTION,
    inp_SHELL_TO_SOLID_COUPLING, inp_SPOT_WELD, inp_SPOT_WELD_INTERACTION,
    inp_SPOT_WELD_PROPERTY, inp_SPRING, inp_SUBMODEL, inp_SURFACE, 
    inp_SURFACE_FLAW, inp_SURFACE_SECTION, inp_SYSTEM,
    inp_TIE, inp_TRANSFORM, inp_UEL_PROPERTY, inp_USER_ELEMENT,
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm interfaceSuboptions[] = { 
    inp_ASYMMETRIC_AXISYMMETRIC, inp_CONTACT_DAMPING, inp_CONTACT_PERMEABILITY,  
    inp_FRICTION, inp_GAP_CONDUCTANCE, inp_GAP_HEAT_GENERATION, inp_GAP_RADIATION, 
    inp_SURFACE_BEHAVIOR, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm itsSuboptions[] = { 
    inp_DASHPOT, inp_FRICTION, inp_SPRING, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm jointSuboptions[] = { 
    inp_DASHPOT, inp_SPRING, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm loadCaseSuboptions[] = {
    inp_BASE_MOTION, inp_CONNECTOR_LOAD, inp_CONNECTOR_MOTION, inp_BOUNDARY,
    inp_CLOAD, inp_DLOAD, inp_DSLOAD, inp_INERTIA_RELIEF, inp_SLOAD, 
    inp_TEMPERATURE, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm loadingdataSuboptions[] = {
    inp_UNLOADING_DATA, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm lowdensityfoamSuboptions[] = { 
    inp_UNIAXIAL_TEST_DATA, inp_VOLUMETRIC_TEST_DATA, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm materialSuboptions[] = {
    inp_ANISOTROPIC_HYPERELASTIC, inp_ANNEAL_TEMPERATURE,
    inp_ACOUSTIC_MEDIUM, inp_BRITTLE_CRACKING, 
    inp_CAP_PLASTICITY,inp_CAST_IRON_PLASTICITY, inp_CLAY_PLASTICITY,
    inp_CONCRETE, inp_CONCRETE_DAMAGED_PLASTICITY, inp_CONDUCTIVITY, inp_CREEP,
    inp_CRUSHABLE_FOAM, inp_DAMAGE_INITIATION, inp_DAMPING, 
    inp_DEFORMATION_PLASTICITY, inp_DENSITY,
    inp_DEPVAR, inp_DIELECTRIC, inp_DIFFUSIVITY, inp_DRUCKER_PRAGER,
    inp_ELASTIC, inp_ELECTRICAL_CONDUCTIVITY, inp_EOS, inp_EXPANSION, inp_FABRIC, 
    inp_FAILURE, inp_FLUID_LEAKOFF, inp_FOAM, inp_GAP_FLOW, inp_GEL,
    inp_HEAT_GENERATION, inp_HYPERELASTIC, inp_HYPERFOAM,  inp_HYPOELASTIC,
    inp_INCLUDE, inp_INELASTIC_HEAT_FRACTION, inp_JOINTED_MATERIAL, 
    inp_JOULE_HEAT_FRACTION, inp_LATENT_HEAT, inp_LICENSE, 
    inp_LOW_DENSITY_FOAM, inp_MAGNETIC_PERMEABILITY, inp_MOHR_COULOMB, 
    inp_MOISTURE_SWELLING, inp_PERMEABILITY, inp_PIEZOELECTRIC, inp_PLASTIC,
    inp_POROUS_BULK_MODULI, inp_POROUS_ELASTIC, inp_POROUS_METAL_PLASTICITY, 
    inp_SOLUBILITY, inp_SORPTION, inp_SPECIFIC_HEAT, inp_SWELLING,
    inp_USER_DEFINED_FIELD, inp_USER_MATERIAL, inp_USER_OUTPUT_VARIABLES, 
    inp_VISCOELASTIC, inp_VISCOSITY, inp_VISCOUS, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm matrixGenerateSuboptions[] = {
    inp_MATRIX_OUTPUT, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm membraneSectionSuboptions[] = {
    inp_DESIGN_VARIATION, inp_HOURGLASS_STIFFNESS, inp_REBAR_LAYER,
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm modelSuboptions[] = {
	inp_ACOUSTIC_WAVE_FORMULATION,inp_AQUA, inp_AMPLITUDE, inp_ASSEMBLY,
    inp_BOUNDARY,  inp_CAVITY_DEFINITION, inp_CLEARANCE,inp_CONNECTOR_BEHAVIOR,
    inp_CONNECTOR_MOTION, inp_CONSTRAINT_CONTROLS, inp_CONTACT, inp_CONTACT_CLEARANCE, 
    inp_CONTACT_INITIALIZATION_DATA, inp_CONTACT_PAIR, inp_CYCLIC_SYMMETRY_MODEL, 
    inp_DESIGN_PARAMETER, inp_DESIGN_VALUE,
    inp_DISCRETE_INTERACTION, inp_DISCRETE_INTERACTION_PROPERTY, 
    inp_DISTRIBUTION, inp_DISTRIBUTION_TABLE, inp_DSA_CONTROLS,
    inp_ELSET, inp_END_ASSEMBLY, inp_END_PART, inp_END_STEP, 
    inp_FASTENER, inp_FASTENER_FAILURE, inp_FASTENER_PROPERTY,
    inp_FILE_FORMAT, inp_FILM_PROPERTY, inp_FILTER, inp_FLUID_EXCHANGE,
    inp_FLUID_EXCHANGE_PROPERTY, inp_FOUNDATION, 
    inp_GASKET_BEHAVIOR, inp_HEADING,
    inp_IMPEDANCE_PROPERTY, inp_IMPERFECTION, inp_IMPORT, inp_INCIDENT_WAVE_INTERACTION_PROPERTY,
    inp_INCIDENT_WAVE_PROPERTY, inp_INCLUDE, inp_INITIAL_CONDITIONS,
    inp_LICENSE,
    inp_MAP_SOLUTION, inp_MASS, inp_MASS_ADJUST, inp_MATERIAL, inp_MATRIX_ASSEMBLE, 
    inp_MATRIX_INPUT, inp_NSET, inp_PARAMETER,
    inp_PART, inp_PERIODIC_MEDIA, inp_POST_OUTPUT, inp_PREPRINT, inp_PSD_DEFINITION, 
    inp_PHYSICAL_CONSTANTS, inp_RADIATION_SYMMETRY, inp_RESTART,  
    inp_ROTARY_INERTIA, inp_SECTION_CONTROLS, inp_SPATIAL_DISTRIBUTION,
    inp_SPECTRUM, inp_SPOT_WELD_INTERACTION, inp_SPOT_WELD_PROPERTY, inp_STEP,
    inp_SUBCYCLING, inp_SUBSTRUCTURECOPY, inp_SUBSTRUCTUREDELETE, inp_SUBSTRUCTUREDIRECTORY,
    inp_SUBSTRUCTUREPROPERTY, inp_SURFACE_INTERACTION,
    inp_SURFACE_PROPERTY, inp_SURFACE_SMOOTHING, inp_SYMMETRIC_MODEL_GENERATION, 
    inp_SYMMETRIC_RESULTS_TRANSFER, inp_TIME_POINTS, inp_UEL_PROPERTY, inp_USER_ELEMENT,
    inp_WAVE, inp_WIND, inp_UNDEFINED_KEYWORD 
};

static const inp_KeywordEnm mohrCoulombsuboptions[] = {
   inp_MOHR_COULOMB_HARDENING, inp_TENSION_CUTOFF,  inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm mullinsEffectSuboptions[] = { 
    inp_BIAXIAL_TEST_DATA, inp_PLANAR_TEST_DATA, inp_UNIAXIAL_TEST_DATA, 
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm orientationSuboptions[] = {
    inp_DESIGN_VARIATION, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm outputSuboptions[] = {
   inp_CONTACT_OUTPUT, inp_ELEMENT_OUTPUT, inp_ENERGY_OUTPUT,  
   inp_INCREMENTATION_OUTPUT, inp_MODAL_OUTPUT, inp_NODE_OUTPUT,
   inp_RADIATION_OUTPUT, inp_INTEGRATED_OUTPUT, inp_SURFACE_OUTPUT,
   inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm moistureSwellingsuboptions[] = {
   inp_RATIOS,   inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm partSuboptions[] = {
    inp_ADJUST,
    inp_BEAM_GENERAL_SECTION, inp_BEAM_SECTION, inp_CENTROID,
    inp_COHESIVE_SECTION,
    inp_CONNECTOR_SECTION, inp_COUPLING, inp_DAMPING, 
    inp_DASHPOT, inp_DESIGN_SHAPE_VARIATION,
    inp_DISCRETE_SECTION, inp_DISTRIBUTING,
    inp_DISTRIBUTING_COUPLING, inp_DISTRIBUTION, inp_DRAG_CHAIN, inp_ELCOPY, inp_ELEMENT,
    inp_ELGEN, inp_ELSET, inp_EMBEDDED_ELEMENT, inp_ENRICHMENT,inp_EPJOINT, 
    inp_EQUATION, inp_EULERIAN_INFLATOR_PROPERTY, inp_EULERIAN_SECTION, 
    inp_FASTENER, inp_FASTENER_FAILURE, inp_FASTENER_PROPERTY,
    inp_FLUID_BEHAVIOR, inp_FLUID_CAVITY, 
    inp_FLUID_INFLATOR,
    inp_FLUID_INFLATOR_PROPERTY,
    inp_FLUID_PROPERTY, inp_FLUID_LINK, inp_FOUNDATION, inp_FRAME_SECTION,
    inp_GAP, inp_GASKET_SECTION, inp_HEAT_CAP, inp_INCLUDE, inp_INTERFACE, 
    inp_ITS, inp_JOINT, inp_KINEMATIC, inp_KINEMATIC_COUPLING, inp_LICENSE, inp_MASS,
    inp_MEMBRANE_SECTION, inp_MPC, inp_NCOPY, inp_NFILL, inp_NGEN, inp_NMAP,
    inp_NODAL_ENERGYRATE, inp_NODAL_THICKNESS, inp_NODE, inp_NONSTRUCTURAL_MASS, inp_NORMAL, 
    inp_NSET, inp_ORIENTATION, 
    inp_INTEGRATED_OUTPUT_SECTION, inp_PARAMETER_SHAPE_VARIATION, inp_PIPE_SOIL_INTERACTION, 
    inp_PRETENSION_SECTION, inp_REBAR, inp_REBAR_LAYER, 
    inp_RELEASE, inp_RIGID_BODY, inp_RIGID_SURFACE, inp_ROTARY_INERTIA,
    inp_SOLID_SECTION, inp_SHELL_GENERAL_SECTION ,inp_SHELL_SECTION, 
    inp_SHELL_TO_SOLID_COUPLING, inp_SPOT_WELD, inp_SPOT_WELD_INTERACTION, 
    inp_SPOT_WELD_PROPERTY, inp_SPRING, inp_SUBMODEL, inp_SURFACE,
    inp_SURFACE_FLAW, inp_SURFACE_SECTION, inp_SYSTEM,
    inp_TIE, inp_TRANSFORM, inp_UEL_PROPERTY, inp_USER_ELEMENT, 
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm pipeSoilInteractionSuboptions[] = { 
    inp_PIPE_SOIL_STIFFNESS, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm plasticSuboptions[] = {
    inp_CYCLED_PLASTIC, inp_CYCLIC_HARDENING, inp_DESIGN_VARIATION, inp_ORNL, 
    inp_POTENTIAL, inp_RATE_DEPENDENT, inp_SHEAR_FAILURE, inp_TENSILE_FAILURE,
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm porousMetalPlasticitySuboptions[] = {
    inp_POROUS_FAILURE_CRITERIA, inp_VOID_NUCLEATION, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm postOutputSuboptions[] = {
    inp_ELFILE, inp_ELPRINT, inp_ELSET, inp_ENERGY_FILE, inp_ENERGY_PRINT,
    inp_FIELD, inp_FILE_OUTPUT, inp_FILE_FORMAT, inp_INCLUDE, inp_LICENSE, 
    inp_MODAL_FILE, inp_MODAL_PRINT, inp_NODE_FILE, inp_NODE_PRINT, inp_NSET, inp_OUTPUT,
    inp_PRINT, inp_RADIATION_FILE, inp_RADIATION_PRINT, inp_TRACER_PARTICLE, 
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm radiationSymmetrySuboptions[] = {
    inp_CYCLIC, inp_PERIODIC, inp_REFLECTION,  inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm rigidBodySuboptions[] = {
    inp_DESIGN_VARIATION, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm shearSuboptions[] = { 
    inp_LOADING_DATA, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm shellSectionSuboptions[] = {
    inp_DESIGN_VARIATION, 
    inp_HOURGLASS_STIFFNESS, inp_TRANSVERSE_SHEAR_STIFFNESS,
    inp_REBAR_LAYER, inp_UNDEFINED_KEYWORD
}; 

static const inp_KeywordEnm solidSectionSuboptions[] = {
    inp_DESIGN_VARIATION, inp_HOURGLASS_STIFFNESS, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm shellGeneralSectionSuboptions[] = {
    inp_DAMPING, inp_HOURGLASS_STIFFNESS,
    inp_TRANSVERSE_SHEAR_STIFFNESS, inp_UNDEFINED_KEYWORD
}; 

static const inp_KeywordEnm sloadCaseSuboptions[] = {
    inp_BOUNDARY, inp_CLOAD, inp_DLOAD, inp_DSLOAD, inp_SLOAD, 
    inp_TEMPERATURE, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm spotWeldInteractionSuboptions[] = {
    inp_SPOT_WELD, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm stepSuboptions[] = {
	inp_ACOUSTIC_FLOW_VELOCITY,
    inp_ADAPTIVE_MESH, inp_ADAPTIVE_MESH_CONSTRAINT,
    inp_ADAPTIVE_MESH_CONTROLS, inp_AMPLITUDE, inp_ANNEAL, inp_BASE_MOTION, 
    inp_BEAM_SECTION_GENERATE, inp_BOUNDARY, inp_BUCKLE, 
    inp_BULK_VISCOSITY, inp_CECHARGE, inp_CECURRENT,
    inp_C_ADDED_MASS, inp_CFILM, inp_CFLUX, inp_CFLOW, inp_CHANGE_FRICTION, 
    inp_CLEARANCE, inp_CLOAD, inp_COMPLEX_FREQUENCY, inp_CONNECTOR_LOAD, 
    inp_CONNECTOR_MOTION, inp_CONSTRAINT_CONTROLS, inp_CONTACT, 
    inp_CONTACT_CONTROLS, inp_CONTACT_FILE, inp_CONTACT_INTERFERENCE,
    inp_CONTACT_PAIR, inp_CONTACT_PRINT, inp_CONTACT_RESPONSE,
    inp_CONTOUR_INTEGRAL, inp_CONTROLS, inp_CORRELATION, inp_COSIMULATION, inp_COSIMULATION_CONTROLS,
    inp_COUPLED_TEMPERATURE_DISPLACEMENT, inp_COUPLED_THERMAL_ELECTRICAL,
    inp_CRADIATE, inp_CREEP_STRAIN_RATE_CONTROL, inp_D_ADDED_MASS, inp_DAMPING_CONTROLS, 
    inp_DEBOND,inp_DECHARGE, inp_DECURRENT, inp_D_EM_POTENTIAL, inp_DESIGN_RESPONSE, inp_DFLOW, inp_DFLUX,
    inp_DIAGNOSTICS, inp_DIRECT_CYCLIC, inp_DISCRETE_INTERACTION, inp_DISCRETE_INTERACTION_PROPERTY,
    inp_DLOAD, inp_DSA_CONTROLS, inp_DSECHARGE,
    inp_DSECURRENT,  inp_DSFLOW,  inp_DSFLUX, inp_DSLOAD, inp_DYNAMIC,
    inp_DYNAMIC_TEMPERATURE_DISPLACEMENT, inp_ELECTROMAGNETIC, inp_ELEMENT_MATRIX_OUTPUT,
    inp_ELEMENT_RESPONSE, inp_ELEMENT_RECOVERY_MATRIX, inp_ELFILE, inp_ELPRINT, inp_ELSET,
    inp_END_LOAD_CASE, inp_ENERGY_FILE, inp_ENERGY_PRINT, 
    inp_ENRICHMENT_ACTIVATION,  inp_EULERIAN_BOUNDARY, 
    inp_EULERIAN_MESH_MOTION, inp_EXTREME_VALUE,
    inp_FIELD, inp_FILE_OUTPUT, inp_FILE_FORMAT, inp_FILM,
    inp_FIXED_MASS_SCALING, inp_FLOW, inp_FLUID_EXCHANGE_ACTIVATION,
    inp_FLUID_EXCHANGE_INTERACTION,  inp_FLUID_INFLATOR_ACTIVATION,
    inp_FLUID_INFLATOR_INTERACTION, inp_FLUID_FLUX, inp_FREQUENCY, 
    inp_GEOSTATIC, inp_GLOBAL_DAMPING, inp_HEAT_TRANSFER, inp_IMPEDANCE, inp_INCIDENT_WAVE, 
    inp_LOAD_CASE, inp_MASS_DIFFUSION, inp_INCIDENT_WAVE_INTERACTION, inp_INCLUDE, 
    inp_INERTIA_RELIEF, inp_LICENSE, inp_MASS_FLOW_RATE, inp_MATRIX_GENERATE, inp_MATRIX_OUTPUT, 
    inp_MEDIA_TRANSPORT, inp_MODAL_DAMPING, inp_MODAL_DYNAMIC, inp_MODAL_FILE,
    inp_MODAL_PRINT, inp_MODEL_CHANGE, inp_MONITOR, inp_MOTION, inp_NODE_FILE,
    inp_NODE_PRINT, inp_NODE_RESPONSE, inp_NSET, inp_OUTPUT,
    inp_PRESSURE_PENETRATION, inp_PRESSURE_STRESS, inp_PRESTRESS_HOLD,
    inp_PRINT,  inp_RADIATE, inp_RADIATION_FILE, inp_RADIATION_PRINT,
    inp_RADIATION_SYMMETRY, inp_RADIATION_VIEWFACTOR,inp_RANDOM_RESPONSE, 
    inp_REMESH_TRIGGER, inp_RESPONSE_SPECTRUM, inp_RESTART,
    inp_RETAINED_EIGENMODES, inp_RETAINED_NODAL_DOFS, inp_SECTION_FILE,
    inp_SECTION_PRINT, inp_SELECT_EIGENMODES, inp_SELECT_CYCLIC_SYMMETRY_MODES,
    inp_SFILM, inp_SFLOW, inp_SIMPEDANCE, inp_SLOAD, inp_SOILS,
    inp_SOLUTION_TECHNIQUE, inp_SOLVER_CONTROLS, inp_SRADIATE, inp_STATIC,
    inp_STEADY_STATE_CRITERIA, inp_STEADY_STATE_DETECTION,
    inp_STEADY_STATE_DYNAMICS, inp_STEADY_STATE_TRANSPORT,
    inp_SUBSTRUCTUREGENERATE, inp_SUBSTRUCTURELOADCASE,
    inp_SUBSTRUCTUREMATRIXOUTPUT, inp_SUBSTRUCTUREPATH,
    inp_SURFACE_INTERACTION, inp_TEMPERATURE, 
    inp_TORQUE_PRINT,
    inp_TRACER_PARTICLE, inp_TRANSPORT_VELOCITY, inp_VARIABLE_MASS_SCALING, 
    inp_VIEWFACTOR_OUTPUT, inp_VISCO, inp_DESIGN_VARIATION,
    inp_CFD, inp_CONDUCTION_EQUATION_SOLVER, inp_FLUID_BOUNDARY,
    inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm substructureGenerateSuboptions[] = {
    inp_RETAINED_EIGENMODES, inp_RETAINED_NODAL_DOFS, inp_SUBSTRUCTURELOADCASE,
    inp_SUBSTRUCTUREMATRIXOUTPUT, inp_ELEMENT_RECOVERY_MATRIX, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm substructurePropertySuboptions[] = { 
    inp_DAMPING, inp_DAMPING_CONTROLS, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm surfaceInteractionSuboptions[] = { 
    inp_BOND, inp_COHESIVE_BEHAVIOR, inp_CONTACT_DAMPING, inp_CONTACT_PERMEABILITY,
    inp_DAMAGE_INITIATION,
    inp_FRACTURE_CRITERION, inp_FRICTION, inp_SURFACE_BEHAVIOR,
    inp_GAP_CONDUCTANCE, inp_GAP_ELECTRICAL_CONDUCTANCE,
    inp_GAP_HEAT_GENERATION, inp_GAP_RADIATION, 
    inp_BLOCKAGE, inp_SURFACE_PERMEABILITY, inp_UNDEFINED_KEYWORD 
};

static const inp_KeywordEnm surfacePropertySuboptions[] = { 
    inp_EMISSIVITY, inp_UNDEFINED_KEYWORD 
};

static const inp_KeywordEnm surfaceSectionSuboptions[] = { 
    inp_REBAR_LAYER, inp_UNDEFINED_KEYWORD 
};

static const inp_KeywordEnm swellingSuboptions[] = { 
    inp_RATIOS, inp_UNDEFINED_KEYWORD 
};

static const inp_KeywordEnm uniaxialSuboptions[] = {
    inp_LOADING_DATA, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm userElementSuboptions[] = { 
    inp_MATRIX, inp_UNDEFINED_KEYWORD 
};

static const inp_KeywordEnm viscoelasticSuboptions[] = {
    inp_COMBINED_TEST_DATA, inp_SHEAR_TEST_DATA, inp_TRS,
    inp_VOLUMETRIC_TEST_DATA, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm gasketsectionSuboptions[] = {
  inp_DESIGN_VARIATION, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm viscositySuboptions[] = { 
    inp_TRS, inp_UNDEFINED_KEYWORD
};

static const inp_KeywordEnm viscousSuboptions[] = {
    inp_POTENTIAL, inp_UNDEFINED_KEYWORD
};


static const inp_RawKeywordInfo validKeywordTable[] =
{
  {  "undefined keyword", inp_UNDEFINED_KEYWORD, 0 },
  {  "acousticflowvelocity", inp_ACOUSTIC_FLOW_VELOCITY, 0 },
  {  "acousticmedium", inp_ACOUSTIC_MEDIUM, 0 },
  {  "acousticwaveformulation", inp_ACOUSTIC_WAVE_FORMULATION, 0 },
  {  "adaptivemesh", inp_ADAPTIVE_MESH, 0 },
  {  "adaptivemeshconstraint", inp_ADAPTIVE_MESH_CONSTRAINT, 0 },
  {  "adaptivemeshcontrols", inp_ADAPTIVE_MESH_CONTROLS, 0 },
  {  "adjust", inp_ADJUST, 0 },
  {  "amplitude", inp_AMPLITUDE, amplitudeSuboptions },
  {  "anisotropichyperelastic", inp_ANISOTROPIC_HYPERELASTIC, anisotropichyperelasticSuboptions },
  {  "anneal", inp_ANNEAL, 0 },
  {  "annealtemperature", inp_ANNEAL_TEMPERATURE, 0 },
  {  "aqua", inp_AQUA, 0 },
  {  "assembly", inp_ASSEMBLY, assemblySuboptions },
  {  "asymmetric-axisymmetric", inp_ASYMMETRIC_AXISYMMETRIC, 0 },
  {  "axial", inp_AXIAL, 0 },
  {  "baselinecorrection", inp_BASELINE_CORRECTION, 0 },
  {  "basemotion", inp_BASE_MOTION, 0 },
  {  "beamaddedinertia", inp_BEAM_ADDED_INERTIA, 0 },
  {  "beamfluidinertia", inp_BEAM_FLUID_INERTIA, 0 },
  {  "beamgeneralsection", inp_BEAM_GENERAL_SECTION, beamGeneralSectionSuboptions },
  {  "beamsection", inp_BEAM_SECTION, beamSectionSuboptions },
  {  "beamsectiongenerate", inp_BEAM_SECTION_GENERATE, 
      beamSectionGenerateSuboptions },
  {  "biaxial", inp_BIAXIAL , biaxialSuboptions },
  {  "biaxialtestdata", inp_BIAXIAL_TEST_DATA , 0 },
  {  "blockage", inp_BLOCKAGE, 0 },
  {  "bond", inp_BOND, 0 },
  {  "boundary", inp_BOUNDARY, 0 },
  {  "brittlecracking", inp_BRITTLE_CRACKING, brittleCrackingSuboptions },
  {  "brittlefailure", inp_BRITTLE_FAILURE, 0 },
  {  "brittleshear", inp_BRITTLE_SHEAR, 0 },
  {  "buckle", inp_BUCKLE, 0 },
  {  "bucklingenvelope", inp_BUCKLING_ENVELOPE, 0 },
  {  "bucklinglength", inp_BUCKLING_LENGTH, 0 },
  {  "bucklingreductionfactors", inp_BUCKLING_REDUCTION_FACTORS, 0},
  {  "bulkviscosity", inp_BULK_VISCOSITY, 0 },
  {  "caddedmass", inp_C_ADDED_MASS, 0 },
  {  "capacity", inp_CAPACITY, 0 },
  {  "capcreep", inp_CAP_CREEP, 0 },
  {  "caphardening", inp_CAP_HARDENING, 0 },
  {  "capplasticity", inp_CAP_PLASTICITY, capPlasticitySuboptions },
  {  "castironcompressionhardening", inp_CAST_IRON_COMPRESSION_HARDENING, 0 },
  {  "castironplasticity", inp_CAST_IRON_PLASTICITY, castIronPlasticitySuboptions },
  {  "castirontensionhardening", inp_CAST_IRON_TENSION_HARDENING, 0 },
  {  "cavitydefinition", inp_CAVITY_DEFINITION, 0 },
  {  "cecharge", inp_CECHARGE, 0 },
  {  "cecurrent", inp_CECURRENT, 0 },
  {  "centroid", inp_CENTROID, 0 },
  {  "cfd", inp_CFD, cfdSuboptions },
  {  "cfilm", inp_CFILM, 0 },
  {  "cflow", inp_CFLOW, 0 },
  {  "cflux", inp_CFLUX, 0 },
  {  "changefriction", inp_CHANGE_FRICTION, changeFrictionSuboptions },
  {  "clayhardening", inp_CLAY_HARDENING, 0 },
  {  "clayplasticity", inp_CLAY_PLASTICITY, clayPlasticitySuboptions },
  {  "clearance", inp_CLEARANCE, 0 },
  {  "cload", inp_CLOAD, cloadSuboptions },
  {  "cohesivebehavior", inp_COHESIVE_BEHAVIOR, 0 },
  {  "cohesivesection", inp_COHESIVE_SECTION, cohesiveSectionSuboptions },
  {  "combinedtestdata", inp_COMBINED_TEST_DATA, 0 },
  {  "complexfrequency", inp_COMPLEX_FREQUENCY, 0 },
  {  "concrete", inp_CONCRETE, concreteSuboptions },
  {  "concretecompressiondamage", inp_CONCRETE_COMPRESSION_DAMAGE, 0 },
  {  "concretecompressionhardening", inp_CONCRETE_COMPRESSION_HARDENING, 0 },
  {  "concretedamagedplasticity", inp_CONCRETE_DAMAGED_PLASTICITY, concreteDamagedPlasticitySuboptions },
  {  "concretetensiondamage", inp_CONCRETE_TENSION_DAMAGE, 0 },
  {  "concretetensionstiffening", inp_CONCRETE_TENSION_STIFFENING, 0 },
  {  "conductionequationsolver", inp_CONDUCTION_EQUATION_SOLVER, 0 },
  {  "conductivity", inp_CONDUCTIVITY, 0 },
  {  "conflicts", inp_CONFLICTS, 0 },
  {  "connectorbehavior", inp_CONNECTOR_BEHAVIOR, connectorBehaviorSuboptions },
  {  "connectorconstitutivereference", inp_CONNECTOR_CONSTITUTIVE_REFERENCE, 0 },
  {  "connectorcontactforce", inp_CONNECTOR_CONTACT_FORCE, 0 },
  {  "connectordamageevolution", inp_CONNECTOR_DAMAGE_EVOLUTION, connectorDamageEvolutionSuboptions},
  {  "connectordamageinitiation", inp_CONNECTOR_DAMAGE_INITIATION, connectorDamageInitiationSuboptions},
  {  "connectordamping", inp_CONNECTOR_DAMPING, 0 },
  {  "connectorderivedcomponent", inp_CONNECTOR_DERIVED_COMPONENT, 0 },
  {  "connectorelasticity", inp_CONNECTOR_ELASTICITY, 0 },
  {  "connectorfailure", inp_CONNECTOR_FAILURE, 0 },
  {  "connectorfriction", inp_CONNECTOR_FRICTION, connectorFrictionSuboptions},
  {  "connectorhardening", inp_CONNECTOR_HARDENING, 0 },
  {  "connectorload", inp_CONNECTOR_LOAD, 0 },
  {  "connectorlock", inp_CONNECTOR_LOCK, connectorLockSuboptions },
  {  "connectormotion", inp_CONNECTOR_MOTION, 0 },
  {  "connectorplasticity", inp_CONNECTOR_PLASTICITY, connectorPlasticitySuboptions },
  {  "connectorpotential", inp_CONNECTOR_POTENTIAL, 0 },
  {  "connectorsection", inp_CONNECTOR_SECTION, 0 },
  {  "connectorstop", inp_CONNECTOR_STOP, connectorStopSuboptions },
  {  "connectoruniaxialbehavior", inp_CONNECTOR_UNIAXIAL_BEHAVIOR, connectorUniaxialBehaviorSuboptions },
  {  "constraintcontrols", inp_CONSTRAINT_CONTROLS, 0 },
  {  "contact", inp_CONTACT, contactSuboptions },
  {  "contactclearance", inp_CONTACT_CLEARANCE, 0 },
  {  "contactclearanceassignment", inp_CONTACT_CLEARANCE_ASSIGNMENT, 0 },
  {  "contactcontrols", inp_CONTACT_CONTROLS, 0 },
  {  "contactcontrolsassignment", inp_CONTACT_CONTROLS_ASSIGNMENT, 0 },
  {  "contactdamping", inp_CONTACT_DAMPING, 0 },
  {  "contactexclusions", inp_CONTACT_EXCLUSIONS, 0 },
  {  "contactfile", inp_CONTACT_FILE, 0 },
  {  "contactformulation", inp_CONTACT_FORMULATION, 0 },
  {  "contactinclusions", inp_CONTACT_INCLUSIONS, 0 },
  {  "contactinitializationassignment", inp_CONTACT_INITIALIZATION_ASSIGNMENT, 0 },
  {  "contactinitializationdata", inp_CONTACT_INITIALIZATION_DATA, 0 },
  {  "contactinterference", inp_CONTACT_INTERFERENCE, 0 },
  {  "contactoutput", inp_CONTACT_OUTPUT, 0 },
  {  "contactpair", inp_CONTACT_PAIR, 0 },
  {  "contactpermeability", inp_CONTACT_PERMEABILITY, 0 },
  {  "contactprint", inp_CONTACT_PRINT, 0 },
  {  "contactpropertyassignment", inp_CONTACT_PROPERTY_ASSIGNMENT, 0 },
  {  "contactresponse", inp_CONTACT_RESPONSE, 0 },
  {  "contactstabilization", inp_CONTACT_STABILIZATION, 0 },
  {  "contourintegral", inp_CONTOUR_INTEGRAL, 0 },
  {  "controls", inp_CONTROLS, 0 },
  {  "conwepchargeproperty", inp_CONWEP_CHARGE_PROPERTY, 0 },
  {  "correlation", inp_CORRELATION, 0 },
  {  "co-simulation", inp_COSIMULATION, cosimulationSuboptions},
  {  "co-simulationcontrols", inp_COSIMULATION_CONTROLS, 0},
  {  "co-simulationregion", inp_COSIMULATION_REGION, 0},
  {  "coupling", inp_COUPLING, couplingSuboptions }, 
  {  "coupledtemperature-displacement", inp_COUPLED_TEMPERATURE_DISPLACEMENT, 0 },
  {  "coupledthermal-electrical", inp_COUPLED_THERMAL_ELECTRICAL, 0 },
  {  "cradiate", inp_CRADIATE, 0 },
  {  "creep", inp_CREEP, creepSuboptions },
  {  "creepstrainratecontrol", inp_CREEP_STRAIN_RATE_CONTROL, 0 },
  {  "crushablefoam", inp_CRUSHABLE_FOAM, crushableFoamSuboptions },
  {  "crushablefoamhardening", inp_CRUSHABLE_FOAM_HARDENING, 0 },
  {  "cycledplastic", inp_CYCLED_PLASTIC, 0 },
  {  "cyclic", inp_CYCLIC, 0 },
  {  "cyclichardening", inp_CYCLIC_HARDENING, 0 },
  {  "cyclicsymmetrymodel", inp_CYCLIC_SYMMETRY_MODEL, 0 },
  {  "daddedmass", inp_D_ADDED_MASS, 0 },
  {  "damageinitiation", inp_DAMAGE_INITIATION, damageInitiationSuboptions },
  {  "damageevolution", inp_DAMAGE_EVOLUTION, damageEvolutionSuboptions },
  {  "damagestabilization", inp_DAMAGE_STABILIZATION, 0 },
  {  "damping", inp_DAMPING, 0 },
  {  "dampingcontrols", inp_DAMPING_CONTROLS, 0 },
  {  "dashpot", inp_DASHPOT, 0 },
  {  "debond", inp_DEBOND, debondSuboptions },
  {  "decharge", inp_DECHARGE, 0 },
  {  "decurrent", inp_DECURRENT, 0 },
  {  "deformationplasticity", inp_DEFORMATION_PLASTICITY, 0 },
  {  "dempotential", inp_D_EM_POTENTIAL, 0 },
  {  "density", inp_DENSITY, densitySuboptions },
  {  "depvar", inp_DEPVAR, 0 },
  {  "designparameter", inp_DESIGN_PARAMETER, 0 },
  {  "designresponse", inp_DESIGN_RESPONSE, 0 },
  {  "designshapevariation", inp_DESIGN_SHAPE_VARIATION, 0 },
  {  "designvalue", inp_DESIGN_VALUE, 0 },
  {  "designvariation", inp_DESIGN_VARIATION, 0 },
  {  "detonationpoint", inp_DETONATION_POINT, 0 },
  {  "dflow", inp_DFLOW, 0 },
  {  "dflux", inp_DFLUX, 0 },
  {  "diagnostics", inp_DIAGNOSTICS, 0 },
  {  "dielectric", inp_DIELECTRIC, 0 },
  {  "diffusivity", inp_DIFFUSIVITY, diffusivitySuboptions },
  {  "directcyclic", inp_DIRECT_CYCLIC, directCyclicSuboptions },
  {  "discretesection", inp_DISCRETE_SECTION, 0 },
  {  "discreteinteraction", inp_DISCRETE_INTERACTION, 0},
  {  "discreteinteractionproperty", inp_DISCRETE_INTERACTION_PROPERTY, discreteInteractionPropertySuboptions },
  {  "displaybody", inp_DISPLAY_BODY, 0 },
  {  "distributing", inp_DISTRIBUTING, 0 },
  {  "distributingcoupling", inp_DISTRIBUTING_COUPLING, 0 },
  {  "distribution", inp_DISTRIBUTION, 0 },
  {  "distributiontable", inp_DISTRIBUTION_TABLE, 0 },
  {  "dload", inp_DLOAD, 0 },
  {  "dragchain", inp_DRAG_CHAIN, 0 },
  {  "druckerprager", inp_DRUCKER_PRAGER, druckerPragerSuboptions },
  {  "druckerpragercreep", inp_DRUCKER_PRAGER_CREEP, 0 },
  {  "druckerpragerhardening", inp_DRUCKER_PRAGER_HARDENING, 0 },
  {  "dsacontrols", inp_DSA_CONTROLS, 0 },
  {  "dsecharge", inp_DSECHARGE, 0 },
  {  "dsecurrent", inp_DSECURRENT, 0 },
  {  "dsflow", inp_DSFLOW, 0 },
  {  "dsflux", inp_DSFLUX, 0 },
  {  "dsload", inp_DSLOAD, 0 },
  {  "dynamic", inp_DYNAMIC, 0 },
  {  "dynamictemperature-displacement", inp_DYNAMIC_TEMPERATURE_DISPLACEMENT, 0 },
  {  "elastic", inp_ELASTIC, elasticSuboptions },
  {  "elcopy", inp_ELCOPY, 0 },
  {  "electricalconductivity", inp_ELECTRICAL_CONDUCTIVITY, 0 },
  {  "electromagnetic", inp_ELECTROMAGNETIC, 0 },
  {  "element", inp_ELEMENT, 0 },
  {  "elementmatrixoutput", inp_ELEMENT_MATRIX_OUTPUT, 0 },
  {  "elementoutput", inp_ELEMENT_OUTPUT, 0 },
  {  "elementrecoverymatrix", inp_ELEMENT_RECOVERY_MATRIX, 0 },
  {  "elementresponse", inp_ELEMENT_RESPONSE, 0 },
  {  "elfile", inp_ELFILE, 0 },
  {  "elgen", inp_ELGEN, 0 },
  {  "elprint", inp_ELPRINT, 0 },
  {  "elset", inp_ELSET, 0 },
  {  "embeddedelement", inp_EMBEDDED_ELEMENT, 0 },
  {  "emissivity", inp_EMISSIVITY, 0 },
  {  "endassembly", inp_END_ASSEMBLY, 0 },
  {  "endinstance", inp_END_INSTANCE, 0 },
  {  "endloadcase", inp_END_LOAD_CASE, 0 },
  {  "endpart", inp_END_PART, 0 },
  {  "endstep", inp_END_STEP, 0 },
  {  "energyfile", inp_ENERGY_FILE, 0 },
  {  "energyoutput", inp_ENERGY_OUTPUT, 0 },
  {  "energyprint", inp_ENERGY_PRINT, 0 },
  {  "enrichment", inp_ENRICHMENT, 0 },
  {  "enrichmentactivation", inp_ENRICHMENT_ACTIVATION, 0 },
  {  "eof", inp_EOF, 0 },
  {  "eos", inp_EOS, eosSuboptions },
  {  "eoscompaction", inp_EOS_COMPACTION, 0 },
  {  "eosshear", inp_EOS_SHEAR, eosShearSuboptions },
  {  "epjoint", inp_EPJOINT, epjointSuboptions },
  {  "equation", inp_EQUATION, 0 },
  {  "eulerianboundary", inp_EULERIAN_BOUNDARY, 0 },
  {  "eulerianinflatormixture", inp_EULERIAN_INFLATOR_MIXTURE, 0},
  {  "eulerianinflatorproperty", inp_EULERIAN_INFLATOR_PROPERTY, eulerianInflatorPropertySuboptions },
  {  "eulerianmeshmotion", inp_EULERIAN_MESH_MOTION, 0 },
  {  "euleriansection", inp_EULERIAN_SECTION, 0 },
  {  "expansion", inp_EXPANSION, 0 },
  {  "extremeelementvalue", inp_EXTREME_ELEMENT_VALUE, 0 },
  {  "extremenodevalue", inp_EXTREME_NODE_VALUE, 0 },
  {  "extremevalue", inp_EXTREME_VALUE, extremeValueSuboptions },
  {  "fabric", inp_FABRIC, fabricSuboptions },
  {  "failstrain", inp_FAIL_STRAIN, 0 },
  {  "failstress", inp_FAILSTRESS, 0 },
  {  "failure", inp_FAILURE, 0 },
  {  "failureratios", inp_FAILURE_RATIOS, 0 },
  {  "fastener", inp_FASTENER, 0 },
  {  "fastenerfailure", inp_FASTENER_FAILURE, 0},
  {  "fastenerproperty", inp_FASTENER_PROPERTY, fastenerPropertySuboptions},
  {  "field", inp_FIELD, 0 },
  {  "fileformat", inp_FILE_FORMAT, 0 },
  {  "fileoutput", inp_FILE_OUTPUT, fileOutputSuboptions },
  {  "film", inp_FILM, 0 },
  {  "filmproperty", inp_FILM_PROPERTY, 0 },
  {  "filter", inp_FILTER, 0 },
  {  "fixedmassscaling", inp_FIXED_MASS_SCALING, 0 },
  {  "flow", inp_FLOW, 0 },
  {  "fluidbehavior", inp_FLUID_BEHAVIOR, fluidBehaviorSuboptions },
  {  "fluidboundary", inp_FLUID_BOUNDARY, 0 },
  {  "fluidbulkmodulus", inp_FLUID_BULK_MODULUS, 0 },
  {  "fluidcavity", inp_FLUID_CAVITY, 0 },
  {  "fluiddensity", inp_FLUID_DENSITY, 0 },
  {  "fluidexchange", inp_FLUID_EXCHANGE, 0 },
  {  "fluidexchangeactivation", inp_FLUID_EXCHANGE_ACTIVATION, 0 },
  {  "fluidexchangeinteraction", inp_FLUID_EXCHANGE_INTERACTION, 0 },
  {  "fluidexchangeproperty", inp_FLUID_EXCHANGE_PROPERTY, 0 },
  {  "fluidexpansion", inp_FLUID_EXPANSION, 0 },
  {  "fluidflux", inp_FLUID_FLUX, 0 },
  {  "fluidinflator", inp_FLUID_INFLATOR, 0},
  {  "fluidinflatoractivation", inp_FLUID_INFLATOR_ACTIVATION, 0},
  {  "fluidinflatorinteraction", inp_FLUID_INFLATOR_INTERACTION, 0},
  {  "fluidinflatormixture", inp_FLUID_INFLATOR_MIXTURE, 0},
  {  "fluidinflatorproperty", inp_FLUID_INFLATOR_PROPERTY, fluidInflatorPropertySuboptions },
  {  "fluidleakoff", inp_FLUID_LEAKOFF, 0 },
  {  "fluidlink", inp_FLUID_LINK, 0 },
  {  "fluidproperty", inp_FLUID_PROPERTY, fluidPropertySuboptions },
  {  "foam", inp_FOAM, foamSuboptions },
  {  "foamhardening", inp_FOAM_HARDENING, 0 },
  {  "foundation", inp_FOUNDATION, 0 },
  {  "fracturecriterion", inp_FRACTURE_CRITERION, 0 },
  {  "framesection", inp_FRAME_SECTION, frameSectionSuboptions },
  {  "frequency", inp_FREQUENCY, 0 },
  {  "friction", inp_FRICTION, frictionSuboptions },
  {  "gap", inp_GAP, gapSuboptions },
  {  "gapconductance", inp_GAP_CONDUCTANCE, 0 },
  {  "gapelectricalconductance", inp_GAP_ELECTRICAL_CONDUCTANCE, 0 },
  {  "gapflow", inp_GAP_FLOW, 0 },
  {  "gapheatgeneration", inp_GAP_HEAT_GENERATION, 0 },
  {  "gapradiation", inp_GAP_RADIATION, 0 },
  {  "gasketbehavior", inp_GASKET_BEHAVIOR, gasketBehaviorSuboptions },
  {  "gasketcontactarea", inp_GASKET_CONTACT_AREA, 0 },
  {  "gasketelasticity", inp_GASKET_ELASTICITY, 0 },
  {  "gasketsection", inp_GASKET_SECTION, gasketsectionSuboptions },
  {  "gasketthicknessbehavior", inp_GASKET_THICKNESS_BEHAVIOR, 0 },
  {  "gasspecificheat", inp_GAS_SPECIFIC_HEAT, 0 },
  {  "gel", inp_GEL, 0 },
  {  "geostatic", inp_GEOSTATIC, 0 },
  {  "globaldamping", inp_GLOBAL_DAMPING, 0 },
  {  "heading", inp_HEADING, 0 },
  {  "heatcap", inp_HEAT_CAP, 0 },
  {  "heatgeneration", inp_HEAT_GENERATION, 0 },
  {  "heattransfer", inp_HEAT_TRANSFER, 0 },
  {  "hourglassstiffness", inp_HOURGLASS_STIFFNESS, 0 },
  {  "hyperelastic", inp_HYPERELASTIC, hyperelasticSuboptions },
  {  "hyperfoam", inp_HYPERFOAM, hyperfoamSuboptions },
  {  "hypoelastic", inp_HYPOELASTIC, 0 },
  {  "hysteresis", inp_HYSTERESIS, 0 },
  {  "impedance", inp_IMPEDANCE, 0 },
  {  "impedanceproperty", inp_IMPEDANCE_PROPERTY, 0 },
  {  "imperfection", inp_IMPERFECTION, 0 },
  {  "import", inp_IMPORT, importSuboptions },
  {  "importcontrols", inp_IMPORT_CONTROLS, 0 },
  {  "importelset", inp_IMPORT_ELSET, 0 },
  {  "importnset", inp_IMPORT_NSET, 0 },
  {  "incidentwave", inp_INCIDENT_WAVE, incidentWaveSuboptions },
  {  "incidentwaveinteraction", inp_INCIDENT_WAVE_INTERACTION, incidentWaveInteractionSuboptions },
  {  "incidentwaveinteractionproperty", inp_INCIDENT_WAVE_INTERACTION_PROPERTY, incidentWaveInteractionPropertySuboptions },
  {  "incidentwaveproperty", inp_INCIDENT_WAVE_PROPERTY, incidentWavePropertySuboptions },
  {  "incidentwavereflection", inp_INCIDENT_WAVE_REFLECTION, 0 },
  {  "incidentwavefluidproperty", inp_INCIDENT_WAVE_FLUID_PROPERTY, 0 },
  {  "include", inp_INCLUDE, 0 },
  {  "incrementationoutput", inp_INCREMENTATION_OUTPUT, 0 },
  {  "inelasticheatfraction", inp_INELASTIC_HEAT_FRACTION, 0 },
  {  "inertiarelief", inp_INERTIA_RELIEF, 0 },
  {  "initialconditions", inp_INITIAL_CONDITIONS, 0 },
  {  "instance", inp_INSTANCE, instanceSuboptions },
  {  "integratedoutput", inp_INTEGRATED_OUTPUT, 0 },
  {  "integratedoutputsection", inp_INTEGRATED_OUTPUT_SECTION, 0 },
  {  "interface", inp_INTERFACE, interfaceSuboptions },
  {  "its", inp_ITS, itsSuboptions },
  {  "joint", inp_JOINT, jointSuboptions },
  {  "jointedmaterial", inp_JOINTED_MATERIAL, 0 },
  {  "jointelasticity", inp_JOINT_ELASTICITY, 0 },
  {  "jointplasticity", inp_JOINT_PLASTICITY, 0 },
  {  "jouleheatfraction", inp_JOULE_HEAT_FRACTION, 0 },
  {  "kappa", inp_KAPPA, 0 },
  {  "kinematic", inp_KINEMATIC, 0 },
  {  "kinematiccoupling", inp_KINEMATIC_COUPLING, 0 },
  {  "latentheat", inp_LATENT_HEAT, 0 },
  {  "license", inp_LICENSE, 0 },
  {  "loadcase", inp_LOAD_CASE, loadCaseSuboptions },
  {  "loadingdata", inp_LOADING_DATA, loadingdataSuboptions },
  {  "lowdensityfoam", inp_LOW_DENSITY_FOAM, lowdensityfoamSuboptions },
  {  "magneticpermeability", inp_MAGNETIC_PERMEABILITY, 0 },
  {  "mapsolution", inp_MAP_SOLUTION, 0 },
  {  "mass", inp_MASS, 0 },
  {  "massadjust", inp_MASS_ADJUST, 0 },
  {  "massdiffusion", inp_MASS_DIFFUSION, 0 },
  {  "massflowrate", inp_MASS_FLOW_RATE, 0 },
  {  "material", inp_MATERIAL, materialSuboptions },
  {  "matrix", inp_MATRIX, 0 },
  {  "matrixassemble", inp_MATRIX_ASSEMBLE, 0 },
  {  "matrixgenerate", inp_MATRIX_GENERATE, matrixGenerateSuboptions },
  {  "matrixinput", inp_MATRIX_INPUT, 0 },
  {  "matrixoutput", inp_MATRIX_OUTPUT, 0 },
  {  "mediatransport", inp_MEDIA_TRANSPORT, 0 },
  {  "membranesection", inp_MEMBRANE_SECTION, membraneSectionSuboptions },
  {  "modaldamping", inp_MODAL_DAMPING, 0 },
  {  "modaldynamic", inp_MODAL_DYNAMIC, 0 },
  {  "modalfile", inp_MODAL_FILE, 0 },
  {  "modaloutput", inp_MODAL_OUTPUT, 0 },
  {  "modalprint", inp_MODAL_PRINT, 0 },
  {  "modelchange", inp_MODEL_CHANGE, 0 },
  {  "model", inp_MODEL, modelSuboptions },
  {  "mohrcoulomb", inp_MOHR_COULOMB, mohrCoulombsuboptions },
  {  "mohrcoulombhardening", inp_MOHR_COULOMB_HARDENING, 0 },
  {  "moistureswelling", inp_MOISTURE_SWELLING, moistureSwellingsuboptions },
  {  "molecularweight", inp_MOLECULAR_WEIGHT, 0 },
  {  "momentumequationsolver", inp_MOMENTUM_EQUATION_SOLVER, 0 },
  {  "monitor", inp_MONITOR, 0 },
  {  "motion", inp_MOTION, 0 },
  {  "mpc", inp_MPC, 0 },
  {  "mullinseffect", inp_MULLINS_EFFECT, mullinsEffectSuboptions },
  {  "m1", inp_M1, 0 },
  {  "m2", inp_M2, 0 },
  {  "ncopy", inp_NCOPY, 0 },
  {  "nfill", inp_NFILL, 0 },
  {  "ngen", inp_NGEN, 0 },
  {  "nmap", inp_NMAP, 0 },
  {  "nocompression", inp_NO_COMPRESSION, 0 },
  {  "nodalenergyrate", inp_NODAL_ENERGYRATE, 0 },
  {  "nodalthickness", inp_NODAL_THICKNESS, 0 },
  {  "node", inp_NODE, 0 },
  {  "nodefile", inp_NODE_FILE, 0 },
  {  "nodeoutput", inp_NODE_OUTPUT, 0 },
  {  "nodeprint", inp_NODE_PRINT, 0 },
  {  "noderesponse", inp_NODE_RESPONSE, 0 },
  {  "nonstructuralmass", inp_NONSTRUCTURAL_MASS, 0 },
  {  "normal", inp_NORMAL, 0 },
  {  "notension", inp_NO_TENSION, 0 },
  {  "nset", inp_NSET, 0 },
  {  "orientation", inp_ORIENTATION, orientationSuboptions },
  {  "ornl", inp_ORNL, 0 },
  {  "output", inp_OUTPUT, outputSuboptions },
  {  "parameter", inp_PARAMETER, 0 },
  {  "parameterdependence", inp_PARAMETER_DEPENDENCE, 0 },
  {  "parametershapevariation", inp_PARAMETER_SHAPE_VARIATION, 0 },
  {  "part", inp_PART , partSuboptions },
  {  "periodic", inp_PERIODIC, 0 },
  {  "periodicmedia", inp_PERIODIC_MEDIA, 0 },
  {  "permeability", inp_PERMEABILITY, 0 },
  {  "physicalconstants", inp_PHYSICAL_CONSTANTS, 0 },
  {  "piezoelectric", inp_PIEZOELECTRIC, 0 },
  {  "pipe-soilinteraction", inp_PIPE_SOIL_INTERACTION, pipeSoilInteractionSuboptions },
  {  "pipe-soilstiffness", inp_PIPE_SOIL_STIFFNESS, 0 },
  {  "planartestdata", inp_PLANAR_TEST_DATA, 0 },
  {  "plastic", inp_PLASTIC, plasticSuboptions },
  {  "plasticaxial", inp_PLASTIC_AXIAL, 0 },
  {  "plasticm1", inp_PLASTIC_M1, 0 },
  {  "plasticm2", inp_PLASTIC_M2, 0 },
  {  "plastictorque", inp_PLASTIC_TORQUE, 0 },
  {  "porousbulkmoduli", inp_POROUS_BULK_MODULI, 0 },
  {  "porouselastic", inp_POROUS_ELASTIC, 0 },
  {  "porousfailurecriteria", inp_POROUS_FAILURE_CRITERIA, 0 },
  {  "porousmetalplasticity", inp_POROUS_METAL_PLASTICITY, porousMetalPlasticitySuboptions },
  {  "postoutput", inp_POST_OUTPUT, postOutputSuboptions },
  {  "potential", inp_POTENTIAL, 0 },
  {  "pre-tensionsection", inp_PRETENSION_SECTION, 0 },
  {  "preprint", inp_PREPRINT, 0 },
  {  "pressureequationsolver", inp_PRESSURE_EQUATION_SOLVER, 0 },
  {  "pressurepenetration", inp_PRESSURE_PENETRATION, 0 },
  {  "pressurestress", inp_PRESSURE_STRESS, 0 },
  {  "prestresshold", inp_PRESTRESS_HOLD, 0 },
  {  "print", inp_PRINT, 0 },
  {  "psd-definition", inp_PSD_DEFINITION, 0 },
  {  "radiate", inp_RADIATE, 0 },
  {  "radiationfile", inp_RADIATION_FILE, 0 },
  {  "radiationoutput", inp_RADIATION_OUTPUT, 0 },
  {  "radiationprint", inp_RADIATION_PRINT, 0 },
  {  "radiationsymmetry", inp_RADIATION_SYMMETRY, radiationSymmetrySuboptions },
  {  "radiationviewfactor", inp_RADIATION_VIEWFACTOR, 0 },
  {  "randomresponse", inp_RANDOM_RESPONSE, 0 },
  {  "ratedependent", inp_RATE_DEPENDENT, 0 },
  {  "ratios", inp_RATIOS, 0 },
  {  "reactionrate", inp_REACTION_RATE, 0 },
  {  "rebar", inp_REBAR, 0 },
  {  "rebarlayer", inp_REBAR_LAYER, 0 },
  {  "reflection", inp_REFLECTION, 0 },
  {  "release", inp_RELEASE, 0 },
  {  "remeshtrigger", inp_REMESH_TRIGGER, 0 },
  {  "responsespectrum", inp_RESPONSE_SPECTRUM, 0 },
  {  "restart", inp_RESTART, 0 },
  {  "retainedeigenmodes", inp_RETAINED_EIGENMODES, 0 },
  {  "retainednodaldofs", inp_RETAINED_NODAL_DOFS, 0 },
  {  "rigidbody", inp_RIGID_BODY, rigidBodySuboptions },
  {  "rigidsurface", inp_RIGID_SURFACE, 0 },
  {  "rotaryinertia", inp_ROTARY_INERTIA, 0 },
  {  "sectioncontrols", inp_SECTION_CONTROLS, 0 },
  {  "sectionfile", inp_SECTION_FILE, 0 },
  {  "sectionorigin", inp_SECTION_ORIGIN, 0 },
  {  "sectionpoints", inp_SECTION_POINTS, 0 },
  {  "sectionprint", inp_SECTION_PRINT, 0 },
  {  "selectcyclicsymmetrymodes", inp_SELECT_CYCLIC_SYMMETRY_MODES, 0 },
  {  "selecteigenmodes", inp_SELECT_EIGENMODES, 0 },
  {  "sfilm", inp_SFILM, 0 },
  {  "sflow", inp_SFLOW, 0 },
  {  "shear", inp_SHEAR, shearSuboptions },
  {  "shearcenter", inp_SHEAR_CENTER, 0 },
  {  "shearfailure", inp_SHEAR_FAILURE, 0 },
  {  "shearretention", inp_SHEAR_RETENTION, 0 },
  {  "sheartestdata", inp_SHEAR_TEST_DATA, 0 },
  {  "shellgeneralsection", inp_SHELL_GENERAL_SECTION, shellGeneralSectionSuboptions },
  {  "shellsection", inp_SHELL_SECTION, shellSectionSuboptions },
  {  "shelltosolidcoupling", inp_SHELL_TO_SOLID_COUPLING, 0 },
  {  "simpedance", inp_SIMPEDANCE, 0 },
  {  "simplesheartestdata", inp_SIMPLE_SHEAR_TEST_DATA, 0 },
  {  "slideline", inp_SLIDE_LINE, 0 },
  {  "sload", inp_SLOAD, 0 },
  {  "soils", inp_SOILS, 0 },
  {  "solidsection", inp_SOLID_SECTION, solidSectionSuboptions },
  {  "solubility", inp_SOLUBILITY, 0 },
  {  "solutiontechnique", inp_SOLUTION_TECHNIQUE, 0 },
  {  "solvercontrols", inp_SOLVER_CONTROLS, 0 },
  {  "sorption", inp_SORPTION, 0 },
  {  "spatialdistribution", inp_SPATIAL_DISTRIBUTION, 0 },
  {  "specificheat", inp_SPECIFIC_HEAT, 0 },
  {  "spectrum", inp_SPECTRUM, 0 },
  {  "spotweld", inp_SPOT_WELD, 0 },
  {  "spotweldinteraction", inp_SPOT_WELD_INTERACTION, spotWeldInteractionSuboptions },
  {  "spotweldproperty", inp_SPOT_WELD_PROPERTY, 0 },
  {  "spring", inp_SPRING, 0 },
  {  "sradiate", inp_SRADIATE, 0 },
  {  "static", inp_STATIC, 0 },
  {  "steadystatecriteria", inp_STEADY_STATE_CRITERIA, 0 },
  {  "steadystatedetection", inp_STEADY_STATE_DETECTION, 0 },
  {  "steadystatedynamics", inp_STEADY_STATE_DYNAMICS, 0 },
  {  "steadystatetransport", inp_STEADY_STATE_TRANSPORT, 0 },
  {  "step", inp_STEP, stepSuboptions },
  {  "subcycling", inp_SUBCYCLING, 0 },
  {  "submodel", inp_SUBMODEL, 0 },
  {  "substructurecopy", inp_SUBSTRUCTURECOPY, 0 },
  {  "substructuredelete", inp_SUBSTRUCTUREDELETE, 0 },
  {  "substructuredirectory", inp_SUBSTRUCTUREDIRECTORY, 0 },
  {  "substructuregenerate", inp_SUBSTRUCTUREGENERATE, substructureGenerateSuboptions },
  {  "substructureloadcase", inp_SUBSTRUCTURELOADCASE, sloadCaseSuboptions },
  {  "substructurematrixoutput", inp_SUBSTRUCTUREMATRIXOUTPUT, 0 },
  {  "substructurepath", inp_SUBSTRUCTUREPATH, 0 },
  {  "substructureproperty", inp_SUBSTRUCTUREPROPERTY, substructurePropertySuboptions },
  {  "surface", inp_SURFACE, 0 },
  {  "surfacebehavior", inp_SURFACE_BEHAVIOR, 0 },
  {  "surfaceflaw", inp_SURFACE_FLAW, 0 },
  {  "surfaceinteraction", inp_SURFACE_INTERACTION, surfaceInteractionSuboptions },
  {  "surfacepermeability", inp_SURFACE_PERMEABILITY, 0 },
  {  "surfaceproperty", inp_SURFACE_PROPERTY, surfacePropertySuboptions },
  {  "surfacepropertyassignment", inp_SURFACE_PROPERTY_ASSIGNMENT, 0 },
  {  "surfaceoutput", inp_SURFACE_OUTPUT, 0 },
  {  "surfacesection", inp_SURFACE_SECTION, surfaceSectionSuboptions },
  {  "surfacesmoothing", inp_SURFACE_SMOOTHING, 0 },
  {  "swelling", inp_SWELLING, swellingSuboptions },
  {  "symmetricmodelgeneration", inp_SYMMETRIC_MODEL_GENERATION, 0 },
  {  "symmetricresultstransfer", inp_SYMMETRIC_RESULTS_TRANSFER, 0 },
  {  "system", inp_SYSTEM, 0 },
  {  "temperature", inp_TEMPERATURE, 0 },
  {  "tensilefailure", inp_TENSILE_FAILURE, 0 },
  {  "tensioncutoff", inp_TENSION_CUTOFF, 0 },
  {  "tensionstiffening", inp_TENSION_STIFFENING, 0 },
  {  "thermalexpansion", inp_THERMAL_EXPANSION, 0 },
  {  "tie", inp_TIE, 0 },
  {  "timepoints", inp_TIME_POINTS, 0},
  {  "torque", inp_TORQUE, 0 },
  {  "torqueprint", inp_TORQUE_PRINT, 0 },
  {  "tracerparticle", inp_TRACER_PARTICLE, 0 },
  {  "transform", inp_TRANSFORM, 0 },
  {  "transportvelocity", inp_TRANSPORT_VELOCITY, 0 },
  {  "transverseshearstiffness", inp_TRANSVERSE_SHEAR_STIFFNESS, 0 },
  {  "transportequationsolver", inp_TRANSPORT_EQUATION_SOLVER, 0 },
  {  "triaxialtestdata", inp_TRIAXIAL_TEST_DATA, 0 },
  {  "trs", inp_TRS, 0 },
  {  "turbulencemodel", inp_TURBULENCE_MODEL, 0 },
  {  "uelproperty", inp_UEL_PROPERTY, 0 },
  {  "undexchargeproperty", inp_UNDEX_CHARGE_PROPERTY, 0 },
  {  "uniaxial", inp_UNIAXIAL, uniaxialSuboptions },
  {  "uniaxialtestdata", inp_UNIAXIAL_TEST_DATA, 0 },
  {  "unloadingdata", inp_UNLOADING_DATA, 0 },
  {  "userdefinedfield", inp_USER_DEFINED_FIELD, 0 },
  {  "userelement", inp_USER_ELEMENT, userElementSuboptions },
  {  "usermaterial", inp_USER_MATERIAL, 0 },
  {  "useroutputvariables", inp_USER_OUTPUT_VARIABLES, 0 },
  {  "variablemassscaling", inp_VARIABLE_MASS_SCALING, 0 },
  {  "viewfactoroutput", inp_VIEWFACTOR_OUTPUT, 0 },
  {  "visco", inp_VISCO, 0 },
  {  "viscoelastic", inp_VISCOELASTIC, viscoelasticSuboptions },
  {  "viscosity", inp_VISCOSITY, viscositySuboptions },
  {  "viscous", inp_VISCOUS, viscousSuboptions },
  {  "voidnucleation", inp_VOID_NUCLEATION, 0 },
  {  "volumetrictestdata", inp_VOLUMETRIC_TEST_DATA, 0 },
  {  "wave", inp_WAVE, 0 },
  {  "wind", inp_WIND, 0 },
  {  0, inp_UNDEFINED_KEYWORD, 0 }
};

#endif
