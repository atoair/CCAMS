#include "stdafx.h"
#include "HttpHelper.h"
#include "version.h"

std::string LoadUpdateString(const char * url)
{
	const std::string AGENT = "EuroScopeModeS/" + std::string { PLUGIN_VERSION };
	HINTERNET connect = InternetOpen(AGENT.c_str(), INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
	if (!connect)
		throw(std::exception { "Connection Failed. Error: " + GetLastError() });

	HINTERNET OpenAddress = InternetOpenUrl(connect, url, NULL, 0, INTERNET_FLAG_PRAGMA_NOCACHE, 0);
	if (!OpenAddress)
	{
		InternetCloseHandle(connect);
		throw(std::exception { "Failed to open URL. Error: " + GetLastError() });
	}

	char DataReceived[256];
	DWORD NumberOfBytesRead = 0;
	std::string answer {};
	while (InternetReadFile(OpenAddress, DataReceived, 256, &NumberOfBytesRead) && NumberOfBytesRead)
	{
		answer.append(DataReceived, NumberOfBytesRead);
	}

	InternetCloseHandle(OpenAddress);
	InternetCloseHandle(connect);
	return answer;
}
