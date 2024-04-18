
#pragma once

#ifndef ANIMATEDLABEL_H
#define ANIMATEDLABEL_H

 #include <QLabel>
#include <QColor>

class AnimatedLabel : public QLabel
{

  Q_OBJECT
  Q_PROPERTY(QColor color READ color WRITE setColor)

public:
  AnimatedLabel(QWidget *parent = 0);
  void setColor (QColor color){
   setStyleSheet(QString("color: rgb(%1, %2, %3);").arg(color.red()).arg(color.green()).arg(color.blue()));
 }
  QColor color(){
    return Qt::black;
  }
};

Q_DECLARE_METATYPE(AnimatedLabel*)

#endif // ANIMATEDLABEL_H
