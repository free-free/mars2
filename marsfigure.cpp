/************************************************************************
 * CopyRights (C): Thogo tech all rights reserved!
 *
 * @file: marfigure.cpp
 * @description: this file contains the implementation of figure class
 * @version: 0.1
 * @author: infinite.ft
 * @date: 2017/02/07
 * @update_at: 2017/03/22
 *
 *
 */
#include "marsfigure.h"
#include <QAction>
#include <QGridLayout>
#include <QFile>
#include <QFileDialog>
#include <QToolBar>
#include <QList>
#include <QComboBox>
#include <QVBoxLayout>
#include "qcustomplot.h"
#include "marsplot.h"


MarsFigure::MarsFigure(QWidget *parent) : QWidget(parent)
{
    layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    layout->setSpacing(0);
    this->setLayout(layout);
    cvidToPidMap[0] = -1;
    cvidToPidMap[1] = -1;
    pidToCvidMap[0] = -1;
    pidToCvidMap[1] = -1;
    // Note:!!!
    // initToolBar() must be called before initPlot(),
    // fuck ,yeah I have written this shit code !!!!!!!!!!!!!!!
    initToolBar();
    initPlot();
    connect(this,&MarsFigure::getImportFileName,this,&MarsFigure::readFile);
    connect(this,&MarsFigure::getExportFileName,this,&MarsFigure::writeFile);
}


MarsFigure::~MarsFigure()
{
    delete exportDataAction;
    delete importDataAction;
    delete plotAction;
    delete savePlotAction;
    delete clearPlotAction;
    delete ploterContainer;
    delete plotLayout;
    delete layout;
}


/**
 *@Desc: init tool bar
 *@Args: None
 *@Returns: None
 *
 */
void
MarsFigure::initToolBar()
{

    toolBar = new QToolBar("hello",this);
    maxNameLabel = new QLabel(this);
    maxValLabel = new QLabel(this);
    minNameLabel = new QLabel(this);
    minValLabel = new QLabel(this);
    avgNameLabel = new QLabel(this);
    avgValLabel = new QLabel(this);
    curXnameLabel = new QLabel(this);
    curXvalLabel = new QLabel(this);
    curYnameLabel = new QLabel(this);
    curYvalLabel = new QLabel(this);
    maxNameLabel->setText(tr("最大值:"));
    maxValLabel->setText(tr("0"));
    minNameLabel->setText(tr("最小值:"));
    minValLabel->setText(tr("0"));
    avgNameLabel->setText(tr("平均值:"));
    avgValLabel->setText(tr("0"));
    curXnameLabel->setText(tr("当前X值:"));
    curXvalLabel->setText(tr("0"));
    curYnameLabel->setText(tr("当前Y值:"));
    curYvalLabel->setText(tr("0"));
    maxNameLabel->setStyleSheet("border:none;"
                                "color:white;"
                                "margin-left:20px;");
    maxValLabel->setStyleSheet("border:none;"
                               "color:white;"
                               );
    minNameLabel->setStyleSheet("border:none;"
                                "color:white;"
                                "margin-left:20px;"
                                );
    minValLabel->setStyleSheet("border:none;"
                               "color:white;"
                               );
    avgNameLabel->setStyleSheet("border:none;"
                                "color:white;"
                                "margin-left:20px;");
    avgValLabel->setStyleSheet("border:none;"
                               "color:white;"
                               );
    curXnameLabel->setStyleSheet("border:none;"
                                "color:white;"
                                "margin-left:20px;");
    curXvalLabel->setStyleSheet("border:none;"
                               "color:white;"
                               );
    curYnameLabel->setStyleSheet("border:none;"
                                "color:white;"
                                "margin-left:20px;");
    curYvalLabel->setStyleSheet("border:none;"
                               "color:white;"
                               );

    toolBar->setStyleSheet(
                           "margin:0px 0px 0px 0px;"
                           "padding:0px 0px 0px 0px;"
                           "background-color:#666;"
                           "border-left:1px solid #333;"
                           "spacing:5px;"
                           );
    toolBar->setAutoFillBackground(true);
    toolBar->setFixedHeight(30);
    toolBar->setContentsMargins(0,0,0,0);
    toolBar->setOrientation(Qt::Horizontal);
    toolBar->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Fixed);
    plotAction = new QAction(QIcon(":/icon/start"),tr("开始绘制"),this);
    savePlotAction = new QAction(QIcon(":/icon/save"),tr("保存图像"),this);
    exportDataAction = new QAction(QIcon(":/icon/export"),tr("导出数据"),this);
    importDataAction = new QAction(QIcon(":/icon/import"),tr("导入数据"),this);
    clearPlotAction = new QAction(QIcon(":/icon/clear"),tr("清除图像"),this);
    ploterNameListBox =new QComboBox(this);
    ploterNameListBox->setStyleSheet("QComboBox{"
                             "padding:0px 10px 0px 10px;"
                             "margin:0px 0px 0px 0px;"
                             "border:0px 0px 0px 0px;"
                             "min-width: 6em;"
                             "color:#efefef;"
                         "}"
                         "QComboBox::drop-down {"
                             "subcontrol-origin: padding;"
                             "subcontrol-position: top right;"
                             "width:20px;"
                             "border-left-width: 0px;"
                             "}"
                         "QComboBox::down-arrow {"
                            "image: url(:/icon/tiny-down-arrow);"
                         "}"
                         "QComboBox::hover{"
                            "background-color:#888;"
                         "}"
                         );

    toolBar->addAction(plotAction);
    toolBar->addSeparator();
    toolBar->addWidget(ploterNameListBox);
    toolBar->addAction(savePlotAction);
    toolBar->addAction(exportDataAction);
    toolBar->addAction(importDataAction);
    toolBar->addAction(clearPlotAction);
    toolBar->addWidget(maxNameLabel);
    toolBar->addWidget(maxValLabel);
    toolBar->addWidget(minNameLabel);
    toolBar->addWidget(minValLabel);
    toolBar->addWidget(avgNameLabel);
    toolBar->addWidget(avgValLabel);
    toolBar->addWidget(curXnameLabel);
    toolBar->addWidget(curXvalLabel);
    toolBar->addWidget(curYnameLabel);
    toolBar->addWidget(curYvalLabel);
    connect(savePlotAction,&QAction::triggered,this,&MarsFigure::saveGraph);
    connect(exportDataAction,&QAction::triggered,this,&MarsFigure::showExportDataDialog);
    connect(importDataAction,&QAction::triggered,this,&MarsFigure::showImportDataDialog);
    connect(plotAction,&QAction::triggered,this,&MarsFigure::onPlotActionTriggered);
    connect(clearPlotAction,&QAction::triggered,this,&MarsFigure::clearCurrentPlot);
    connect(ploterNameListBox,SIGNAL(currentIndexChanged(int)),this,SLOT(changeCurrentPloter(int)));
    layout->addWidget(toolBar);

}


