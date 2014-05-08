/********************************************************************************
** Form generated from reading UI file 'SpreadsheetUigq2476.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef SPREADSHEETUIGQ2476_H
#define SPREADSHEETUIGQ2476_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

/*
//Q_OBJECT WORKS: can use for slots and signals eventually
class Q_WIDGETS_EXPORT TLineEdit : public QLineEdit
{
	Q_OBJECT

	Q_PROPERTY(QString cellLocation READ cellLocation WRITE cellLocation)
};
*/

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionClose;
    QWidget *centralwidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_5;
    QLineEdit *lineEdit_4;
    QLineEdit *lineEdit_6;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_7;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_9;
    QLineEdit *lineEdit_10;
    QLineEdit *lineEdit_11;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_12;
    QLineEdit *lineEdit_13;
    QLineEdit *lineEdit_14;
    QLineEdit *lineEdit_15;
    QLineEdit *lineEdit_16;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);

		//Menu bar
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
		actionNew->setShortcut(QKeySequence(QKeySequence::New));
        
		//Make central
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));

		//Make grid
        gridLayoutWidget = new QWidget(centralwidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 791, 541));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(20,0,20,0);

		//Populate with cells
		for(int row = 0; row < 10; row++)
		{
			for(int col = 0; col < 10; col++)
			{
				QWidget *line;
				
				//If label
				if(row == 0 || col == 0)
				{
					line = new QLabel(gridLayoutWidget);
					line->setObjectName(QStringLiteral("spreadsheetLabel"));

					QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
					sizePolicy.setHorizontalStretch(0);
					sizePolicy.setVerticalStretch(0);
					sizePolicy.setHeightForWidth(line->sizePolicy().hasHeightForWidth());
					line->setSizePolicy(sizePolicy);

					line->setProperty("alignment", Qt::AlignCenter);

					char location[20];
					if(row == 0 && col > 0)
					{
						sprintf_s(location, 20, "%c", col+'A'-1);
						line->setProperty("text", location);
					}
					else if(col == 0 && row > 0)
					{
						sprintf_s(location, 20, "%d", row);
						line->setProperty("text", location);
					}
				}

				//If cell
				else
				{
					line = new QLineEdit(gridLayoutWidget);
					line->setObjectName(QStringLiteral("spreadsheetCell"));

					char location[20];
					sprintf_s(location, 20, "%c%d", col+'A'-1, row);
					line->setProperty("cellLocation", location);
				}

				gridLayout->addWidget(line, row, col, 1, 1);
			}
		}

		/*
        lineEdit_5 = new QLineEdit(gridLayoutWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 1, 0, 1, 1);

        lineEdit_4 = new QLineEdit(gridLayoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 0, 3, 1, 1);

        lineEdit_6 = new QLineEdit(gridLayoutWidget);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 1, 1, 1, 1);

        lineEdit_3 = new QLineEdit(gridLayoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 0, 2, 1, 1);

        lineEdit_7 = new QLineEdit(gridLayoutWidget);
        lineEdit_7->setObjectName(QStringLiteral("lineEdit_7"));

        gridLayout->addWidget(lineEdit_7, 1, 2, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 0, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 0, 1, 1, 1);

        lineEdit_9 = new QLineEdit(gridLayoutWidget);
        lineEdit_9->setObjectName(QStringLiteral("lineEdit_9"));

        gridLayout->addWidget(lineEdit_9, 2, 0, 1, 1);

        lineEdit_10 = new QLineEdit(gridLayoutWidget);
        lineEdit_10->setObjectName(QStringLiteral("lineEdit_10"));

        gridLayout->addWidget(lineEdit_10, 2, 1, 1, 1);

        lineEdit_11 = new QLineEdit(gridLayoutWidget);
        lineEdit_11->setObjectName(QStringLiteral("lineEdit_11"));

        gridLayout->addWidget(lineEdit_11, 2, 2, 1, 1);

        lineEdit_8 = new QLineEdit(gridLayoutWidget);
        lineEdit_8->setObjectName(QStringLiteral("lineEdit_8"));

        gridLayout->addWidget(lineEdit_8, 1, 3, 1, 1);

        lineEdit_12 = new QLineEdit(gridLayoutWidget);
        lineEdit_12->setObjectName(QStringLiteral("lineEdit_12"));

        gridLayout->addWidget(lineEdit_12, 2, 3, 1, 1);

        lineEdit_13 = new QLineEdit(gridLayoutWidget);
        lineEdit_13->setObjectName(QStringLiteral("lineEdit_13"));

        gridLayout->addWidget(lineEdit_13, 3, 0, 1, 1);

        lineEdit_14 = new QLineEdit(gridLayoutWidget);
        lineEdit_14->setObjectName(QStringLiteral("lineEdit_14"));

        gridLayout->addWidget(lineEdit_14, 3, 1, 1, 1);

        lineEdit_15 = new QLineEdit(gridLayoutWidget);
        lineEdit_15->setObjectName(QStringLiteral("lineEdit_15"));

        gridLayout->addWidget(lineEdit_15, 3, 2, 1, 1);

        lineEdit_16 = new QLineEdit(gridLayoutWidget);
        lineEdit_16->setObjectName(QStringLiteral("lineEdit_16"));

        gridLayout->addWidget(lineEdit_16, 3, 3, 1, 1);
		*/

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionNew);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Tiny Spreadsheet", 0));
        actionNew->setText(QApplication::translate("MainWindow", "New", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // SPREADSHEETUIGQ2476_H
