#ifndef odb_EnumMap_h
#define odb_EnumMap_h

// Begin local includes
#include <bdo_types.h>
#include <ptoC_BeamOrientation.h>
#include <ptoC_MaterialOrientation.h>
#include <res_Invariant.h>
#include <dtu_DatumEnums.h>
#include <odb_Enum.h>
#include <udd_Enums.h>
#include <annC_Enums.h>

// End local includes
// Forward declarations
class shp_Shape;


odb_Enum::odb_DataTypeEnum mapTypeEnum(res_DataTypeEnm res);
res_DataTypeEnm unMapTypeEnum(odb_Enum::odb_DataTypeEnum res);

odb_Enum::odb_ResultPositionEnum mapOutputLocEnum(res_OutputPositionEnm res);
res_OutputPositionEnm unMapOutputLocEnum(odb_Enum::odb_ResultPositionEnum res);

odb_Enum::odb_InvariantEnum mapInvarEnum(res_InvariantEnm res);
res_InvariantEnm unMapInvarEnum(odb_Enum::odb_InvariantEnum res);

unsigned int unMapAxisEnum(odb_Enum::odb_AxisEnum axis);
ptoC_MaterialOrientation::axisEnm unMapAxisEnumToOrientationAxis(odb_Enum::odb_AxisEnum axis);
odb_Enum::odb_AxisEnum mapAxisEnumToOrientationAxis(ptoC_MaterialOrientation::axisEnm axis);

unsigned int unMapStackDirectionEnum(odb_Enum::odb_StackDirectionEnum stack);
ptoC_MaterialOrientation::stackDirectionEnm unMapStackDirectionEnumToStackDirection(odb_Enum::odb_StackDirectionEnum stack);
odb_Enum::odb_StackDirectionEnum mapStackDirectionEnumToStackDirection(ptoC_MaterialOrientation::stackDirectionEnm stack);

odb_Enum::odb_OrientationMethodEnum mapOrientationMethodEnum(ptoC_BeamOrientation::methodEnm method);
ptoC_BeamOrientation::methodEnm unMapOrientationMethodEnum(odb_Enum::odb_OrientationMethodEnum method);

dtu_DatumCsysType unMapDatumCsysType(odb_Enum::odb_DatumCsysTypeEnum);

odb_Enum::odb_XYSourceTypeEnm mapSourceTypeEnum( udd_XYSourceTypeEnm udd);
udd_XYSourceTypeEnm unMapSourceTypeEnum(odb_Enum::odb_XYSourceTypeEnm odb);
typedef udd_xySourceTypeEnumConst odb_xySourceTypeEnumConst;

odb_Enum::odb_PartTypeEnum mapPartTypeEnum(bdo_Analysis type);

odb_Enum::odb_DimensionEnum mapDimensionEnum(bdo_Space space);

odb_Enum::odb_RelativePositionEnm mapRelativePositionEnum(annC_RelativePositionEnm  res);

odb_Enum::odb_ArrowHeadStyleEnm mapArrowHeadStyleEnm(annC_ArrowHeadStyleEnm  res);

odb_Enum::odb_LineStyleEnm mapLineStyleEnm(annC_LineStyleEnm   res);

odb_Enum::odb_LineThicknessEnm mapLineThicknessEnm(annC_LineThicknessEnm  res);

odb_Enum::odb_BackgroundStyleEnm mapBackgroundStyleEnm(annC_BackgroundStyleEnm  res);

odb_Enum::odb_LineJustificationEnm mapLineJustificationEnm(annC_JustificationEnm  res);

odb_Enum::odb_ElementFaceEnum mapElementFaceEnum(int faceId,
                                                 const shp_Shape *shape);
odb_Enum::odb_ElementFaceEnum mapElementFaceEnum(int  faceId,
                                                 bool shell, bool edge);
int unMapElementFaceEnum(odb_Enum::odb_ElementFaceEnum face);

annC_RelativePositionEnm unMapRelativePositionEnm(odb_Enum::odb_RelativePositionEnm  res);

annC_ArrowHeadStyleEnm unMapArrowHeadStyleEnm(odb_Enum::odb_ArrowHeadStyleEnm  res);

annC_LineStyleEnm unMapLineStyleEnm(odb_Enum::odb_LineStyleEnm  res);

annC_LineThicknessEnm unMapLineThicknessEnm(odb_Enum::odb_LineThicknessEnm  res);

annC_BackgroundStyleEnm unMapBackgroundStyleEnm(odb_Enum::odb_BackgroundStyleEnm  res);

annC_JustificationEnm unMapLineJustificationEnm(odb_Enum::odb_LineJustificationEnm  res);

odb_Enum::odb_DimensionEnum mapPartSpaceEnm(bdo_Space space);

#endif // odb_EnumMap_h
