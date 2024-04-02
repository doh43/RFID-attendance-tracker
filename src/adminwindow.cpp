/**
 * @file adminwindow.cpp
 * @brief The window that shows up when the admin logs into the system
*/
#include "../include/adminwindow.h"

AdminWindow::AdminWindow() {
  setupWindow();
  setupTable();
  pollDB();
}

void AdminWindow::setupWindow() {
  this->resize(1000,540);
  this->setWindowTitle("Admin Window");
  this->show();
}

void AdminWindow::pollDB() {
  QTimer *timer = new QTimer(this);
  connect(timer, &QTimer::timeout, this, &AdminWindow::setupTable);
  timer->start(10000);
}

void AdminWindow::setupTable() {
  table = new QTableWidget(100,5);

  QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
  db.setHostName("mysqlgroup10");
  db.setPort(3306);
  db.setDatabaseName("rfid_database");
  db.setUserName("root");
  db.setPassword("root"); //change later
  if (!db.open()) {
    qDebug() << "Database error occured: " << db.lastError().text();
  }
  QSqlQuery query;
  query.exec("SELECT UID, username, email, tap_count, last_scan_time FROM users");
  int row = 0;
  while (query.next()) {
    QString userid = query.value(0).toString();
    QString username = query.value(1).toString();
    QString email = query.value(2).toString();
    int tapcount = query.value(3).toInt();
    QString scantime = query.value(4).toString();

    QString loginstate = tapcount % 2 ? "Logged in":"Logged out";

    QTableWidgetItem *item1 = new QTableWidgetItem(userid);
    table->setItem(row, 0, item1);
    QTableWidgetItem *item2 = new QTableWidgetItem(username);
    table->setItem(row, 1, item2);
    QTableWidgetItem *item3 = new QTableWidgetItem(email);
    table->setItem(row, 2, item3);
    QTableWidgetItem *item4 = new QTableWidgetItem(scantime);
    table->setItem(row, 3, item4);
    QTableWidgetItem *item5 = new QTableWidgetItem(loginstate);
    table->setItem(row, 4, item5);
    row++;
  }
  // Set column headers
  QStringList headers;
  headers << "UserId" << "Username" << "Email" << "Time" << "Action";
  table->setHorizontalHeaderLabels(headers);
  table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
  table->setEditTriggers(QAbstractItemView::NoEditTriggers);
  // Show the table widget
  this->setCentralWidget(table);
}

void AdminWindow::closeWindow() {
  close();
}

AdminWindow::~AdminWindow() {
}
