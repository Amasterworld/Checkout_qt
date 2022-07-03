#include "checkout.h"
#include "ui_checkout.h"
#include "calcprice.h"

#include <QMessageBox> // to use QMessageBox
#include <QCloseEvent> // to deal when the user click to X in order to exit progrw
#include <QRegularExpression>
#include<QDebug>
CheckOut::CheckOut(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CheckOut)
{
    ui->setupUi(this);

    connect(ui->OkButton, SIGNAL(released()), this, SLOT(AgreeBasket()));

    connect(ui->actionExit, SIGNAL(triggered()), this, SLOT(actionToExitPressed()));

    connect(ui->actionAbout_Checkout, &QAction::triggered,
                this, // control object to avoid crash if the signal is emitted after the receiver is deleted.
                [this](){
                    AboutCheckout();
                });
  // name_of_drugs =  ui->drug_name_lineEdit->text();

}

CheckOut::~CheckOut()
{
    delete ui;
}
double CheckOut:: CalcTotalOfDiscountItems(const QString& item, int num_of_items, int percentage_discount, int  price){

    name_and_quantity_items[item] = num_of_items;
    // map the price to the item
    prices[item] = (double) price;

    Discount discount;
    discount.nums_of_items =  num_of_items;
    discount.percentage_discount = percentage_discount;

    // map the item to the discount structure to know the quantity of items that are discounting
    map_discount[item] = discount;

    for (auto it_items = name_and_quantity_items.begin(); it_items != name_and_quantity_items.end(); ++it_items) {
            // get name of item
            QString name_item = it_items->first;
            double price_item = prices.find(name_item)->second;
            //std::cout << "price of the " << name_item << " is " << price_item << std::endl;
            int quantity_items = it_items->second;
            //std::cout << "Quantity of the items is "<< quantity_items <<std::endl;
            // find whether the item is available:
            auto items = map_discount.find(name_item);
            // if the item is found
            if (items != map_discount.end()) {
                // because the items->second contains the struct Discount hence
                Discount discount = items->second;
                // if the available items discounting are >= the discount quantity


                if (quantity_items >= discount.nums_of_items) {
                    m_total = (double)discount.nums_of_items * (price_item * ((100.0 - (double)discount.percentage_discount) / 100));
                }


            }


        }
        return m_total;

}
void CheckOut::AgreeBasket(){
     QMessageBox msgBox;
     double temp_total{};
    // check whether the inputs are suitable with the data
    int quanity_drug = ui->quantity_lineEdit->text().toInt();
    int price =  ui->price_lineEdit->text().toInt();
    int  discount_percentahge = ui->percentage_discount_lineEdit->text().toInt();
    if (quanity_drug < 0|| price < 0 || discount_percentahge < 0){
        msgBox.setText("Please re-check, the information should be positive number ");
        msgBox.exec();
    }

    else{
        msgBox.setText("Do you want to buy this drug?");
        msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        msgBox.setDefaultButton(QMessageBox::Yes); // set default button

        int ret = msgBox.exec(); // Shows the message box as a modal dialog, blocking until the user closes it.
            switch (ret){
            case QMessageBox::Yes: // Yes was clicked
                    name_of_drugs =  ui->drug_name_lineEdit->text();

                    //quanity_drugs = ui->quantity_lineEdit->text();
                    //price =  ui->price_lineEdit->text();

                   // discount_percentahge = ui->percentage_discount_lineEdit->text();
                    //qInfo() << "the name of drugs "<<name_of_drugs;

                   temp_total= CalcTotalOfDiscountItems(name_of_drugs, quanity_drug, discount_percentahge, price);

            case QMessageBox::No: // No was clicked

                    break;
            default:
                // should never be reached
                   break;
            }
    }
    ui->total_lineEdit->setText(QString::number(temp_total));
}
void CheckOut::actionToExitPressed(){



        QApplication::quit(); // it will call closeEvent function whenever QApplication::quit() is called.

}

void CheckOut::closeEvent(QCloseEvent *event){ // show prompt when user wants to close app by X icon

    event->ignore();

    if (QMessageBox::Yes == QMessageBox::question(this, "Close Confirmation", "Do you really want to exit?", QMessageBox::No| QMessageBox::Yes))
    {
        event->accept();
    }

}

void CheckOut::AboutCheckout(){

    QString str;

    str = QString(" Checkout ver 1.0.0, July 2022.\n This program is made to calculate the price of drug \n when the client applies the voucher. \n The program also was tested by unit tests. \n Please report bugs via the tracking systems at...");
    QMessageBox::information(0, "About Checkout", str);
   }



