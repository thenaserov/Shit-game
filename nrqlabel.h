#ifndef NRQLABEL_H
#define NRQLABEL_H

#include <QObject>
#include <QLabel>

class NRQLabel : public QLabel
{
    Q_OBJECT
public:
    NRQLabel(QWidget *parent=nullptr);
    void mousePressEvent(QMouseEvent *event);
    // QWidget interface
protected:

};

#endif // NRQLABEL_H
