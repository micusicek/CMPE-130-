#include "arraydatabase.h"


//helper function
void merge( database &arr, int left, int middle, int right){
       int i, j, k;
       int n1 = middle - left + 1;
       int n2 =  right - middle;

       /* create temp arrays */
       ListNode L[n1], R[n2];

       /* Copy data to temp arrays L[] and R[] */
       for (i = 0; i < n1; i++)
           L[i] = arr[left + i];
       for (j = 0; j < n2; j++)
           R[j] = arr[middle +1+ j];

       /* Merge the temp arrays back into arr[l..r]*/
       i = 0; // Initial index of first subarray
       j = 0; // Initial index of second subarray
       k = left; // Initial index of merged subarray
       while (i < n1 && j < n2)
       {
           if (L[i].room_price <= R[j].room_price)         //checks to see if which index of L[] & R[] is smaller; adds smallest to arr[]
           {
               arr[k] = L[i];
               i++;
           }
           else                                          
           {
               arr[k] = R[j];
               j++;
           }
           k++;
       }

       /* Copy the remaining elements of L[], if there
          are any */
       while (i < n1)
       {
           arr[k] = L[i];
           i++;
           k++;
       }

       /* Copy the remaining elements of R[], if there
          are any */
       while (j < n2)
       {
           arr[k] = R[j];
           j++;
           k++;
       }
}


arrayDatabase::arrayDatabase(){

    this->list_size = 0;
}

void arrayDatabase::createDatabase(int rooms)
{
    this->list.resize(rooms);
    this->list_size = rooms;

    for(unsigned int i=0; i<this->list.size(); i++){
        this->list[i].room_price = this->bell_curve_generator();
        this->list[i].room_num = i;
    }
}


int arrayDatabase::bell_curve_generator()
{
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);
    std::normal_distribution<double> distrN(350.0, 12.0);
    int ran_num = distrN(e);

    return ran_num;
}


void arrayDatabase::changePrice()
{

    for(int i=0; i<this->list_size; i++){
        this->list[i].room_price = bell_curve_generator();
    }
}



void arrayDatabase::print_database()
{
    //prints out information of room number & the room's price
    for(int i=0; i<this->list.size(); i++){
        std::cout<<"\nRecord # "<< i+1<<std::endl;
        std::cout<<this->list[i].room_num<<std::endl;
        std::cout<<this->list[i].room_price<<std::endl;

    }
    std::cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<std::endl;
}




void arrayDatabase::insertionSort()
{
        int i, j;
        ListNode key;
        for(i=0; i<this->list_size; i++){ 
            key = this->list[i];
            j = i-1;
            
            /*
            moves elements that are greater than the key to a poition
            ahead of their spot that it is already in */
            while(j>= 0 && this->list[j].room_price>key.room_price) 
            {                                                       
                this->list[j+1] = this->list[j];
                j=j-1;
            }

            this->list[j+1] = key;
        }
    }

void arrayDatabase::selectionSort()
{
    int i, j, minIndex;
    ListNode temp;

    for(i=0; i<this->list_size-1; i++){
        minIndex = i;   //reseting the minIndex back "i" after nested loops are done
        
        /*
        gets the lowest element and stores it in minIndex,
        in the unsorted section of the elements*/
        for(j=i+1; j<this->list_size; j++){
            if(this->list[j].room_price<this->list[minIndex].room_price){
                minIndex = j;
            }
        }
        if(minIndex != i){        //swap two element poition
            temp = this->list[i];
            this->list[i] = this->list[minIndex];
            this->list[minIndex] = temp;
        }
    }
}

void arrayDatabase::mergeSort(int l, int r)
{

    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        this->mergeSort(l, m);
        this->mergeSort(m+1, r);

        merge(this->list, l, m, r);
    }
}

//helper function
int partition(database &arr, int low, int high)
{
        ListNode temp;
        ListNode pivot = arr[low];
        int i = low - 1, j = high + 1;

        while (true)
        {
            // Find leftmost element greater than
            // or equal to pivot
            do
            {
                i++;
            } while (arr[i].room_price < pivot.room_price);

            // Find rightmost element smaller than
            // or equal to pivot
            do
            {
                j--;
            } while (arr[j].room_price > pivot.room_price);

            // If two pointers met.
            if (i >= j)
                return j;

            temp  = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

        }
}


void arrayDatabase::randomizedQuickSort(int low, int high)
{
    if (low < high)
       {
           /* pi is partitioning index, arr[p] is now
              at right place */
           int pi = partition(this->list, low, high);

           // Separately sort elements before
           // partition and after partition
           randomizedQuickSort(low, pi);
           randomizedQuickSort(pi + 1, high);
    }
}


void arrayDatabase::bubbleSort()
{
    int i, j;
    ListNode temp;
		for (i = 0; i < this->list_size - 1; i++)

			// Last i elements are already in place   
			for (j = 0; j < this->list_size - i - 1; j++)
                if (this-> list[j].room_price > this->list[j + 1].room_price){

                    temp = this->list[j];
                    this->list[j] = this->list[j+1];
                    this->list[j+1] = temp;

                }
}

void arrayDatabase::deleteValue(int room_price)
{
    this->list.erase(list.begin()+room_price);
}

void arrayDatabase::addItem()
{
    ListNode newItem;
    newItem.room_price = bell_curve_generator();
    newItem.room_num = this->list_size + 1;
    this->list_size++;
    this->list.push_back(newItem);
}







