#ifndef Win32WindowWrapperWidget_H_
#define Win32WindowWrapperWidget_H_

#include <QtGui/QWidget.h>
#include <windows.h>

class Win32WindowWrapperWidget: public QWidget {
public:
	Win32WindowWrapperWidget(QWidget* parent = 0, Qt::WindowFlags f = 0);

	void setWindow(HWND windowHwnd);

	void unsetWindow();

	//! Does the actual work of resizing the contained window
	void refitInnerWindow();

protected:
	//! Inherited from QWidget
	void resizeEvent(QResizeEvent* );

	void showWindow(HWND hWnd);
	void hideWindow(HWND hWnd);

	HWND m_hwnd;
	HWND m_oldParent;
};

#endif // Win32WindowWrapperWidget_H_
