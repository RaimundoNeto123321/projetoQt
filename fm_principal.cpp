#include "fm_principal.h"
#include "ui_fm_principal.h"
#include <QMessageBox>
#include "fm_logar.h"
#include "fm_novavenda.h"
#include "fm_gestaocolaboradores.h"
#include "fm_gestaoestoque.h"
#include "fm_gestaovendas.h"
#include "variaveis_globais.h"

int variaveis_globais::id_colab;
QString variaveis_globais::nome_colab;
QString variaveis_globais::acesso_colab;
QString variaveis_globais::username_colab;
bool variaveis_globais::logado;

Fm_principal::Fm_principal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Fm_principal)
{
    ui->setupUi(this);

    variaveis_globais::logado=false;
    cadFechado.addFile(":/imagens/imgs/cadeado_fechado.png");
    cadAberto->addFile(":/imagens/imgs/cadeado_aberto.png");

    ui->btn_bloquear->setText("");
    ui->btn_bloquear->setIcon(cadFechado);
    ui->statusBar->addWidget(ui->btn_bloquear);
    ui->statusBar->addWidget(ui->lb_nome);
}

Fm_principal::~Fm_principal()
{
    delete ui;
}

void Fm_principal::on_btn_bloquear_clicked()
{
    if(!variaveis_globais::logado){
        fm_logar f_logar;
        f_logar.exec();
        if(variaveis_globais::logado){
            ui->btn_bloquear->setIcon(*cadAberto);
            ui->lb_nome->setText(variaveis_globais::nome_colab);
        }
    }else{
        variaveis_globais::logado=false;
        ui->btn_bloquear->setIcon(cadFechado);
        ui->lb_nome->setText("Sem Colaborador");
    }
}

void Fm_principal::on_pushButton_2_clicked()
{
    if(variaveis_globais::logado){
        fm_novavenda f_novavenda;
        f_novavenda.exec();
    }else{
        QMessageBox::information(this,"LOGIN","Não existe colaborador logado","OK");
    }
}

void Fm_principal::on_actionEstoque_triggered()
{
    if(variaveis_globais::logado){
        if(variaveis_globais::acesso_colab=="A"){
            fm_gestaoEstoque f_gestaoEstoque;
            f_gestaoEstoque.exec();
        }else{
            QMessageBox::information(this,"ACESSO","Acesso não permitido","OK");
        }
    }else{
        QMessageBox::information(this,"LOGIN","Não existe colaborador logado","OK");
    }
}

void Fm_principal::on_actionColaboradores_triggered()
{
    if(variaveis_globais::logado){
        if(variaveis_globais::acesso_colab=="A"){
            fm_gestaoColaboradores f_gestaoColaboradores;
            f_gestaoColaboradores.exec();
        }else{
            QMessageBox::information(this,"ACESSO","Acesso não permitido","OK");
        }
    }else{
        QMessageBox::information(this,"LOGIN","Não existe colaborador logado","OK");
    }
}

void Fm_principal::on_actionVendas_triggered()
{
    if(variaveis_globais::logado){
        if(variaveis_globais::acesso_colab=="A"){
            fm_gestaoVendas f_gestaoVendas;
            f_gestaoVendas.exec();
        }else{
            QMessageBox::information(this,"ACESSO","Acesso não permitido","OK");
        }
    }else{
        QMessageBox::information(this,"LOGIN","Não existe colaborador logado","OK");
    }
}
