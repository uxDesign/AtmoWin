/*
* AtmoTools.h: Collection of tool and helperfunction
*
* See the README.txt file for copyright information and how to reach the author(s).
*
* $Id: 106201adb95b5a4c387489394959e2b6ffdeac0b $
*/
#ifndef _AtmoTools_h_
#define _AtmoTools_h_

#include "AtmoDefs.h"

#include "AtmoConfig.h"
#include "AtmoConnection.h"
#include "AtmoDynData.h"

/*
implements some tool functions - for use in different classes - and cases!

to avoid copy and paste code ...
*/
class CAtmoTools
{
private:
	CAtmoTools(void);
	~CAtmoTools(void);
public:
	static EffectMode SwitchEffect(CAtmoDynData *pDynData, EffectMode newEffectMode);
	static ColorOrder SwitchColorOrder(CAtmoDynData *pDynData, ColorOrder newColorOrder);
	static LivePictureSource SwitchLiveSource(CAtmoDynData *pDynData, LivePictureSource newLiveSource);

	static void ShowShutdownColor(CAtmoDynData *pDynData);
	static ATMO_BOOL RecreateConnection(CAtmoDynData *pDynData);

	static pColorPacket WhiteCalibration(CAtmoConfig *pAtmoConfig, pColorPacket ColorPacket);
	static pColorPacket ApplyGamma(CAtmoConfig *pAtmoConfig, pColorPacket ColorPacket);
	static pColorPacket ApplyGamma2(AtmoGammaCorrect Software_gamma_mode, int red, int green, int blue, int global, pColorPacket ColorPacket);
	static pColorPacket ApplyColorK(CAtmoConfig *pAtmoConfig, pColorPacket ColorPacket);
	static pColorPacket Apply3dlut(CAtmoConfig *pAtmoConfig, pColorPacket ColorPacket);
	static pColorPacket Applyinvert(CAtmoConfig *pAtmoConfig, pColorPacket ColorPacket);
	static pColorPacket ApplySens(CAtmoConfig *pAtmoConfig, pColorPacket ColorPacket);
	static int trilinear3dl(CAtmoConfig *pAtmoConfig,int x, int y, int z, int col);
	static int trilinear(CAtmoConfig *pAtmoConfig,int x, int y, int z, int col);

	static int SetChannelAssignment(CAtmoDynData *pDynData, int index);

	static void setDMXout(unsigned char DMXout[CAP_MAX_NUM_ZONES * 3 + 4], int iBuffer, ColorOrder colorOrder, int r, int g, int b);

#if !defined(_ATMO_VLC_PLUGIN_)
	static void SaveBitmap(HDC hdc,HBITMAP hBmp,char *fileName);
#endif
};

#endif
