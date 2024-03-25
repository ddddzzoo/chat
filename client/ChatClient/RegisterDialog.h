#pragma once

#include <QDialog>

#include "ui_RegisterDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class RegisterDialogClass;
};
QT_END_NAMESPACE

class RegisterDialog : public QDialog {
  Q_OBJECT

 public:
  RegisterDialog(QWidget *parent = nullptr);
  ~RegisterDialog();

 private slots:
  void on_get_code_btn_clicked();

 private:
  void showTip(QString str, bool b_ok);

  Ui::RegisterDialogClass *ui;
};
