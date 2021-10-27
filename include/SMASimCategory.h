#ifndef SMASimCategory_h
#define SMASimCategory_h

// EDITING THIS FILE:
// You must never remove anything from this file.  If an
// enumerant is obsolete, either leave it or replace it with
// a dummy.  Don't reuse the place or remove it outright.
// If you need new enumerants add them at the end of the
// list for either the distributions API or the list for the
// records API.  Count the enumerants to make sure there is
// no overlap.

enum SMASimCategory
{
    SMASimCategoryNull = 0,

    // Categories for Distributions API
    // Do NOT remove or rearrange anything.  See above.
    SMASimCategoryCollection = 1,
    SMASimCategoryDistribution,
    SMASimCategoryDSet,
    SMASimCategoryOCompartment,
    SMASimCategoryCSet,
    SMASimCategoryOCSet,
    SMASimCategoryDrawer,
    SMASimCategoryGrid,
    SMASimCategoryCompartment,
    SMASimCategoryCtation,
    SMASimCategoryOCtation,
    SMASimCategoryODSet,
    SMASimCategoryCMember,
    SMASimCategoryDMember,
    SMASimCategoryTable,

    // Categories for Records API
    // Do NOT remove or rearrange anything.  See above.
    SMASimCategoryDataRecord = 64,
    SMASimCategoryAssociation,
    SMASimCategoryViewFocus,
    SMASimCategoryFTable,

    // Category codes can't be larger then 1024.
    SMASimCategoryLimit = 1024
};

#endif
