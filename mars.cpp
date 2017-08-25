/************************************************************************
 * CopyRights (C): Thogo tech all rights reserved!
 *
 * @file: mars.cpp
 * @description: this file contains the Mars class definition
 * @version: 0.1
 * @author: infinit.ft
 * @date: 2017/02/07
 * @update_at: 2017/03/21
 *
 *
 */

#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QAction>
#include <QDebug>
#include <QGridLayout>
#include <QTimer>
#include <QDataStream>
#include <QMessageBox>
#include <QErrorMessage>

#include "mars.h"
#include "ui_mars.h"
#include "spsettingsdialog.h"
#include "marsserialport.h"
#include "marscommandline.h"
#include "marsconsole.h"
#include "marsfigure.h"
#include "marsbyteslistbuffer.h"
#include "qcustomplot.h"
#include "helper.h"



Mars::Mars(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mars)
{
    ui->setupUi(this);
    pModeFormWidget = NULL;
    plModeFormWidget = NULL;
    tModeFormWidget = NULL;
    lastFormWidget = NULL;
    modeRadioButtonList = new QList<QRadioButton *>();
    modeRadioButtonList->append(ui->pModeRadioButton);
    modeRadioButtonList->append(ui->plModeRadioButton);
    modeRadioButtonList->append(ui->tModeRadioButton);
    mainWidgetLayout = new QGridLayout(ui->mainWidget);
    mainWidgetLayout->setSpacing(0);
    mainWidgetLayout->setContentsMargins(0,0,0,0);
    serialPortSettingsDialog = new SPSettingsDialog(this);
    serialPort = new MarsSerialPort(serialPortSettingsDialog->settings(),this);
    ui->mainWidget->setLayout(mainWidgetLayout);
    figure = NULL;
    renderFigureWindow();
    bindMenuBar();
    initConnections();
    onSerialPortClosed();
    setWindowIcon(QIcon(":/icon/mars"));
    setWindowTitle(tr("Mars"));
    setWindowIconText(tr("Mars"));
    ui->pModeRadioButton->click();
    ui->forceCurveCheckBox->click();
    // testing  data;
    for(int i = 0; i < 1000; i++)
    {
        figure->plotForceCurve(sin(180*6.18*i));
    }
}


Mars::~Mars()
{
    delete ui;
}


/*
 *@Desc:show software information dialog
 *@Args:None
 *@Returns:None
 */
void Mars::showAboutSoftwareDialog()
{
    /*no implementation */
}


/*
 * @brief: create position mode input form view
 * @args: None
 * @returns: None
 *
 */
void Mars::renderPositionModeForm()
{
    // if the layout instance don't exist, then create it
    if(NULL == pModeFormWidget)
    {
        QGridLayout * layout;
        QLabel *positionLabel, *velocityLabel, *maxForceLabel;
        QLineEdit *position, *velocity , *maxForce;
        pModeFormWidget = new QWidget(this);
        layout = new QGridLayout(this);
        positionLabel = new QLabel("位置:", this);
        velocityLabel = new QLabel("速度:", this);
        maxForceLabel = new QLabel("最大力:", this);
        position = new QLineEdit(this);
        velocity = new QLineEdit(this);
        maxForce = new QLineEdit(this);
        position->setPlaceholderText(QString("位置(m)"));
        velocity->setPlaceholderText(QString("速度(m/s)"));
        maxForce->setPlaceholderText(QString("最大力(N)"));
        position->setStyleSheet("padding:5px 5px;"
                                "background-color:white;"
                                "border-radius:5px");
        velocity->setStyleSheet("padding:5px 5px;"
                                "background-color:white;"
                                "border-radius:5px");
        maxForce->setStyleSheet("padding:5px 5px;"
                                "background-color:white;"
                                "border-radius:5px;");
        position->setFixedWidth(200);
        position->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
        maxForce->setFixedWidth(200);
        maxForce->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
        velocity->setFixedWidth(200);
        velocity->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
        layout->addWidget(positionLabel, 0, 0);
        layout->addWidget(position, 0, 1, 1, 14, Qt::AlignLeft);
        layout->addWidget(velocityLabel, 0, 15);
        layout->addWidget(velocity, 0, 16, 1, 14, Qt::AlignLeft);
        layout->addWidget(maxForceLabel, 1, 0);
        layout->addWidget(maxForce, 1, 1, 1, 14, Qt::AlignLeft);
        pModeFormWidget->setStyleSheet("background-color:#aaa;"
                                       "margin-bottom:5px;"
                                       "border-radius:5px;");
        pModeFormWidget->setLayout(layout);
    }
    else
    {
        pModeFormWidget->setVisible(true);
    }
    // add layout instance to form widget
    if(lastFormWidget != NULL)
    {
        lastFormWidget->setHidden(true);
        ui->formLayout->removeWidget(lastFormWidget);
    }
    ui->formLayout->addWidget(pModeFormWidget);
    lastFormWidget = pModeFormWidget;
}


