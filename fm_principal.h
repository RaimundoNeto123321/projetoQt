#ifndef FM_PRINCIPAL_H
#define FM_PRINCIPAL_H

#include <QMainWindow>
#include <QtSql>

namespace Ui {
class Fm_principal;
}

class Fm_principal : public QMainWindow
{
    Q_OBJECT

public:
    explicit Fm_principal(QWidget *parent = nullptr);
    ~Fm_principal();
    QIcon cadFechado;
    QIcon *cadAberto=new QIcon();

private slots:
    void on_btn_bloquear_clicked();

    void on_pushButton_2_clicked();

    void on_actionEstoque_triggered();

    void on_actionColaboradores_triggered();

    void on_actionVendas_triggered();

private:
    Ui::Fm_principal *ui;
};

#endif // FM_PRINCIPAL_H
