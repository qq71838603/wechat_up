#ifndef BUTTON_H
#define BUTTON_H

#include <QToolButton>

class Button : public QToolButton
{
    Q_OBJECT
public:
    explicit Button(QWidget *parent = 0);
public slots:
    void  button_clicked();
};

#endif // BUTTON_H