/*
 * @brief: display current x and y value when mouse is moving
 * @args: MarsPlot * obj
 *        double x,
 *        double y
 * @returns: None
 *
 */
void MarsFigure::displayCurrentXYValue(MarsPlot * obj, double x, double y)
{
    if(obj == currentPloter)
    {
        curXvalLabel->setText(QString("%1").arg(x, 0, 'f'));
        curYvalLabel->setText(QString("%1").arg(y, 0, 'f'));
    }
}


/*
 * @brief: init plot
 * @args: None
 * @returns: None
 *
 */
void
MarsFigure::initPlot()
{
    plotLayout = new QGridLayout();
    layout->addLayout(plotLayout);
    ploterContainer = new QList<MarsPlot*>();
    plotState = false;
}


/*
 * @brief: create force curve view
 * @args: None
 * @returns: None
 *
 */
MarsPlot* MarsFigure::createForceCurveView(void)
{
    MarsPlot * tmpPloter;
    tmpPloter = new MarsPlot(this);
    tmpPloter->xAxis->setLabel(tr("时间"));
    tmpPloter->yAxis->setLabel(tr("牛(N)"));
    tmpPloter->setTitleText(tr("力曲线"));
    tmpPloter->xAxis->setLabelPadding(0);
    tmpPloter->yAxis->setLabelPadding(0);
    connect(tmpPloter, &MarsPlot::focusIn, this, &MarsFigure::changeCurrentPloterOnFocusIn);
    connect(tmpPloter, &MarsPlot::mouseMoveOn, this, &MarsFigure::displayCurrentXYValue);
    tmpPloter->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    tmpPloter->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    tmpPloter->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    tmpPloter->legend->setVisible(true);
    tmpPloter->legend->setSelectableParts(QCPLegend::spItems);
    tmpPloter->setBackground(QBrush(QColor(0xcf, 0xcf, 0xcf)));
    ploterContainer->append(tmpPloter);
    cvidToPidMap[0] = ploterContainer->length() - 1;
    pidToCvidMap[cvidToPidMap[0]] = 0;
    changeCurrentPloter(cvidToPidMap[0]);
    arrangePloter();
    updateStatusBar();
    return tmpPloter;
}


/*
 * @brief: create displacement curve view
 * @args: None
 * @returns: None
 *
 */
MarsPlot* MarsFigure::createDisplacementCurveView(void)
{
    MarsPlot * tmpPloter;
    tmpPloter = new MarsPlot(this);
    tmpPloter->xAxis->setLabel(tr("时间"));
    tmpPloter->yAxis->setLabel(tr("厘米(cm)"));
    tmpPloter->setTitleText(tr("位移曲线"));
    tmpPloter->xAxis->setLabelPadding(0);
    tmpPloter->yAxis->setLabelPadding(0);
    connect(tmpPloter, &MarsPlot::focusIn, this, &MarsFigure::changeCurrentPloterOnFocusIn);
    connect(tmpPloter, &MarsPlot::mouseMoveOn, this, &MarsFigure::displayCurrentXYValue);
    tmpPloter->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    tmpPloter->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    tmpPloter->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    tmpPloter->legend->setVisible(true);
    tmpPloter->legend->setSelectableParts(QCPLegend::spItems);
    tmpPloter->setBackground(QBrush(QColor(0xcf, 0xcf, 0xcf)));
    ploterContainer->append(tmpPloter);
    cvidToPidMap[1] = ploterContainer->length() - 1;
    pidToCvidMap[cvidToPidMap[1]] = 1;
    changeCurrentPloter(cvidToPidMap[1]);
    arrangePloter();
    updateStatusBar();
    return tmpPloter;
}


/**
 *@Desc: create ploter instance and config it ,finally append it to ploterContainter
 *@Args: None
 *@Returns: MarsPlot *
 *
 */
