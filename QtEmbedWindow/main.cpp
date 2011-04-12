#include <QtGui/QApplication>

#include "Win32WindowWrapperWidget.h"
#include "TopLevelWindowFinder.h"

int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	const char* titleToSearch = "OCU";

	TopLevelWindowFinder windowFinder;
	const HWND windowToEmbed = windowFinder.findWindow(titleToSearch);
	if (windowToEmbed == 0) {
		return EXIT_FAILURE;
	}

	Win32WindowWrapperWidget* pWidget = new Win32WindowWrapperWidget();
	pWidget->setWindow(windowToEmbed);
	pWidget->resize(1024, 768);
	pWidget->show();

	return app.exec();
}
