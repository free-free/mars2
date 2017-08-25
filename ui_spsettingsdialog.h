/********************************************************************************
** Form generated from reading UI file 'spsettingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPSETTINGSDIALOG_H
#define UI_SPSETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SPSettingsDialog
{
public:
    QGroupBox *selectPortBox;
    QGridLayout *gridLayout;
    QComboBox *serialPortInfoListBox;
    QLabel *descriptionLabel;
    QLabel *manufactureLabel;
    QLabel *serialPortNumberLabel;
    QLabel *locationLabel;
    QLabel *VendIdLabel;
    QLabel *productIdLabel;
    QGroupBox *portParamsBox;
    QGridLayout *gridLayout_2;
    QLabel *baudRateLabel;
    QComboBox *baudRateBox;
    QLabel *stopBitLabel;
    QComboBox *stopBitBox;
    QLabel *checkBitLabel;
    QComboBox *checkBitBox;
    QLabel *dataBitLabel;
    QComboBox *dataBitBox;
    QLabel *flowControlLabel;
    QComboBox *flowControlBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *spConfigApplyBtn;

    void setupUi(QDialog *SPSettingsDialog)
    {
        if (SPSettingsDialog->objectName().isEmpty())
            SPSettingsDialog->setObjectName(QStringLiteral("SPSettingsDialog"));
        SPSettingsDialog->resize(446, 349);
        selectPortBox = new QGroupBox(SPSettingsDialog);
        selectPortBox->setObjectName(QStringLiteral("selectPortBox"));
        selectPortBox->setGeometry(QRect(20, 10, 161, 261));
        gridLayout = new QGridLayout(selectPortBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        serialPortInfoListBox = new QComboBox(selectPortBox);
        serialPortInfoListBox->setObjectName(QStringLiteral("serialPortInfoListBox"));
        serialPortInfoListBox->setStyleSheet(QStringLiteral(""));

        gridLayout->addWidget(serialPortInfoListBox, 0, 0, 1, 1);

        descriptionLabel = new QLabel(selectPortBox);
        descriptionLabel->setObjectName(QStringLiteral("descriptionLabel"));

        gridLayout->addWidget(descriptionLabel, 1, 0, 1, 1);

        manufactureLabel = new QLabel(selectPortBox);
        manufactureLabel->setObjectName(QStringLiteral("manufactureLabel"));

        gridLayout->addWidget(manufactureLabel, 2, 0, 1, 1);

        serialPortNumberLabel = new QLabel(selectPortBox);
        serialPortNumberLabel->setObjectName(QStringLiteral("serialPortNumberLabel"));

        gridLayout->addWidget(serialPortNumberLabel, 3, 0, 1, 1);

        locationLabel = new QLabel(selectPortBox);
        locationLabel->setObjectName(QStringLiteral("locationLabel"));

        gridLayout->addWidget(locationLabel, 4, 0, 1, 1);

        VendIdLabel = new QLabel(selectPortBox);
        VendIdLabel->setObjectName(QStringLiteral("VendIdLabel"));

        gridLayout->addWidget(VendIdLabel, 5, 0, 1, 1);

        productIdLabel = new QLabel(selectPortBox);
        productIdLabel->setObjectName(QStringLiteral("productIdLabel"));

        gridLayout->addWidget(productIdLabel, 6, 0, 1, 1);

        portParamsBox = new QGroupBox(SPSettingsDialog);
        portParamsBox->setObjectName(QStringLiteral("portParamsBox"));
        portParamsBox->setGeometry(QRect(230, 10, 181, 271));
        gridLayout_2 = new QGridLayout(portParamsBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        baudRateLabel = new QLabel(portParamsBox);
        baudRateLabel->setObjectName(QStringLiteral("baudRateLabel"));

        gridLayout_2->addWidget(baudRateLabel, 0, 0, 1, 1);

        baudRateBox = new QComboBox(portParamsBox);
        baudRateBox->setObjectName(QStringLiteral("baudRateBox"));

        gridLayout_2->addWidget(baudRateBox, 0, 1, 1, 1);

        stopBitLabel = new QLabel(portParamsBox);
        stopBitLabel->setObjectName(QStringLiteral("stopBitLabel"));

        gridLayout_2->addWidget(stopBitLabel, 1, 0, 1, 1);

        stopBitBox = new QComboBox(portParamsBox);
        stopBitBox->setObjectName(QStringLiteral("stopBitBox"));

        gridLayout_2->addWidget(stopBitBox, 1, 1, 1, 1);

        checkBitLabel = new QLabel(portParamsBox);
        checkBitLabel->setObjectName(QStringLiteral("checkBitLabel"));

        gridLayout_2->addWidget(checkBitLabel, 2, 0, 1, 1);

        checkBitBox = new QComboBox(portParamsBox);
        checkBitBox->setObjectName(QStringLiteral("checkBitBox"));

        gridLayout_2->addWidget(checkBitBox, 2, 1, 1, 1);

        dataBitLabel = new QLabel(portParamsBox);
        dataBitLabel->setObjectName(QStringLiteral("dataBitLabel"));

        gridLayout_2->addWidget(dataBitLabel, 3, 0, 1, 1);

        dataBitBox = new QComboBox(portParamsBox);
        dataBitBox->setObjectName(QStringLiteral("dataBitBox"));

        gridLayout_2->addWidget(dataBitBox, 3, 1, 1, 1);

        flowControlLabel = new QLabel(portParamsBox);
        flowControlLabel->setObjectName(QStringLiteral("flowControlLabel"));

        gridLayout_2->addWidget(flowControlLabel, 4, 0, 1, 1);

        flowControlBox = new QComboBox(portParamsBox);
        flowControlBox->setObjectName(QStringLiteral("flowControlBox"));

        gridLayout_2->addWidget(flowControlBox, 4, 1, 1, 1);

        layoutWidget = new QWidget(SPSettingsDialog);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 300, 371, 35));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        spConfigApplyBtn = new QPushButton(layoutWidget);
        spConfigApplyBtn->setObjectName(QStringLiteral("spConfigApplyBtn"));

        horizontalLayout->addWidget(spConfigApplyBtn);


        retranslateUi(SPSettingsDialog);

        QMetaObject::connectSlotsByName(SPSettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SPSettingsDialog)
    {
        SPSettingsDialog->setWindowTitle(QApplication::translate("SPSettingsDialog", "Dialog", Q_NULLPTR));
        selectPortBox->setTitle(QApplication::translate("SPSettingsDialog", "   \351\200\211\346\213\251\344\270\262\345\217\243", Q_NULLPTR));
        descriptionLabel->setText(QApplication::translate("SPSettingsDialog", "\346\217\217\350\277\260:", Q_NULLPTR));
        manufactureLabel->setText(QApplication::translate("SPSettingsDialog", "\345\216\202\345\225\206:", Q_NULLPTR));
        serialPortNumberLabel->setText(QApplication::translate("SPSettingsDialog", "\344\270\262\345\217\243\345\217\267:", Q_NULLPTR));
        locationLabel->setText(QApplication::translate("SPSettingsDialog", "\344\275\215\347\275\256:", Q_NULLPTR));
        VendIdLabel->setText(QApplication::translate("SPSettingsDialog", "\345\216\202\345\225\206ID:", Q_NULLPTR));
        productIdLabel->setText(QApplication::translate("SPSettingsDialog", "\344\272\247\345\223\201ID:", Q_NULLPTR));
        portParamsBox->setTitle(QApplication::translate("SPSettingsDialog", "\344\270\262\345\217\243\345\217\202\346\225\260", Q_NULLPTR));
        baudRateLabel->setText(QApplication::translate("SPSettingsDialog", "\346\257\224\347\211\271\347\216\207", Q_NULLPTR));
        stopBitLabel->setText(QApplication::translate("SPSettingsDialog", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        checkBitLabel->setText(QApplication::translate("SPSettingsDialog", "\346\240\241\351\252\214\344\275\215", Q_NULLPTR));
        dataBitLabel->setText(QApplication::translate("SPSettingsDialog", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        flowControlLabel->setText(QApplication::translate("SPSettingsDialog", "\346\265\201\346\216\247\345\210\266", Q_NULLPTR));
        spConfigApplyBtn->setText(QApplication::translate("SPSettingsDialog", "\345\272\224\347\224\250", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SPSettingsDialog: public Ui_SPSettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPSETTINGSDIALOG_H