MarsPlot *
MarsFigure::createPloter()
{

    MarsPlot * tmpPloter;
    // greater than max ploter number
    if(ploterContainer->length() >= MAX_PLOTER_NUMBER)
        return NULL;
    tmpPloter = new MarsPlot(this);
    //tmpPloter->xAxis2->setVisible(true);
    //tmpPloter->xAxis2->setTickLabels(false);
    //tmpPloter->yAxis2->setVisible(true);
    //tmpPloter->yAxis2->setTickLabels(false);
    //tmpPloter->xAxis->setLabel("x");
    tmpPloter->xAxis->setLabelPadding(0);
    //tmpPloter->yAxis->setLabel("y");
    tmpPloter->yAxis->setLabelPadding(0);
    // make left and bottom axes always transfer their ranges to right and top axes:
    //connect(tmpPloter->xAxis, SIGNAL(rangeChanged(QCPRange)), tmpPloter->xAxis2, SLOT(setRange(QCPRange)));
    //connect(tmpPloter->yAxis, SIGNAL(rangeChanged(QCPRange)), tmpPloter->yAxis2, SLOT(setRange(QCPRange)));
    connect(tmpPloter, &MarsPlot::focusIn, this, &MarsFigure::changeCurrentPloterOnFocusIn);
    tmpPloter->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectPlottables);
    tmpPloter->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    tmpPloter->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    tmpPloter->legend->setVisible(true);
    tmpPloter->legend->setSelectableParts(QCPLegend::spItems);
    tmpPloter->setBackground(QBrush(QColor(0x00, 0x00, 0x00)));
    tmpPloter->xAxis->setLabel(tr("时间"));
    tmpPloter->yAxis->setLabel(tr("牛(N)"));
    tmpPloter->setTitleText(tr("力曲线"));
    ploterContainer->append(tmpPloter);
    currentPloter = tmpPloter;
    arrangePloter();
    updateStatusBar();
    return tmpPloter;
}


/**
 *@Desc: create graph
 *@Args: int plotId
 *@Returns: int graphId
 */
int
MarsFigure::createGraph(int plotId)
{
    int graphId;
    ploterContainer->at(plotId)->addGraph();
    // recorrect graphId after creating new graph in the current ploter
    graphId = ploterContainer->at(plotId)->graphCount()-1;
    ploterContainer->at(plotId)->graph(graphId)->setPen(QPen(graphColor(graphId), 1));
    ploterContainer->at(plotId)->graph(graphId)->setScatterStyle(graphScatterStyle(graphId));
    ploterContainer->at(plotId)->rescaleAxes();
    return graphId;
}


/*
 * @brief: delete curve view by id
 * @args: int cvid
 * @returns: None
 *
 */
void MarsFigure::deleteCurveViewById(int cvid)
{
    MarsPlot * tmpPloter = NULL;
    if(cvid > 2 || cvidToPidMap[cvid] < 0)
        return ;
    if(cvidToPidMap[cvid] < ploterContainer->length() - 1)
    {
        // exchange last ploter and current ploter
        tmpPloter = ploterContainer->at(cvidToPidMap[cvid]);
        ploterContainer->replace(cvidToPidMap[cvid],
                                 ploterContainer->at(ploterContainer->length() - 1));
        ploterContainer->replace(ploterContainer->length() - 1, tmpPloter);

        cvidToPidMap[pidToCvidMap[ploterContainer->length() - 1]] = cvidToPidMap[cvid];
        pidToCvidMap[cvidToPidMap[cvid]] = cvid;
    }
    currentPloter = ploterContainer->last();
    ploterContainer->removeLast();
    delete currentPloter;
    pidToCvidMap[cvidToPidMap[cvid]] = -1;
    cvidToPidMap[cvid] = -1;
    if(ploterContainer->length() > 0)
    {
        currentPloter = ploterContainer->last();
    }
    else
        currentPloter = NULL;
    arrangePloter();
    updateStatusBar();
}


/*
 * @brief: delete selected ploter
 * @args: None
 * @returns: None
 */
void
MarsFigure::deletePloter()
{
    if(ploterContainer->length()<=1)
        return ;
    ploterContainer->removeAt(ploterContainer->indexOf(currentPloter));
    delete currentPloter;
    currentPloter = ploterContainer->last();
    arrangePloter();
    updateStatusBar();
}


/**
 *@Desc: update status bar actions when create ploter or delete ploter
 *@Args: None
 *@Returns: None
 */
void
MarsFigure::updateStatusBar()
{

    // enable or disable deletePloterAction
    /*
    if(ploterContainer->length()==MIN_PLOTER_NUMBER)
         deletePloterAction->setEnabled(false);
    else
         deletePloterAction->setEnabled(true);
    // enable or disable createPloterAction
    if(ploterContainer->length()>=MAX_PLOTER_NUMBER)
         createPloterAction->setEnabled(false);
    else
         createPloterAction->setEnabled(true);
    // update ploterNameListBox
    disconnect(ploterNameListBox,SIGNAL(currentIndexChanged(int)),this,SLOT(changeCurrentPloter(int)));
    ploterNameListBox->clear();
    for(int i =0;i<ploterContainer->length();i++)
        ploterNameListBox->addItem("plot "+QString::number(i+1),i);
    ploterNameListBox->setCurrentIndex(ploterContainer->indexOf(currentPloter));
    connect(ploterNameListBox,SIGNAL(currentIndexChanged(int)),this,SLOT(changeCurrentPloter(int)));
    */
    disconnect(ploterNameListBox,SIGNAL(currentIndexChanged(int)),
               this,SLOT(changeCurrentPloter(int)));
    ploterNameListBox->clear();
    for(int i = 0; i < ploterContainer->length(); i++)
    {
        ploterNameListBox->addItem(ploterContainer->at(i)->getTitleText(),i);
    }
    ploterNameListBox->setCurrentIndex(ploterContainer->indexOf(currentPloter));
    connect(ploterNameListBox,SIGNAL(currentIndexChanged(int)),
            this,SLOT(changeCurrentPloter(int)));
}


/*
 * @brief: arrange ploter in parent layout
 * @args: None
 * @returns: None
 */
