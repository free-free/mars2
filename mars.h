#ifndef MARS_H
#define MARS_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPortInfo>
#include <QRadioButton>
#include "marstypes.h"

class QSerialPort;
class QGridLayout;
class MarsSerialPort;
class SPSettingsDialog;
class MarsCommandLine;
class MarsConsole;
class MarsFigure;
class QTimer;

namespace Ui {
class Mars;
}

class Mars : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mars(QWidget *parent = 0);
    ~Mars();

private:
    /*
     * init signals to the respective slots
     */
    void initConnections();

private slots:

     // connect to aboutAction's triggered signal
    void showAboutSoftwareDialog();
    // error handler
    void handleError(MarsError  error);
    /* serial port operation */
    void onSerialPortClosed();
    void onSerialPortOpened();
    void showSerialPortProtocolDialog();
    void showSerialPortSettingsDialog();
    void onConnectBtnClicked();
    void renderSerialPortData();
    void plotConsoleData(MarsCommandLine * requestedObj);
    void connectSerialPort();
    void disconnectSerialPort();
    void renderForceCurvePlot(int state);
    void renderDisplacementCurvePlot(int state);
    void renderPositionModeForm();
    void renderPermanentLoadModeForm();
    void renderTestModeForm();
    void switchWorkModeOnRButtonToggled(bool checked);

public:
    void renderFigureWindow();
    void bindMenuBar(void);
    void tickTask();

private:
    Ui::Mars *ui;
    MarsSerialPort * serialPort;
    SPSettingsDialog * serialPortSettingsDialog;
    MarsFigure *  figure;
    QGridLayout * mainWidgetLayout;
    QTimer *tick;
    QWidget * pModeFormWidget;
    QWidget * plModeFormWidget;
    QWidget * tModeFormWidget;
    QWidget * lastFormWidget;

    /*
    QGridLayout * pModeFormLayout;
    QGridLayout * plModeFormLayout;
    QGridLayout * tModeFormLayout;
    */
    QList<QRadioButton *>  * modeRadioButtonList;



};

#endif // MAINWINDOW_H
