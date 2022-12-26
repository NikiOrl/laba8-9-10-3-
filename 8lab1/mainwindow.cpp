#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include <stdlib.h>
#include <QTextEdit>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>
#define MAS_SIZE 200
#define BIG_SIZE 1000

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->pushButton_max->setEnabled(false);
    ui->pushButton_min->setEnabled(false);
    ui->pushButton_puz->setEnabled(false);
    ui->pushButton_ras->setEnabled(false);
    ui->pushButton_sl->setEnabled(false);
    ui->pushButton_sred->setEnabled(false);
    ui->pushButton_tabl->setEnabled(true);
    //ui->pushButton_tabl->setEnabled(false);
    ui->pushButton_bict->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->pushButton_gnom->setEnabled(false);
    ui->pushButton_obezi->setEnabled(false);

}

MainWindow::~MainWindow()
{
    delete ui;
    ui->tableWidget->setRowCount(1);


}





//////////////////////////////////////////////////////
void bubleScort(int *arr, int size)
{
    //while
    for (int i = 0;i<size;i++)
    {
        for (int j = 0; j < i;j++)
        {
            if (arr[j]>arr[i])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j]= temp;
            }
        }
    }
}

void GnomeSort(int *massiv, int size)
{
    int i=1, j=2;
    while (i<size)
    {
        if (massiv[i-1]<massiv[i])
        {
            i=j;
            j++;
        }
        else
        {
            int temp=massiv[i];
            massiv[i]=massiv[i-1];
            massiv[i-1]=temp;
            i--;
            if (i==0)
            {
                i=j;
                j++;
            }
        }
    }
}
void bistray(int *mas, int size) {
    //Указатели в начало и в конец массива
    int i = 0;
    int j = size - 1;//Центральный элемент массива


    int mid = mas[size / 2];  //Делим массив


    do {
        //Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
        //В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
        while(mas[i] < mid) {
            i++;
        }
        //В правой части пропускаем элементы, которые больше центрального
        while(mas[j] > mid) {
            j--;
        }

        //Меняем элементы местами
        if (i <= j) {
            int tmp = mas[i];
            mas[i] = mas[j];
            mas[j] = tmp;

            i++;
            j--;
        }
    } while (i <= j);


    //Рекурсивные вызовы, если осталось, что сортировать
    if(j > 0) {
        //"Левый кусок"
        bistray(mas, j + 1);
    }
    if (i < size) {
        //"Првый кусок"
        bistray(&mas[i], size - i);
    }
}
bool correct(int *arr, int size) //Проверяем корректность данных
{
    while (--size > 0 ) // цикл пока
        if (arr[size - 1] > arr[size])
            return true;
    return false;
}
void rasch(int *arr,int size)
{	 int step=size; // готовим начальный шаг
     bool pr_peres;// вводим контроль перестановки
      while(step>1 or pr_peres)
      {
          step/=1.247f; // шаг на этом проходе.  На первом проходе получается примерно 80% от размера массива,
          // и легкие элементы в хвосте переносятся в первые 20%
          if (step<1) step=1; // 0 быть не может, присвоим 1
          pr_peres =false;
          for (int i=0; i+step<size;++i)
          { // двигаемся, пока сравниваемый элемент (на шаг от текущего) в массиве
              if(arr[i]>arr[i+step])
              {
                  int tmp=arr[i];
                  arr[i]=arr[i+step];
                  arr[i+step]=tmp;
                  pr_peres=true;//перестановка выполнена
              }
          }
      }
}
void shuffle(int *arr, int size) // Рандомно раскидываем элементы
{
    for (int i = 0; i < size; ++i) // цикл
    {
        int rnd = rand() % size;
        int temp = arr[i];
        arr[i] = arr[rnd];
        arr[rnd] = temp;
        //      std::swap(arr[i], arr[(rand() % size)]);
    }
}

