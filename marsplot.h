#ifndef MARSPLOT_H
#define MARSPLOT_H

#include <QWidget>
#include "qcustomplot.h"

class MarsPlot : public QCustomPlot
{

Q_OBJECT
public:
    explicit MarsPlot(QWidget * parent=0);
    ~MarsPlot();
   void wheelEvent (QWheelEvent *event);
   void focusInEvent(QFocusEvent*event);
   double xMaxRange() const;
   double yMaxRange() const;
   void setTitleText(QString text);
   QString getTitleText(void) const;

protected slots:
   void changeGraphLegendName(QCPLegend *legend, QCPAbstractLegendItem *item);
   void changeAxisLabelName(QCPAxis * axis,QCPAxis::SelectablePart);
   void changeTitle(QMouseEvent * event);
   void onMouseMove(QMouseEvent * event);

signals:
   void focusIn(MarsPlot * focusInObj);
   void mouseMoveOn(MarsPlot * obj, double x, double y);

private:
   QString titleText;
   double xMaxRangeValue;
   double yMaxRangeValue;
   QCPTextElement *title;

public:
   double yMax;
   double yMin;
   double yAvg;
   double ySum;
};

#endif // MARSPLOT_H