/*
 * @brief: create permanent load mode input form view
 * @args: None
 * @returns: None
 *
 */
void Mars::renderPermanentLoadModeForm()
{
    // if the layout instance don't exist, then create it
    if(NULL == plModeFormWidget)
    {
        QGridLayout *layout;
        QLabel * loadLabel, *maxForceLabel;
        QLineEdit * load , *maxForce;
        plModeFormWidget = new QWidget(this);
        layout = new QGridLayout(this);
        loadLabel = new QLabel("载荷:", this);
        maxForceLabel = new QLabel("最大力:", this);
        load = new QLineEdit(this);
        maxForce = new QLineEdit(this);
        load->setPlaceholderText(QString("载荷(w)"));
        maxForce->setPlaceholderText(QString("最大力(N)"));
        load->setStyleSheet("padding:5px 5px;"
                                "background-color:white;"
                                "border-radius:5px");
        maxForce->setStyleSheet("padding:5px 5px;"
                                "background-color:white;"
                                "border-radius:5px;");
        load->setFixedWidth(200);
        load->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
        maxForce->setFixedWidth(200);
        maxForce->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
        layout->addWidget(loadLabel, 0, 0);
        layout->addWidget(load, 0, 1, 1, 14, Qt::AlignLeft);
        layout->addWidget(maxForceLabel, 1, 0);
        layout->addWidget(maxForce, 1, 1, 1, 14, Qt::AlignLeft);
        plModeFormWidget->setStyleSheet("background-color:#aaa;"
                                        "margin-bottom:5px;"
                                        "border-radius:5px;");
        plModeFormWidget->setLayout(layout);
    }
    else
    {
        plModeFormWidget->setVisible(true);
    }
    // add layout instance to form widget
    if(lastFormWidget != NULL)
    {
        lastFormWidget->setHidden(true);
        ui->formLayout->removeWidget(lastFormWidget);
    }
    ui->formLayout->addWidget(plModeFormWidget);
    lastFormWidget = plModeFormWidget;
}


/*
 * @brief: create testing mode input form view
 * @args: None
 * @returns: None
 *
 */