void
MarsFigure::arrangePloter()
{
    int length = ploterContainer->length();
    if(length == 0)
    {
        this->setHidden(true);
    }
    else
    {
        this->setVisible(true);
    }
    switch(length)
    {
        case 1:
            plotLayout->addWidget(ploterContainer->at(0),1,1);
            break;
        case 2:
            plotLayout->addWidget(ploterContainer->at(0),1,1);
            plotLayout->addWidget(ploterContainer->at(1),1,2);
            break;
        case 3:
            plotLayout->addWidget(ploterContainer->at(0),1,1,1,2);
            plotLayout->addWidget(ploterContainer->at(1),2,1);
            plotLayout->addWidget(ploterContainer->at(2),2,2);
            break;
        case 4:
            plotLayout->addWidget(ploterContainer->at(0),1,1);
            plotLayout->addWidget(ploterContainer->at(1),2,1);
            plotLayout->addWidget(ploterContainer->at(2),2,2);
            plotLayout->addWidget(ploterContainer->at(3),1,2);
            break;
        default:

            break;
    }
}


/*
 * @brief: start plot(including set plot state to true ,call replot function  and emit plotStarted signal
 * @args: None
 * @returns: None
 */
void
MarsFigure::startPlot()
{
    plotState=true;
    int ploterNumber = ploterContainer->length();
    /* replot all */
    for(int i = 0; i < ploterNumber; ++i)
    {
       if(ploterContainer->at(i) != NULL)
       {
           ploterContainer->at(i)->replot();
       }
    }
    emit plotStarted();
}


/*
 * @brief: stop plot(including set plot state to false  and emit plotStopped signal
 * @args: None
 * @returns: None
 */
void
MarsFigure::stopPlot()
{
    plotState = false;
    emit plotStopped();
}


/**
 *@Desc: change plotAction's icon and text ,call stopPlot function
 *@Args: None
 *@Returns: None
 *
 */
void
MarsFigure::onPlotActionTriggered()
{
    if(plotState)
    {
        plotAction->setIcon(QIcon(":/icon/start"));
        plotAction->setText(tr("开始绘制"));
        stopPlot();
    }
    else
    {
        plotAction->setIcon(QIcon(":/icon/pause"));
        plotAction->setText(tr("停止绘制"));
        startPlot();
    }
}


/**
 *@Desc: change current Ploter
 *@Args: int (ploter index in ploterContainer)
 *@Returns: None
 */
void
MarsFigure::changeCurrentPloter(int index)
{
   currentPloter = ploterContainer->at(index);
   maxValLabel->setText(QString("%1").arg(currentPloter->yMax, 0, 'f'));
   minValLabel->setText(QString("%1").arg(currentPloter->yMin, 0, 'f'));
   avgValLabel->setText(QString("%1").arg(currentPloter->yAvg, 0, 'f'));
   curXvalLabel->setText("0");
   curYvalLabel->setText("0");

}


/**
 *@Desc: clear plot
 *@Args: None
 *@Returns: None
 */
void
MarsFigure::clearCurrentPlot()
{
    currentPloter->clearGraphs();
    for(int i=0;i<currentPloter->graphCount();i++)
    {
        currentPloter->graph(i)->data()->clear();
    }
    currentPloter->replot();
    currentPloter->yMax = 0;
    currentPloter->yMin = 0;
    currentPloter->yAvg = 0;
    currentPloter->ySum = 0;
    maxValLabel->setText("0");
    minValLabel->setText("0");
    avgValLabel->setText("0");
    curXvalLabel->setText("0");
    curYvalLabel->setText("0");
}


/**
*
* @Desc: generate graph's scatter style
* @Args: graphId, graph id
* @Returns: QCPScatterStyle
*/
QCPScatterStyle
MarsFigure::graphScatterStyle(int graphId)
{
   QCPScatterStyle scatterStyle;
   switch(graphId)
   {
       case 0:
           scatterStyle.setShape(QCPScatterStyle::ssCircle);
           break;
       case 1:
           scatterStyle.setShape(QCPScatterStyle::ssDiamond);
           break;
       case 2:
           scatterStyle.setShape(QCPScatterStyle::ssTriangle);
           break;
       case 3:
           scatterStyle.setShape(QCPScatterStyle::ssPlus);
           break;
       case 4:
            scatterStyle.setShape(QCPScatterStyle::ssDot);
           break;
       default:
           scatterStyle.setShape(QCPScatterStyle::ssCross);
           break;
   }
   scatterStyle.setSize(5);
   return scatterStyle;
}

/**
 *@Desc: generate graph color and return color
 *@Args: int (graph id)
 *@Returns: QColor
 */
QColor
MarsFigure::graphColor(int graphId)
{
    switch(graphId)
    {
        case 0:
            return Qt::blue;
        case 1:
            return Qt::green;
        case 2:
            return Qt::red;
        case 3:
            return Qt::black;
        case 4:
            return Qt::cyan;
        default:
            return Qt::blue;
    }
}


/**
 *@Desc: fuck you, another plotting method
 *@Args: QList<QByteArray> & data
 *@Returns: None
 */
void
MarsFigure::plot(QList<QByteArray> & data)
{
    QString dataStr = data.join('\n');
    plot(dataStr);
}


/**
 *@Desc: fuck you , another plotting method
 *@Args: QByteArray & data
 *@Returns: None
 *
 */
void
MarsFigure::plot(QByteArray & data)
{
    QString dataStr = data;
    plot(dataStr);
}


/**
 *
 * @brief:
 *  plot graph with string data
 *  string data formation:
 *      each data line end with '\n',each data line contains a space characters as a seperator.
 *
 *      generally speaking, it almost like the following formation:
 *              "x1 y^11 y^12 y^13"
 *
 * @param: QString & data
 * @returns: None
 */

/** yeah, I have written this shit code,fuck you ,the code */

