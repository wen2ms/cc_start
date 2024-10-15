#ifndef CALCULATOR_APP_H
#define CALCULATOR_APP_H

#include <QWidget>

#include "scientific_calculator.h"

class QLineEdit;

class CalculatorApp : public QWidget {
    Q_OBJECT

  public:
    CalculatorApp(QWidget* parent = nullptr);

  private slots:
    void on_add_clicked();
    void on_subtract_clicked();
    void on_mutiply_clicked();
    void on_divide_clicked();
    void on_power_clicked();

  private:
    double get_input(const QString& prompt, bool& ok);
    void perform_operation(double (Calculator::*operation)(double, double) const);
    void show_error(const QString& err_message);

    ScientificCalculator* sci_calculator_;
    QLineEdit* display_;
};

#endif  // CALCULATOR_APP_H