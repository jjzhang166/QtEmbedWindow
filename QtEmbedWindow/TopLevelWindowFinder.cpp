#include "TopLevelWindowFinder.h"
#include <QtCore/QString>

TopLevelWindowFinder::TopLevelWindowFinder()
: m_result(0)
{
}

HWND TopLevelWindowFinder::findWindow(const char* partialTitle)
{
	m_partialTitle = partialTitle;
	::EnumWindows(enumWindowsProc, (LPARAM)this);
	return m_result;
}

BOOL TopLevelWindowFinder::enumWindowsCallback(HWND hwnd)
{
	char buff[256];
	::GetWindowTextA(hwnd, buff, 256);
	const HWND parent = ::GetParent(hwnd);
	const QString title(buff);

	const bool foundWindow = 
		parent == 0 && title.contains(m_partialTitle);

	if (foundWindow) {
		m_result = hwnd;
		return FALSE;
	}
	
	return TRUE;
}

BOOL CALLBACK TopLevelWindowFinder::enumWindowsProc(HWND hwnd, LPARAM lParam)
{
	TopLevelWindowFinder* instance = (TopLevelWindowFinder*)lParam;
	return instance->enumWindowsCallback(hwnd);
}
