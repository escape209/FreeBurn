#include <rwcore.h>

#include "../../../../GameShared/Common/System/GtLocalisation.h"
#include "../../../../GameShared/Common/System/GtUnicode.h"
#include "../../../../GameShared/Common/System/GtFSM.h"
#include "../../../../GameShared/Common/Graphical/2D/Gt2dFont.h"
#include "../../../../GameShared/Common/Core/GtID.h"

extern char * gaLanguageCodePostfix[];

char16_t kaDollarString[]      = u"$";
char16_t kaDollarSpaceString[] = u"$ ";
char16_t kaSpaceDollarString[] = u" $";
char16_t kaEmptyString[]       = u"";

class CBoLanguageManager { 
public:
	void Construct();
	void SetLanguage(EGtLanguage leLanguage);
	bool Prepare();
	EGtLanguage GetSKUHardwareLanguage();
	GtUTF16 * FindString(const char * lpcStringID); const
	void ReleaseStrings();
	bool PrepareInGame();
	void ReleaseInGame();
	void SetNumericSeperators();
	void PrepareDollarStrings();
	void GenerateCrashHoleStringID(GtID lTrackID, RwInt32 lnHole, bool lbEasyHole, char * lacStringID);
	void GenerateTrackStringID(GtID lTrackID, char * lacStringID);

private:
	EGtPrepareState mePrepareState;
	EGtPrepareState meFontsPrepareState;
	CGtHashIDStringArray * mpMainStrings;
    CGt2dFont * mpBigFont;
    CGt2dFont * mpSmallFont;
    CGt2dFont * mpDigitalFont;
    GtUTF16 * mpNoStringString;
    GtUTF16 * mpHeadDollarStringString;
    GtUTF16 * mpTailDollarStringString;
    EGtLanguage meLanguage;
    bool mbIsDollarOnLeft;
	bool mbFileLoaded;
	bool mbIsBigFontLoaded;
	bool mbIsSmallFontLoaded;
};

extern CBoLanguageManager gLanguageManager;