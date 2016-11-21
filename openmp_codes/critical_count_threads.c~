#include<stdio.h>
#include<omp.h>

//Counts the total number of threads

int main()
{
	int myid, total;
	
	omp_set_num_threads(4);
	
	#pragma omp parallel private(myid) shared(total)
	{		
		myid = omp_get_thread_num();
		
		#pragma omp atomic
		total++;		
	}
	printf("\n total number of threads = %d", total);
	printf("\nProgram Exit!\n");
}

