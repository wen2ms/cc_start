#include "calculator_app.h"

#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QInputDialog>

CalculatorApp::CalculatorApp(QWidget* parent)
    : QWidget(parent), sci_calculator_(new ScientificCalculator()) {
    display_ = new QLineEdit(this);
    display_->setReadOnly(true);
    display_->setAlignment(Qt::AlignRight);

    QPushButton* add_button = new QPushButton("+", this);
    QPushButton* subtract_button = new QPushButton("-", this);
    QPushButton* mutiply_button = new QPushButton("*", this);
    QPushButton* divide_button = new QPushButton("/", this);
    QPushButton* power_button = new QPushButton("^", this);
    QPushButton* clear_button = new QPushButton("Clear", this);

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(display_);
    layout->addWidget(add_button);
    layout->addWidget(subtract_button);
    layout->addWidget(mutiply_button);
    layout->addWidget(divide_button);
    layout->addWidget(power_button);
    layout->addWidget(clear_button);

    connect(add_button, &QPushButton::clicked, this, &CalculatorApp::on_add_clicked);
    connect(subtract_button, &QPushButton::clicked, this, &CalculatorApp::on_subtract_clicked);
    connect(mutiply_button, &QPushButton::clicked, this, &CalculatorApp::on_mutiply_clicked);
    connect(divide_button, &QPushButton::clicked, this, &CalculatorApp::on_divide_clicked);
    connect(power_button, &QPushButton::clicked, this, &CalculatorApp::on_power_clicked);
    connect(clear_button, &QPushButton::clicked, display_, &QLineEdit::clear);
}

void CalculatorApp::on_add_clicked() {
    perform_operation(&Calculator::add);
}

void CalculatorApp::on_subtract_clicked() {
    perform_operation(&Calculator::subtract);
}

void CalculatorApp::on_mutiply_clicked() {
    perform_operation(&Calculator::mutiply);
}

void CalculatorApp::on_divide_clicked() {
    try {
        perform_operation(&Calculator::divide);
    } catch (const std::invalid_argument& e) {
        show_error(e.what());
    }
}

void CalculatorApp::on_power_clicked() {
    bool ok_base, ok_exp;
    double base = get_input("Base", ok_base);
    double exponent = get_input("Exponent", ok_exp);

    if (ok_base && ok_exp) {
        double result = sci_calculator_->power(base, exponent);
        display_->setText(QString::number(result));
    }
}

double CalculatorApp::get_input(const QString& prompt, bool& ok) {
    QString input = QInputDialog::getText(this, prompt, prompt + ": ", QLineEdit::Normal, "", &ok);
    return input.toDouble(&ok);
}

void CalculatorApp::perform_operation(double (Calculator::*operation)(double, double) const) {
    bool ok1, ok2;
    double a = get_input("First number", ok1);
    double b = get_input("Second number", ok2);

    if (ok1 && ok2) {
        double result = (sci_calculator_->*operation)(a, b);
        display_->setText(QString::number(result));
    }
}

void CalculatorApp::show_error(const QString& message) {
    QMessageBox::warning(this, "Error", message);
}