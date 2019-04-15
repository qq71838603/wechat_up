#include "button.h"
#include <QKeyEvent>
#include <QApplication>

Button::Button(QWidget* parent):QToolButton(parent)
{
    connect(this, SIGNAL(clicked(bool)),this, SLOT(button_clicked()));
}

void Button::button_clicked()
{
    QString ch = this->text();
    QKeyEvent *key = NULL;
    if(ch.isEmpty())
    {
         key = new QKeyEvent(QKeyEvent::KeyPress,Qt::Key_Space,Qt::NoModifier, "");
    }else if(ch == "<-")
    {
         key = new QKeyEvent(QKeyEvent::KeyPress,Qt::Key_Backspace,Qt::NoModifier, "");
    }else if(ch == "enter")
    {
         key = new QKeyEvent(QKeyEvent::KeyPress,Qt::Key_Enter,Qt::NoModifier, "");
    }else{
         key = new QKeyEvent(QKeyEvent::KeyPress,ch.at(0).toLatin1(),Qt::NoModifier, ch);
    }
    QApplication::postEvent(QApplication::focusWidget(),key);
}
