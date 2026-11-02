/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 6.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDark_Mode;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionDisplay_Name;
    QAction *actionExport_CSV;
    QAction *actionUndo;
    QAction *actionQuit;
    QAction *actionDark_Mode_New;
    QAction *actionShow_Subcategory_Totals;
    QAction *actionKeyboard_Shortcuts;
    QAction *actionAbout;
    QAction *actionShow_Toolbar;
    QAction *actionGuide;
    QAction *actionShow_Username_in_Window_Title;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QFrame *frame_2;
    QFrame *frame_3;
    QFrame *frame_4;
    QFrame *frame_8;
    QLabel *timerLabel;
    QLabel *pauseLabel;
    QFrame *frame_5;
    QFrame *frame;
    QFrame *frame_6;
    QFrame *frame_7;
    QTreeWidget *logTreeWidget;
    QTreeWidget *categoryTreeWidget;
    QWidget *page_2;
    QMenuBar *menubar;
    QMenu *menuFile;
    QMenu *menuView;
    QMenu *menuHelp;
    QMenu *menuSettings;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(975, 637);
        actionDark_Mode = new QAction(MainWindow);
        actionDark_Mode->setObjectName("actionDark_Mode");
        actionCopy = new QAction(MainWindow);
        actionCopy->setObjectName("actionCopy");
        actionPaste = new QAction(MainWindow);
        actionPaste->setObjectName("actionPaste");
        actionDisplay_Name = new QAction(MainWindow);
        actionDisplay_Name->setObjectName("actionDisplay_Name");
        actionExport_CSV = new QAction(MainWindow);
        actionExport_CSV->setObjectName("actionExport_CSV");
        actionUndo = new QAction(MainWindow);
        actionUndo->setObjectName("actionUndo");
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName("actionQuit");
        actionDark_Mode_New = new QAction(MainWindow);
        actionDark_Mode_New->setObjectName("actionDark_Mode_New");
        actionShow_Subcategory_Totals = new QAction(MainWindow);
        actionShow_Subcategory_Totals->setObjectName("actionShow_Subcategory_Totals");
        actionKeyboard_Shortcuts = new QAction(MainWindow);
        actionKeyboard_Shortcuts->setObjectName("actionKeyboard_Shortcuts");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        actionShow_Toolbar = new QAction(MainWindow);
        actionShow_Toolbar->setObjectName("actionShow_Toolbar");
        actionGuide = new QAction(MainWindow);
        actionGuide->setObjectName("actionGuide");
        actionShow_Username_in_Window_Title = new QAction(MainWindow);
        actionShow_Username_in_Window_Title->setObjectName("actionShow_Username_in_Window_Title");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        gridLayout_2 = new QGridLayout(page);
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox = new QGroupBox(page);
        groupBox->setObjectName("groupBox");
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        frame_2 = new QFrame(groupBox);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout->addWidget(frame_2);

        frame_3 = new QFrame(groupBox);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout->addWidget(frame_3);

        frame_4 = new QFrame(groupBox);
        frame_4->setObjectName("frame_4");
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout->addWidget(frame_4);

        frame_8 = new QFrame(groupBox);
        frame_8->setObjectName("frame_8");
        frame_8->setFrameShape(QFrame::Shape::StyledPanel);
        frame_8->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout->addWidget(frame_8);

        timerLabel = new QLabel(groupBox);
        timerLabel->setObjectName("timerLabel");
        QFont font;
        font.setPointSize(40);
        font.setBold(true);
        font.setUnderline(false);
        font.setStrikeOut(false);
        timerLabel->setFont(font);
        timerLabel->setContextMenuPolicy(Qt::ContextMenuPolicy::DefaultContextMenu);

        verticalLayout->addWidget(timerLabel, 0, Qt::AlignmentFlag::AlignHCenter);

        pauseLabel = new QLabel(groupBox);
        pauseLabel->setObjectName("pauseLabel");

        verticalLayout->addWidget(pauseLabel, 0, Qt::AlignmentFlag::AlignHCenter);

        frame_5 = new QFrame(groupBox);
        frame_5->setObjectName("frame_5");
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout->addWidget(frame_5);

        frame = new QFrame(groupBox);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout->addWidget(frame);

        frame_6 = new QFrame(groupBox);
        frame_6->setObjectName("frame_6");
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout->addWidget(frame_6);

        frame_7 = new QFrame(groupBox);
        frame_7->setObjectName("frame_7");
        frame_7->setFrameShape(QFrame::Shape::StyledPanel);
        frame_7->setFrameShadow(QFrame::Shadow::Raised);

        verticalLayout->addWidget(frame_7);

        logTreeWidget = new QTreeWidget(groupBox);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setTextAlignment(1, Qt::AlignCenter);
        logTreeWidget->setHeaderItem(__qtreewidgetitem);
        logTreeWidget->setObjectName("logTreeWidget");

        verticalLayout->addWidget(logTreeWidget);


        gridLayout_2->addWidget(groupBox, 0, 1, 1, 1);

        categoryTreeWidget = new QTreeWidget(page);
        QFont font1;
        font1.setBold(true);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setTextAlignment(1, Qt::AlignCenter);
        __qtreewidgetitem1->setFont(1, font1);
        __qtreewidgetitem1->setText(0, QString::fromUtf8("Categories"));
        __qtreewidgetitem1->setTextAlignment(0, Qt::AlignCenter);
        __qtreewidgetitem1->setFont(0, font1);
        categoryTreeWidget->setHeaderItem(__qtreewidgetitem1);
        categoryTreeWidget->setObjectName("categoryTreeWidget");
        categoryTreeWidget->setMinimumSize(QSize(467, 0));

        gridLayout_2->addWidget(categoryTreeWidget, 0, 0, 1, 1);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        gridLayout->addWidget(stackedWidget, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 975, 33));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        menuView = new QMenu(menubar);
        menuView->setObjectName("menuView");
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName("menuHelp");
        menuSettings = new QMenu(menubar);
        menuSettings->setObjectName("menuSettings");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menubar->addAction(menuView->menuAction());
        menubar->addAction(menuSettings->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionExport_CSV);
        menuFile->addAction(actionQuit);
        menuView->addAction(actionDark_Mode_New);
        menuView->addAction(actionShow_Subcategory_Totals);
        menuView->addAction(actionShow_Toolbar);
        menuView->addAction(actionShow_Username_in_Window_Title);
        menuHelp->addAction(actionGuide);
        menuHelp->addAction(actionAbout);
        menuSettings->addAction(actionDisplay_Name);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "TimeBranchr2", nullptr));
        actionDark_Mode->setText(QCoreApplication::translate("MainWindow", "Dark Mode", nullptr));
        actionCopy->setText(QCoreApplication::translate("MainWindow", "Copy (Ctrl+C)", nullptr));
        actionPaste->setText(QCoreApplication::translate("MainWindow", "Paste (Ctrl+V)", nullptr));
        actionDisplay_Name->setText(QCoreApplication::translate("MainWindow", "Change Display Name", nullptr));
        actionExport_CSV->setText(QCoreApplication::translate("MainWindow", "Export (CSV)", nullptr));
        actionUndo->setText(QCoreApplication::translate("MainWindow", "Undo (Ctrl+Z)", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        actionDark_Mode_New->setText(QCoreApplication::translate("MainWindow", "Dark Mode", nullptr));
        actionShow_Subcategory_Totals->setText(QCoreApplication::translate("MainWindow", "Show Subcategory Totals", nullptr));
        actionKeyboard_Shortcuts->setText(QCoreApplication::translate("MainWindow", "Keyboard Shortcuts", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        actionShow_Toolbar->setText(QCoreApplication::translate("MainWindow", "Show Toolbar", nullptr));
        actionGuide->setText(QCoreApplication::translate("MainWindow", "Guide", nullptr));
        actionShow_Username_in_Window_Title->setText(QCoreApplication::translate("MainWindow", "Show Username in Window Title", nullptr));
        groupBox->setTitle(QString());
        timerLabel->setText(QCoreApplication::translate("MainWindow", "00:00:00", nullptr));
        pauseLabel->setText(QCoreApplication::translate("MainWindow", "Paused", nullptr));
        QTreeWidgetItem *___qtreewidgetitem = logTreeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QCoreApplication::translate("MainWindow", "DateTime", nullptr));
        ___qtreewidgetitem->setText(0, QCoreApplication::translate("MainWindow", "Logs", nullptr));
        QTreeWidgetItem *___qtreewidgetitem1 = categoryTreeWidget->headerItem();
        ___qtreewidgetitem1->setText(1, QCoreApplication::translate("MainWindow", "Time", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuView->setTitle(QCoreApplication::translate("MainWindow", "View", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainWindow", "Help", nullptr));
        menuSettings->setTitle(QCoreApplication::translate("MainWindow", "Settings", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
