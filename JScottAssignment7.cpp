//159.201 Assignment 7
//Jamie Scott
//ID 18041508

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

vector<int> vector_random;
vector<int> vector_reversed;
vector<int> vector_sorted;

/*  Implement a Heap class here (from the slides)  */
class Heap {
private:
	vector <int> data;
	int last;
	int insComparisons; //keep track of comparisons - insert
	int delComparisons; //keep track of comparisons - delete

public:
	Heap(){
		last=-1;
		insComparisons=0;
		delComparisons=0;
	}
	~Heap() {};
	void InsertHeap (unsigned int newthing);
	void DeleteRoot ();
	void PrintHeap(); 
	int getInsComparisons();
	int getDelComparisons();

};

void Heap::InsertHeap (unsigned int newthing){
	data.push_back(newthing);
	last=last+1;
	if (last==0){return;}
	int temp;
	int swindex = last;
	int parindex=0;
	bool swapping = true;
	while (swapping){
		swapping = false;
		if (swindex%2==0){
			parindex = swindex/2 - 1; //right
		} 
		else parindex = swindex /2; //left
		if (parindex>=0){
			if (data[swindex]>data[parindex]){
				temp=data[swindex];
				data[swindex] = data[parindex];
				data[parindex] = temp;
				swapping=true;
				swindex=parindex;
			}
			insComparisons++; //increase the count of comparisons by one
		}
	}
}

void Heap::DeleteRoot (){
	if (last<0) return;
	//'delete' root - swap it with last 
	swap(data[last], data[0]);
	last = last-1;
	int parindex = 0;
	int leftindex = parindex*2+1;
	int rightindex=parindex*2+2;

	while (data[parindex]<data[leftindex]||data[parindex]<data[rightindex]){
		if(leftindex>last){break;}
		else {
			if (rightindex>last){
				if (data[parindex]<data[leftindex]){
					swap(data[parindex], data[leftindex]);
				}
				delComparisons++;
				break;
			}
		}

		delComparisons=delComparisons+2;
		if (data[rightindex]<data[leftindex]){
			swap(data[leftindex], data[parindex]);
			parindex=leftindex;
		}
		else {
			swap(data[rightindex], data[parindex]);
			parindex=rightindex;
		}

		leftindex=parindex*2+1;
		rightindex=parindex*2+2;
		if(leftindex>last){break;}
		else {
			if (rightindex>last){
				delComparisons++;
				if (data[parindex]<data[leftindex]){
		//			/*debug*/ cout<<"Debug 3 - swapping "<<data[parindex]<<" at "<<parindex<<" and "<<data[leftindex]<<" at "<<leftindex<<endl;
					swap(data[parindex], data[leftindex]);
		//				/*debug*/ PrintHeap();

				}
				//delComparisons++;
				break;
			}
		}
	}
}

void Heap::PrintHeap(){
	for (int i=0; i<data.size(); i++){
		cout<<data[i]<<" ";
	}
	cout<<endl;
}
/*methods to allow HeapSort acces to coumparisons counts within Heap class*/
int Heap::getInsComparisons(){
	return insComparisons;
}

int Heap::getDelComparisons(){
	return delComparisons;
}

/* the char* filename is just for printing the name, the file is opened and dealt with in the main() */
void HeapSort(vector<int> &sortingvector,int number_of_elements, char* filename){
  Heap myHeap; 

  /* Using the sortingvector, INSERT elements into the Heap */
  for (int i=0; i<sortingvector.size(); i++){
	  myHeap.InsertHeap(sortingvector[i]);
  }
  
  /* After building the heap from the file, PRINT the current state of the heap before sorting */
  cout<<"Heap before sorting: "<<filename<<endl;
  myHeap.PrintHeap();
  
  /* DELETE elements from the Heap, copying it back to the vector in a way that it is sorted */
  for (int i=0; i<number_of_elements; i++){
	  myHeap.DeleteRoot();
  }
    
  /* PRINT the number of comparisons for the Insert and Deletion tasks */
  cout<<"InsertHeap: "<<myHeap.getInsComparisons()<<" comparisons"<<endl;
  cout<<"DeleteRoot: "<<myHeap.getDelComparisons()<<" comparisons"<<endl;

  /* Print the state of the vector after sorting */
  cout<<"Vector after sorting:"<<endl;
  myHeap.PrintHeap();
}


int main (int argc, char** argv ){//get filename from arguments
	char expression[100];
	int number;
	ifstream input_file_random;
	ifstream input_file_reversed;
	ifstream input_file_sorted;
	if(argc==4) {
	  input_file_random.open(argv[1]);
	  input_file_reversed.open(argv[2]);
	  input_file_sorted.open(argv[3]);
	}
	else {printf("The program needs 3 filenames, in this order: random, reversed and sorted.\n");exit(0);}
	int number_of_elements_random=0;
	while(input_file_random >> number){
		sscanf(expression,"%d",&number);
		/*Comment out this printout, this is just to check that the file can be read */
//		printf("%d ",number );	
		vector_random.push_back(number);
		number_of_elements_random++;
	}
	// /*Comment out this printout, this is just to check that the array was copied */
	// printf("File %s:\n", argv[1]);
	// for(int count=0;count<number_of_elements_random;count++){
	// 	printf("%d ",vector_random[count]);
	// }
	// printf("\n");
	// /*end printout*/

	int number_of_elements_reversed=0;
	while(input_file_reversed >> number){
		sscanf(expression,"%d",&number);
		/*Comment out this printout, this is just to check that the file can be read */
//		printf("%d ",number );	
		vector_reversed.push_back(number);
		number_of_elements_reversed++;
	}
	// /*Comment out this printout, this is just to check that the array was copied */
	// printf("File %s:\n", argv[2]);
	// for(int count=0;count<number_of_elements_reversed;count++){
	// 	printf("%d ",vector_reversed[count]);
	// }
	// printf("\n");
	// /*end printout*/


	int number_of_elements_sorted=0;
	while(input_file_sorted >> number){
		sscanf(expression,"%d",&number);
		/*Comment out this printout, this is just to check that the file can be read */
//		printf("%d ",number );	
		vector_sorted.push_back(number);
		number_of_elements_sorted++;
	}
	// /*Comment out this printout, this is just to check that the array was copied */
	// printf("File %s:\n", argv[3]);
	// for(int count=0;count<number_of_elements_sorted;count++){
	// 	printf("%d ",vector_sorted[count]);
	// }
	// printf("\n");
	// /*end printout*/


	/* Implement or call your Heap sort here, the Heap class with methods should be copied/implemented before main() */
	HeapSort(vector_random, number_of_elements_random, argv[1]);
	cout << endl;
	HeapSort(vector_reversed, number_of_elements_reversed, argv[2]);
	cout << endl;
	HeapSort(vector_sorted, number_of_elements_sorted, argv[3]);	
}
