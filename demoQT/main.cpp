#include <QApplication>
#include <QMainWindow>
#include "ParamWidget.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QMainWindow mainWindow;
    mainWindow.setWindowTitle("参数调整");

    // 创建参数调整组件
    ParameterWidget *parameterWidget = new ParameterWidget(&mainWindow);
    mainWindow.setCentralWidget(parameterWidget);

    mainWindow.resize(800, 600);
    mainWindow.show();

    return app.exec();
}
