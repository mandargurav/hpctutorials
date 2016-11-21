#include"stdio.h"
#include"mpi.h"

#define ARRSIZE 20

main(int argc, char **argv)
{
	int myid, size;
	int i;
	int total_data[ARRSIZE];
	int data[ARRSIZE/4];	
	
	//Initialize MPI environment 
	MPI_Init(&argc,&argv);
	
	//Get total number of processes
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	
	//Get my unique identification among all processes
	MPI_Comm_rank(MPI_COMM_WORLD, &myid);
	
	//Exit the code if the number of processes is not equal to 4
	if(size!=4)
	{
		MPI_Finalize();
		exit(0);
	}
	
	//Every process initializes data to some value
	for(i=0;i<ARRSIZE/4;i++)
	{
		data[i] = myid*10 + i;			
	}
	
	//print the initialized data
	for(i=0;i<ARRSIZE/4;i++)
	{
		printf("\nmyid: %d \t%d", myid, data[i]);			
	}
	
	//Collect / Gather the data at root = 0 
	MPI_Gather(&data, ARRSIZE/4, MPI_INT, &total_data, ARRSIZE/4, MPI_INT, 0, MPI_COMM_WORLD);
	
	//If root
	if(myid==0)
	{
		//print the data
		printf("\nFinal data: ");
		for(i=0;i<ARRSIZE;i++)
		{
			printf("\t%d", total_data[i]);			
		}
		printf("\n\nProgram exit!\n");
	}
	
	//End MPI environment        
	MPI_Finalize();
}
