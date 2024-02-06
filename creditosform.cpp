#include "creditosform.h"
#include "ui_creditosform.h"
#include <QDesktopServices>
#include <QUrl>

CreditosForm::CreditosForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CreditosForm)
{
    ui->setupUi(this);

       // Establecer el texto del QLabel como un enlace HTML
       ui->linkGithub->setText("<a href=\"https://github.com/Hayai01/RegistroNotas\">Visitar GitHub</a>");

       // Conectar la señal linkActivated del QLabel al slot abrirEnlaceGithub
       connect(ui->linkGithub, &QLabel::linkActivated, this, &CreditosForm::on_linkGithub_linkActivated);
   }

   CreditosForm::~CreditosForm()
   {
       delete ui;
   }


void CreditosForm::on_linkGithub_linkActivated(const QString &link)
{
     QDesktopServices::openUrl(QUrl(link));
}

