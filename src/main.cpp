#include "pch.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QPushButton button("push me");
    button.show();
    return app.exec();

    return 0;
}
