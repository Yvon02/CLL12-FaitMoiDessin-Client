#include "faitmoidessin.h"
#include "ui_faitmoidessin.h"

FaitMoiDessin::FaitMoiDessin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::FaitMoiDessin)
{
    ui->setupUi(this);
}

FaitMoiDessin::~FaitMoiDessin()
{
    delete ui;
}