/** strongly recommend, the data size is better less than 100 thousands line */
void
MarsFigure::plot(QString &data)
{

    if (!plotState)
        return ;
    double yValue;
    QStringList dataLines;
    QStringList dataLineItems;
    dataLines = data.split("\n");
    int dataSize = dataLines.length();
    if(dataSize == 0)
        return ;
    QVector<double> x;
    QList<QVector<double>*> y;
    int dataGraphNum = dataLines.at(0).split(' ').length() - 1;
    for(int i = 0; i < dataGraphNum; i++)
    {
        y.append(new QVector<double>());
    }
    for(int i = 0; i < dataSize; i++)
    {
        dataLineItems = dataLines.at(i).split(' ');
        if(dataLineItems.length()<=1)
            continue;
        x.append(dataLineItems.at(0).toDouble());
        for( int j = 0; j< dataGraphNum; j++)
        {
            yValue = dataLineItems.at(j+1).toDouble();
            y.at(j)->append(yValue);
            currentPloter->ySum += yValue;
            currentPloter->yMax = currentPloter->yMax < yValue ? yValue: currentPloter->yMax;
            currentPloter->yMin = currentPloter->yMin > yValue ? yValue: currentPloter->yMin;
        }
    }
    currentPloter->yAvg = currentPloter->ySum / x.length();
    int graphId = 0;
    int plotId = 0;
    int currentPloterId = ploterContainer->indexOf(currentPloter);
    changeCurrentPloter(currentPloterId);
    for(int i = 0; i < dataGraphNum; i++)
    {
        plotId = ceil(i / MAX_GRAPH_NUMBER) + currentPloterId;
        graphId = (i % MAX_GRAPH_NUMBER);
        plot(x, *y.at(i), graphId , plotId);
        delete y.at(i);
    }


}


/**
 *
 * @brief:
 *  plot graph
 *  Note !!!:
 *      The graphId starts from 0 ,the same as plotId.
 *      If you pass a graphId or plotId variable which's value is greater than 3, the result
 *      is no affected.
 *
 * @param: x
 * @param: y
 * @param: graphId, graph identification
 * @param: plotId, ploter id
 * @returns: None
 *
 */
void
MarsFigure::plot(double x, double y, int graphId,int plotId)
{
    /* return back if plotState is false ,it indicates the plotting  is stopped */
    if (!plotState)
        return ;
    if((graphId + 1) > MAX_GRAPH_NUMBER)
        plotId += 1;
    if((ploterContainer->length() - 1) < plotId)
    {
        if(!createPloter())
            return ;
        // recorrect plotId after creating new ploter
        plotId = ploterContainer->length() - 1;
    }
    if((graphId + 1) > ploterContainer->at(plotId)->graphCount())
    {
        graphId = createGraph(plotId);
    }
    ploterContainer->at(plotId)->graph(graphId)->addData(x,y);
    double xRange = ploterContainer->at(plotId)->xMaxRange();
    ploterContainer->at(plotId)->xAxis->setRange(x+xRange/8, xRange, Qt::AlignRight);
    ploterContainer->at(plotId)->replot();
}


void
MarsFigure::plot(double y , int graphId, int plotId)
{
    double x;
    /* return back if plotState is false ,it indicates the plotting  is stopped */
    if (!plotState)
        return ;
    if((graphId+1) > MAX_GRAPH_NUMBER)
        plotId += 1;
    if((ploterContainer->length()-1)<plotId)
    {
        if(!createPloter())
            return ;
        // recorrect plotId after creating new ploter
        plotId = ploterContainer->length()-1;
    }
    if((graphId+1) > ploterContainer->at(plotId)->graphCount())
    {
         graphId = createGraph(plotId);
    }
    if(ploterContainer->at(plotId)->graph(graphId) != 0)
    {
        int dataCount = ploterContainer->at(plotId)->graph(graphId)->dataCount();
        if(dataCount > 0 )
            x = ploterContainer->at(plotId)->graph(graphId)->dataMainKey(dataCount-1) + 1;
        else
            x = 0.0;
    }
    else
        x = 0.0;
    ploterContainer->at(plotId)->graph(graphId)->addData(x, y);
    double xRange = ploterContainer->at(plotId)->xMaxRange();
    ploterContainer->at(plotId)->xAxis->setRange(x+xRange/8, xRange, Qt::AlignRight);
    ploterContainer->at(plotId)->replot();
}


/**
 *
 * @brief:
 *  plot data graph
 *  Note !!!:
 *      The graphId start from 0 ,the same as plotId.
 *      If you pass a graphId or plotId variable which's value is greater than 3,
 *      the result is no affected.
 * @param:
 *  QVector<double> &x,QVector<double> &y,int graphId(max graphId is 3),
 *  int plotId( max plotId is 3)
 * @returns: None
 *
 */
void
MarsFigure::plot(QVector<double> &x, QVector<double> &y, int graphId,int plotId)
{

    // return back if plotState is false ,it indicate ploting stopped
    if (!plotState)
        return ;
    if((graphId + 1) > MAX_GRAPH_NUMBER)
            plotId += 1;
    if((ploterContainer->length() - 1) < plotId)
    {
        if(!createPloter())                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           
            return ;
        // recorrect plotId after create new ploter
        plotId = ploterContainer->length() - 1;
    }
    if((graphId + 1) > ploterContainer->at(plotId)->graphCount())
    {
        graphId = createGraph(plotId);
    }
    // 65-67 ms /per hundred thousand data
    ploterContainer->at(plotId)->graph(graphId)->setData(x,y);
    ploterContainer->at(plotId)->replot();
}


/**
 *
 *@Desc: another overrid plotting method
 *@Args: QVector<double> & x,QVector<double> &y, int graphId
 *@Returns: None
 *
 */
