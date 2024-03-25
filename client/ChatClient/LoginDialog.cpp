#include "LoginDialog.h"

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent), ui(new Ui::LoginDialogClass()) {
  ui->setupUi(this);
  connect(ui->reg_btn, &QPushButton::clicked, this,
          &LoginDialog::SwitchRegister);
}

LoginDialog::~LoginDialog() { delete ui; }