void Mars::renderTestModeForm()
{
    // if the layout instance don't exist, then create it
    if(NULL == tModeFormWidget)
    {
        QGridLayout * layout;
        QLabel * ampLabel, *maxForceLabel, *freqLabel;
        QLineEdit * amplitude , *maxForce, *freq;
        tModeFormWidget = new QWidget(this);
        layout = new QGridLayout(this);
        freqLabel = new QLabel("频率:", this);
        ampLabel = new QLabel("振幅:", this);
        maxForceLabel = new QLabel("最大力:", this);
        freq = new QLineEdit(this);
        maxForce = new QLineEdit(this);
        amplitude = new QLineEdit(this);
        freq->setPlaceholderText(QString("频率(Hz)"));
        amplitude->setPlaceholderText(QString("振幅(cm)"));
        maxForce->setPlaceholderText(QString("最大力(N)"));
        freq->setStyleSheet("padding:5px 5px;"
                                "background-color:white;"
                                "border-radius:5px");
        amplitude->setStyleSheet("padding:5px 5px;"
                                "background-color:white;"
                                "border-radius:5px");
        maxForce->setStyleSheet("padding:5px 5px;"
                                "background-color:white;"
                                "border-radius:5px;");
        freq->setFixedWidth(200);
        freq->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
        maxForce->setFixedWidth(200);
        maxForce->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
        amplitude->setFixedWidth(200);
        amplitude->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
        layout->addWidget(freqLabel, 0, 0);
        layout->addWidget(freq, 0, 1, 1, 14, Qt::AlignLeft);
        layout->addWidget(ampLabel, 0, 15);
        layout->addWidget(amplitude, 0, 16, 1, 14, Qt::AlignLeft);
        layout->addWidget(maxForceLabel, 1, 0);
        layout->addWidget(maxForce, 1, 1, 1, 14, Qt::AlignLeft);
        tModeFormWidget->setStyleSheet("background-color:#aaa;"
                                       "margin-bottom:5px;"
                                       "border-radius:5px;");
        tModeFormWidget->setLayout(layout);
    }
    else
    {
        tModeFormWidget->setVisible(true);
    }
    // add layout instance to form widget
    if(lastFormWidget != NULL)
    {
        lastFormWidget->setHidden(true);
        ui->formLayout->removeWidget(lastFormWidget);
    }
    ui->formLayout->addWidget(tModeFormWidget);
    lastFormWidget = tModeFormWidget;

}


/*
 * @brief: switch the system's working mode when radio button groups is checked
 * @args: bool checked
 * @returns: None
 *
 */
void Mars::switchWorkModeOnRButtonToggled(bool checked)
{
    if(checked)
    {
        for(int i = 0; i < modeRadioButtonList->length(); i++)
        {
            if(modeRadioButtonList->at(i)->isChecked())
            {
                qDebug()<<modeRadioButtonList->at(i);
                switch(i)
                {
                    case 0:
                        renderPositionModeForm();
                        break;
                    case 1:
                        renderPermanentLoadModeForm();
                        break;
                    case 2:
                        renderTestModeForm();
                        break;
                    default:
                        break;
                }
            }
        }

    }

}


/*
 *@Desc: init Mars all signals to the respective slots
 *@Args:None
 *@Returns:None
 */
void Mars::initConnections()
{
    connect(ui->connectSPAction, &QAction::triggered,
            this, &Mars::connectSerialPort);
    connect(ui->disconnectSPAction, &QAction::triggered,
            this, &Mars::disconnectSerialPort);
    /*connect(ui->connectBtn, &QPushButton::clicked,
            this, &Mars::onConnectBtnClicked);
            */
    connect(serialPort, &MarsSerialPort::disconnected,
            this, &Mars::onSerialPortClosed);
    connect(serialPort, &MarsSerialPort::connected,
            this, &Mars::onSerialPortOpened);
    connect(serialPort, &MarsSerialPort::dataFrameReceived,
            this, &Mars::renderSerialPortData);
    connect(serialPort, &MarsSerialPort::errors,
            this, &Mars::handleError);
    connect(ui->serialPortConfigDialogAction, &QAction::triggered,
            this, &Mars::showSerialPortSettingsDialog);
    connect(ui->exitAppAction, &QAction::triggered,
            this, &QApplication::exit);
    connect(ui->forceCurveCheckBox, &QCheckBox::stateChanged,
            this, &Mars::renderForceCurvePlot);
    connect(ui->displacementCurveCheckBox, &QCheckBox::stateChanged,
            this, &Mars::renderDisplacementCurvePlot);
    connect(ui->pModeRadioButton, &QRadioButton::toggled,
            this,&Mars::switchWorkModeOnRButtonToggled);
    connect(ui->plModeRadioButton, &QRadioButton::toggled,
            this,&Mars::switchWorkModeOnRButtonToggled);
    connect(ui->tModeRadioButton, &QRadioButton::toggled,
            this,&Mars::switchWorkModeOnRButtonToggled);
  /*  connect(ui->figureWindowBtn, &QPushButton::clicked,
            this, &Mars::showFigureWindow);
            */
}



/*
 *@Desc: connect to serial port
 *@Args: None
 *@Returns: None
 */
