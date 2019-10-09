#ifndef SENDPROPERTIES_HPP
#define SENDPROPERTIES_HPP

#include <QDialog>
#include "credentials.hpp"

namespace Ui {
class sendProperties;
}

class sendProperties : public QDialog
{
    Q_OBJECT

public:
    explicit sendProperties(QDialog *parent = nullptr);
    ~sendProperties();
public: signals:
    void cancelPressed();
    void sendPressed(ModemProperties p);
private:
    Ui::sendProperties *ui;
private slots:
    void send();
};

#endif // SENDPROPERTIES_HPP
