#include "MainWindow.h"
#include <QApplication>

int main(int argc, char **argv)
{
    // Every Qt GUI needs a QApplication.
    QApplication app(argc, argv);

    app.setOrganizationName("BluePanel");
    app.setOrganizationDomain("BluePanel.org");
    app.setApplicationName("Laguna Chat");

    app.setWindowIcon(QIcon(":/internet-chat-2.png"));

    // This is your MainWindow that you created with Designer
    // Declare it and show it.
    MainWindow mainWindow;
    mainWindow.show();



    // This will not return until the last window is closed.
    // This runs the GUI's event loop handling painting and
    // user input and stuff like that.
    return app.exec();
}