void
MarsFigure::plot(QVector<double> &x, QVector<double> &y, int graphId)
{

    // return back if plotState is false ,it indicate ploting stopped
    if (!plotState)
        return ;
    if((graphId+1) > MAX_GRAPH_NUMBER)
        return ;
    if((graphId+1) > currentPloter->graphCount())
    {
        currentPloter->addGraph();
        // recorrent graphId after create new graph in the current ploter
        graphId = currentPloter->graphCount() - 1;
        currentPloter->graph(graphId)->setPen(QPen(graphColor(graphId), 1.5));
        currentPloter->graph(graphId)->setScatterStyle(graphScatterStyle(graphId));
        currentPloter->graph(graphId)->rescaleAxes(false);

    }
    currentPloter->graph(graphId)->setData(x,y); // 65-67 ms /per hundred thousand data
   // currentPloter->xAxis->setRange(x.last()-10,100,Qt::AlignRight);
    currentPloter->replot();
}


/*
 * @brief: plot force curve
 * @args: double x
 *        double y
 * @returns: None
 *
 */
void MarsFigure::plotForceCurve(double x, double y)
{
    int plotId = 0;
    MarsPlot * fPloter;
    plotId = cvidToPidMap[0];
    fPloter = ploterContainer->at(plotId);
    fPloter->ySum += y;
    fPloter->yMax = (fPloter->yMax < y)? y : fPloter->yMax;
    fPloter->yMin = (fPloter->yMin > y)? y : fPloter->yMin;
    if(fPloter->graphCount() == 0)
    {
        this->createGraph(plotId);
        startPlot();
    }
    fPloter->yAvg = fPloter->ySum/fPloter->graph(0)->dataCount();
    plot(x, y, 0, plotId);
    if(currentPloter == fPloter)
    {
        maxValLabel->setText(QString("%1").arg(fPloter->yMax, 0, 'f'));
        minValLabel->setText(QString("%1").arg(fPloter->yMin,0, 'f'));
        avgValLabel->setText(QString("%1").arg(fPloter->yAvg,0, 'f'));
    }

}


/*
 * @brief: plot force curve
 * @args:
 *        double y
 * @returns: None
 *
 */
void MarsFigure::plotForceCurve(double y)
{
    int plotId = 0;
    MarsPlot * fPloter;
    plotId = cvidToPidMap[0];
    fPloter = ploterContainer->at(plotId);
    fPloter->ySum += y;
    fPloter->yMax = (fPloter->yMax < y)? y : fPloter->yMax;
    fPloter->yMin = (fPloter->yMin > y)? y : fPloter->yMin;
    if(fPloter->graphCount() == 0)
    {
        this->createGraph(plotId);
        startPlot();
    }
    fPloter->yAvg = fPloter->ySum/fPloter->graph(0)->dataCount();
    plot(y, 0, plotId);
    if(currentPloter == fPloter)
    {
        maxValLabel->setText(QString("%1").arg(fPloter->yMax, 0, 'f'));
        minValLabel->setText(QString("%1").arg(fPloter->yMin,0, 'f'));
        avgValLabel->setText(QString("%1").arg(fPloter->yAvg,0, 'f'));
    }
}


/*
 * @brief: plot displacement curve
 * @args:double x,
 *       double y
 * @returns: None
 *
 */
void MarsFigure::plotDisplacementCurve(double x,double y)
{
    int plotId = 0;
    MarsPlot * dPloter;
    plotId = cvidToPidMap[1];
    dPloter = ploterContainer->at(plotId);
    dPloter->ySum += y;
    dPloter->yMax = (dPloter->yMax < y)? y : dPloter->yMax;
    dPloter->yMin = (dPloter->yMin > y)? y : dPloter->yMin;
    if(dPloter->graphCount() == 0)
    {
        this->createGraph(plotId);
        startPlot();
    }
    dPloter->yAvg = dPloter->ySum/dPloter->graph(0)->dataCount();
    plot(x, y, 0, plotId);
    if(currentPloter == dPloter)
    {
        maxValLabel->setText(QString("%1").arg(dPloter->yMax, 0, 'f'));
        minValLabel->setText(QString("%1").arg(dPloter->yMin,0, 'f'));
        avgValLabel->setText(QString("%1").arg(dPloter->yAvg,0, 'f'));
    }
}


/*
 * @brief: plot displacement curve
 * @args: double y
 * @returns: None
 *
 */
void MarsFigure::plotDisplacementCurve(double y)
{
    int plotId = 0;
    MarsPlot * dPloter;
    plotId = cvidToPidMap[1];
    dPloter = ploterContainer->at(plotId);
    dPloter->ySum += y;
    dPloter->yMax = (dPloter->yMax < y)? y : dPloter->yMax;
    dPloter->yMin = (dPloter->yMin > y)? y : dPloter->yMin;
    if(dPloter->graphCount() == 0)
    {
        this->createGraph(plotId);
        startPlot();
    }
    dPloter->yAvg = dPloter->ySum/dPloter->graph(0)->dataCount();
    plot(y, 0, plotId);
    if(currentPloter == dPloter)
    {
        maxValLabel->setText(QString("%1").arg(dPloter->yMax, 0, 'f'));
        minValLabel->setText(QString("%1").arg(dPloter->yMin,0, 'f'));
        avgValLabel->setText(QString("%1").arg(dPloter->yAvg,0, 'f'));
    }
}


/**
 *
 *@Desc: return error instance
 *@Args:  QString ,MarsErrorLevel
 *@Returns: MarsError
 *
 */
