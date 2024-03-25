#include "Global.h"

std::function<void(QWidget*)> repolish = [](QWidget* w) {
  w->style()->unpolish(w);
  w->style()->polish(w);
};