void Mars::connectSerialPort()
{
    serialPort->connect(serialPortSettingsDialog->settings());
}


/*
 * @brief: render force curve plot
 * @args: int state
 * @returns: None
 *
 */
void Mars::renderForceCurvePlot(int state)
{

    if(state == Qt::Unchecked)
    {
        figure->deleteCurveViewById(0);
    }
    else if(state == Qt::Checked)
    {
        figure->createForceCurveView();
    }
    else
    {
    }
}


/*
 * @brief: render displacement curve plot
 * @args: int state
 * @returns: None
 *
 */
void Mars::renderDisplacementCurvePlot(int state)
{

    if(state == Qt::Unchecked)
    {
        figure->deleteCurveViewById(1);
    }
    else if(state == Qt::Checked)
    {
        figure->createDisplacementCurveView();
    }
    else
    {
    }
}


/*
 *@Desc: disconnect from serial port
 *@Args: None
 *@Returns: None
 */
void Mars::disconnectSerialPort()
{
    serialPort->disconnect();
}


/*
 *@Desc:show serial port connection protocol dialog
 *@Args:None
 *@Returns:None
 */
void Mars::showSerialPortProtocolDialog()
{
    /* no implementation */
}


/*
 *@Desc:show serial port  config dialog
 *@Args:None
 *@Returns:None
 */
void Mars::showSerialPortSettingsDialog()
{
    serialPortSettingsDialog->exec();
}


/*
 *@Desc: slot method for connectBtn clicked,connect to serial port or disconnect serial port
 *@Args: None
 *@Returns: None
 */
void Mars::onConnectBtnClicked()
{
    if(serialPort->isOpen())
    {
        disconnectSerialPort();
    }
    else
    {
        connectSerialPort();
    }
}


/*
 *@Desc: handler MarsSerialPort's connected signal
 *@Args: None
 *@Returns: None
 */
void Mars::onSerialPortOpened()
{
    ui->connectSPAction->setEnabled(false);
    ui->serialPortConfigDialogAction->setEnabled(false);
    ui->disconnectSPAction->setEnabled(true);
    //ui->connectBtn->setIcon(QIcon(":/icon/earth-connected"));
    //ui->connectBtn->setToolTip(tr("关闭串口"));
}


/*
 *@Desc: handler MarsSerialPort's disconnected signal
 *@Args: None
 *@Returns: None
 */
void Mars::onSerialPortClosed()
{
    ui->serialPortConfigDialogAction->setEnabled(true);
    ui->connectSPAction->setEnabled(true);
    ui->disconnectSPAction->setEnabled(false);
    //ui->connectBtn->setIcon(QIcon(":/icon/earth-disconnected"));
    //ui->connectBtn->setToolTip(tr("连接串口"));
}


/*
 *@Desc: handler MarsSerialPort's dataReady signal,
 *     read serial port data and send it to figure or console
 *@Args: None
 *@Returns: None
 */
void Mars::renderSerialPortData()
{
    QByteArray data;
    // read data frame from serial frame queue
    serialPort->readDataFrame(data);
    if(data.isEmpty())
        return ;
    // parse serial port data and send data to figure
    for (int i = 0 ; i < 5; i++)
    {
        if(data.mid(1+i*4, 4).toHex()==QByteArray(0x00000000))
            break;
        figure->plot(bytesToFloat(data.mid(1+i*4 ,4)), i, (unsigned char)data.at(0));
    }
}



/*
 *@Desc: be responsible for parse console's data and plot it's graph in figure window
 *@Args: MarsCommandLine * requestedObj
 *@Returns: None
 */
