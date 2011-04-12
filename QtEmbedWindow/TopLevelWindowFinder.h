#ifndef TopLevelWindowFinder_H_
#define TopLevelWindowFinder_H_

#include <windows.h>

class TopLevelWindowFinder {
public:
	TopLevelWindowFinder();

	HWND findWindow(const char* partialTitle);

private:
	const char* m_partialTitle;
	HWND m_result;
	
	BOOL enumWindowsCallback(HWND hwnd);
	static BOOL CALLBACK enumWindowsProc(HWND hwnd, LPARAM lParam);
};

#endif TopLevelWindowFinder_H_
