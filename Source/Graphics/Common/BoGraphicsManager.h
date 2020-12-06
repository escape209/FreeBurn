#ifndef BOGRAPHICSMANAGER_H
#define BOGRAPHICSMANAGER_H

#include <rwcore.h>

#include "../../../Shared/Graphical/Common/Camera/GtViewport.h"

enum EBoViewportSelection {
	eBoViewportMain = 0,
	eBoViewportPlayer1 = 1,
	eBoViewportPlayer2 = 2
};
enum EBoVideoMode {
	eBoVideoModeNTSC = 0, 
	eBoVideoModeHDTV = 1, 
	eBoVideoModePAL = 2, 
	eBoVideoModeMax = 3
};
enum EBoFullScreenPassBlendMode {
	eBoFSPBM_Normal = 0, 
	eBoFSPBM_Additive = 1, 
	eBoFSPBM_AdditiveDestAlpha = 2, 
	eBoFSPBM_Subtractive = 3, 
	eBoFSPBM_Max = 4
};

class CBoViewport : CGtViewport {
public:
	RwCamera* mpRwCamera;
};

class CBoGraphicsManagerBase {
public:
	RwInt32 mnScreenWidth;
	RwInt32 mnScreenHeight;
	CBoViewport mMainViewport;

	void CloseViewport();
	void Downsample(
		RwUInt32 luFrameBufferAddress, 
		RwUInt32 luFrameBufferWidth, 
		RwUInt32 luWorkspaceAddress, 
		RwUInt32 luWorkspaceWidth, 
		RwInt32 lnTopLeftX, 
		RwInt32 lnTopLeftY, 
		RwInt32 lnSizeX, 
		RwInt32 lnSizeY
	);
	void DrawBootLoadingScreen(RwReal lrProgress);
	virtual void OpenViewport(EBoViewportSelection);
};

#endif // !#define BOGRAPHICSMANAGER_H