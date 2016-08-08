#ifndef FILELOAD_H
#define FILELOAD_H

#include <QDialog>

namespace Ui {
class FileLoad;
}

class FileLoad : public QDialog
{
  Q_OBJECT

public:
  explicit FileLoad(QWidget *parent = 0);
  ~FileLoad();

private slots:
  void on_loadScript_clicked();

private:
  Ui::FileLoad *m_ui;
};

#endif // FILELOAD_H