void MonkeySort(int *arr, int size) //Сортируем по-обезьяньи
{
    while (correct(arr, size)) // цикл пока
        shuffle(arr, size); // сортировочный прикол
}
bool MainWindow::IsSort(int *mas, int count)
{
    while (--count>=1)
        if (mas [count]<mas[count-1]) return true;
    return true;

}
//}//////////////////////////////////////////////////////////////





//////////////////////////////////////////////////////////////
void MainWindow::on_pushButton_tabl_clicked()
{

    ui->label_max->clear();
    ui->label_min->clear();
    ui->label_sred->clear();
    if(ui->lineEdit_kolvo->text() == "")
    {
        ui->pushButton_max->setEnabled(false);
        ui->pushButton_min->setEnabled(false);
        ui->pushButton_puz->setEnabled(false);
        ui->pushButton_ras->setEnabled(false);
        ui->pushButton_sl->setEnabled(false);
        ui->pushButton_sred->setEnabled(false);
        ui->pushButton_tabl->setEnabled(true);
        //ui->pushButton_tabl->setEnabled(false);
        ui->pushButton_bict->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_gnom->setEnabled(false);
        ui->pushButton_obezi->setEnabled(false);
        ui->tableWidget->clear();
        QMessageBox::warning(this, "Ошибка", "Поле не должно быть пустым");
        return;
    }
    else
    {
        ui->pushButton_max->setEnabled(true);
        ui->pushButton_puz->setEnabled(true);
        ui->pushButton_ras->setEnabled(true);
        ui->pushButton_min->setEnabled(true);
        ui->pushButton_sl->setEnabled(true);
        ui->pushButton_sred->setEnabled(true);
        ui->pushButton_bict->setEnabled(true);
        ui->pushButton_gnom->setEnabled(true);
        ui->pushButton_obezi->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
    }
    ui->tableWidget->setColumnCount(1);
    bool flag;
    int razmer = ui->lineEdit_kolvo->text().toInt(&flag);
    if (!flag)
    {
        QMessageBox::information(this,"Внимание","Данные введены не правильно");
        ui->tableWidget->setEnabled(false);
        ui->pushButton_max->setEnabled(false);
        ui->pushButton_puz->setEnabled(false);
        ui->pushButton_ras->setEnabled(false);
        ui->pushButton_min->setEnabled(false);
        ui->pushButton_sl->setEnabled(false);
        ui->pushButton_sred->setEnabled(false);
        ui->pushButton_bict->setEnabled(false);
        ui->pushButton_gnom->setEnabled(false);
        ui->pushButton_obezi->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        return;
    }
    if (razmer<1 or razmer>200 )
    {
        QMessageBox::information(this,"Внимание","кол-во элементов долдно быть от 1 до 200");
        ui->tableWidget->setEnabled(false);
        ui->pushButton_max->setEnabled(false);
        ui->pushButton_puz->setEnabled(false);
        ui->pushButton_ras->setEnabled(false);
        ui->pushButton_min->setEnabled(false);
        ui->pushButton_sl->setEnabled(false);
        ui->pushButton_sred->setEnabled(false);
        ui->pushButton_bict->setEnabled(false);
        ui->pushButton_gnom->setEnabled(false);
        ui->pushButton_obezi->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        return;
    }

    ui->tableWidget->setRowCount(razmer);


}
void MainWindow::on_pushButton_sl_clicked()
{

    ui->pushButton_2->setEnabled(false);
    ui->lineEdit_element->clear();
    /// ui->lineEdit_poisk->clear();
    ui->lineEdit_rezalt->clear();
    int n_row = ui->tableWidget->rowCount();
    srand(clock());
    int chislo;
    QString stroka;
    for (int i=0;i<n_row;i++)
    {
        if (ui->tableWidget->item(i,0)==NULL)
        {
            QTableWidgetItem*  new_item;
            new_item = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,new_item);
        }
        chislo = rand()%201-100;
        stroka.setNum(chislo);
        ui->tableWidget->item(i,0)->setText(stroka);
    }
    ui->label_max->clear();
    ui->label_min->clear();
    ui->label_sred->clear();
}
/////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////
void MainWindow::on_pushButton_min_clicked()
{
    int razmer = ui->tableWidget->rowCount();
    int *mas = new int [ razmer];
    bool flag;
    for (int i = 0;i<razmer;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag);

        }
        else
        {
            QMessageBox::information(this,"Внимание","пустая ячека");
            return;
        }
        if(!flag)
        {
            QMessageBox::information(this,"Внимание","ячейка должна содержать число");
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            return;
        }


    }
    int min = mas[0];
    for (int i =0;i<razmer;i++)
    {
        if(mas[i]<min)
        {
            min = mas[i];
        }

    }
    ui->label_min->setText(QString::number(min));
}
void MainWindow::on_pushButton_max_clicked()
{
    int razmer = ui->tableWidget->rowCount();
    int *mas = new int [ razmer];
    bool flag;
    for (int i = 0;i<razmer;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag);

        }
        else
        {
            QMessageBox::information(this,"Внимание","пустая ячека");
            return;
        }
        if(!flag)
        {
            QMessageBox::information(this,"Внимание","ячейка должна содержать число");
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            delete [] mas;
            mas = nullptr;
            return;
        }


    }
    int max = mas[0];
    for (int i =0;i<razmer;i++)
    {
        if(mas[i]>max)
        {
            max = mas[i];
        }

    }
    ui->label_max->setText(QString::number(max));
    delete [] mas;
    mas = nullptr;
}
void MainWindow::on_pushButton_sred_clicked()
{
    int razmer = ui->tableWidget->rowCount();
    int *mas = new int [ razmer];
    bool flag;
    for (int i = 0;i<razmer;i++)
    {
        if(ui->tableWidget->item(i,0)!=nullptr)
        {
            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag);

        }
        else
        {
            QMessageBox::information(this,"Внимание","пустая ячека");
            return;
        }
        if(!flag)
        {
            QMessageBox::information(this,"Внимание","ячейка должна содержать число");
            ui->tableWidget->scrollToItem(ui->tableWidget->item(i,0));
            delete [] mas;
            mas = nullptr;
            return;
        }


    }
    double sred=0;
    double sum=0;
    for (int i =0;i<razmer;i++)
    {
        sum += mas[i];
        sred=sum/razmer;

    }
    ui->label_sred->setText(QString::number(sred));
    delete [] mas;
    mas = nullptr;
}

