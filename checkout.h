#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class CheckOut; }
QT_END_NAMESPACE

class CheckOut : public QMainWindow
{
    Q_OBJECT

public:
    CheckOut(QWidget *parent = nullptr);
    ~CheckOut();

    QString name_of_drugs{};
    QString quanity_drugs{};
    QString price{};
    QString discount_percentahge{};


protected:
    struct Discount {
            int nums_of_items{};
            int percentage_discount{};

    };

    std::map<QString, double > prices;
    std::map<QString, Discount > map_discount;
    std::map<QString, int > name_and_quantity_items;

    double m_total{};

private:
    Ui::CheckOut *ui;
    double CalcTotalOfDiscountItems(const QString& item, int num_of_items, int percentage_discount, int  price);


private slots:

    void actionToExitPressed();
    void AgreeBasket();
    void AboutCheckout();
    void closeEvent(QCloseEvent* );
};
#endif // CHECKOUT_H