void Mars::plotConsoleData(MarsCommandLine *requestedObj)
{
    /* get data size from console's data buffer */
    int dataSize = requestedObj->outputBuffer()->length();
    if(dataSize == 0)
        return ;
    QVector<double> x;
    QList<QVector<double>*> y;
    QList<QByteArray> dataLineItems;
    /* calculate graph number */
    int dataGraphNum = requestedObj->outputBuffer()->at(0).split(' ').length();
    /* create container for y axis value  */
    for(int i =0;i<dataGraphNum;i++)
    {
        y.append(new QVector<double>());
    }
    /* parse data from console's command line data */
    for(int i = 0;i<dataSize;i++)
    {
        x.append(i);
        dataLineItems = requestedObj->outputBuffer()->at(i).split(' ');
        for(int j =0;j<dataGraphNum;j++)
        {
            y.at(j)->append(dataLineItems.at(j).toDouble());
        }
    }
    int graphId = 0;
    int plotId = 0;
    /* starting plot */
    figure->startPlot();
    for(int i=0;i<dataGraphNum;i++)
    {
        /* calculate plot id , max plot number is  4 */
        plotId = ceil(i/4);
        /* calculate graph id ,max graph number of each plot is also 4 */
        graphId = i%4;
        /* starting plot */
        figure->plot(x,*y.at(i),graphId,plotId);
        delete y.at(i);
    }

}


/*
 *@Desc: create figure window and connect signals to slots ,finally render it in top level
 *@Args: None
 *@Returns: None
 */
void Mars::renderFigureWindow()
{
    if(!figure)
    {
        // create MarsFigure instance
        figure = new MarsFigure(ui->mainWidget);
        // bind slots method to the related signal
        connect(figure,&MarsFigure::error,this,&Mars::handleError);
        connect(ui->saveGraphAction,&QAction::triggered,figure,&MarsFigure::saveGraph);
    }
    figure->setHidden(false);
    mainWidgetLayout->addWidget(figure,1,1);
}


/*
 *@Desc: update menu bar's action  and widget status when current window has changed
 *@Args: int winId(0 denotes console window ,1  denotes figure window)
 *@Returns: None
 */
void Mars::bindMenuBar(void)
{
    /*
    ui->saveGraphAction->setEnabled(false);
    ui->clearScreenAction->setText(tr("清空输出"));
    connect(ui->exportAction,&QAction::triggered,console,&MarsConsole::showExportDataDialog);
    connect(ui->importAction,&QAction::triggered,console,&MarsConsole::showImportDataDialog);
    connect(ui->clearScreenAction,&QAction::triggered,console,&MarsConsole::clearCurrentCmdLine);
    if(figure)
    {
        disconnect(ui->clearScreenAction,&QAction::triggered,figure,&MarsFigure::clearCurrentPlot);
        disconnect(ui->importAction,&QAction::triggered,figure,&MarsFigure::showImportDataDialog);
        disconnect(ui->exportAction,&QAction::triggered,figure,&MarsFigure::showExportDataDialog);
    }
    */
    ui->saveGraphAction->setEnabled(true);
    ui->clearScreenAction->setText(tr("清除图像"));
    connect(ui->importAction,&QAction::triggered,figure,&MarsFigure::showImportDataDialog);
    connect(ui->exportAction,&QAction::triggered,figure,&MarsFigure::showExportDataDialog);
    connect(ui->clearScreenAction,&QAction::triggered,figure,&MarsFigure::clearCurrentPlot);
}


/*
 *@Desc: error handler for all QWidget object
 *@Args: waiting to define
 *@Returns:None
 */
void Mars::handleError(MarsError  error)
{
    if(error.level==INFO)
    {
        QMessageBox::information(this, tr("information"),error.msg);
    }
    else if(error.level==DEBUG)
    {

    }
    else if(error.level==WARNING)
    {
        QMessageBox msgBox(QMessageBox::Warning, tr("warning"),error.msg, 0, this);
        msgBox.setDetailedText(error.msg);
        msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
        if (msgBox.exec() == QMessageBox::RejectRole)
             return;
    }
    else if(error.level==ERROR)
    {
        QErrorMessage errorMsg(this);
        errorMsg.showMessage(error.msg);
        errorMsg.exec();
    }
    else
    {
       QMessageBox::StandardButton reply;
       reply = QMessageBox::critical(this, tr("critical"),
             error.msg,QMessageBox::Abort | QMessageBox::Ignore);
       if (reply == QMessageBox::Abort)
           QApplication::instance()->quit();
    }
}