//////////////////////////////////////////////////////



void MainWindow::on_pushButton_puz_clicked()
{
    int size = ui->tableWidget->rowCount();
    ui->pushButton_2->setEnabled(true);
    int *mas = new int [size];

    bool error = false;
    for (int i =0;i<size;i++)
    {
        QTableWidgetItem* item = ui->tableWidget->item(i,0);
        if (item== nullptr)
        {
            item = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,item);
            item->setBackground(Qt::red);
            error = true;
        }
        else
        {
            QString str = item->text();
            bool flag;
            int value = str.toInt(&flag);

            if (flag)
            {
                mas[i]=value;
                item->setBackground(Qt::white);
            }
            else
            {
                item->setBackground(Qt::red);
                error=true;
            }
        }
    }
    if(error)
    {
        QMessageBox::information(this,"Внимание","Таблица заполнена не корректно");
        int i;
        QTableWidgetItem* item = ui->tableWidget->item(i,0);
        item = new QTableWidgetItem;

        item->setBackground(Qt::red);
        error = true;

        delete [] mas;
        mas = nullptr;
        return;
    }
    else
    {
        bubleScort(mas,size);
        for (int i = 0; i < size; i++)
        {
            ui->tableWidget->item(i,0)->setText(QString::number(mas[i]));
        }
    }
    delete [] mas;
    mas = nullptr;
}
void MainWindow::on_pushButton_ras_clicked()
{
    int size = ui->tableWidget->rowCount();
    ui->pushButton_2->setEnabled(true);
    int *mas = new int [size];
    bool error = false;
    for (int i =0;i<size;i++)
    {
        QTableWidgetItem* item = ui->tableWidget->item(i,0);
        if (item== nullptr)
        {
            item = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,item);
            item->setBackground(Qt::red);
            error = true;
        }
        else
        {
            QString str = item->text();
            bool flag;
            int value = str.toInt(&flag);

            if (flag)
            {
                mas[i]=value;
                item->setBackground(Qt::white);
            }
            else
            {
                item->setBackground(Qt::red);
                error=true;
            }
        }
    }
    if(error)
    {
        QMessageBox::information(this,"Внимание","Таблица заполнена не корректно");
        int i;
        QTableWidgetItem* item = ui->tableWidget->item(i,0);
        item = new QTableWidgetItem;

        item->setBackground(Qt::red);
        error = true;
        delete [] mas;
        mas = nullptr;
        return;
    }
    else
    {
        rasch(mas,size);
        for (int i = 0; i < size; i++)
        {
            ui->tableWidget->item(i,0)->setText(QString::number(mas[i]));
        }
    }
    delete [] mas;
    mas = nullptr;
}
void MainWindow::on_pushButton_gnom_clicked()
{
    int size = ui->tableWidget->rowCount();
    ui->pushButton_2->setEnabled(true);
    int *mas = new int [size];
    bool error = false;
    for (int i =0;i<size;i++)
    {
        QTableWidgetItem* item = ui->tableWidget->item(i,0);
        if (item== nullptr)
        {
            item = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,item);
            item->setBackground(Qt::red);
            error = true;
        }
        else
        {
            QString str = item->text();
            bool flag;
            int value = str.toInt(&flag);

            if (flag)
            {
                mas[i]=value;
                item->setBackground(Qt::white);
            }
            else
            {
                item->setBackground(Qt::red);
                error=true;
            }
        }
    }
    if(error)
    {
        QMessageBox::information(this,"Внимание","Таблица заполнена не корректно");
        int i;
        QTableWidgetItem* item = ui->tableWidget->item(i,0);
        item = new QTableWidgetItem;

        item->setBackground(Qt::red);
        error = true;
        delete [] mas;
        mas = nullptr;
        return;
    }
    else
    {
        GnomeSort(mas,size);
        for (int i = 0; i < size; i++)
        {
            ui->tableWidget->item(i,0)->setText(QString::number(mas[i]));
        }
    }
    delete [] mas;
    mas = nullptr;
}
void MainWindow::on_pushButton_bict_clicked()
{
    int size = ui->tableWidget->rowCount();
    ui->pushButton_2->setEnabled(true);
    int *mas = new int [size];
    bool error = false;
    for (int i =0;i<size;i++)
    {
        QTableWidgetItem* item = ui->tableWidget->item(i,0);
        if (item== nullptr)
        {
            item = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,item);
            item->setBackground(Qt::red);
            error = true;
        }
        else
        {
            QString str = item->text();
            bool flag;
            int value = str.toInt(&flag);

            if (flag)
            {
                mas[i]=value;
                item->setBackground(Qt::white);
            }
            else
            {
                item->setBackground(Qt::red);
                error=true;
            }
        }
    }
    if(error)
    {
        QMessageBox::information(this,"Внимание","Таблица заполнена не корректно");
        int i;
        QTableWidgetItem* item = ui->tableWidget->item(i,0);
        item = new QTableWidgetItem;

        item->setBackground(Qt::red);
        error = true;
        delete [] mas;
        mas = nullptr;
        return;
    }
    else
    {
        bistray(mas,size);
        for (int i = 0; i < size; i++)
        {
            ui->tableWidget->item(i,0)->setText(QString::number(mas[i]));
        }
    }
    delete [] mas;
    mas = nullptr;
}
void MainWindow::on_pushButton_obezi_clicked()
{
    int size = ui->tableWidget->rowCount();
    ui->pushButton_2->setEnabled(true);
    int *mas = new int [size];
    bool error = false;
    bool flag;
    int razmer = ui->lineEdit_kolvo->text().toInt(&flag);
    if (!flag)
    {
        QMessageBox::information(this,"Внимание","Данные введены не правильно");
        return;
    }
    if (razmer<1 or razmer>5 )
    {
        QMessageBox::information(this,"Внимание","кол-во элементов долдно быть от 1 до 5");
        return;
    }

    ui->tableWidget->setRowCount(razmer);
    for (int i =0;i<size;i++)
    {
        QTableWidgetItem* item = ui->tableWidget->item(i,0);
        if (item== nullptr)
        {
            item = new QTableWidgetItem;
            ui->tableWidget->setItem(i,0,item);
            item->setBackground(Qt::red);
            error = true;
        }
        else
        {
            QString str = item->text();
            bool flag;
            int value = str.toInt(&flag);

            if (flag)
            {
                mas[i]=value;
                item->setBackground(Qt::white);
            }
            else
            {
                item->setBackground(Qt::red);
                error=true;
            }
        }
    }
    if(error)
    {
        QMessageBox::information(this,"Внимание","Таблица заполнена не корректно");
        return;
        int i;
        QTableWidgetItem* item = ui->tableWidget->item(i,0);
        item = new QTableWidgetItem;

        item->setBackground(Qt::red);
        error = true;
        delete [] mas;
        mas = nullptr;
        return;
    }
    else
    {
        MonkeySort(mas,size);
        for (int i = 0; i < size; i++)
        {
            ui->tableWidget->item(i,0)->setText(QString::number(mas[i]));
        }
    }
    delete [] mas;
    mas = nullptr;
}




