#include "sortingprogram.h"
#include "ui_sortingprogram.h"

#include "sortingalgorithms.hpp"

SortingProgram::SortingProgram(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SortingProgram)
{
    ui->setupUi(this);
}

SortingProgram::~SortingProgram()
{
    delete ui;
}

void SortingProgram::on_buttOntimeSort_released()
{
    array = new int[ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt()];

    SortingAlgorithms::ArrayProcessing<int>::generatedArray(array, ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt(), 10, 1989);

    QElapsedTimer *timer = new QElapsedTimer;
    timer->start();

    if(ui->sortingMethod_box->currentIndex() == 0)
    {
        SortingAlgorithms::InsertSort<int>::insert_sort(array, ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt());
    }
    else if(ui->sortingMethod_box->currentIndex() == 1)
    {
        SortingAlgorithms::BubbleSort<int>::bubble_sort(array, ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt());
    }
    else if(ui->sortingMethod_box->currentIndex() == 2)
    {
        SortingAlgorithms::CocktailShakerSort<int>::cocktail_shaker_sort(array, ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt());
    }
    else if(ui->sortingMethod_box->currentIndex() == 3)
    {
        SortingAlgorithms::MergeSort<int>::merge_sort(array, 0, ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt() - 1);
    }
    else if(ui->sortingMethod_box->currentIndex() == 4)
    {
        SortingAlgorithms::HeapSort<int>::heap_sort(array, ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt());
    }
    else if(ui->sortingMethod_box->currentIndex() == 5)
    {
        SortingAlgorithms::QuickSort<int>::quick_sort(array, 0, ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt() - 1);
    }
    else if(ui->sortingMethod_box->currentIndex() == 6)
    {
        SortingAlgorithms::CountingSort<int>::counting_sort(array, ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt());
    }
    else if(ui->sortingMethod_box->currentIndex() == 7)
    {
        SortingAlgorithms::RadixSort<int>::radix_sort(array, ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt());
    }

    ui->line_nanotime->setText(QString::number(timer->nsecsElapsed()));
    delete(timer);
    ui->line_militime->setText(QString::number(ui->line_nanotime->text().toFloat() / 1000000));
    ui->line_time->setText(QString::number(ui->line_nanotime->text().toFloat() / 1000000000));

    delete[] array;
}

void SortingProgram::on_buttOncountSort_released()
{
    array = new int[ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt()];
    int *count_passes = new int(0), *count_comparisons = new int(0), *count_permutations = new int(0);

    SortingAlgorithms::ArrayProcessing<int>::generatedArray(array, ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt(), 10, 1989);

    if(ui->sortingMethod_box->currentIndex() == 0)
    {
        SortingAlgorithms::InsertSort<int>::insert_sort(array, ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt(), *count_passes, *count_comparisons, *count_permutations);
    }
    else if(ui->sortingMethod_box->currentIndex() == 1)
    {
        SortingAlgorithms::BubbleSort<int>::bubble_sort(array, ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt(), *count_passes, *count_comparisons, *count_permutations);
    }
    else if(ui->sortingMethod_box->currentIndex() == 2)
    {
        SortingAlgorithms::CocktailShakerSort<int>::cocktail_shaker_sort(array, ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt(), *count_passes, *count_comparisons, *count_permutations);
    }
    else if(ui->sortingMethod_box->currentIndex() == 3)
    {
        SortingAlgorithms::MergeSort<int>::merge_sort(array, 0, ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt() - 1, *count_passes, *count_comparisons, *count_permutations);
    }
    else if(ui->sortingMethod_box->currentIndex() == 4)
    {
        SortingAlgorithms::HeapSort<int>::heap_sort(array, ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt(), *count_passes, *count_comparisons, *count_permutations);
    }
    else if(ui->sortingMethod_box->currentIndex() == 5)
    {
        SortingAlgorithms::QuickSort<int>::quick_sort(array, 0, ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt() - 1, *count_passes, *count_comparisons, *count_permutations);
    }
    else if(ui->sortingMethod_box->currentIndex() == 6)
    {
        SortingAlgorithms::CountingSort<int>::counting_sort(array, ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt(), *count_passes, *count_comparisons, *count_permutations);
    }
    else if(ui->sortingMethod_box->currentIndex() == 7)
    {
        SortingAlgorithms::RadixSort<int>::radix_sort(array, ui->arraySize_box->itemText(ui->arraySize_box->currentIndex()).toInt(), *count_passes, *count_comparisons, *count_permutations);
    }

    ui->line_passes->setText(QString::number(*count_passes));
    ui->line_comparisons->setText(QString::number(*count_comparisons));
    ui->line_permutations->setText(QString::number(*count_permutations));

    delete(count_passes);
    delete(count_comparisons);
    delete(count_permutations);
    delete[] array;
}

