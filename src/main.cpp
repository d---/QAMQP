#include <stdio.h>

#include <QtCore/QCoreApplication>
#include "test.h"

void myMessageOutput(QtMsgType type, const char *msg) {
	switch (type) {
	case QtDebugMsg:
		fprintf(stderr, "INFO: %s\n", msg);
		break;
	case QtWarningMsg:
		fprintf(stderr, "WARN: %s\n", msg);
		break;
	case QtCriticalMsg:
		fprintf(stderr, "ERROR: %s\n", msg);
		break;
	case QtFatalMsg:
		fprintf(stderr, "FATAL: %s\n", msg);
		abort();
	default:
		break;
	}
}

int main(int argc, char *argv[]) {
	qInstallMsgHandler(myMessageOutput);
	QCoreApplication a(argc, argv);	
	Test test;
	return a.exec();
}