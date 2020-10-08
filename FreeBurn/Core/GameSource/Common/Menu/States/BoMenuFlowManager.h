#pragma once 

#include "Online/BoOnlineCarSelectState.h"
#include "../Interaction/Services/Online/BoNetworkingService.h"
#include "../../../../../GameShared/Common/System/GtFSM.h"
#include "../../../../../GameShared/Common/System/GtTimer.h"

extern CBoMenuFlowManager gMenuFlowManager;

extern GtID kB4MainMenuStateID;

enum class EBoTrackLocale {
	Invalid = -1,
	Detroit = 0,
	Tokyo = 1,
	Rome = 2,
	LosAngeles = 3,
	Montana = 4,
	Florida = 5,
	Switzerland = 6,
	HongKong = 7,
	Count = 8,
	None = 8
};

class CBoMenuFlowManager : public CGtFSM {
public:
	CBoOpenInterfaceService mOpenInterfaceMenuState;

	void Construct(void * lpOwner, CGtStateOffset * lpOffsetTable, CGtTimer * lpStateTimer);
	CGtStateOffset * GetOffsetTable();
	void Update();
};

class CBoLocationSelectState : CGtState {
public:
	bool mbDictionaryPrepared;

	void Action(EGtStateAction leAction);
	void LoadTextureDictionaryForCity(EBoTrackLocale);
};

class CBoMainMenuState : CGtState {
	void Action(EGtStateAction param_1, /*void * param_3,*/ int param_4); // param_2 is not used.
	void InitiateConfirm(GtID lDestinationState);
};

class CBoPreviewEventState : CGtState {

};