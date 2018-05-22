#include "IllustratorSDK.h"
#include "BleedSuites.h"

// Suite externs
extern "C"
{
	SPBlocksSuite*              sSPBlocks = NULL;
	AIUnicodeStringSuite*       sAIUnicodeString = NULL;
	AIStringFormatUtilsSuite*   sAIStringFormatUtils = NULL;
	AIDocumentSuite*            sAIDocument = NULL;
}

// Import suites
ImportSuite gImportSuites[] = 
{
	kSPBlocksSuite, kSPBlocksSuiteVersion, &sSPBlocks,
	kAIUnicodeStringSuite, kAIUnicodeStringVersion, &sAIUnicodeString,
	kAIStringFormatUtilsSuite, kAIStringFormatUtilsSuiteVersion, &sAIStringFormatUtils,
	kAIDocumentSuite, kAIDocumentSuiteVersion, &sAIDocument,
    nil, 0, nil
};
