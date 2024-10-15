#include <QApplication>

#include "calculator_app.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    CalculatorApp window;
    window.setWindowTitle("Calculator cc_start");
    window.resize(600, 700);
    window.show();

    return app.exec();
}