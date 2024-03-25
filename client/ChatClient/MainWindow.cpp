#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindowClass()) {
  ui->setupUi(this);

  _login_dlg = new LoginDialog(this);
  setCentralWidget(_login_dlg);

  // 创建和注册消息链接
  connect(_login_dlg, &LoginDialog::SwitchRegister, this,
          &MainWindow::SlotSwitchReg);

  _reg_dlg = new RegisterDialog(this);
  _reg_dlg->hide();

  _login_dlg->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
  _reg_dlg->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::SlotSwitchReg() {
  setCentralWidget(_reg_dlg);
  _login_dlg->hide();
  _reg_dlg->show();
}
