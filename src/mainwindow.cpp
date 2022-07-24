#include "include/mainwindow.h"
#include "ui_mainwindow.h"
#include <QQmlContext>

MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent)
  , ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  setFixedSize(800, 500);
  ui->quickContainer->rootContext()->setContextProperty("mainWindow", this);
  ui->quickContainer->setSource(QUrl("qrc:/ui/TileMap.qml"));
  ui->quickContainer->show();
  connect(ui->updCoordBtn, &QPushButton::clicked, this, &MainWindow::onOkBtnClick);
}

MainWindow::~MainWindow()
{
  delete ui;
}

void MainWindow::onOkBtnClick()
{
  auto lon = ui->lonLineEdit->text().toDouble();
  auto lat = ui->latLineEdit->text().toDouble();
  emit changeCoord(lon, lat);
}

