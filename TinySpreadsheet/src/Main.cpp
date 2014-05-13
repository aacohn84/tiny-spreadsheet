#include "ui_spreadsheet.h"
#include <QtWidgets\qapplication.h>
#include <iostream>
#include <QtWidgets\qspinbox.h>
#include <QtWidgets\qtreewidget.h>
#include <QtWidgets\qpushbutton.h>
#include <QtCore\qobject.h>
#include <QtGui\qpalette.h>
#include "core\DAG.h"
#include "core\Evaluator.h"

//https://www.youtube.com/watch?v=cLvxLkgHqQs

using namespace std;
using namespace core;

class SpreadsheetView : public QMainWindow, public Ui_MainWindow
{
public:
	SpreadsheetView() : QMainWindow()
	{
		this->setupUi(this);

		//QObject::connect(lineEdit, SIGNAL("lksjdf"), 
		//QObject::connect(lineEdit_13, SIGNAL(editingFinished()), this, SLOT(clear()));
	}
};

class SpreadsheetApp : public QApplication
{
public:
	DAG *dag;
	Evaluator *eval;
	SpreadsheetView *view;

	SpreadsheetApp(int argc, char *argv[]) : QApplication(argc, argv) 
	{ 
		dag = new core::DAG();
		eval = new Evaluator(dag);
		view = new SpreadsheetView();

		view->show();
	}

	bool notify(QObject *object, QEvent *e)
	{
		if(object->objectName().toStdString() == "spreadsheetCell")
		{
			if(e->type() == e->FocusOut)
				focusOut((QLineEdit*)object, e);
			else if(e->type() == e->FocusIn)
				focusIn((QLineEdit*)object, e);
		}
		
		else if(e->type() == e->Close || (object->objectName().toStdString() == "actionNew" && e->type() == e->Shortcut))
		{
			clearSpreadsheet();
		}

		//cout << object->objectName().toStdString() << "::" << e->type() << endl;

		return QApplication::notify(object, e);
	}

	void clearSpreadsheet()
	{
		std::map<std::string, core::Cell*> *map = dag->getMap();
		for(auto pair : *map)
		{
			//Get pair data
			string coord = pair.first;
			Cell *auxCell = (core::Cell *) pair.second;

			int col = coord.at(0) - 'A' + 1;
			int row = coord.at(1) - '0';
			
			//Get the box in the grid
			QWidget *aux = view->gridLayout->itemAtPosition(row, col)->widget();

			QPalette p;
			p.setColor(QPalette::Text, Qt::black);
			aux->setPalette(p);
			view->gridLayout->itemAtPosition(row, 0)->widget()->setPalette(p);
			view->gridLayout->itemAtPosition(0, col)->widget()->setPalette(p);

			aux->setProperty("text", "");
			aux->setProperty("displayValue", "");
			aux->setProperty("rawValue", "");
			aux->setProperty("errorMessage", "");

			//Cell *cleanCell = new Cell(coord, "");
			//eval->evaluate(cleanCell);
			auxCell->rawInput = "";
		}
		eval->evalAllCells();
	}

	void focusIn(QLineEdit *object, QEvent *e)
	{
		if(!object->property("rawText").isNull())
		{
			object->setText(object->property("rawText").toString());
		}

		string coord = object->property("cellLocation").toString().toStdString();
		int col = coord.at(0) - 'A' + 1;
		int row = coord.at(1) - '0';

		//Get the grid
		QWidget *gridWidget = object->parentWidget();
		QGridLayout *grid = (QGridLayout *) gridWidget->children().at(0);

		QFont font;
		font.setUnderline(true);
		font.setBold(true);
		font.setWeight(75);
		grid->itemAtPosition(row, 0)->widget()->setFont(font);
		grid->itemAtPosition(0, col)->widget()->setFont(font);

		QPalette p;
		p.setColor(QPalette::Foreground, Qt::red);
		grid->itemAtPosition(row, 0)->widget()->setPalette(p);
		grid->itemAtPosition(0, col)->widget()->setPalette(p);
	}

	void focusOut(QLineEdit *object, QEvent *e)
	{
		//Get lineEdit data
		string coord = object->property("cellLocation").toString().toStdString();
		string value = object->property("text").toString().toStdString();

		//Write lineEdit data to cell
		bool shouldRecord = (object->property("rawText").isNull()) ? value != "" : true;
		if(shouldRecord)
		{
			Cell *cell = new Cell(coord, value);
			eval->evaluate(cell);
			eval->evalAllCells();
			object->setProperty("rawText", value.c_str());
		}

		//Get the grid
		QWidget *gridWidget = object->parentWidget();
		QGridLayout *grid = (QGridLayout *) gridWidget->children().at(0);

		int col = coord.at(0) - 'A' + 1;
		int row = coord.at(1) - '0';

		//Unemphasize col/row headers
		QFont font;
		font.setUnderline(false);
		font.setBold(false);
		grid->itemAtPosition(row, 0)->widget()->setFont(font);
		grid->itemAtPosition(0, col)->widget()->setFont(font);

		QPalette p;
		p.setColor(QPalette::Foreground, Qt::black);
		grid->itemAtPosition(row, 0)->widget()->setPalette(p);
		grid->itemAtPosition(0, col)->widget()->setPalette(p);

		//Populate all cells with updated data
		std::map<std::string, core::Cell*> *map = dag->getMap();
		for(auto pair : *map)
		{
			//Get pair data
			string coord = pair.first;
			core::Cell *auxCell = (core::Cell *) pair.second;

			int col = coord.at(0) - 'A' + 1;
			int row = coord.at(1) - '0';
			
			//Get the box in the grid
			QWidget *aux = grid->itemAtPosition(row, col)->widget();

			QPalette p;
			if(auxCell->errorMessage != "No errors.")
				p.setColor(QPalette::Text, Qt::red);
			else if(auxCell->dependencies.size() > 0)
				p.setColor(QPalette::Text, Qt::blue);
			else
				p.setColor(QPalette::Text, Qt::black);
			aux->setPalette(p);

			string displayValue;
			if(auxCell->errorMessage != "No errors.")
			{
				displayValue = auxCell->errorMessage;
			}
			else if(auxCell->hasNumValue)
			{
				displayValue = to_string(auxCell->numValue);
			}
			else
			{
				displayValue = auxCell->displayValue;
			}
			cout << auxCell->hasError << endl;
			aux->setProperty("text", displayValue.c_str());
			aux->setProperty("displayValue", displayValue.c_str());
			aux->setProperty("cursorPosition", 0);
		}

		eval->printAllCells();
	}
};

int main(int argc, char *argv[])
{
	SpreadsheetApp app(argc, argv);

    return app.exec();
}
