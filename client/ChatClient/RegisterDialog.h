#pragma once

#include <QDialog>

#include "Global.h"
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
  void slot_reg_mod_finish(ReqId id, QString res, ErrorCodes err);

 private:
  void showTip(QString str, bool b_ok);

  void initHttpHandles();

  Ui::RegisterDialogClass *ui;
  QMap < ReqId, std::function<void(const QJsonObject &)>> _handlers;
};