void MainWindow::on_lineEdit_kolvo_textChanged(const QString &arg1)
{
    ui->pushButton_max->setEnabled(false);
    ui->pushButton_min->setEnabled(false);
    ui->pushButton_puz->setEnabled(false);
    ui->pushButton_ras->setEnabled(false);
    ui->pushButton_sl->setEnabled(false);
    ui->pushButton_sred->setEnabled(false);
    ui->pushButton_tabl->setEnabled(true);
    ui->pushButton_bict->setEnabled(false);
    ui->pushButton_gnom->setEnabled(false);
    ui->pushButton_obezi->setEnabled(false);
    ui->pushButton_2->setEnabled(false);
    ui->lineEdit_element->clear();
    //  ui->lineEdit_poisk->clear();
    ui->lineEdit_rezalt->clear();

    int a = ui->pushButton_tabl->text().toInt();
    if(a =0)
    {
        ui->pushButton_tabl->setEnabled(false);
    }
    else
    {
        ui->pushButton_tabl->setEnabled(true);
    }

}


void MainWindow::on_pushButton_clicked()
{
    ui->lineEdit_rezalt->clear();
    ui->lineEdit_rezalt->clear();
    ui->lineEdit_element->clear();
    bool flag;
    bool flag2;
    int poisk = ui->lineEdit_poisk->text().toInt(&flag2);
    int razmer = ui->tableWidget->rowCount();
    int *mas = new int [razmer];
    for (int i = 0; i < razmer; i++)
    {
        if (ui->tableWidget->item(i,0)!=NULL)
        {

            mas[i] = ui->tableWidget->item(i,0)->text().toInt(&flag);
            if (!flag)
            {
                QMessageBox::information(this,"Внимание","Напишите цифры");
                delete [] mas;
                return;
            }
        }
        else
        {
            QMessageBox::information(this,"Внимание","Пустые ячейки");
            delete [] mas;
            return;
        }
    }

    //пошск перебором
    int element = 0 ;
    QString rezalt = "";
    for (int i=0;i<razmer;i++)
    {
        if (mas[i]== poisk)
        {
            rezalt.append(QString::number(i+1));
            rezalt.append(" ");
            element++;
        }
    }
    ui->lineEdit_element->setText(QString::number(element));
    ui->lineEdit_rezalt->setText("Найдено значение в "+rezalt+"строчке");
    delete [] mas;

    //ui->textEdit->clear();
    int index_key = ui->lineEdit_element->text().toInt(&flag);//Считываем значение ключа
    int size = ui->tableWidget->rowCount();//получаем количество строк
    if (!correct(mas, size))//Если массив отсортирован(бинарный поиск)
    {
        //QMessageBox::information(this,"Количество совпадений","Опа, бинарочка");//Бинарный поиск
        int low, high, mid,score;

        low = 0; high = size-0,score=0;

        bool nashel;
        for (int i=0;i<size-1;i++)
        {
            while(low<=high)
            {
                mid = (low+high)/2;
                if (mas[mid] == index_key)//проверяем ключ со серединным элементом
                {
                    QString A="Число найдено в строке: ";

                    QTableWidgetItem *item = ui->tableWidget->item(mid,0); //Получаем указатель на ячейку
                    item->setBackground(Qt::green);
                    nashel=true;
                    score++;

                    mas[mid]++;
                }
                if (mas[mid] > index_key) high = mid - 1; // проверяем, какую часть нужно отбросить
                else low = mid + 1;
            }
        }
        if(nashel)
        {
            QString A="Всего совпадений: ";

        }
        if(!nashel)
        {
            // QMessageBox::information(this,"Внимание","Таких чисел нет в массиве!");
        }
    }

}



