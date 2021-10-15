#ifndef SORTINGPROGRAM_H
#define SORTINGPROGRAM_H

#include <QMainWindow>
#include <QElapsedTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class SortingProgram; }
QT_END_NAMESPACE

class SortingProgram : public QMainWindow
{
    Q_OBJECT

public:
    SortingProgram(QWidget *parent = nullptr);
    ~SortingProgram();

private slots:
    void on_buttOntimeSort_released();
    void on_buttOncountSort_released();
    void on_buttTestingSort_released();

private:
    Ui::SortingProgram *ui;
    int *array;
};
#endif // SORTINGPROGRAM_H
