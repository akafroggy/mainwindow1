#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    
    connect(ui->actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::saveFile()
{
   
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Text Files (*.txt);;All Files (*)"));

    
    if (filePath.isEmpty())
        return;

   
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QMessageBox::warning(this, tr("Error"), tr("Cannot open file for writing"));
        return;
    }

    
    QTextStream out(&file);
    out << ui->textEdit->toPlainText(); // 將 QTextEdit 的內容寫入檔案

    file.close();
    QMessageBox::information(this, tr("Success"), tr("File saved successfully"));
}