MarsError
MarsFigure::errorInstance(QString msg, MarsErrorLevel level)
{
    MarsError error;
    error.datetime = QDateTime::currentDateTime();
    error.type = CONSOLE;
    error.msg = msg;
    error.level = level;
    return error;
}


/**
 *
 *@Desc: save plot graph as a file
 *@Args: None
 *@Return: None
 *
 */
void
MarsFigure::saveGraph()
{
    QString fullFileName = QFileDialog::getSaveFileName(this,tr("保存图像"),QString(),
                tr("pdf files(*.pdf);;jpg files(*.jpg);; png files(*.png);; bmp file(*.bmp);;"));
    if(fullFileName.isEmpty())
    {
        emit error(errorInstance(tr("文件名不能为空"),WARNING));
        return ;
    }
    QString fileType =fullFileName.split('.').last();
    fileType = fileType.toLower();
    if(fileType=="pdf")
    {
        currentPloter->savePdf(fullFileName);
    }
    else if(fileType =="jpg")
    {
        currentPloter->saveJpg(fullFileName);
    }
    else if(fileType == "png")
    {
        currentPloter->savePng(fullFileName);
    }
    else if(fileType=="bmp")
    {
        currentPloter->saveBmp(fullFileName);
    }
    else
    {
        currentPloter->saveJpg(fullFileName);
    }

}


/**
 *
 *@Desc: show exporting data  dialog;
 *@Args: None
 *@Returns: None
 *
 */
void
MarsFigure::showExportDataDialog()
{
    QString fileName = QFileDialog::getSaveFileName(this,tr("导出数据"),QString(),
                                                    tr("*.txt files(*.txt);;*.json files(*.json);;*.dat files(*.dat);;"));
    if(fileName.isEmpty())
    {
        emit error(errorInstance(tr("文件名不能为空"),WARNING));
        return ;
    }
    QTimer::singleShot(10,[=](){
        emit getExportFileName(fileName);
    });

}


/**
 *
 *@Desc: write graph's data into file
 *@Args: const QString & fileName
 *@Returns: None
 *
 */
void
MarsFigure::writeFile(const QString &fileName)
{
    QFile file(fileName);
    if(!file.open(QIODevice::WriteOnly))
    {
        QString shortFileName = (fileName.split(QRegExp("[/\\]+"))).last();
        emit error(errorInstance(shortFileName+"打开失败",WARNING));
        return ;
    }
    QString fileType =fileName.split('.').last();
    fileType = fileType.toLower();
    try{

        if(fileType == "json")
        {
            writeJSONFile(&file);
        }
        else if(fileType == "dat")
        {
            writeDatFile(&file);
        }
        else
        {
            writeTextFile(&file);
        }
        file.close();
    }catch(exception e)
    {
        file.close();
        emit error(errorInstance("导出数据失败",WARNING));
    }
}


/**
 *
 *@Desc: show importing data dialog
 *@Args: None
 *@Returns: None
 *
 */
void
MarsFigure::showImportDataDialog()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("导入文件"),QString(),
                                     tr("*.txt files(*.txt);;*.json files(*.json);;*.dat files(*.dat);;"));
    if(fileName.isEmpty())
    {
        emit error(errorInstance(tr("文件名不能为空"),WARNING));
        return ;
    }
    QTimer::singleShot(5,[=](){
          emit getImportFileName(fileName);
    });
}


/**
 *
 *@Desc: read file data to ploting
 *@Args: const QString & fileName
 *@Returns: None
 *
 */
void
MarsFigure::readFile(const QString &fileName)
{
    QFile file(fileName);
    QString shortFileName = (fileName.split(QRegExp("[/\\]+"))).last();
    if(!file.open(QIODevice::ReadOnly))
    {
        emit error(errorInstance(shortFileName+"打开失败",WARNING));
        return ;
    }
    // max file size 20M
    if(file.size()>1024*1024*20)
    {
        emit error(errorInstance(shortFileName+"大小已超过20M",WARNING));
        return ;
    }
    QString fileType =shortFileName.split('.').last();
    fileType = fileType.toLower();
    try{
        if(fileType == "json")
        {

            readJSONFile(&file);
        }
        else if(fileType == "dat")
        {
            readDatFile(&file);
        }
        else
        {
            readTextFile(&file);
        }

        file.close();
    }catch(exception e)
    {
        file.close();
        emit error(errorInstance("导入"+shortFileName+"文件数据失败",WARNING));
    }
}


/**
 *
 *@Desc: reading text file and plot data's graph
 *@Args: QFile *
 *@Returns: None
 *
 */
void
MarsFigure::readTextFile(QFile * file)
{

    QTextStream stream(file);
    QString data = stream.readAll();
    clearCurrentPlot();
    startPlot();
    plot(data);
}


/**
 *
 *@Desc: writting graph's data into text file
 *@Args: QFile *
 *@Returns: None
 *
 */
void
MarsFigure::writeTextFile(QFile * file)
{
    QTextStream out(file);
    int graphNumber = currentPloter->graphCount();
    if (graphNumber<=0)
        return ;
    int dataCount = currentPloter->graph(0)->dataCount();
    for( int j=0;j<dataCount;j++)
    {
        out<<currentPloter->graph(0)->dataMainKey(j);
        for(int i =0;i<graphNumber;i++)
        {
            out<<" "<<currentPloter->graph(i)->dataMainValue(j);
        }
        out<<"\n";
    }
}


/**
 *
 *@Desc: reading josn file and plot data's graph
 *@Args: QFile *
 *@Returns: None
 *
 */
