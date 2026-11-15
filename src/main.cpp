#include "pch.h"
#include "main_window.h"
#include "user_data.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    UserData* userData = new UserData{};
    UserSettings* userSettings = new UserSettings{};

    MainWindow mainWindow(*userData, *userSettings);
    mainWindow.show();

    return app.exec();
}
