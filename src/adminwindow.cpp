/* Represents the window that opens when an admin user logs in */
#include "../include/adminwindow.h"

AdminWindow::AdminWindow() {
  setupWindow();
  setupTable();
}

void AdminWindow::setupWindow() {
  this->resize(1000,540);
  this->setWindowTitle("Admin Window");
  this->show();
}

void AdminWindow::setupGrid() {
  gridLayout = new QGridLayout(this);
  gridLayout->setSpacing(0);
  gridLayout->setContentsMargins(0,0,0,0);
  this->setLayout(gridLayout);
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
  query.exec("SELECT * FROM users");
  while (query.next()) {
    int userid = query.value(0).toInt();
    QString username = query.value(1).toString();
    QString email = query.value(2).toString();
    qDebug() << userid << username << email;
  }

  // Populate the table with items
  for (int row = 0; row < 100; ++row) {
      for (int col = 0; col < 5; ++col) {
          QTableWidgetItem *item = new QTableWidgetItem(QString("Item %1,%2").arg(row).arg(col));
          table->setItem(row, col, item);
      }
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

void AdminWindow::generateReport() {
}

void AdminWindow::closeWindow() {
  close();
}

AdminWindow::~AdminWindow() {
}
