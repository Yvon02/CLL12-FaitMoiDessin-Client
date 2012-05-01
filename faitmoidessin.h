#ifndef FAITMOIDESSIN_H
#define FAITMOIDESSIN_H

#include <QMainWindow>

namespace Ui {
class FaitMoiDessin;
}

class FaitMoiDessin : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit FaitMoiDessin(QWidget *parent = 0);
    ~FaitMoiDessin();
    
private:
    Ui::FaitMoiDessin *ui;
};

#endif // FAITMOIDESSIN_H
