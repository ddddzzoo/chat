#pragma once

#include <QtWidgets/QMainWindow>

#include "LoginDialog.h"
#include "RegisterDialog.h"
#include "ui_MainWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindowClass;
};
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 public slots:
  void SlotSwitchReg();

 private:
  Ui::MainWindowClass *ui;
  LoginDialog *_login_dlg;
  RegisterDialog *_reg_dlg;
};