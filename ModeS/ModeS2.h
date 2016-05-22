#pragma once
#include "stdafx.h"
#include <vector>
#include <string>
#include <regex>
#include <future>
#include <thread>
#include <EuroScopePlugIn.h>
#include "version.h"
#include "HttpHelper.h"
#include "ModeSDisplay.h"
#include "Helpers.h"
#include "ModeSCodes.h"

using namespace std;
using namespace EuroScopePlugIn;

class CModeS :
	public EuroScopePlugIn::CPlugIn
{
public:
	CModeS();
	~CModeS();

	const int TAG_ITEM_ISMODES = 501;
	const int TAG_ITEM_MODESHDG = 502;
	const int TAG_ITEM_MODESROLLAGL = 503;
	const int TAG_ITEM_MODESREPGS = 504;

	const int TAG_FUNC_ASSIGNMODES = 869;
	const int TAG_FUNC_ASSIGNMODEAS = 870;

	future<string> fUpdateString;

	void OnGetTagItem(CFlightPlan FlightPlan, EuroScopePlugIn::CRadarTarget RadarTarget,
		int ItemCode,
		int TagData,
		char sItemString[16],
		int * pColorCode,
		COLORREF * pRGB,
		double * pFontSize);

	void OnFunctionCall(int FunctionId,
		const char * sItemString,
		POINT Pt,
		RECT Area);

	void OnRadarTargetPositionUpdate(CRadarTarget RadarTarget);
	void OnTimer(int Counter);
	CRadarScreen * OnRadarScreenCreated(const char * sDisplayName, 
										bool NeedRadarContent, 
										bool GeoReferenced, 
										bool CanBeSaved, 
										bool CanBeCreated);
};
