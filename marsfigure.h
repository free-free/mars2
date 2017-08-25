#ifndef MARSFIGURE_H
#define MARSFIGURE_H

#include <QWidget>
#include <QLabel>
#include "marstypes.h"

using namespace std;

class QAction;
class QToolBar;
class QGridLayout;
class QFile;
class QCustomPlot;
class QColor;
class QComboBox;
class QVBoxLayout;
class MarsPlot;
class QCPGraph;
class QCPScatterStyle;

class MarsFigure : public QWidget
{
    Q_OBJECT
public:
    explicit MarsFigure(QWidget *parent = 0);
    ~MarsFigure();
    MarsError  errorInstance(QString msg, MarsErrorLevel level);


signals:
    void error(MarsError error);
    void plotStarted();
    void plotStopped();
    void getImportFileName(const QString &fileName);
    void getExportFileName(const QString &fileName);


public slots:
    void showExportDataDialog();
    void showImportDataDialog();
    void saveGraph();
    void changeCurrentPloterOnFocusIn(MarsPlot * focusInObj);
    void displayCurrentXYValue(MarsPlot * obj, double x, double y);

    void readTextFile(QFile * file);
    void writeTextFile(QFile *file);
    void readJSONFile(QFile * file);
    void writeJSONFile(QFile* file);
    void readDatFile(QFile * file);
    void writeDatFile(QFile * file);

    void plot(QList<QByteArray> &data);
    void plot(QByteArray &data);
    void plot(QString & data);
    void plot(double y , int graphId, int plotId);
    void plot(double x, double y, int graphId=0, int plotId=0);
    void plot(QVector<double>& x, QVector<double> &y, int graphId,int plotId);
    void plot(QVector<double> &x, QVector<double> &y, int graphId);
    void plotForceCurve(double y);
    void plotForceCurve(double x, double y);
    void plotDisplacementCurve(double y);
    void plotDisplacementCurve(double x, double y);
    void startPlot();
    void stopPlot();
    void clearCurrentPlot();
    void onPlotActionTriggered();
    void changeCurrentPloter(int index);
    MarsPlot* createPloter();
    MarsPlot* createForceCurveView();
    MarsPlot* createDisplacementCurveView();
    int createGraph(int plotId);
    void deletePloter();
    void deleteCurveViewById(int id);

private:

    void initToolBar();
    void initPlot();
    void arrangePloter();
    QColor graphColor(int graphId);
    QCPScatterStyle graphScatterStyle(int graphId);
    void updateStatusBar();
    void readFile(const QString &fileName);
    void writeFile(const QString &fileName);




private:
    const int MAX_PLOTER_NUMBER = 2;
    const int MIN_PLOTER_NUMBER = 1;
    const int MAX_GRAPH_NUMBER = 5;
    int cvidToPidMap[2];
    int pidToCvidMap[2];
    QVBoxLayout *layout;
    QGridLayout *plotLayout;
    QToolBar *toolBar;
    QAction *exportDataAction;
    QAction *importDataAction;
    QAction *plotAction;
    QAction *savePlotAction;
    QAction *clearPlotAction;
    QLabel *maxNameLabel;
    QLabel *minNameLabel;
    QLabel *maxValLabel;
    QLabel *minValLabel;
    QLabel *avgNameLabel;
    QLabel *avgValLabel;
    QLabel *curXnameLabel;
    QLabel *curXvalLabel;
    QLabel *curYnameLabel;
    QLabel *curYvalLabel;
    QComboBox * ploterNameListBox;
    MarsPlot * currentPloter;
    QList<MarsPlot*> *ploterContainer;
    /*
     * plotState=true (start plot)
     * plotState=false (stop plot)
     */
    bool plotState;

};

#endif // MARSFIGURE_H