void MainWindow::on_pushButton_2_clicked()
{
    int size = ui->tableWidget->rowCount();
    if( size == 0)
    {
        QMessageBox::information(this, "Ошибка", "Нет строк");
        return;
    }
    double *mas = new double[size];

    int errors = 0;
    QTableWidgetItem *itemError= nullptr ;
    for (int i=0; i<size; i++)
    {
        if(ui->tableWidget->item(i, 0) == nullptr)
        {
            QMessageBox::information(this, "Ошибка", "Массив не заполнен");
            return;

        }
        QString str_numb = ui->tableWidget->item(i, 0)->text();
        bool ok = false;
        double number_in_Item = str_numb.toDouble(&ok);
        if(ok)
        {
            mas[i] = number_in_Item;
        }
        else
        {
            if (errors == 0)
            {
                itemError = ui->tableWidget->item(i, 0);
            }
            errors++;
        }
    }
    if (errors > 0)
    {
        ui->tableWidget->scrollToItem(itemError);
        QMessageBox::information(this, "Ошибка", "Массив заполнен некорректно ");
        return;
    }
    if(size >= BIG_SIZE)
    {
        QMessageBox::information(this, "Внимание", "В массиве больше" + QString::number(BIG_SIZE) + "элементов.\n Выполнение операции займет некоторе время ");
    }
    double *mas_without_copy =  new double[size];
    int c = 0;//хранит, в какой элемент массива без повторов мы должны положить новый элемент
    //проверка корректности массива; сортирован ли он
    bool sorted = true;
    for(int i = 0; i<size-1; i++)
    {
        if(mas[i+1] < mas[i])
        {
            sorted = false;
            break;
        }
    }
    if(!sorted)
    {
        QMessageBox::information(this, "Ошибка", "Массив не отсортирован!");
    }
    for(int i=0; i<size-1; i++)
    {
        if(mas[i] != mas[i+1])
        {
            mas_without_copy[c] = mas[i];//добавляю текущий элемент в массив без повторов
            c++;
        }
    }
    mas_without_copy[c] = mas[size-1];//заносим последний элемент
    c++;
    //выводим элементы в таблицу
    ui->tableWidget->setRowCount(c);// количество строк задаю равное размеру массива без повторений

    for(int i=0; i<c; i++)
    {
        QString text;
        ui->tableWidget->item(i, 0)->setText(text.setNum(mas_without_copy[i]));
    }
    //удаление памяти
    delete [] mas;
    mas = NULL;

}













