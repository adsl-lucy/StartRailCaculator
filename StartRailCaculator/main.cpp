#include "./caculator/StarRailMediator.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget* mainFrame = StarRailMediator::instance()->getMainFrame();
    mainFrame->setWindowTitle("StartRailCaculator");
    mainFrame->show();
    return a.exec();
}
