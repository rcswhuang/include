#ifndef HGRAPHPAGE_H
#define HGRAPHPAGE_H

#include <QDialog>

namespace Ui {
class HGraphPage;
}

class HGraphPage : public QDialog
{
    Q_OBJECT

public:
    explicit HGraphPage(QWidget *parent = 0);
    ~HGraphPage();

private:
    Ui::HGraphPage *ui;
};

#endif // HGRAPHPAGE_H
