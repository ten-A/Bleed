#ifndef __BleedSuites_H__
#define __BleedSuites_H__

#include "IllustratorSDK.h"
#include "Suites.hpp"
#include "AIStringFormatUtils.h"
#include "AIDocument.h"

extern "C"  SPBlocksSuite*              sSPBlocks;
extern "C"  AIUnicodeStringSuite*       sAIUnicodeString;
extern "C"  AIStringFormatUtilsSuite*   sAIStringFormatUtils;
extern "C"  AIDocumentSuite*            sAIDocument;

#endif
