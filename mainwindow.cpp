#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QtCore"
#include "QtGui"
#include "QFileDialog"
#include "QFile"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui-> textEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionBold_triggered()
{

}


void MainWindow::on_actionSuperscript_triggered()
{

}


void MainWindow::on_actionSubscript_triggered()
{

}


void MainWindow::on_actionNew_triggered()
{
       mFilename = "";
       ui->textEdit->setPlainText("");
}


void MainWindow::on_actionSave_triggered()
{
    QFile sFile(mFilename);
    if(sFile.open(QFile::WriteOnly | QFile::Text));
    {
        QTextStream out(&sFile);

        out << ui->textEdit->toPlainText();

        sFile.flush();
        sFile.close();
    }
}


void MainWindow::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this,"Open A File");
    {
    if(!file.isEmpty())
    {
        QFile sFile(file);
        if(sFile.open(QFile::ReadOnly | QFile::Text));
        {
            mFilename = file;
            QTextStream in (&sFile);
            QString text = in.readAll();
            sFile.close();

            ui->textEdit->setPlainText(text);

        }
      }

    }
}

