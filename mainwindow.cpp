#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "arraydatabase.h"




MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //Program banner for GUI
    QPixmap pix("C:/Users/amer0/Pictures/desktop_banner.png");
    int w = ui->Desktop_banner->width();
    int h = ui->Desktop_banner->height();
    // No need to change it is for graphical purpose 
    ui->Desktop_banner->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatioByExpanding));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_generate_database_clicked()
{

    //Add room prices to the vectors
    this->database_insertion.createDatabase(ui->spinBox->value());
    this->database_selection.createDatabase(ui->spinBox->value());
    this->database_merge.createDatabase(ui->spinBox->value());
    this->database_quickSort.createDatabase(ui->spinBox->value());
    this->database_bubbleSort.createDatabase(ui->spinBox->value());
    this->database_AVL.createDatabase(ui->spinBox->value());


    //send message to GUI that databases were created
    QMessageBox::information(this, "Progress", "Database created!");
}

void MainWindow::on_print_database_clicked()
{
   //print the database. Used for debugging
    std::cout<<"~~~~~~~~~~~~~~~~INSERTION SORT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    this->database_insertion.print_database();
    std::cout<<std::endl<<std::endl;
    std::cout<<"~~~~~~~~~~~~~~~~SELECTION SORT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    this->database_selection.print_database();
    std::cout<<std::endl<<std::endl;
    std::cout<<"~~~~~~~~~~~~~~~~MERGE SORT ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    this->database_merge.print_database();
    std::cout<<std::endl<<std::endl;
    std::cout<<"~~~~~~~~~~~~~~~~Randomized QuickSort ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
    this->database_quickSort.print_database();
    std::cout<<std::endl<<std::endl;
    std::cout<<"~~~~~~~~~~~~~~~~END!!~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
}



void MainWindow::on_Insertion_sort_clicked()
{
    QElapsedTimer timer;
    timer.start();
   int frequency = ui->frequency_box->value();
   for(int i=0; i<frequency; i++){
        this->database_insertion.changePrice();
        this->database_insertion.insertionSort();
   }
   this->insertion_time = timer.elapsed();
   QString value = QString::number(this->insertion_time);
   QMessageBox::information(this, "Time Taken", "It took " + value + "ms to sort using insertion sort");


}

void MainWindow::on_selection_sort_clicked()
{
   QElapsedTimer timer;
   timer.start();
   int frequency = ui->frequency_box->value();
   for(int i=0; i<frequency; i++){
        this->database_selection.changePrice();
        this->database_selection.selectionSort();
   }
   this->selection_time = timer.elapsed();
   QString value = QString::number(this->selection_time);
   QMessageBox::information(this, "Time Taken", "It took " + value + "ms to sort using selection sort");

 }

void MainWindow::on_merge_sort_clicked()
{

    QElapsedTimer timer;
    timer.start();
    int size = this->database_merge.list_size-1;
    int frequency = ui->frequency_box->value();
    for(int i=0; i<frequency; i++){
         this->database_merge.changePrice();
         this->database_merge.mergeSort(0, size);
    }
    this->merge_time = timer.elapsed();
    QString value = QString::number(this->merge_time);
    QMessageBox::information(this, "Time Taken", "It took " + value + "ms to sort using Merge sort");
}

void MainWindow::on_quick_sort_clicked()
{
    QElapsedTimer timer;
    timer.start();

    int frequency = ui->frequency_box->value();
    for(int i=0; i<frequency; i++){
         this->database_quickSort.changePrice();
         this->database_quickSort.randomizedQuickSort(0, database_quickSort.list.size()-1);
    }
    this->random_quick_time = timer.elapsed();
    QString value = QString::number(this->random_quick_time);
    QMessageBox::information(this, "Time Taken", "It took " + value + "ms to sort using Quicksort");
}


