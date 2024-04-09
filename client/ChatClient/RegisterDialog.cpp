#include "RegisterDialog.h"

#include "HttpMgr.h"

RegisterDialog::RegisterDialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::RegisterDialogClass()) {
  ui->setupUi(this);
  ui->pwd_edit->setEchoMode(QLineEdit::Password);
  ui->confirm_edit->setEchoMode(QLineEdit::Password);
  ui->err_tip->setProperty("state", "normal");
  repolish(ui->err_tip);
  connect(&HttpMgr::GetInstance(), &HttpMgr::sig_http_finish, this,
          &RegisterDialog::slot_reg_mod_finish);

  initHttpHandles();
}

RegisterDialog::~RegisterDialog() { delete ui; }

void RegisterDialog::on_get_code_btn_clicked() {
  // 验证邮箱的地址正则表达式
  auto email = ui->email_edit->text();
  // 邮箱地址的正则表达式
  QRegularExpression regex(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
  bool match = regex.match(email).hasMatch();  // 执行正则表达式匹配
  if (match) {
    // 发送http请求获取验证码
  }
  else {
    // 提示邮箱不正确
    showTip(tr("邮箱地址不正确"), false);
  }
}

void RegisterDialog::slot_reg_mod_finish(ReqId id, QString res,
                                         ErrorCodes err) {
  if (err != ErrorCodes::SUCCESS) {
    showTip(tr("网络请求错误"), false);
    return;
  }

  // 解析json字符串 res => QByteArray
  QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
  if (jsonDoc.isNull()) {
    showTip(tr("json解析失败"), false);
    return;
  }

  // json解析失败
  if (!jsonDoc.isObject()) {
    showTip(tr("json解析失败"), false);
    return;
  }

  _handlers[id](jsonDoc.object());

  return;
}

void RegisterDialog::showTip(QString str, bool b_ok) {
  if (b_ok) {
    ui->err_tip->setProperty("state", "normal");
  }
  else {
    ui->err_tip->setProperty("state", "err");
  }

  ui->err_tip->setText(str);

  repolish(ui->err_tip);
}

void RegisterDialog::initHttpHandles() {
  // 注册获取验证码回包逻辑
  _handlers.insert(ReqId::ID_GET_VARIFY_CODE,
                   [this](const QJsonObject& jsonObj) {
                     int error = jsonObj["error"].toInt();
                     if (error != ErrorCodes::SUCCESS) {
                       showTip(tr("参数错误"), false);
                       return;
                     }
                     auto email = jsonObj["email"].toString();
                     showTip(tr("验证码已发送到邮箱，注意查收"), true);
                     qDebug() << "email is " << email;
                   });

  // 用户注册逻辑
  _handlers.insert(ReqId::ID_REG_USER, [this](const QJsonObject& jsonObj) {
    int error = jsonObj["error"].toInt();
    if (error != ErrorCodes::SUCCESS) {
      showTip(tr("参数错误"), false);
      return;
    }
    auto email = jsonObj["email"].toString();
    showTip(tr("用户注册成功"), true);
    qDebug() << "email is " << email;
  });
}