void
MarsFigure::readJSONFile(QFile *file)
{


    QByteArray saveData=file->readAll();
    /* load data from json file */
    QJsonDocument document=QJsonDocument::fromJson(saveData);
    QJsonArray xArray=document.object().take("x").toArray();
    QJsonArray yArray=document.object().take("y").toArray();
    int size = xArray.size();
    QVector<double> xVector(size);
    QList<QVector<double> *> yVector;
    QList<QJsonArray> yArrayList;
    int graphNumber = yArray.size();
    /* check y axis value */
    for(int i=0;i<graphNumber;++i)
    {
        yArrayList.append(yArray.at(i).toArray());
        yVector.append(new QVector<double>(size));
    }
    /* convert json array to vector */
    for(int i=0;i<size;i++)
    {
        xVector.append(xArray.at(i).toDouble());
        for(int j =0;j<graphNumber;j++)
        {
            yVector.at(j)->append(yArrayList.at(j).at(i).toDouble());
        }
    }
    /* start ploting data */
    clearCurrentPlot();
    startPlot();

    for(int i=0;i<graphNumber;i++)
    {
        QVector<double> * y = yVector.at(i);
        plot(xVector,*y,i);
        delete y;
    }
}


/**
 *
 *@Desc: writting graph's data into json file
 *@Args: QFile * file
 *@Returns: None
 *
 */
void
MarsFigure::writeJSONFile(QFile * file)
{
    int graphNumber = currentPloter->graphCount();
    if (graphNumber<=0)
        return ;
    QJsonObject data;
    QJsonArray yValue;
    QVariantList xValueList;
    QList<QVariantList*> yValueList;
    for(int i =0;i<graphNumber;i++)
    {
        yValueList.append(new QVariantList);
    }
    int dataCount = currentPloter->graph(0)->dataCount();
    for( int j=0;j<dataCount;j++)
    {
        xValueList.append(currentPloter->graph(0)->dataMainKey(j));
        for(int i =0;i<graphNumber;i++)
        {
           yValueList.at(i)->append(currentPloter->graph(i)->dataMainValue(j));
        }
    }
    /* convert y axis value to VariantList */
    for(int i =0;i<graphNumber;i++)
    {
        yValue.append(QJsonArray::fromVariantList(*(yValueList.at(i))));
        delete yValueList.at(i);
    }
    /* convert x axis value variant list to json array*/
    data["x"]=QJsonArray::fromVariantList(xValueList);
    data["y"]=yValue;
    /* writing json document to file */
    QJsonDocument saveDocument(data);
    file->write(saveDocument.toJson());
}


/**
 *
 *@Desc: readding dat file and draw data's graph
 *@Args: QFile * file
 *@Returns: None
 *
 */
void
MarsFigure::readDatFile(QFile * file)
{
    QByteArray saveData=file->readAll();
    /* load data from dat file */
    QJsonDocument document=QJsonDocument::fromBinaryData(saveData);
    QJsonArray xArray=document.object().take("x").toArray();
    QJsonArray yArray=document.object().take("y").toArray();
    int size = xArray.size();
    QVector<double> xVector(size);
    QList<QVector<double> *> yVector;
    QList<QJsonArray> yArrayList;
    int graphNumber = yArray.size();
    /* check y axis value */
    for(int i=0;i<graphNumber;++i)
    {
        yArrayList.append(yArray.at(i).toArray());
        yVector.append(new QVector<double>(size));
    }
    /* convert json array to vector */
    for(int i=0;i<size;i++)
    {
        xVector.append(xArray.at(i).toDouble());
        for(int j =0;j<graphNumber;j++)
        {
            yVector.at(j)->append(yArrayList.at(j).at(i).toDouble());
        }
    }
    /* start ploting data */
    clearCurrentPlot();
    startPlot();
    for(int i=0;i<graphNumber;i++)
    {
        QVector<double> * y = yVector.at(i);
        plot(xVector,*y,i);
        delete y;
    }
}


/**
 *
 *@Desc: writting graph's data into dat file
 *@Args: QFile * file
 *@Returns: None
 *
 */
void
MarsFigure::writeDatFile(QFile * file)
{
    int graphNumber = currentPloter->graphCount();
    if (graphNumber<=0)
        return ;
    QJsonObject data;
    QJsonArray yValue;
    QVariantList xValueList;
    QList<QVariantList*> yValueList;
    for(int i =0;i<graphNumber;i++)
    {
        yValueList.append(new QVariantList);
    }
    int dataCount = currentPloter->graph(0)->dataCount();
    for( int j=0;j<dataCount;j++)
    {
        xValueList.append(currentPloter->graph(0)->dataMainKey(j));
        for(int i =0;i<graphNumber;i++)
        {
           yValueList.at(i)->append(currentPloter->graph(i)->dataMainValue(j));
        }
    }
    /* convert y axis value to VariantList */
    for(int i =0;i<graphNumber;i++)
    {
        yValue.append(QJsonArray::fromVariantList(*(yValueList.at(i))));
        delete yValueList.at(i);
    }
    /* convert x axis value variant list to json array*/
    data["x"]=QJsonArray::fromVariantList(xValueList);
    data["y"]=yValue;
    /* writing json document to binary file */
    QJsonDocument saveDocument(data);
    file->write(saveDocument.toBinaryData());
}


void
MarsFigure::changeCurrentPloterOnFocusIn(MarsPlot *focusInObj)
{
    int index = ploterContainer->indexOf(focusInObj);
    if(index<0)
        return ;
    maxValLabel->setText(QString("%1").arg(focusInObj->yMax, 0, 'f'));
    minValLabel->setText(QString("%1").arg(focusInObj->yMin, 0, 'f'));
    avgValLabel->setText(QString("%1").arg(focusInObj->yAvg, 0, 'f'));
    curXvalLabel->setText("0");
    curYvalLabel->setText("0");
    ploterNameListBox->setCurrentIndex(index);
}