void MainWindow::on_bubbleSort_clicked()
{
    QElapsedTimer timer;
    timer.start();
    int frequency = ui->frequency_box->value();
    for(int i=0; i<frequency; i++){
        this->database_bubbleSort.changePrice();
        this->database_bubbleSort.bubbleSort();
    }
    this->bubble_time = timer.elapsed();
    QString value = QString::number(this->bubble_time);
    QMessageBox::information(this, "Time Taken", "It took " + value + "ms to sort using Bubble Sort");
}

void MainWindow::on_AVL_tree_clicked()
{
    QElapsedTimer timer;
    timer.start();
    int frequency = ui->frequency_box->value();
    for(int i=0; i<frequency; i++){

        this->database_AVL.createDatabase(ui->spinBox->value());
    }
    this->AVL_time = timer.elapsed();
    QString value = QString::number(this->AVL_time);
    QMessageBox::information(this, "Time Taken", "It took " + value + "ms to update AVL tree");
}



void MainWindow::on_AddItem_clicked()
{
    int num_items = ui->vector_add->value();
    QElapsedTimer timer1, timer2;
    timer1.start();
    for(int i=0; i<num_items; i++){
        database_quickSort.addItem();
    }
    double time_taken1 = timer1.elapsed();

    timer2.start();
    for(int i=0; i<num_items; i++){
        database_AVL.insert(database_AVL.AVL_size+1, database_AVL.bell_curve_generator());
        this->database_AVL.AVL_size++;
    }
    double time_taken2 = timer2.elapsed();
    QString value1 = QString::number(time_taken1);
    QString value2 = QString::number(time_taken2);
    QMessageBox::information(this, "Time Taken","Vector add took: "+ value1 + "ms" + "\nAVL add took: " + value2 + "ms");

}

void MainWindow::on_pushButton_clicked()
{
    int num_items = ui->vector_delete->value();
    int vect_size = database_quickSort.list.size();
    int random_num, random_num2;
    srand(time(NULL));
    QElapsedTimer timer1, timer2;

    //Delete from the vector
    timer1.start();
    random_num = rand() % vect_size + 1;
    database_quickSort.list.erase(database_quickSort.list.begin(), database_quickSort.list.begin()+num_items);
    double time_taken1 = timer1.elapsed();

    //delete nodes from AVL

    timer2.start();
    for(int i=0; i<num_items; i++){
        random_num2 = rand()% database_AVL.AVL_size + 1;
        database_AVL.deleteKey(database_AVL.bell_curve_generator());
    }
    double time_taken2 = timer2.elapsed();

    //print the time taken!
    QString value1 = QString::number(time_taken1);
    QString value2 = QString::number(time_taken2);
    QMessageBox::information(this, "Time Taken","Vector delete took: "+ value1 + "ms" + "\nAVL delete took: " + value2 + "ms");
}

void MainWindow::on_pushButton_2_clicked()
{
    QString num = ui->search->text();
    QString found_vect, found_AVL;
    bool AVL;
    double searchedNum = num.toInt();
    QElapsedTimer timer1, timer2;
    timer1.start();
    for(int i=0; i<database_quickSort.list.size(); i++){

        if(searchedNum == this->database_quickSort.list[i].room_price){
            found_vect = "found!";
            break;
        }
        else {
            found_vect = "not Found!";
        }

    }

    double time_taken1 = timer1.elapsed();

    timer2.start();
    AVL = database_AVL.search(searchedNum);
    if(AVL == true){
        found_AVL = "found!";
    }
    else{
        found_AVL = "not Found!";
    }
    double time_taken2 = timer2.elapsed();

    QString value1 = QString::number(time_taken1);
    QString value2 = QString::number(time_taken2);
    QMessageBox::information(this, "Time Taken","For Vector database the item was " + found_vect + "\nFor AVL database the item was " + found_AVL + "\n Vector time taken: " + value1 + " ms\nAVL time taken: " + value2 + " ms");


}