void SortingProgram::on_buttTestingSort_released()
{
    array = new int[ui->test_arraySize_box->itemText(ui->test_arraySize_box->currentIndex()).toInt()];

    SortingAlgorithms::ArrayProcessing<int>::generatedArray(array, ui->test_arraySize_box->itemText(ui->test_arraySize_box->currentIndex()).toInt(), 10, 1989);

    QString arr;
    for(int i = 0; i < ui->test_arraySize_box->itemText(ui->test_arraySize_box->currentIndex()).toInt(); i++)
    {
        if(i == ui->test_arraySize_box->itemText(ui->test_arraySize_box->currentIndex()).toInt() - 1)
        {
            arr = arr + QString::number(array[i]);
        }
        else
        {
            arr = arr + QString::number(array[i]) + " ";
        }
    }
    ui->generation_field->setText(arr);

    if(ui->test_sortingMethod_box->currentIndex() == 0)
    {
        SortingAlgorithms::InsertSort<int>::insert_sort(array, ui->test_arraySize_box->itemText(ui->test_arraySize_box->currentIndex()).toInt());
    }
    else if(ui->test_sortingMethod_box->currentIndex() == 1)
    {
        SortingAlgorithms::BubbleSort<int>::bubble_sort(array, ui->test_arraySize_box->itemText(ui->test_arraySize_box->currentIndex()).toInt());
    }
    else if(ui->test_sortingMethod_box->currentIndex() == 2)
    {
        SortingAlgorithms::CocktailShakerSort<int>::cocktail_shaker_sort(array, ui->test_arraySize_box->itemText(ui->test_arraySize_box->currentIndex()).toInt());
    }
    else if(ui->test_sortingMethod_box->currentIndex() == 3)
    {
        SortingAlgorithms::MergeSort<int>::merge_sort(array, 0, ui->test_arraySize_box->itemText(ui->test_arraySize_box->currentIndex()).toInt() - 1);
    }
    else if(ui->test_sortingMethod_box->currentIndex() == 4)
    {
        SortingAlgorithms::HeapSort<int>::heap_sort(array, ui->test_arraySize_box->itemText(ui->test_arraySize_box->currentIndex()).toInt());
    }
    else if(ui->test_sortingMethod_box->currentIndex() == 5)
    {
        SortingAlgorithms::QuickSort<int>::quick_sort(array, 0, ui->test_arraySize_box->itemText(ui->test_arraySize_box->currentIndex()).toInt() - 1);
    }
    else if(ui->test_sortingMethod_box->currentIndex() == 6)
    {
        SortingAlgorithms::CountingSort<int>::counting_sort(array, ui->test_arraySize_box->itemText(ui->test_arraySize_box->currentIndex()).toInt());
    }
    else if(ui->test_sortingMethod_box->currentIndex() == 7)
    {
        SortingAlgorithms::RadixSort<int>::radix_sort(array, ui->test_arraySize_box->itemText(ui->test_arraySize_box->currentIndex()).toInt());
    }

    arr = "";
    for(int i = 0; i < ui->test_arraySize_box->itemText(ui->test_arraySize_box->currentIndex()).toInt(); i++)
    {
        if(i == ui->test_arraySize_box->itemText(ui->test_arraySize_box->currentIndex()).toInt() - 1)
        {
            arr = arr + QString::number(array[i]);
        }
        else
        {
            arr = arr + QString::number(array[i]) + " ";
        }
    }
    ui->sorting_field->setText(arr);

    delete[] array;
}

